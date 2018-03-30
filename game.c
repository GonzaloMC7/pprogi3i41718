/**
* @brief It implements the game interface and all the associated callbacks
* for each command
*
* @file game.c
* @author Profesores PPROG, Javier Martin, Gonzalo Martinez
* @version 1.0
* @date 13-01-2015
* @copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"



#define N_CALLBACK 9


/**
Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);
struct _Game{
  Player * pl; /*Jugador*/
  Object * ob[MAX_OBJ+1]; /*Objetos del juego*/
  Space* spaces[MAX_SPACES + 1]; /*Espacios del juego*/
  Command *cmd; /*comando */
  Die * die; /*Dado que se utiliza en el juego*/
};
/**
List of callbacks for each command in the game
*/

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Hace la función asignada al comando desconocido, y por lo tanto mantiene el juego como está
 * sin cambiar nada.
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_unknown(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Termina el juego
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_exit(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la siguiente posición
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_following(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la posición previa
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_previous(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Coge un objeto y lo asigna al jugador hasta que se haga un drop
 * @author Javier Martin
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_take(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Deja un objeto que se haya cogido anteriormente
 * @author Javier Martin
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_drop(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Hace rodar el dado
 * @author Gonzalo Martinez
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_roll(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la anterior posición de una oca
 * @author Gonzalo Martinez
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_left(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la siguiente posición de una oca
 * @author Gonzalo Martinez
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
void game_callback_right(Game* game);


static callback_fn game_callback_fn_list[N_CALLBACK]={
	game_callback_unknown,
	game_callback_exit,
	game_callback_following,
	game_callback_previous,
	game_callback_take,
	game_callback_drop,
	game_callback_roll,
	game_callback_left,
	game_callback_right
};

/**
Private functions
*/

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de una posición en el espacio a partir del número de posición
 * @author Profesores PPROG
 * @param Game game creado anteriormente, int con el número de posición del cual se quiere obtener el id
 * @return Devuelve el Id obtenido
 */
Id     game_get_space_id_at(Game* game, int position);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna al jugador una posición en el espacio
 * @author Profesores PPROG
 * @param Game game creado anteriormente, Id id del jugador
 * @return Devuelve OK si se ha asignado correctamente y ERROR si se ha producido algún fallo
 */
STATUS game_set_player_location(Game* game, Id id);

/**
Game interface implementation
*/
/*-----------------------------------------------------------------------------------------------------------------------*/

Game *game_create() {
	int i;
	Game *game=NULL;
	game =(Game*)malloc(sizeof(Game));
	if(!game){
		return NULL;
	}
	/*^^^Control de errores game^^^*/

	game->pl = player_create(1);

	/*Se le pasa un 1 porque hay que inicializarlo con un id*/
	/*Bucle que inicializa un puntero (a NULL) por cada objeto de juego (MAX_OBJ=100)*/
	/*Bucle que inicializa un puntero (a NULL) por cada espacio de juego (MAX_SPACES=100)*/

	for (i = 0; i < MAX_SPACES; i++) {
		game->spaces[i] = NULL;
	}
	for (i = 0; i < MAX_OBJ; i++) {
		game->ob[i] = NULL;
	}

	/*Inicialización del último comando a ninguno ya que no ha habido un comando anterior*/

	game->cmd = command_ini();
	game->die = die_create();

	/*Se devuelve OK si el juego se ha creado correctamente (falta control de errores)*/
	return game;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS game_create_from_file(Game* game, char* filename) {

	if(!game){
		return ERROR;
	}
	if(!filename){
		return ERROR;
	}
	/*^^^Controles de errores game y file^^^*/
	/*Se crea el juego correspondiente*/

	/*Se encarga de cargar los espacios y los objetos mediante un fichero de datos dado y el juego creado anteriormente*/
	if (game_reader_load_spaces(game, filename) == ERROR)
		return ERROR;
	if (game_reader_load_objects(game, filename) == ERROR)
		return ERROR;
	game_set_player_location(game,game_get_space_id_at(game,0));

	/*Se devuelve OK si se ha creado el juego en el archivo correctamente (falta control de errores)*/
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de liberar los recursos del juego*/

STATUS game_destroy(Game* game) {
	int i = 0;

	if(!game){
		return ERROR;
	}
	/*^^^Control de errores game^^^*/

	/*Se destruirán los espacios de todo el juego uno a uno (hasta MAX_SPACES) siempre que estos todavía no hayan sido destruidos o sean NULL*/
	for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
		space_destroy(game->spaces[i]);
	}
	/*Se destruirán los objetos de todo el juego uno a uno (hasta MAX_OBJ) siempre que estos todavía no hayan sido destruidos o sean NULL*/
	for (i = 0; (i < MAX_OBJ) && (game->ob[i] != NULL); i++) {
		object_destroy(game->ob[i]);
	}

	/*Se destruye el jugador*/
	player_destroy(game->pl);

	/*Se destruye el dado*/
	die_destroy(game->die);

	command_destroy(game->cmd);

	/*Se devuelve OK si se ha destruido el juego correctamente (falta control de errores)*/
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función para añadir un espacio adicional*/

STATUS game_add_space(Game* game, Space* space) {
	int i = 0;

	/*^^^Control de errores game^^^*/
	if(!game){
		return ERROR;
	}


	/*Control de errores space*/
	if (space == NULL) {
		return ERROR;
	}

	/*Ir al último espacio, para ello buscamos el primero menor que MAX_SPACES que sea igual a NULL, es decir, que este vacío*/
	while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
		i++;
	}

	/*Se devuelve error si ha habido un problema y el número del último espacio supera a la macro MAX_SPACES*/
	if (i >= MAX_SPACES) {
		return ERROR;
	}

	/*Se sitúa en el último espacio añadido*/
	game->spaces[i] = space;

	/*Se devuelve OK si se ha añadido el espacio correctamente*/
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función para añadir un objeto adicional*/

STATUS game_add_object(Game* game, Object* object) {
	int i = 0;

	/*^^^Control de errores game^^^*/
	if (game == NULL) {
		return ERROR;
	}

	/*Control de errores object*/
	if (object == NULL) {
		return ERROR;
	}
	/*Ir al último objeto, para ello buscamos el primero menor que MAX_OBJ que sea igual a NULL, es decir, que este vacío*/
	while ((i < MAX_OBJ) && (game->ob[i] != NULL)){
		i++;
	}

	/*Se devuelve error si ha habido un problema y el número del último espacio supera a la macro MAX_OBJ*/
	if (i >= MAX_OBJ) {
		return ERROR;
	}

	/*Se sitúa en el último objeto añadido*/
	game->ob[i] = object;

	/*Se devuelve OK si se ha añadido el objeto correctamente*/
	return OK;
}


/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de proporcionar el ID de un espacio mediante una posicion determinada*/

Id game_get_space_id_at(Game* game, int position) {

	if(!game){
		return NO_ID;
	}
	/*^^^Control de errores game^^^*/

	if (position < 0 || position >= MAX_SPACES) {
		return NO_ID;
	}
	/*^^^Se devuelve un NO_ID, es decir, ninguno, si se introduce una posición no válida^^^*/

	/*Se devuelve el id del espacio en el que se encuentra a partir de la función de space.c*/
	return space_get_id(game->spaces[position]);
}


/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de dar un espacio a partir de un Id*/

Space* game_get_space(Game* game, Id id){
	int i = 0;

	if(!game){
		return NULL;
	}
	/*^^^Control de errores game^^^*/


	if (id == NO_ID) {
		return NULL;
	}
	/*^^^Si no se obtiene un id se devuelve NULL^^^*/

	/*Bucle for: desde 0 hasta el final y siempre que los espacios estén cubiertos, si el id dado es igual al del espacio, se devuelve ese espacio*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		if (id == space_get_id(game->spaces[i])){
			return game->spaces[i];
		}
	}

	/*Si no se devuelve el espacio entonces se devolverá NULL*/
	return NULL;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Establece una localizacion a un jugador*/

STATUS game_set_player_location(Game* game, Id id) {

	if (id == NO_ID) {
		return ERROR;
	}
	if(!game){
		return ERROR;
	}
	/*^^^Controles de errores game y id^^^*/

	/*Asignación de la localización del jugador a partir de sus funciones y las de game*/
	player_set_location(game->pl, id);

	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Establece una localizaciona un objeto determinado a traves de las id's de ambos*/

STATUS game_set_object_location(Game* game, Id idSpace, Id IdObject) {

	if (idSpace == NO_ID) {
		return ERROR;
	}
	if(!game){
		return ERROR;
	}
	/*^^^Controles de errores game y idSpace^^^*/

	/*Asignación de la localización del objeto determinado por un id en un espacio*/
	space_set_object(game->spaces[idSpace-1], IdObject);

	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Obtiene la loaclizacion de un jugador*/

Id game_get_player_location(Game* game) {

	if(!game){
		return NO_ID;
	}
	/*^^^Control de errores game^^^*/

	/*Se devuelve el valor de la localización como un id a partir de sus funciones*/

	return player_get_location(game->pl);
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Obtiene la localizacion de un objeto determinado por su Id*/

Id game_get_object_location(Game* game, Id IdObject){
	int i = 0;

	if (!game || IdObject==NO_ID) {
		return NO_ID;
	}
	/*Control de errores si no existe el juego o no tiene ID el objeto*/

	/*Bucle encargado de obtener el Id de una localizacion de unn objeto determinado*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		if (space_find_id(game->spaces[i], IdObject)==TRUE){ /*Si en el espacio determinado se encuentra el objeto, devuleve el Id del espacio*/
			return game_get_space_id_at(game, i);
		}
	}
	/*En caso contrario se devuelve NO_ID*/
	return NO_ID;
}


/*-----------------------------------------------------------------------------------------------------------------------*/
Die * game_get_die(Game * game) {
	return game->die;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de actualizar el juego dependiendo del comando introducido*/

STATUS game_update(Game* game) {

	T_Command cmd_type;

	if(!game){
		return ERROR;
	}
	/*^^^Controles de errores game y cmd^^^*/
	cmd_type = command_get_type(game->cmd);
	(*game_callback_fn_list[cmd_type])(game);

	/*Se devuelve OK si no se ha producido ningún error*/
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de obtener el ultimo comando introducido*/

Command * game_get_last_command(Game* game) {
    if (game == NULL)
        return NULL;

    return game->cmd;
}


/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de imprimir por pantalla los datos del juego tales como espacios, objetos o jugadores*/

void game_print_data(Game* game) {
	int i = 0;

	if(!game){
		return;
	}
	/*^^^Control de errores game^^^*/

	/*Se imprimen los siguientes datos: space, object location y player location*/
	printf("\n\n-------------\n\n");

	printf("=> Spaces: \n");
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		space_print(game->spaces[i]);
	}

	printf("=> Objects: \n");
	for (i = 0; i < MAX_OBJ && game->ob[i] != NULL; i++) {
		object_print(game->ob[i]);
	}

	printf("=> Player location: %d\n", (int) game_get_player_location(game));
	printf("prompt:> ");

	/*La función no devuelve nada*/
}

/*-----------------------------------------------------------------------------------------------------------------------*/
int game_get_die_lastroll(Game * game){
	if(!game) return -1;
	return die_get_lastroll(game->die);
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de informar si el juego se ha acabado o no*/

BOOL game_is_over(Game* game) {
	if(!game){
		return TRUE;
	}
	/*^^^Control de errores game, y se devuelve TRUE para que acabe el juego ya que ha habido un error en game^^^*/

	/*Si el juego no ha terminado se devuelve FALSE*/
	return FALSE;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de obtener el nombre de un objeto determinado*/

const char *game_get_name_object(Game* game, int ob){
	if (!game) {
		return NULL;
	}
	/*^^^Control de errores game^^^*/

	/*devolucion del objeto determinado*/
	return object_get_name(game->ob[ob-1]);
}




/*-----------------------------------------------------------------------------------------------------------------------*/

/**
Callbacks implementation for each action
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion que no se sabe el comando introducido*/

void game_callback_unknown(Game* game) {
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcionen la que se quiere salir del juego*/

void game_callback_exit(Game* game) {
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion en la que se coge un objeto*/

void game_callback_take(Game* game){


	int i=0, objloc=0;
	Id id_object=NO_ID;
	Id space_id_player = NO_ID;
	Id space_id_object = NO_ID;

	space_id_player = game_get_player_location(game);

	if(space_id_player == NO_ID){
		return ;
	}


	for(i=0;game->ob[i]!=NULL;i++){
		if(strcmp(game_get_name_object(game, i+1),command_get_ob(game->cmd))==0){
			objloc=i;
		}
	}

	if(game->ob[objloc]==NULL){
		command_interpret_input(game->cmd,command_get_ob(game->cmd));
		return ;
	}

	id_object = object_get_id(game->ob[objloc]);
	space_id_object=game_get_object_location(game, id_object);
	if(space_id_player==space_id_object){
		player_set_object(game->pl, id_object);
		space_destroy_object(game->spaces[space_id_player-1], id_object);
		return ;
	}
	else{
		command_interpret_input(game->cmd,command_get_ob(game->cmd));
		return ;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion para dejar un objeto*/

void game_callback_drop(Game* game){

	Id space_id_player = NO_ID;

	space_id_player = game_get_player_location(game);

	if(space_id_player == NO_ID||player_get_object(game->pl, id)==NO_ID){ /*TODO hay que indicarle al drop el objeto del inv que se quiere soltar*/
		return ;
	}
	game_set_object_location(game, game_get_space_id_at(game, space_id_player-1), player_get_object(game->pl) );
	player_set_object (game->pl, NO_ID);
	return ;

}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion para avanzar en el espacio*/

void game_callback_following(Game* game) {

	int i = 0;
	Id current_id = NO_ID;
	Id space_id = NO_ID;

	if(!game){
		return;
	}
	/*^^^Control de errores game^^^*/

	/*Se obtiene la localización del jugador*/
	space_id = game_get_player_location(game);

	if (space_id == NO_ID) {
		return;
	}
	/*^^^Control de errores id^^^*/


	/*Se le pasa a la localización del player la localización del espacio situado en el sur del que se encontraba*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		current_id = space_get_id(game->spaces[i]);
		if (current_id == space_id) {
			current_id = space_get_south(game->spaces[i]);
			if (current_id != NO_ID) {
				game_set_player_location(game, current_id);
			}
			return;
		}
	}
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion para retroceder en el espacio*/

void game_callback_previous(Game* game) {
	int i = 0;
	Id current_id = NO_ID;
	Id space_id = NO_ID;

	if(!game){
		return;
	}
	/*^^^Control de errores game^^^*/

	/*Se obtiene la localización del jugador*/
	space_id = game_get_player_location(game);

	if (NO_ID == space_id) {
		return;
	}
	/*^^^Control de errores id^^^*/

	/*Se le pasa a la localización del player la localización del espacio situado en el norte del que se encontraba*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		current_id = space_get_id(game->spaces[i]);
		if (current_id == space_id) {
			current_id = space_get_north(game->spaces[i]);
			if (current_id != NO_ID) {
				game_set_player_location(game, current_id);
			}
			return;
		}
	}
}


/*-----------------------------------------------------------------------------------------------------------------------*/

void game_callback_left(Game * game){
	int i = 0;
	Id current_id = NO_ID;
	Id space_id = NO_ID;

	if(!game){
		return;
	}
	/*^^^Control de errores game^^^*/

	/*Se obtiene la localización del jugador*/
	space_id = game_get_player_location(game);

	if (space_id == NO_ID) {
		return;
	}
	/*^^^Control de errores id^^^*/


	/*Se le pasa a la localización del player la localización del espacio situado en el sur del que se encontraba*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		current_id = space_get_id(game->spaces[i]);
		if (current_id == space_id) {
			current_id = space_get_west(game->spaces[i]);
			if (current_id != NO_ID) {
				game_set_player_location(game, current_id);
			}
			return;
		}
	}
}

/*-----------------------------------------------------------------------------------------------------------------------*/
void game_callback_right(Game * game){
	int i = 0;
	Id current_id = NO_ID;
	Id space_id = NO_ID;

	if(!game){
		return;
	}
	/*^^^Control de errores game^^^*/


	/*Se obtiene la localización del jugador*/
	space_id = game_get_player_location(game);


	if (space_id == NO_ID) {
		return;
	}
	/*^^^Control de errores id^^^*/


	/*Se le pasa a la localización del player la localización del espacio situado en el sur del que se encontraba*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		current_id = space_get_id(game->spaces[i]);
		if (current_id == space_id) {
			current_id = space_get_east(game->spaces[i]);
			if (current_id != NO_ID) {
				game_set_player_location(game, current_id);
			}
			return;
		}
	}
}

/*-----------------------------------------------------------------------------------------------------------------------*/

void game_callback_roll(Game* game) {
	die_roll(game->die);
}
/*-----------------------------------------------------------------------------------------------------------------------*/
