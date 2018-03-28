/** 
 * @brief It defines a textual graphic engine
 * 
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "screen.h"
#include "space.h"
#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Crea e inicializa el motor grafico
 * @author Profesores PPROG
 * @param 
 * @return retorna la EdD del motor grafico si se ha podido inicializar correctamente
 */
Graphic_engine* graphic_engine_create();

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Elimina los recursos del motor grafico seleccionado
 * @author Profesores PPROG
 * @param puntero al motor grafico
 * @return no devuelve un valor especifico por ser una funcion de tipo void 
 */
void graphic_engine_destroy(Graphic_engine *ge);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Muestra por pantalla en la terminal los espacios y comentarios necesarios
 * @author Profesores PPROG
 * @param puntero al motor grafico y a game
 * @return no devuelve un valor especifico por ser una funcion de tipo void 
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Muestra por pantalla el comando introducido
 * @author Profesores PPROG
 * @param puntero a motor gráfico y a la cadena que es el comando
 * @return no devuelve un valor específico por ser una función tipo void
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

/*-----------------------------------------------------------------------------------------------------*/

#endif
