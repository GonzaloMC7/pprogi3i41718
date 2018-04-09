/**
 * @brief Define las primitivas de las funciones que se van a desarrollar en object.c, así como la definición
 * de la estructura a utilizar en este módulo object.c
 *
 * @file object.h
 * @author Javier Martin
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
 * @param Id que se utiliza para crear el objeto
 * @return El nuevo objeto creado
 */
Object* object_create(Id id);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Destruye el objecto determinado
 * @author Javier Martin
 * @param Objeto determinado a eliminar
 * @return OK si se ha destruido correctamente y ERROR si no se ha destruido correctamente
 */
STATUS object_destroy(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna un nombre al objecto determinado
 * @author Javier Martin
 * @param Objeto determinado y char con el nombre que se le asigna
 * @return OK si se ha asignado correctamente y ERROR si no se ha destruido correctamente
 */
STATUS object_set_name(Object* object, char* name);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el nombre de un objeto determinado
 * @author Javier Martin
 * @param Objeto determinado
 * @return char con el nombre del objeto determinado
 */
const char * object_get_name(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de un objeto determinado
 * @author Javier Martin
 * @param Objeto determinado
 * @return Id del objeto determinado
 */
Id object_get_id(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime un objeto determinado
 * @author Javier Martin
 * @param Objeto determinado
 * @return OK si se ha impreso correctamente y ERROR si no se ha impreso correctamente
 */
STATUS object_print(Object* object);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Establece una Id a un objeto determinado
 * @author Javier Martin
 * @param Objeto determinado y el Id a establecer
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */
STATUS object_set_id(Object* object, Id id);
STATUS object_set_description(Object* object, char* description);
const char * object_get_description(Object* object);
#endif
