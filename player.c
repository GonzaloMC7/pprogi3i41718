/**
 * @brief Implementa las funciones para crear un nuevo jugador y las funciones para asignar y obtener la información
 * de sus diferentes campos, aparte de una función que imprimira la información de estos campos.
 *
 * @file player.c
 * @author Gonzalo Martinez
 * @version 1.0
 * @date 5-01-2018
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

#define inv_tam 5


/*Estructura de un jugador, con su nombre, el id, el id del objeto que puede portar, y su localización*/
struct _Player {
  char name[NAME_SIZE]; /*Nombre del jugador*/
  Id id; /*Id deul jugador*/
  Inventory* object; /*Id del objeto que porta el jugador*/
  Id location; /*Id de la localización del jugador*/
};

/*-----------------------------------------------------------------------------------------------------------------------*/

Player * player_create (Id id){
  Player *newpl;

  if(id==NO_ID) return NULL;
  /*^^^Control de errores id^^^*/

  /*Reserva de memoria para player*/
  newpl=(Player*)malloc(sizeof(Player));
  if(!newpl) return NULL;

  /*Asignaciones campos player*/
  newpl->id=id; /*El id que se recibe se le asigna al nuevo jugador*/
  newpl->location=NO_ID;
  newpl->object=inventory_ini(inv_tam);
  newpl->name[0]='\0';

  return newpl;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS player_destroy (Player * pl){
  if(!pl) return ERROR;
  /*^^^Control de errores player^^^*/

  /*Liberación player*/
  inventory_destroy(pl->object);
  free(pl);
  pl=NULL;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS player_set_name (Player * pl, char * name){
  if(!pl) return ERROR;
  /*^^^Control de errores player^^^*/
  if(!name) return ERROR;
  /*^^^Control de errores name^^^*/

  /*Asignación del nombre recibido en el nombre de player*/
  if (!strcpy(pl->name,name)) return ERROR;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS player_set_id (Player * pl, Id id){
  if(!pl) return ERROR;
  /*^^^Control de errores player^^^*/
  if(id==NO_ID) return ERROR;
  /*^^^Control de errores id^^^*/

  /*Asignación del id recibido en el id de player*/
  pl->id=id;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS player_set_location (Player * pl, Id location){
  if(!pl) return ERROR;
  /*^^^Control de errores player^^^*/

  /*Asignación de la localización recibida en la localización de player*/
  pl->location=location;
  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/


STATUS player_set_object (Player * pl, Id id){
  if(!pl) return ERROR;
  /*^^^Control de errores player^^^*/

  if(inventory_push_id(pl->object, id)==ERROR)
    return ERROR;


  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
STATUS player_destroy_object(Player *pl, Id IdObject){
    if(pl == NULL){
        return ERROR;
    }

    return inventory_pop_id(pl->object, IdObject);
}
/*-----------------------------------------------------------------------------------------------------------------------*/


char * player_get_name (Player * pl){
  if(!pl) return NULL;
  /*^^^Control de errores player^^^*/
  return pl->name;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

Id player_get_id (Player * pl){
  if(!pl) return NO_ID;
  /*^^^Control de errores player^^^*/
  return pl->id;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
BOOL player_find_object(Player *player, Id IdObject){
    if(player==NULL){
        return FALSE;
    }
    return inventory_find_id(player->object, IdObject);
}
/*-----------------------------------------------------------------------------------------------------------------------*/
Id player_get_location (Player * pl){
  if(!pl) return NO_ID;
  /*^^^Control de errores player^^^*/
  return pl->location;
}
/*-----------------------------------------------------------------------------------------------------------------------*/

Id player_get_object (Player * pl, Id id){
  if(!pl) return NO_ID;
  /*^^^Control de errores player^^^*/

  return inventory_get_id(pl->object, id);
}

/*-----------------------------------------------------------------------------------------------------------------------*/

STATUS player_print(Player * pl){
	if (!pl) return ERROR;
  /*^^^Control de errores player^^^*/

  /*Se imprimen los campos del jugador y se devuelve OK si se ha ejecutado correctamente*/
  fprintf(stdout, "--> Player (Id: %ld; Name: %s\n", pl->id, pl->name);

	return OK;
}
