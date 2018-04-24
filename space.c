/**
* @brief It implements the functions to the space.c module, which creates the game space
*
* @file types.h
* @author Profesores PPROG
* @version 1.0
* @date 13-01-2015
* @copyright GNU Public License
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

#define ILUSTAM 20

/*COMENTADO*/
/*Estructura que determina los elementos de un espacio, entre ellos se encuentra los id's del espacio,
su id norte, sur, este y oeste, ademas del nombre del espacio y el conjunto de objetos pertenecientes a los espacios*/
struct _Space {
	Id id;
	char name[WORD_SIZE + 1];
	Id north;
	Id south;
	Id east;
	Id west;
	Id up;
	Id down;
	Set* objects;
	char ilus1[WORD_SIZE];
	char ilus2[WORD_SIZE];
	char ilus3[WORD_SIZE];
	char description[WORD_SIZE];
	BOOL light;
};

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de creación del espacio de juego con sus diferentes posiciones*/

Space* space_create(Id id) {

	Space *newSpace = NULL;

	/*Control de errores del id recibido*/
	if (id == NO_ID)
		return NULL;

	/*Creación del espacio y su correspondiente control de errores*/
	newSpace = (Space *) malloc(sizeof (Space));

	if (newSpace == NULL) {
		return NULL;
	}

	/*Asignaciones de los valores de newSpace*/

	newSpace->id = id;

	newSpace->name[0] = '\0';

	newSpace->north = NO_ID;
	newSpace->south = NO_ID;
	newSpace->east = NO_ID;
	newSpace->west = NO_ID;
	newSpace->up = NO_ID;
	newSpace->down = NO_ID;

	newSpace->objects = set_create();

	newSpace->light = TRUE; /*Al inicializarlo lo ponemos a espacio iluminado*/	

	return newSpace;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de destrucción del espacio de juego y sus diferentes posiciones*/

STATUS space_destroy(Space* space) {
	if (!space) {
		return ERROR;
	}

	/*^^^Control de errores space^^^*/
	set_destroy(space->objects);
	free(space);

	/*Se libera el espacio y se devuelve OK si no ha habido ningún error en la función entera*/

	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de nombres para cada uno de los espacios*/

STATUS space_set_name(Space* space, char* name) {
	if (!space || !name) {
		return ERROR;
	}

	/*^^^Control de errores space y name^^^*/

	if (!strcpy(space->name, name)) {
		return ERROR;
	}
	/*Se hace la asignación y después se devuelve OK si no ha habido ningún problema*/

	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la posición norte*/

STATUS space_set_north_link(Space* space, Id idlink) {
	if (!space || idlink == NO_ID) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	space->north = idlink;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la posición sur*/

STATUS space_set_south_link(Space* space, Id idlink) {
	if (!space || idlink == NO_ID) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	space->south = idlink;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la posición este*/

STATUS space_set_east_link(Space* space, Id idlink) {
	if (!space || idlink == NO_ID) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	space->east = idlink;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la posición oeste*/

STATUS space_set_west_link(Space* space, Id idlink) {
	if (!space || idlink == NO_ID) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	space->west = idlink;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la posición up*/

STATUS space_set_up_link(Space* space, Id idlink) {
	if (!space || idlink == NO_ID) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	space->up = idlink;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la posición down*/

STATUS space_set_down_link(Space* space, Id idlink) {
	if (!space || idlink == NO_ID) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	space->down = idlink;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la parte sueprior de la ilus3acion*/

STATUS space_set_ilus1(Space* space, char* ilus1) {
	if (!space || !ilus1) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	strcpy(space->ilus1, ilus1);
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la parte media de la ilus3acion*/

STATUS space_set_ilus2(Space* space, char* ilus2) {
	if (!space || !ilus2) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	strcpy(space->ilus2, ilus2);
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación de la parte inferior de la ilus3acion*/

STATUS space_set_ilus3(Space* space, char* ilus3) {
	if (!space || !ilus3) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	strcpy(space->ilus3, ilus3);
	return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que establece una descripcion al espacio deseado*/
STATUS space_set_description(Space* space, char* description) {
  if (!space || !description) {
    return ERROR;
  }

  if (!strcpy(space->description, description)) {
    return ERROR;
  }

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de asignación del objeto en una posición*/

STATUS space_set_object(Space* space, Id value) {
	if (!space) {
		return ERROR;
	}
	/*^^^Control de errores arriba y asignación debajo^^^*/
	set_add_id(space->objects,value);
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención del nombre de un espacio*/

const char * space_get_name(Space* space) {
	if (!space) {
		return NULL;
	}
	/*^^^Control de errores arriba y se devuelve el nombre del espacio (debajo)^^^*/
	return space->name;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención del id de un espacio*/

Id space_get_id(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el id del espacio (debajo)^^^*/
	return space->id;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la posición norte de un espacio*/

Id space_get_north_link(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el espacio norte (debajo)^^^*/
	return space->north;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la posición sur de un espacio*/

Id space_get_south_link(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el espacio sur (debajo)^^^*/
	return space->south;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la posición este de un espacio*/

Id space_get_east_link(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el espacio este (debajo)^^^*/
	return space->east;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la posición oeste de un espacio*/

Id space_get_west_link(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el espacio oeste (debajo)^^^*/
	return space->west;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la posición up de un espacio*/

Id space_get_up_link(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el espacio up (debajo)^^^*/
	return space->up;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la posición oeste de un espacio*/

Id space_get_down_link(Space* space) {
	if (!space) {
		return NO_ID;
	}
	/*^^^Control de errores arriba y se devuelve el espacio down (debajo)^^^*/
	return space->down;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la ilus3acion superior*/

const char * space_get_ilus1(Space* space) {
	if (!space) {
		return NULL;
	}
	/*^^^Control de errores arriba y se devuelve la ilus3acion (debajo)^^^*/
	return space->ilus1;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la ilus3acion del medio*/

const char * space_get_ilus2(Space* space) {
	if (!space) {
		return NULL;
	}
	/*^^^Control de errores arriba y se devuelve la ilus3acion (debajo)^^^*/
	return space->ilus2;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención de la ilus3acion inferior*/

const char * space_get_ilus3(Space* space) {
	if (!space) {
		return NULL;
	}
	/*^^^Control de errores arriba y se devuelve la ilus3acion(debajo)^^^*/
	return space->ilus3;
}

/*-----------------------------------------------------------------------------------------------------*/
/*Funcion que devuelve la descripcion de un espacio, el cual se recibe por argumento.*/
const char * space_get_description(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->description;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función de obtención del objeto en un espacio*/

int space_get_object(Space* space){
	if (!space) {
		return -1;
	}
	if(set_get_top(space->objects)!=NO_ID){
		return set_get_top(space->objects);
	}
	else
		return -1;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que sirve para obtener el id de un objeto */

Id space_get_object_id(Space* space, int i){

	if(space==NULL){
		return NO_ID;
	}

	return set_get_id(space->objects, i);

}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de eliminar un objeto de un espacio*/

STATUS space_destroy_object(Space* space, Id IdObject) {

	if (!space||IdObject==NO_ID) {
		return ERROR;
	}

	set_destroy_id(space->objects, IdObject);
	return OK;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de comprobar si esta un objeto determinado en el conjunto determinado */

BOOL space_find_id(Space *space, Id IdObject){

	if(space==NULL){
		return FALSE;
	}

	/*comprueba que se encuentre el  Id del objeto entre los ids de los conjuntos de objetos*/
	/*si devuelve >-1 significa que ese id del objeto se encuentra*/

	if(set_find_id(space->objects, IdObject) > -1){
		return TRUE;
	}
	else
		return FALSE;

}

/*-----------------------------------------------------------------------------------------------------------------------*/
STATUS space_set_lightON(Space * space){
	if(!space) return ERROR;

	space->light=TRUE;
	return OK;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
STATUS space_set_lightOFF(Space * space){
	if(!space) return ERROR;

	space->light=FALSE;
	return OK;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
BOOL space_get_light(Space * space){
	if(!space) return FALSE;

	if(space->light==TRUE){
		return TRUE;
	}else return FALSE;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Función que imprime el estado de un espacio*/

STATUS space_print(Space* space) {
	Id idaux = NO_ID;

	if (!space) {
		return ERROR;
	}
	/*^^^Control de errores space^^^*/

	fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

	/*Se busca un link en el norte y si existe se muestra por pantalla*/

	idaux = space_get_north_link(space);
	if (NO_ID != idaux) {
		fprintf(stdout, "---> North link: %ld.\n", idaux);
	} else {
		fprintf(stdout, "---> No north link.\n");
	}

	/*Se busca un link en el sur y si existe se muestra por pantalla*/

	idaux = space_get_south_link(space);
	if (NO_ID != idaux) {
		fprintf(stdout, "---> South link: %ld.\n", idaux);
	} else {
		fprintf(stdout, "---> No south link.\n");
	}

	/*Se busca un link en el este y si existe se muestra por pantalla*/

	idaux = space_get_east_link(space);
	if (NO_ID != idaux) {
		fprintf(stdout, "---> East link: %ld.\n", idaux);
	} else {
		fprintf(stdout, "---> No east link.\n");
	}

	/*Se busca un link en el oeste y si existe se muestra por pantalla*/

	idaux = space_get_west_link(space);
	if (NO_ID != idaux) {
		fprintf(stdout, "---> West link: %ld.\n", idaux);
	} else {
		fprintf(stdout, "---> No west link.\n");
	}

	/*Se busca un link en up y si existe se muestra por pantalla*/

	idaux = space_get_up_link(space);
	if (NO_ID != idaux) {
		fprintf(stdout, "---> Up link: %ld.\n", idaux);
	} else {
		fprintf(stdout, "---> No up link.\n");
	}

	/*Se busca un link en down y si existe se muestra por pantalla*/

	idaux = space_get_down_link(space);
	if (NO_ID != idaux) {
		fprintf(stdout, "---> Down link: %ld.\n", idaux);
	} else {
		fprintf(stdout, "---> No down link.\n");
	}

	/*Se busca un objeto en la posición actual y si existe se muestra por pantalla*/

	if (space_get_object(space)) {
		fprintf(stdout, "---> Object in the space.\n");
	} else {
		fprintf(stdout, "---> No object in the space.\n");
	}

	if(space_get_light(space)==TRUE){
		fprintf(stdout, "---> Illuminated space\n");
	}else {
		fprintf(stdout, "---> Dark space\n");
	}


	return OK;
}
