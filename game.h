/**
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG, Javier Martin, Gonzalo Martinez, Juan Martin
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

/*COMENTADO*/

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "player.h"
#include "object.h"
#include "types.h"
#include "die.h"
#include "link.h"


/*Estructura de los elementos del juego, como son el jugador, el objeto y los espacios, o el último comando introducido*/
typedef struct _Game Game;

/*Primitivas de las funciones de game.c*/

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de asignar una localizacion a un objeto determinado
 * game_set_object_location(Game* game, Id idSpace, Id IdObject);
 *
 * @author Javier  Martin
 * @param Puntero a las EdD Game, Id del espacio determinado y Id del objeto determinado
 * @return OK si el espacio ha sido añadido correctamente o ERROR en caso contrario
 */
STATUS game_set_object_location(Game* game, Id idSpace, Id IdObject);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de obtener el nombre del link al que se refiere
 *
 * game_get_name_link(Game* game, int idlink);
 * @author Javier  Martin
 * @param Puntero a las EdD Game,
 * @param Id del link determinado
 * @return cadena de caracteres con el nombre
 */
const char *game_get_name_link(Game* game, int idlink);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de obtener el link
 *
 * game_get_link(Game* game, Id idLink);
 * @author Javier  Martin
 * @param Puntero a las EdD Game,
 * @param Id del link determinado
 * @return puntero al link que se refiere
 */
Link* game_get_link(Game* game, Id idLink);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de obtener el id2 de un link determinado
 *
 * game_get_link_id2(Game* game, Id idLink);
 * @author Javier  Martin
 * @param Puntero a las EdD Game,
 * @param Id del link determinado
 * @return id al que se refiere
 */
Id game_get_link_id2(Game *game,Id idLink);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de añadir un objeto adicional
 *
 * game_add_object(Game* game, Object* object);
 * @author Javier Martin
 * @param game Puntero a las EdD Game
 * @param object Objeto seleccionado
 * @return OK si el objeto ha sido añadido correctamente o ERROR en caso contrario
 */
STATUS game_add_object(Game* game, Object* object);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de añadir un espacio adicional
 *
 * game_add_space(Game* game, Space* space);
 * @author Profesores PPROG
 * @param game Puntero a las EdD Game
 * @param space
 * @return OK si el espacio ha sido añadido correctamente o ERROR en caso contrario
 */
STATUS game_add_space(Game* game, Space* space);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de añadir un enlace adicional
 *
 * game_add_link(Game* game, Link* link);
 * @author Javier Martin
 * @param game Puntero a las EdD Game
 * @param link
 * @return OK si el objeto ha sido añadido correctamente o ERROR en caso contrario
 */
STATUS game_add_link(Game* game, Link* link);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Crea el juego en sí
 *
 * game_create();
 * @author Profesores PPROG
 * @param Se le pasa una variable Game creada en el game_loop.c
 * @return Devuelve OK si se ha creado correctamente y ERROR si se ha producido algún fallo
 */
 Game *game_create();
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Función de creación del juego en el archivo que se va a mostrar por pantalla
 *
 * game_create_from_file(Game* game, char* filename);
 * @author Javier Martin
 * @param El juego creado anteriormente
 * @param filename el archivo donde se va a representar el juego
 * @return Devuelve OK si se ha creado en el archivo correctamente y ERROR si se ha producido algún fallo
 */
 STATUS game_create_from_file(Game* game, char* filename);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Actualiza el juego con el nuevo comando
 *
 * game_update(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve OK si se ha creado correctamente y ERROR si se ha producido algún fallo
 */
 STATUS game_update(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Función para destruir el juego cuando se vaya a salir de él o se produzca algún error
 *
 * game_destroy(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve OK si se ha creado correctamente y ERROR si se ha producido algún fallo
 */
 STATUS game_destroy(Game* game);
 /*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el último valor del dado
 *
 * game_get_die_lastroll(Game* game);
 * @author Gonzalo Martínez
 * @param El juego creado anteriormente
 * @return Devuelve el último valor del dado
 */
 int game_get_die_lastroll(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Comprueba si el juego ha terminado
 *
 * game_is_over(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve TRUE si el juego ha terminado y sino devuelve FALSE
 */
 BOOL game_is_over(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la pantalla de juego en la terminal
 *
 * game_print_screen(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
 void game_print_screen(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la información de juego en la terminal
 *
 * game_print_data(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
 void game_print_data(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene un espacio a partir de un id
 *
 * game_get_space(Game* game, Id id);
 * @author Profesores PPROG
 * @param El juego creado anteriormente y el id del cual queremos averiguar la localización
 * @return Devuelve un puntero a la estructura space o NULL en caso de que se haya producido algún error
 */
 Space* game_get_space(Game* game, Id id);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id de la localización en la que está el player
 *
 * game_get_player_location(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve ese id a localizar o NO_ID en caso de que se haya producido algún error
 */
 Id game_get_player_location(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id de la localización en la que está en objeto
 *
 * game_get_object_location(Game* game,Id IdObject);
 * @author Javier Martin
 * @param game El juego creado anteriormente
 * @param IdObject el Id del objeto al que nos referimos
 * @return Devuelve ese id a localizar o NO_ID en caso de que se haya producido algún error
 */
Id game_get_object_location(Game* game,Id IdObject);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el dado que se va a utilizar en el juego
 *
 * game_get_die(Game* game);
 * @author Gonzalo Martínez
 * @param El juego creado anteriormente
 * @return Devuelve el Die die creado
 */
Die * game_get_die(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el último comando introducido
 *
 * game_get_last_command(Game* game);
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve una variable de tipo T_Command
 */
 Command *game_get_last_command(Game* game);
 /*-----------------------------------------------------------------------------------------------------*/
 /**
  * @brief Funcion encargada de devolver el estado del comando
  *
  * game_get_estado(Game* game);
  * @author Javier Martin
  * @param El juego creado anteriormente
  * @return Ok o ERROR
  */
 STATUS game_get_estado(Game* game);
 /*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el nombre del objeto al que se refiere
 *
 * game_get_name_object(Game* game, int ob);
 * @author Javier Martin
 * @param game El juego creado
 * @param ob el numero del objeto al que se refiere
 * @return Devuelve la cadena de caracteres que pertenece al objeto que se busca
 */
 const char *game_get_name_object(Game* game, int ob);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Comprueba que el objeto se encuentre con el jugador
 *
 * game_find_player_object(Game* game, Id IdObject);
 * @author Javier Martin
 * @param game Puntero a las EdD Game,
 * @param IdObject Id del objeto determinado
 * @return OK si el objeto se encuentra con el jugador o ERROR si no se encuentra con el jugador
 */
BOOL game_find_player_object(Game* game, Id IdObject);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene la descricion almacenada en el juego indicado
 * @author Juan Martin
 * @param El juego creado
 * @return Devuelve la descricion almacenada en game
 */
const char *game_get_info (Game* game);

#endif
