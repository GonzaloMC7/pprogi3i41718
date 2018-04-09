/**
* @brief It implements the game interface and all the associated callbacks
* for each command
*
* @file game.c
* @author Profesores PPROG, Javier Martin, Gonzalo Martinez, Juan Martin
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
typedef STATUS (*callback_fn)(Game* game);
struct _Game{
  Player * pl; /*!<Jugador*/
  Object * ob[MAX_OBJ+1]; /*!<Objetos del jugador*/
  Space* spaces[MAX_SPACES + 1]; /*!<Espacios del juego*/
  Link *link[MAX_LINK + 1]; /*!<Enlaces del juego */
  Command *cmd; /*!<comando */
  Die * die; /*!<Dado que se utiliza en el juego*/
  STATUS estado;/*!<estado del comando*/
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
STATUS game_callback_unknown(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Termina el juego
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_exit(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la siguiente posición
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_following(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la posición previa
 * @author Profesores PPROG
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_previous(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Coge un objeto y lo asigna al jugador hasta que se haga un drop
 * @author Javier Martin
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_take(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Deja un objeto que se haya cogido anteriormente
 * @author Javier Martin
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_drop(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Hace rodar el dado
 * @author Gonzalo Martinez
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_roll(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la anterior posición de una oca
 * @author Gonzalo Martinez
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_left(Game* game);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Sitúa al jugador en la siguiente posición de una oca
 * @author Gonzalo Martinez
 * @param Game game creado anteriormente
 * @return No devuelve nada al ser una función void
 */
STATUS game_callback_right(Game* game);

/*Lista de comando que se pueden dar*/
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
Id game_get_space_id_at(Game* game, int position);
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
	/*!<Control de errores game*/
	game->pl = player_create(1);
	for (i = 0; i < MAX_SPACES; i++) {
		game->spaces[i] = NULL;
	}
	for (i = 0; i < MAX_OBJ; i++) {
		game->ob[i] = NULL;
	}
	for (i = 0; i < MAX_LINK; i++) {
		game->link[i] = NULL;
	}
  game->estado=ERROR;
	game->cmd = command_ini();
	game->die = die_create();
	/*Se devuelve OK si el juego se ha creado correctamente (falta control de errores)*/
	return game;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS game_create_from_file(Game* game, char* filename) {

	if(!game||!filename){
		return ERROR;
	}
	/*!<Controles de errores game y file*/
	if (game_reader_load_spaces(game, filename) == ERROR)
		return ERROR;
	if (game_reader_load_objects(game, filename) == ERROR)
		return ERROR;
	if (game_reader_load_links(game, filename) == ERROR)
		return ERROR;

  game_set_player_location(game,game_get_space_id_at(game,0));
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de liberar los recursos del juego*/

STATUS game_destroy(Game* game) {
	int i = 0;

	if(!game){
		return ERROR;
	}
	/*!<Control de errores game^^^*/
	/*!<Se destruirán los espacios de todo el juego uno a uno (hasta MAX_SPACES) siempre que estos todavía no hayan sido destruidos o sean NULL*/
	for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
		space_destroy(game->spaces[i]);
	}
	/*Se destruirán los objetos de todo el juego uno a uno (hasta MAX_OBJ) siempre que estos todavía no hayan sido destruidos o sean NULL*/
	for (i = 0; (i < MAX_OBJ) && (game->ob[i] != NULL); i++) {
		object_destroy(game->ob[i]);
	}
	/*Se destruirán los enlaces de todo el juego uno a uno (hasta MAX_LINK) siempre que estos todavía no hayan sido destruidos o sean NULL*/
	for (i = 0; (i < MAX_LINK) && (game->link[i] != NULL); i++) {
		link_destroy(game->link[i]);
	}
	player_destroy(game->pl);
	die_destroy(game->die);
	command_destroy(game->cmd);
  free(game);
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función para añadir un espacio adicional*/

STATUS game_add_space(Game* game, Space* space) {
	int i = 0;

	/*!<Control de errores game^^^*/
	if(!game||!space){
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
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función para añadir un objeto adicional*/

STATUS game_add_object(Game* game, Object* object) {
	int i = 0;
	/*!<Control de errores game^^^*/
	if (!game||!object) {
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
	return OK;
}


/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función para añadir un objeto adicional*/

STATUS game_add_link(Game* game, Link * link) {
	int i = 0;

	/*^^^Control de errores game^^^*/
	if (!game||!link) {
		return ERROR;
	}
	/*Ir al último objeto, para ello buscamos el primero menor que MAX_OBJ que sea igual a NULL, es decir, que este vacío*/
	while ((i < MAX_LINK) && (game->link[i] != NULL)){
		i++;
	}
	if (i >= MAX_LINK) {
		return ERROR;
	}
	/*Se sitúa en el último objeto añadido*/
	game->link[i] = link;
	return OK;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que devuelve el nombre del link que se ha introducido*/

const char *game_get_name_link(Game* game, int idlink){
    if (!game) {
      return NULL;
    }
    return link_get_name(game->link[idlink-1]);
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que devuelve el link */

Link* game_get_link(Game* game, Id idLink){
    int i = 0;

    if (!game) {
      return NULL;
    }
    if (idLink==NO_ID){
      return NULL;
    }
    for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
      if (idLink == link_get_id(game->link[i])){
      	return game->link[i];
      }
    }
    return NULL;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
Id game_get_link_id2(Game* game, Id id) {
	if(!game){
		return NO_ID;
	}
	return link_get_id2(game->link[id]);
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de proporcionar el ID de un espacio mediante una posicion determinada*/

Id game_get_space_id_at(Game* game, int position) {

	if(!game){
		return NO_ID;
	}
	if (position < 0 || position >= MAX_SPACES) {
		return NO_ID;
	}
	/*!<Se devuelve un NO_ID, es decir, ninguno, si se introduce una posición no válida*/
	return space_get_id(game->spaces[position]);
}


/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de dar un espacio a partir de un Id*/

Space* game_get_space(Game* game, Id id){
	int i = 0;

	if(!game||!id){
		return NULL;
	}
	if (id == NO_ID) {
		return NULL;
	}
	/*Bucle for: desde 0 hasta el final y siempre que los espacios estén cubiertos, si el id dado es igual al del espacio, se devuelve ese espacio*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		if (id == space_get_id(game->spaces[i])){
			return game->spaces[i];
		}
	}
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
  space_set_object(game->spaces[idSpace-1], IdObject);
  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Obtiene la loaclizacion de un jugador*/

Id game_get_player_location(Game* game) {

	if(!game){
		return NO_ID;
	}
  return player_get_location(game->pl);
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Obtiene la localizacion de un objeto determinado por su Id*/

Id game_get_object_location(Game* game, Id IdObject){
	int i = 0;

	if (!game || IdObject==NO_ID) {
		return NO_ID;
	}
	/*Bucle encargado de obtener el Id de una localizacion de unn objeto determinado*/
	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
		if (space_find_id(game->spaces[i], IdObject)==TRUE){ /*Si en el espacio determinado se encuentra el objeto, devuleve el Id del espacio*/
			return game_get_space_id_at(game, i);
		}
	}
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
	cmd_type = command_get_type(game->cmd);
	game->estado=(*game_callback_fn_list[cmd_type])(game);
  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de obtener el estado del comando introducido*/

STATUS game_get_estado(Game* game){
    if (!game) return ERROR;
    return game->estado;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de obtener el ultimo comando introducido*/

Command * game_get_last_command(Game* game) {
    if (!game) return NULL;
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
	return FALSE;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de obtener el nombre de un objeto determinado*/

const char *game_get_name_object(Game* game, int ob){
	if (!game) {
		return NULL;
	}
	/*devolucion del objeto determinado*/
	return object_get_name(game->ob[ob-1]);
}
/*-----------------------------------------------------------------------------------------------------------------------*/
BOOL game_find_player_object(Game* game, Id IdObject){

  if(!game){
    return FALSE;
  }
  return player_find_object(game->pl, IdObject);
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/**
Callbacks implementation for each action
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion que no se sabe el comando introducido*/

STATUS game_callback_unknown(Game* game) {
	return ERROR;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcionen la que se quiere salir del juego*/

STATUS game_callback_exit(Game* game) {
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion en la que se coge un objeto*/

STATUS game_callback_take(Game* game){

	int i=0;
	Id id_object=NO_ID;
	Id space_id_player = NO_ID;
	Id space_id_object = NO_ID;

  space_id_player = game_get_player_location(game);

	if(space_id_player == NO_ID){
		return ERROR;
	}
	for(i=0;game->ob[i]!=NULL;i++){
		if(strcmp(game_get_name_object(game, i+1),command_get_ob(game->cmd))==0){
			break;
		}
	}
  if(game->ob[i]==NULL){
		command_interpret_input(game->cmd,command_get_ob(game->cmd));
		return ERROR;
	}
  id_object = object_get_id(game->ob[i]);
	space_id_object=game_get_object_location(game, id_object);
	if(space_id_player==space_id_object){
		player_set_object(game->pl, id_object);
		space_destroy_object(game->spaces[space_id_player-1], id_object);
		return OK;
	}
	else{
    return ERROR;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------*/
STATUS game_callback_drop(Game* game){

	Id space_id_player = NO_ID;
  Id id_object=NO_ID;
  int i=0;

	space_id_player = game_get_player_location(game);

  for(i=0;game->ob[i]!=NULL;i++){
    if(strcmp(game_get_name_object(game, i+1),command_get_ob(game->cmd))==0){
      break;
    }
  }
  if(game->ob[i]==NULL){
		command_interpret_input(game->cmd,command_get_ob(game->cmd));
		return ERROR;
	}
	if(space_id_player == NO_ID){
		return ERROR;
	}
  id_object = object_get_id(game->ob[i]);

  if (game_find_player_object(game, id_object)==TRUE){

    game_set_object_location(game, game_get_space_id_at(game, space_id_player-1), id_object);
    player_destroy_object (game->pl, id_object);
    return OK;
  }
  else {
    return ERROR;
  }
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion para avanzar en el espacio*/
STATUS game_callback_following(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id_player = NO_ID;
  Id idlink = NO_ID;
  Link* links = NULL;

  space_id_player = game_get_player_location(game);
  if (!space_id_player) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
  		current_id = space_get_id(game->spaces[i]);
  		if (current_id == space_id_player) {
  			idlink = space_get_south_link(game->spaces[i]);
  			if (idlink != NO_ID) {
  				links = game_get_link(game, idlink);
          if(link_get_idopenclose(links) == TRUE){
            if(current_id == link_get_id1(links)){
              current_id = link_get_id2(links);
              game_set_player_location(game, current_id);
              return OK;
            }else if(current_id == link_get_id2(links)){
              current_id = link_get_id1(links);
              game_set_player_location(game, current_id);
              return OK;
            }
          }
  			}
      }
    }
    return ERROR;
  }


/*-----------------------------------------------------------------------------------------------------------------------*/
/*Llamada a funcion para retroceder en el espacio*/
STATUS game_callback_previous(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id_player = NO_ID;
  Id idlink = NO_ID;
  Link* links = NULL;

  space_id_player = game_get_player_location(game);
  if (!space_id_player) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
  		current_id = space_get_id(game->spaces[i]);
  		if (current_id == space_id_player) {
  			idlink = space_get_north_link(game->spaces[i]);
  			if (idlink != NO_ID) {
  				links = game_get_link(game, idlink);
          if(link_get_idopenclose(links) == TRUE){
            if(current_id == link_get_id1(links)){
              current_id = link_get_id2(links);
              game_set_player_location(game, current_id);
              return OK;
            }else if(current_id == link_get_id2(links)){
              current_id = link_get_id1(links);
              game_set_player_location(game, current_id);
              return OK;
            }
          }
  			}
      }
    }
    return ERROR;
  }

/*-----------------------------------------------------------------------------------------------------------------------*/
STATUS game_callback_left(Game* game) {
  int i;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id link_id = NO_ID;
  Link* link = NULL;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      link_id = space_get_west_link(game->spaces[i]);
      if (link_id != NO_ID) {
        link = game_get_link(game, link_id);
        if(!link){
          return ERROR;
        }
        if(link_get_idopenclose(link) == TRUE){
          if(current_id == link_get_id1(link)){
            current_id = link_get_id2(link);
            game_set_player_location(game, current_id);
            return OK;
          }else if(current_id == link_get_id2(link)){
            current_id = link_get_id1(link);
            game_set_player_location(game, current_id);
           return OK;
          }
        }
      }
    }
  }
  return ERROR;
}


/*-----------------------------------------------------------------------------------------------------------------------*/
STATUS game_callback_right(Game* game) {
  int i;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id link_id = NO_ID;
  Link* link = NULL;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      link_id = space_get_east_link(game->spaces[i]);
      if (link_id != NO_ID) {
        link = game_get_link(game, link_id);
        if(!link){
          return ERROR;
        }
        if(link_get_idopenclose(link) == TRUE){
          if(current_id == link_get_id1(link)){
            current_id = link_get_id2(link);
            game_set_player_location(game, current_id);
            return OK;

          }else if(current_id == link_get_id2(link)){
            current_id = link_get_id1(link);
            game_set_player_location(game, current_id);
            return OK;
          }
        }
      }
    }
  }
  return ERROR;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS game_callback_roll(Game* game) {
	die_roll(game->die);
	return OK;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
