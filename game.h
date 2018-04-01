/**
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG, Javier Martin, Gonzalo Martinez
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


/*Estructura de los elementos del juego, como son el jugador, el objeto y los espacios, o el último comando introducido*/
typedef struct _Game Game;

/*Primitivas de las funciones de game.c*/

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de asignar una localizacion a un objeto determinado
 * @author Javier  Martin
 * @param Puntero a las EdD Game, Id del espacio determinado y Id del objeto determinado
 * @return OK si el espacio ha sido añadido correctamente o ERROR en caso contrario
 */

STATUS game_set_object_location(Game* game, Id idSpace, Id IdObject);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de añadir un objeto adicional
 * @author Javier Martin
 * @param Puntero a las EdD Game y Object
 * @return OK si el objeto ha sido añadido correctamente o ERROR en caso contrario
 */
STATUS game_add_object(Game* game, Object* object);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de añadir un espacio adicional
 * @author Profesores PPROG
 * @param Puntero a las EdD Game y Space
 * @return OK si el espacio ha sido añadido correctamente o ERROR en caso contrario
 */
STATUS game_add_space(Game* game, Space* space);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Crea el juego en sí
 * @author Profesores PPROG
 * @param Se le pasa una variable Game creada en el game_loop.c
 * @return Devuelve OK si se ha creado correctamente y ERROR si se ha producido algún fallo
 */
 Game *game_create();
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Función de creación del juego en el archivo que se va a mostrar por pantalla
 * @author Javier Martin
 * @param El juego creado anteriormente y el archivo donde se va a representar el juego
 * @return Devuelve OK si se ha creado en el archivo correctamente y ERROR si se ha producido algún fallo
 */
 STATUS game_create_from_file(Game* game, char* filename);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Actualiza el juego con el nuevo comando
 * @author Profesores PPROG
 * @param El juego creado anteriormente 
 * @return Devuelve OK si se ha creado correctamente y ERROR si se ha producido algún fallo
 */
 STATUS game_update(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Función para destruir el juego cuando se vaya a salir de él o se produzca algún error
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve OK si se ha creado correctamente y ERROR si se ha producido algún fallo
 */
 STATUS game_destroy(Game* game);
 /*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el último valor del dado
 * @author Gonzalo Martínez
 * @param El juego creado anteriormente
 * @return Devuelve el último valor del dado
 */
 int game_get_die_lastroll(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Comprueba si el juego ha terminado
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve TRUE si el juego ha terminado y sino devuelve FALSE
 */
 BOOL game_is_over(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la pantalla de juego en la terminal
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
 void game_print_screen(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la información de juego en la terminal
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
 void game_print_data(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene un espacio a partir de un id
 * @author Profesores PPROG
 * @param El juego creado anteriormente y el id del cual queremos averiguar la localización
 * @return Devuelve un puntero a la estructura space o NULL en caso de que se haya producido algún error
 */
 Space* game_get_space(Game* game, Id id);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id de la localización en la que está el player
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve ese id a localizar o NO_ID en caso de que se haya producido algún error
 */
 Id game_get_player_location(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id de la localización en la que está en objeto
 * @author Javier Martin
 * @param El juego creado anteriormente y el Id del objeto al que nos referimos
 * @return Devuelve ese id a localizar o NO_ID en caso de que se haya producido algún error
 */
Id game_get_object_location(Game* game,Id IdObject);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el dado que se va a utilizar en el juego
 * @author Gonzalo Martínez
 * @param El juego creado anteriormente
 * @return Devuelve el Die die creado
 */
Die * game_get_die(Game* game);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el último comando introducido
 * @author Profesores PPROG
 * @param El juego creado anteriormente
 * @return Devuelve una variable de tipo T_Command
 */
 Command *game_get_last_command(Game* game);
 STATUS game_estado(Game* game);
 /*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el nombre del objeto al que se refiere 
 * @author Javier Martin
 * @param El juego creado y el numero del objeto al que se refiere
 * @return Devuelve la cadena de caracteres que pertenece al objeto que se busca
 */
 const char *game_get_name_object(Game* game, int ob);
/*-----------------------------------------------------------------------------------------------------*/

#endif
