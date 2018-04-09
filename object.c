/**
 * @brief  Implementa las funciones para crear un nuevo objeto y las funciones para asignar
 * y obtener sus diferentes campos, asi como una función para imprimir la info de estos campos.
 *
 * @file object.c
 * @author Javier Martin
 * @version 1.0
 * @date 4-02-2018
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"



/*Estructura de un objeto, con un id y un nombre*/
struct _Object {
  Id id; /*Id del objeto*/
  char name[WORD_SIZE + 1]; /*Nombre del objeto*/
  char description[WORD_SIZE];
};

/*-----------------------------------------------------------------------------------------------------*/
/*Esta funcion permite la creacion del objeto*/
Object* object_create(Id id) {

  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->description[0]= '\0';
  return newObject;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que permite la eliminacion del objeto y la liberacion de la memoria de los recursos utilizados*/
STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }
  free(object);
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que permite dar un nombre al objeto deseado*/
STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que devuelve el nombre de un objeto, el cual se recibe por argumento.*/
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que devuelve el id de un objeto dado*/
Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}
/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que establece una descripcion al objeto deseado*/
STATUS object_set_description(Object* object, char* description) {
  if (!object || !description) {
    return ERROR;
  }

  if (!strcpy(object->description, description)) {
    return ERROR;
  }

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que devuelve la descripcion de un objeto, el cual se recibe por argumento.*/
const char * object_get_description(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->description;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que establece un id al objeto deseado*/
STATUS object_set_id(Object* object, Id id) {
  if (!object || !id) {
    return ERROR;
  }
  object->id=id;
  return OK;
}


/*-----------------------------------------------------------------------------------------------------*/
/*Funcion encargada de imprimir el objeto por pantalla*/
STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
  return OK;
}
