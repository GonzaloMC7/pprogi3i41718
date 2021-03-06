/**
* @brief It implements the game interface and all the associated callbacks
* for each command
*
* @file game_management.c
* @author Javier Martin y Miguel Manzano
* @version 1.0
* @date 13-01-2015
* @copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"


#define ILUSTAM 8

/*Funcion que se encarga de cargar los espacios correspondientes dado un fichero determinado*/
STATUS game_management_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  char ilus1[WORD_SIZE] = "";
  char ilus2[WORD_SIZE] = "";
  char ilus3[WORD_SIZE] = "";
  char ilus4[WORD_SIZE] = "";
  char ilus5[WORD_SIZE] = "";
  char ilus6[WORD_SIZE] = "";
  char ilus7[WORD_SIZE] = "";
  char ilus8[WORD_SIZE] = "";
  char ilus9[WORD_SIZE] = "";
  char ilus10[WORD_SIZE] = "";
  char ilus11[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char description2[WORD_SIZE] = "";
  char dialogue1[WORD_SIZE] = "";
  char dialogue2[WORD_SIZE] = "";
  char dialogue3[WORD_SIZE] = "";
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID, light=NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  /*^^^Inicialización de variables^^^*/


  /*Controles de errores de game y file*/
  if(!game){
    return ERROR;
  }
  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r"); /*Se encarga de abrir el fichero*/
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) { /*Bucle encargado de leer el fichero de datos referido a los espacios y los objetos*/
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      toks = strtok(NULL, "|");

      strcpy(ilus1,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus2,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus3,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus4,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus5,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus6,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus7,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus8,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus9,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus10,toks);
      toks = strtok(NULL, "|");
      strcpy(ilus11,toks);
      toks = strtok(NULL, "|");
      strcpy(description,toks);
      toks = strtok(NULL, "|");
      strcpy(description2,toks);
      toks = strtok(NULL, "|");
      strcpy(dialogue1,toks);
      toks = strtok(NULL, "|");
      strcpy(dialogue2,toks);
      toks = strtok(NULL, "|");
      strcpy(dialogue3,toks);
      toks = strtok(NULL, "|");
      light = atol(toks);



      #ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%d\n", id, name, north, east, south, west, up, down, ilus1, ilus2, ilus3,ilus4,ilus5,ilus6,ilus7,ilus8,ilus9,ilus10,ilus11,description,description2,dialogue1,dialogue2,dialogue3,light);
      #endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north_link(space, north);
        space_set_east_link(space, east);
        space_set_south_link(space, south);
        space_set_west_link(space, west);
        space_set_up_link(space, up);
        space_set_down_link(space, down);
        space_set_ilus1(space, ilus1);
        space_set_ilus2(space, ilus2);
        space_set_ilus3(space, ilus3);
        space_set_ilus4(space, ilus4);
        space_set_ilus5(space, ilus5);
        space_set_ilus6(space, ilus6);
        space_set_ilus7(space, ilus7);
        space_set_ilus8(space, ilus8);
        space_set_ilus9(space, ilus9);
        space_set_ilus10(space, ilus10);
        space_set_ilus11(space, ilus11);
        space_set_description(space, description);
        space_set_description2(space, description2);
        space_set_dialogue1(space, dialogue1);
        space_set_dialogue2(space, dialogue2);
        space_set_dialogue3(space, dialogue3);
        space_set_light(space,light);

        game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion encargada de leer los objetos de un fichero determinado*/

STATUS game_management_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char* toks = NULL;
  Id idObject=NO_ID, idspace_object=NO_ID,movable=NO_ID,moved=NO_ID,hidden=NO_ID,light=NO_ID,on=NO_ID,key=NO_ID;
  Object *object=NULL;
  STATUS status = OK;

  /*^^^Inicialización de variables^^^*/


  /*Controles de errores de game y file*/
  if(!game){
    return ERROR;
  }
  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r"); /*Se encarga de abrir el fichero*/
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) { /*Bucle encargado de leer el fichero de datos referido a los objetos*/

    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      idObject = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      idspace_object = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(description,toks);

      toks = strtok(NULL, "|");
      movable = atol(toks);
      toks = strtok(NULL, "|");
      moved = atol(toks);
      toks = strtok(NULL, "|");
      hidden = atol(toks);
      toks = strtok(NULL, "|");
      light = atol(toks);
      toks = strtok(NULL, "|");
      on = atol(toks);
      toks = strtok(NULL, "|");
      key = atol(toks);

      #ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s|%d|%d|%d|%d|%d|%d\n", idObject, name, idspace_object,description,movable,moved,hidden,light,on,key);
      #endif
      object= object_create(idObject);

      if (object != NULL) {
        object_set_name(object, name);
        object_set_description(object, description);
        game_set_object_location(game, idspace_object, idObject);
        object_set_movable(object,movable);
        object_set_moved(object,moved);
        object_set_hidden(object,hidden);
        object_set_light(object,light);
        object_set_on(object,on);
        object_set_key(object,key);
        game_add_object(game, object);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);
  return status;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*Funcion que se encarga de cargar los enlaces correspondientes dado un fichero determinado*/

STATUS game_management_load_links(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id idlink = NO_ID, idprevio = NO_ID, idnext = NO_ID, idopenclose = NO_ID;
  Link *link = NULL;
  STATUS status = OK;


  /*Controles de errores de game y file*/
  if(!game){
    return ERROR;
  }
  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r"); /*Se encarga de abrir el fichero*/
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) { /*Bucle encargado de leer el fichero de datos referido a los enlaces*/

    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      idlink = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      idprevio = atol(toks);
      toks = strtok(NULL, "|");
      idnext = atol(toks);
      toks = strtok(NULL, "|");
      idopenclose = atol(toks);
      #ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld\n", idlink, name, idprevio, idnext, idopenclose);
      #endif
      link= link_ini(idlink);
      if (link != NULL) {
        link_set_name(link, name);
        link_set_id(link, idlink);
        link_set_id1(link, idprevio);
        link_set_id2(link, idnext);
        link_set_idopenclose(link, idopenclose);

        game_add_link(game, link);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);
  return status;
}
