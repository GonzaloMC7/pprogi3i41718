/**
* @brief Fichero de prueba para object
*
* Se encarga de comprobar el funcionamiento de object
* @file game_management_test.c
* @author: Javier Martin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "player_test.h"

#include "test.h"
#include "types.h"

#define MAX_TESTS 22

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module object_test:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }
  if (all || test == 1) test1_player_create();
  if (all || test == 2) test2_player_create();
  if (all || test == 3) test1_player_destroy();
  if (all || test == 4) test2_player_destroy();
  if (all || test == 5) test1_player_setid();
  if (all || test == 6) test2_player_setid();
  if (all || test == 7) test3_player_setid();
  if (all || test == 8) test1_player_setlocation();
  if (all || test == 9) test2_player_setlocation();
  if (all || test == 10) test1_player_setobject();
  if (all || test == 11) test2_player_setobject();
  if (all || test == 12) test1_player_destroyobject();
  if (all || test == 13) test2_player_destroyobject();
  if (all || test == 14) test1_player_getname();
  if (all || test == 15) test2_player_getname();
  if (all || test == 16) test1_player_getid();
  if (all || test == 17) test2_player_getid();
  if (all || test == 18) test1_player_findobject();
  if (all || test == 19) test2_player_findobject();
  if (all || test == 20) test1_player_getlocation();
  if (all || test == 21) test2_player_getlocation();
  if (all || test == 22) test1_player_getobject();
  if (all || test == 23) test2_player_getobject();


  PRINT_PASSED_PERCENTAGE;

  return 1;
}

/*-----------------------------------------------------------------*/
void test1_player_create(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(pl!=NULL);
  player_destroy(pl);
}
void test2_player_create(){
  Player *pl=NULL;
  pl=player_create(NO_ID);
  PRINT_TEST_RESULT(pl==NULL);
}
/*-----------------------------------------------------------------*/
void test1_player_destroy(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_destroy(pl)==OK);
}
void test2_player_destroy(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_destroy(pl)==ERROR);
}

/*-----------------------------------------------------------------*/

void test1_player_setid(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_set_id(pl,3)==OK);
  player_destroy(pl);
}
void test2_player_setid(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_set_id(pl,3)==ERROR);
}
void test3_player_setid(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_set_id(pl,NO_ID)==ERROR);
}
/*-----------------------------------------------------------------*/

void test1_player_setlocation(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_set_location(pl,3)==OK);
  player_destroy(pl);
}
void test2_player_setlocation(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_set_location(pl,3)==ERROR);
}

/*-----------------------------------------------------------------*/
void test1_player_setobject(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_set_object(pl,3)==OK);
  player_destroy(pl);
}
void test2_player_setobject(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_set_location(pl,3)==ERROR);
}

/*-----------------------------------------------------------------*/
void test1_player_destroyobject(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_destroy_object(pl,3)!=OK);
  player_destroy(pl);
}
void test2_player_destroyobject(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_destroy_object(pl,3)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_player_getname(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_get_name(pl)!=NULL);
  player_destroy(pl);
}
void test2_player_getname(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_get_name(pl)==NULL);
}
/*-----------------------------------------------------------------*/
void test1_player_getid(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_get_id(pl)!=NO_ID);
  player_destroy(pl);
}
void test2_player_getid(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_get_id(pl)==NO_ID);
}
/*-----------------------------------------------------------------*/
void test1_player_findobject(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_find_object(pl,1)!=TRUE);
  player_destroy(pl);
}
void test2_player_findobject(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_find_object(pl,1)==FALSE);
}
/*-----------------------------------------------------------------*/
void test1_player_getlocation(){
  Player *pl=NULL;
  pl=player_create(1);
  player_set_location(pl,1);
  PRINT_TEST_RESULT(player_get_location(pl)!=NO_ID);
  player_destroy(pl);
}
void test2_player_getlocation(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_get_location(pl)==NO_ID);
}
/*-----------------------------------------------------------------*/
void test1_player_getobject(){
  Player *pl=NULL;
  pl=player_create(1);
  PRINT_TEST_RESULT(player_get_object(pl,1)!=NO_ID);
  player_destroy(pl);
}
void test2_player_getobject(){
  Player *pl=NULL;
  PRINT_TEST_RESULT(player_get_object(pl,1)==NO_ID);
}
