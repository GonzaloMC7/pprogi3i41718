/** 
 * @brief It implements the command interpreter
 * 
 * @file command.h
 * @author Profesores PPROG, Javier Martin, Gonzalo Martinez
 * @version 1.0 
 * @date 19-12-2014 
 * @copyright GNU Public License
 */

/*COMENTADO2*/

#ifndef COMMAND_H
#define COMMAND_H
#include "types.h"

typedef struct _Command Command;

/*Estructura enumerada de los comandos que se pueden dar*/
/*Editada por Gonzalo Martinez y Javier Martin*/
/*Siguen una enumeracion de los comando que se pueden reconocer, empezando por -1 en el caso que no haya ningun comando, hasta el ultimo comando enumerado, que en este caso sera RIGHT*/
typedef enum enum_Command {
  NO_CMD = -1, 
  UNKNOWN, /*No reconocido*/ 
  EXIT, /*Salir del juego*/
  FOLLOWING, /*Siguiente posición*/
  PREVIOUS, /*Anterior posición*/
  TAKE, /*Coger un objeto*/
  DROP, /*Dejar un objeto*/
  MOVE, /*Rodar el dado*/
  LEFT, /*Posición siguiente de oca*/
  RIGHT /*Posición anterior de oca*/
} T_Command;

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga obtener el comando que ha introducido el usuario
 * @author Profesores PPROG
 * @param 
 * @return Devuelve el comando que se ha introducido, es decir, algun comando de la EdD enumerada
 */
T_Command get_user_input(); 

#endif
