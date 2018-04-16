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
  UNKNOWN, /*!<No reconocido*/
  EXIT, /*!<Salir del juego*/
  TAKE, /*!<Coger un objeto*/
  DROP, /*!<Dejar un objeto*/
  MOVE, /*!<Rodar el dado*/
  GO,
  CHECK
  } T_Command;

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga obtener el comando que ha introducido el usuario
 *
 * command_get_user_input(Command* cmd);
 * @author Javier Martin
 * @param cmd comando creado anteriormente en donde se gurada la informacion
 * @return tipo void
 */
void command_get_user_input(Command* cmd);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de interpretar el comando que ha introducido el usuario
 *
 *  command_interpret_input(Command* cmd, char* input);
 * @author Javier Martin
 * @param cmd comando que se ha creado
 * @param input cadena de caracteres input que ha leido anteriormente
 * @return Devuelve Ok en caso de que el comando sea bien interpretado o ERROR en caso contrario
 */
STATUS command_interpret_input(Command* cmd, char* input);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de iniciar el comando
 *
 *  command_ini();
 * @author Javier Martin
 * @param
 * @return Devuelve el comando inicializdo
 */
Command *command_ini();
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga eliminar la informacion de un comando introducido
 *
 * command_destroy(Command* cmd);
 * @author Javier Martin
 * @param cmd comando que se quiere eliminar
 * @return tipo void
 */
void command_destroy(Command* cmd);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga obtener el "objeto" que se ha introducido con el comando dado
 *
 * command_get_ob(Command* cmd);
 * @author Javier Martin
 * @param cmd comando del que se quiere obtener la informacion
 * @return cadena de caracteres del "objeto" del comando introducido
 */
char* command_get_ob(Command* cmd);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga obtener el "comando" que se ha introducido con el comando dado
 *
 * command_get_vrb(Command* cmd);
 * @author Javier Martin
 * @param cmd comando del que se quiere obtener la informacion
 * @return cadena de caracteres del "comando"
 */
char* command_get_vrb(Command* cmd);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga obtener el typo de comando enumerado que ha introducido el usuario
 *
 * command_get_type(Command* cmd);
 * @author Javier Martin
 * @param cmd comando del que se quiere obtener la informacoin
 * @return Devueve el tipo enumerado del comando que se ha introducido por argumento
 */
T_Command command_get_type(Command* cmd);

#endif
