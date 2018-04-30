/**
* @brief Define las primitivas de las funciones que se van a desarrollar en object.c, así como la definición
* de la estructura a utilizar en este módulo object.c
*
* @file object.h
* @author Javier Martin y Gonzalo Martinez
* @version 1.0
* @date 4-02-2018
* @copyright GNU Public License
*/


#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define MAX_OBJ 100

typedef struct _Object Object;

/*Funciones primitivas de object.c*/

/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Crea el objecto determinado
* @author Javier Martin
* @param id que se utiliza para crear el objeto
* @return El nuevo objeto creado
*/
Object* object_create(Id id);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Destruye el objecto determinado
* @author Javier Martin
* @param object determinado a eliminar
* @return OK si se ha destruido correctamente y ERROR si no se ha destruido correctamente
*/
STATUS object_destroy(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Asigna un nombre al objecto determinado
* @author Javier Martin
* @param object determinado
* @param name char con el nombre que se le asigna
* @return OK si se ha asignado correctamente y ERROR si no se ha destruido correctamente
*/
STATUS object_set_name(Object* object, char* name);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene el nombre de un objeto determinado
* @author Javier Martin
* @param object Objeto determinado
* @return char con el nombre del objeto determinado
*/
const char * object_get_name(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene el Id de un objeto determinado
* @author Javier Martin
* @param object Objeto determinado
* @return Id del objeto determinado
*/
Id object_get_id(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Imprime un objeto determinado
* @author Javier Martin
* @param object Objeto determinado
* @return OK si se ha impreso correctamente y ERROR si no se ha impreso correctamente
*/
STATUS object_print(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece una Id a un objeto determinado
* @author Javier Martin
* @param object Objeto determinado
* @param id el Id a establecer
* @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
*/
STATUS object_set_id(Object* object, Id id);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece una descripcion al objeto determinado
* @author Javier Martin
* @param object Objeto determinado
* @param description char con la descripcion a establecer en el objeto
* @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
*/
STATUS object_set_description(Object* object, char* description);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene la descripcion del objeto determinado
* @author Javier Martin
* @param object Objeto determinado
* @return cadena de caracteres con la descripcion del objeto determinado
*/
const char * object_get_description(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece si un objeto se puede mover
* @author Gonzalo Martinez
* @param object Objeto determinado
* @param cond Booleano con la condicion que se le establece al objeto si se puede mover o no
* @return Ok en caso de asignacion correcta o ERROR en caso contrario
*/
STATUS object_set_movable(Object * object, BOOL cond);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece si un objeto se ha movido
* @author Gonzalo Martinez
* @param object Objeto determinado
* @param cond Booleano con la condicion que se le establece al objeto si se ha movido
* @return Ok en caso de asignacion correcta o ERROR en caso contrario
*/
STATUS object_set_moved(Object * object, BOOL cond);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece si un objeto se esconde o no
* @author Gonzalo Martinez
* @param object Objeto determinado
* @param cond Booleano con la condicion que se le establece al objeto si se esconde o no
* @return Ok en caso de asignacion correcta o ERROR en caso contrario
*/
STATUS object_set_hidden(Object * object, BOOL cond);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece si un objeto se puede mover
* @author Gonzalo Martinez
* @param object Objeto determinado
* @param id Id con la condicion que se le establece al objeto con el link que se puede abrir con la "llave"
* @return Ok en caso de asignacion correcta o ERROR en caso contrario
*/
STATUS object_set_key(Object * object, Id id);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece si un objeto se puede mover
* @author Gonzalo Martinez
* @param object Objeto determinado
* @param cond Booleano con la condicion que se le establece al objeto si se puede iluminar o no
* @return Ok en caso de asignacion correcta o ERROR en caso contrario
*/
STATUS object_set_light(Object * object, BOOL cond);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Establece si un objeto se ha iluminado o no
* @author Gonzalo Martinez
* @param object Objeto determinado
* @param cond Booleano con la condicion que se le establece al objeto si se ha iluminado
* @return Ok en caso de asignacion correcta o ERROR en caso contrario
*/
STATUS object_set_on(Object * object, BOOL cond);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene si un objeto se puede mover o no
* @author Gonzalo Martinez
* @param object Objeto determinado
* @return TRUE en caso de que se pueda mover o FALSE en caso contrario
*/
BOOL object_get_movable(Object * object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene si un objeto se ha movido
* @author Gonzalo Martinez
* @param object Objeto determinado
* @return TRUE en caso de que se haya movido o FALSE en caso contrario
*/
BOOL object_get_moved(Object * object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene si un objeto se ha escondido o no
* @author Gonzalo Martinez
* @param object Objeto determinado
* @return TRUE en caso de que se haya escondido o FALSE en caso contrario
*/
BOOL object_get_hidden(Object * object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene el id de un objeto con el cual se quiere abrir un link detemrinado
* @author Gonzalo Martinez
* @param object Objeto determinado
* @return Id del "key" del objeto determiando con el que se abre el link
*/
Id object_get_key(Object * object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene si un objeto se puede iluminar o no
* @author Gonzalo Martinez
* @param object Objeto determinado
* @return TRUE en caso de que se pueda iluminar o FALSE en caso contrario
*/
BOOL object_get_light(Object * object);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Obtiene si un objeto se ha iluminado o no
* @author Gonzalo Martinez
* @param object Objeto determinado
* @return TRUE en caso de que se haya iluminado o FALSE en caso contrario
*/
BOOL object_get_on(Object * object);

#endif
