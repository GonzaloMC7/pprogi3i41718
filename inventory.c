/**
* @brief Crea un inventario para almacenar objetos(ids)
*
* @file inventory.c
* @author: Gonzalo Martinez
* @version: 1.0
* @date: 14/3/2018
*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventory.h"

struct _Inventory{
  Set * ids;
  int max_ids;
};

/*-----------------------------------------------------------------------------------------------*/

Inventory * inventory_ini(int max){
  Inventory * inv = NULL;

  inv = (Inventory*)malloc(sizeof(Inventory));
  if(!inv) return NULL;

  inv->ids = set_create();
  inv->max_ids = max;

  return inv;
}

/*-----------------------------------------------------------------------------------------------*/

STATUS inventory_destroy(Inventory * inv){
  if(!inv){
    return ERROR;
  }
  free(inv);

  return OK;
}

/*-----------------------------------------------------------------------------------------------*/

BOOL inventory_isFull(Inventory * inv){
  if(!inv) return FALSE;

  if(set_get_top(inv->ids)>=inv->max_ids){
    return TRUE;
  }
  return FALSE;
}

/*-----------------------------------------------------------------------------------------------*/

STATUS inventory_push_id(Inventory * inv, Id id){
  if(!inv) return ERROR;
	if (inventory_isFull(inv)==TRUE) return ERROR;

	set_add_id(inv->ids,id);
  set_print(inv->ids);
	return OK;
}

/*-----------------------------------------------------------------------------------------------*/

STATUS inventory_pop_id(Inventory * inv, Id id){
  if(!inv) return ERROR;
  if(set_find_id(inv->ids,id)==-1){
    return ERROR;
  }
  set_destroy_id(inv->ids,id);
  return OK;
}
/*-----------------------------------------------------------------------------------------------*/

STATUS inventory_del_object(Inventory* inventory, Id IdObject) {

    if (!inventory) {
        return ERROR;
    }
    return set_destroy_id(inventory->ids, IdObject);
}
/*-----------------------------------------------------------------------------------------------*/

Id inventory_get_id(Inventory * inv, Id id){
  Id auxid;

  if(!inv) return ERROR;
  if(set_find_id(inv->ids,id)==-1){
    return ERROR;
  }
  auxid = set_get_id(inv->ids, set_find_id(inv->ids, id));
  /*set_destroy_id(inv->ids,id);*/
  return auxid;
}

/*-----------------------------------------------------------------------------------------------*/
BOOL inventory_comprueba_objeto(Inventory* inventory, Id IdObject){

    if(inventory==NULL){
        return FALSE;
    }

    if(set_find_id(inventory->ids, IdObject) > -1){
        return TRUE;
    }
    else
        return FALSE;

}
/*-----------------------------------------------------------------------------------------------*/
STATUS inventory_print(FILE * fp, Inventory * inv){
  int i=0;

  if(!fp) return ERROR;
  if(!inv) return ERROR;

  fprintf(fp,"Inventory-->Number of Ids: %d\n",set_get_top(inv->ids));

	for(i=0; i<set_get_top(inv->ids);i++){
		fprintf(fp,"--> %d: %d\n",i,set_find_id(inv->ids,set_get_id(inv->ids,i)));
	}
	return OK;
}
/*-----------------------------------------------------------------------------------------------*/
