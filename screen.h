/** 
 * @brief It defines a screen
 * 
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

/*COMENTADO*/

typedef struct _Area Area;

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Inicializa y crear la pantalla
 * @author Profesores PPROG
 * @param 
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_init();

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de eliminar los recursos de la pantalla
 * @author Profesores PPROG
 * @param 
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_destroy();

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief "Pintan" la terminal en la que se muestra el juego por pantalla
 * @author Profesores PPROG
 * @param 
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_paint();

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de determinar el comando y la informacion que aparece por pantalla
 * @author Profesores PPROG
 * @param Cadena de caracteres referido al comando
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_gets(char *str);


/*Funciones relacionadas con el área a utilizar en pantalla*/

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Inicializa y reserva memoria para el area que se imprime por pantalla
 * @author Profesores PPROG
 * @param Enteros x,y,whidht y height referidos a la posicion x e y, la altura y la anchura respectivamente
 * @return Devolucion de un puntero a la EdD Area que se ha inicializado en la funcion
 */
Area* screen_area_init(int x, int y, int width, int height);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Elimina los recursos de memoria del area de la pantalla seleccionada
 * @author Profesores PPROG
 * @param Puntero al area que se refiere
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_area_destroy(Area* area);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief "Limpia" la pantalla cuando se ha introducido un comando y se pasa a la siguiente
 * @author Profesores PPROG
 * @param Puntero al area que se refiere
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_area_clear(Area* area);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de reiniciar la posicion que se tiene del cursor
 * @author Profesores PPROG
 * @param Puntero al area que se refiere
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_area_reset_cursor(Area* area);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Determina el cursor en la posicion la cual se está en ese momento
 * @author Profesores PPROG
 * @param Puntero al area que se refiere, y cadena de caracteres 
 * @return No devuelve un valor especifico por ser una funcion de tipo void
 */
void  screen_area_puts(Area* area, char *str);

#endif

