/**
* @brief Crea el conjunto de enlaces entre los espacios
*
* @file link.c
* @author: Gonzalo Martinez
* @version: 1.0
* @date: 14/3/2018
*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "link.h"


struct _Link {
  char name[WORD_SIZE-1];
  Id id; /*Id del link que se crea*/
  Id id1; /*Id del espacio1 a conectar*/
  Id id2; /*Id del espacio2 a conectar*/
};

/*-----------------------------------------------------------------------------------------------*/

Link * link_ini(Id id){
  Link * l;

  l=(Link*)malloc(sizeof(Link));
  if(!l) return NULL;

  l->id1=NO_ID;
  l->id2=NO_ID;
  l->id=id;

  return l;
}

/*-----------------------------------------------------------------------------------------------*/

void link_destroy(Link * l){
  if(!l) return;
  free(l);
}

/*-----------------------------------------------------------------------------------------------*/

Link * link_set_id(Link * l, Id id){
  if(!l) return NULL;
  if(id==NO_ID) return NULL;

  l->id=id;

  return l;
}

/*-----------------------------------------------------------------------------------------------*/

Link * link_set_name(Link * l, char * name){
  if(!l) return NULL;
  if(!name) return NULL;
  if(strlen(name)>(WORD_SIZE-1)) return NULL;

  if(!strcpy(l->name,name)) return NULL;

  return l;
}

/*-----------------------------------------------------------------------------------------------*/

Id link_get_id(Link * l){
  if(!l) return NO_ID;

  return l->id;
}

/*-----------------------------------------------------------------------------------------------*/

char * link_get_name(Link * l){
  if(!l) return NULL;

  return l->name;
}

/*-----------------------------------------------------------------------------------------------*/

Link * link_get_id1(Link * l){
  if(!l) return NULL;

  return l->id1;
}

/*-----------------------------------------------------------------------------------------------*/

Link * link_get_id2(Link * l){
  if(!l) return NULL;

  return l->id2;
}

/*-----------------------------------------------------------------------------------------------*/

int link_print(FILE * fp, Link * l){
  int i=0;
  int suma=0;

  if(!l||!fp) return -1;

  i=fprintf(f,"  Link: Nombre: %s,\n         Id: %li\n",l->name,l->id);
  suma+=i;
  i=0;
  i=fprintf(f,"  Id prev. space: %li\n", l->id1);
  suma+=i;
  i=0;
  i+=fprintf(f,"  Id next space: %li\n", l->id2);
  suma+=i;

  return suma;
}
/*-----------------------------------------------------------------------------------------------*/