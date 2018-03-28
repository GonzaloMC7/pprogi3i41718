  /**
   * @brief It implements the game interface and all the associated callbacks
   * for each command
   *
   * @file game_reader.c
   * @author Javier Martin
   * @version 1.0
   * @date 13-01-2015
   * @copyright GNU Public License
   */
  
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "game_reader.h"

  
#define ILUSTAM 8

  /*Funcion que se encarga de cargar los espacios correspondientes dado un fichero determinado*/
  STATUS game_reader_load_spaces(Game* game, char* filename) {
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char* toks = NULL;
    char ilus1[WORD_SIZE] = "";
    char ilus2[WORD_SIZE] = "";
    char ilus3[WORD_SIZE] = "";
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
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
		strcpy(ilus1,toks);
        toks = strtok(NULL, "|");
		strcpy(ilus2,toks);
        toks = strtok(NULL, "|");
		strcpy(ilus3,toks);


  #ifdef DEBUG
        printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s\n", id, name, north, east, south, west, ilus1, ilus2, ilus3);
  #endif
        space = space_create(id);
        if (space != NULL) {
  		  space_set_name(space, name);
  		  space_set_north(space, north);
  		  space_set_east(space, east);
  		  space_set_south(space, south);
  		  space_set_west(space, west);
		  space_set_ilus1(space, ilus1);
	  	  space_set_ilus2(space, ilus2);
	  	  space_set_ilus3(space, ilus3);
			 
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

  STATUS game_reader_load_objects(Game* game, char* filename) {
      FILE* file = NULL;
      char line[WORD_SIZE] = "";
      char name[WORD_SIZE] = "";
      char* toks = NULL;
      Id idObject=NO_ID, idspace_object=NO_ID;
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
    #ifdef DEBUG
    	  printf("Leido: %ld|%s|%ld\n", idObject, name, idspace_object);
    #endif
  	  object= object_create(idObject);
    	  if (object != NULL) {
    		  object_set_name(object,name);
    		  game_set_object_location(game, idspace_object, idObject);
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
  