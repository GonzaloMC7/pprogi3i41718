/**
* @brief  Implementa las funciones para crear un nuevo objeto y las funciones para asignar
* y obtener sus diferentes campos, asi como una función para imprimir la info de estos campos.
*
* @file object.c
* @author Gonzalo Martinez
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
  BOOL movable; /*Si el objeto se puede mover o no*/
  BOOL moved; /*Si el objeto ha sido movido o no*/
  BOOL hidden; /*Si el objeto está oculto o no*/
  Id key; /*Si el objeto puede abrir links o no*/
  BOOL light; /*Si el objeto puede iluminar*/
  BOOL on; /*Si el objeto, pudiendo iluminar, esta en On o en Off*/
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
  newObject->movable=FALSE;
  newObject->moved=FALSE;
  newObject->hidden=FALSE;
  newObject->key=NO_ID;
  newObject->light=FALSE;
  newObject->on=FALSE;
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
  if (!object) {
    return ERROR;
  }

  if (id==NO_ID){
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

/*-----------------------------------------------------------------------------------------------------*/

STATUS object_set_movable(Object * object, BOOL cond){
  if(object == NULL){
      return ERROR;
  }
  object->movable=cond;
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

STATUS object_set_moved(Object * object, BOOL cond){
  if(!object) return ERROR;
  if(object_get_movable(object)==FALSE) return ERROR;

  if(cond==TRUE){
    object->moved=TRUE;
  }else if(cond==FALSE){
    object->moved=FALSE;
  }
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

STATUS object_set_hidden(Object * object, BOOL cond){
  if(!object) return ERROR;

  if(cond==TRUE){
    object->hidden=TRUE; /*Esto lo pone a oculto*/
  }else if(cond==FALSE){
    object->hidden=FALSE;
  }
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

STATUS object_set_key(Object * object, Id id){
  if(!object) return ERROR;
  if(id==NO_ID) return ERROR;

  object->key=id;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

STATUS object_set_light(Object * object, BOOL cond){
  if(!object) return ERROR;

  object->light=cond;
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

STATUS object_set_on(Object * object, BOOL cond){
  if(!object) return ERROR;
  if(object_get_light(object)==FALSE) return ERROR;

  if(cond==TRUE){
    object->on=TRUE;
  }else if(cond==FALSE){
    object->on=FALSE;
  }
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------*/

BOOL object_get_movable(Object * object){
  if(object==NULL) return FALSE;
  return object->movable;
}

/*-----------------------------------------------------------------------------------------------------*/

BOOL object_get_moved(Object * object){
  if(!object) return FALSE;

  if(object->moved==TRUE){
    return TRUE;
  }else return FALSE;

}

/*-----------------------------------------------------------------------------------------------------*/

BOOL object_get_hidden(Object * object){
  if(!object) return FALSE;

  if(object->hidden==TRUE){
    return TRUE;
  }else return FALSE;

}

/*-----------------------------------------------------------------------------------------------------*/

Id object_get_key(Object * object){
  if(!object) return NO_ID;
  return object->key;
}

/*-----------------------------------------------------------------------------------------------------*/

BOOL object_get_light(Object * object){
  if(!object) return FALSE;

  if(object->light==TRUE){
    return TRUE;
  }else return FALSE;

}

/*-----------------------------------------------------------------------------------------------------*/

BOOL object_get_on(Object * object){
  if(!object) return FALSE;

  if(object->on==TRUE){
    return TRUE;
  }else return FALSE;

}
