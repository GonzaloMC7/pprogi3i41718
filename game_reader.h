/**
 * @brief Fichero del modulo game_reader.h encargado de la lectura de los diferentes espacios
 *
 *
 * @file game_reader.h
 * @author Javier Martin y Miguel Manzano
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


/*COMENTADO*/

#ifndef _GAME_READER_H
#define _GAME_READER_H
#include "game.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "link.h"


/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de cargar los espacios correspondientes de un fichero dado
 * @author Javi Martin
 * @param game Puntero a las EdD Game
 * @param filename puntero al nombre de un archivo determinado
 * @return OK si los espacios han sido cargados del fichero correctamente o ERROR en caso contrario
 */

STATUS game_reader_load_spaces(Game* game, char* filename);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de cargar los objetos correspondientes de un fichero dado
 * @author Javi Martin
 * @param game Puntero a las EdD Game
 * @param filename puntero al nombre de un archivo determinado
 * @return OK si los objetos han sido cargados del fichero correctamente o ERROR en caso contrario
 */

STATUS game_reader_load_objects(Game* game, char* filename);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de cargar los enlaces correspondientes de un fichero dado
 * @author Miguel Manzano
 * @param game Puntero a las EdD Game
 * @param filename puntero al nombre de un archivo determinado
 * @return OK si los espacios han sido cargados del fichero correctamente o ERROR en caso contrario
 */
STATUS game_reader_load_links(Game* game, char* filename);


#endif
