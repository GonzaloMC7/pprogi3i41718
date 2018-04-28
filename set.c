/**
* @brief Interfaz de set
*
* Se encarga de implementar el conjunto (set)
* @file set.c
* @author: Javier Martin
* @version: 2.0
* @date: 5-3-2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"


/*Estructura de datos que recoge un array de ids y el numero del id en el array*/
struct _Set {
	Id id[MAX_IDS]; /*!<Array con los ids del juego*/
	int top; /*!<int que indica el número de ids guardados*/
};

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de crear el set y asignarle valores*/

Set * set_create() {

	int i;
	Set* set= NULL;

	set = (Set *) malloc (sizeof(Set));
	if(!set){
		return NULL;
	}

	set->top = 0;
	for(i=0; i< MAX_IDS; i++){
		set->id[i] = 0;
	}
	return set;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de destruir el conjunto definido*/

STATUS set_destroy(Set * set){

	if(!set){
		return ERROR;
	}

	free(set);
	return OK;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de añadir un ID al conjunto que estamos definiendo(array de ID's)*/

Set* set_add_id(Set * set, Id id) {

	if (!set) {
		return NULL;
	}

	if (id ==  NO_ID) {
		return NULL;
	}
  set->id[set->top] = id;
	set->top++;
	return set;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de eliminar un Id determinado del array de ID's*/

STATUS set_destroy_id(Set * set, Id id) {
	int i;
	if (!set||id==NO_ID) {
		return ERROR;
	}

	if(set_find_id(set, id) == -1){
		return ERROR;
	}
	else{
		for(i=set_find_id(set, id); i<set->top; i++){
			set->id[i]=set->id[i+1];
		}
		set->id[set->top]=0;
		set->top--;
	}

	return OK;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de devolver el ID de un array de una posicion determinada*/

Id set_get_id(Set *set, int i){
	if(!set){
		return NO_ID;
	}
	return set->id[i];
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de devolver la posicion del array en la que se encuentra el ID*/

int set_find_id(Set *set, Id id){

	int i;
	if(!set||id==NO_ID){
		return -1;
	}

	for(i=0; i<MAX_IDS; i++){
		if(set_get_id(set, i)==id){
			return i;
		}

	}
	return -1;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de obtener el numero de ids que se encuentran en el set*/

int set_get_top(Set *set){
	if(!set){
		return -1;
	}
	return set->top;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de imprimir los id's de un set determinado*/

STATUS set_print(Set * set) {
	int i;
	if(set == NULL){
		return ERROR;
	}


	for(i=set->top; i>=0; i--){
		printf("[%ld]",set->id[i]);
	}

	return OK;
}
