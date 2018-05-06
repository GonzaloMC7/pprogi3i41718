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
#include "object.h"
#include "object_test.h"

#include "test.h"
#include "types.h"

#define MAX_TESTS 45

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
  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  if (all || test == 3) test1_object_destroy();
  if (all || test == 4) test2_object_destroy();
  if (all || test == 5) test3_object_destroy();
  if (all || test == 6) test1_object_setname();
  if (all || test == 7) test2_object_setname();
  if (all || test == 8) test3_object_setname();
  if (all || test == 9) test1_object_getname();
  if (all || test == 10) test2_object_getname();
  if (all || test == 11) test1_object_getid();
  if (all || test == 12) test2_object_getid();
  if (all || test == 13) test1_object_setdescription();
  if (all || test == 14) test2_object_setdescription();
  if (all || test == 15) test3_object_setdescription();
  if (all || test == 16) test1_object_getdescription();
  if (all || test == 17) test2_object_getdescription();
  if (all || test == 18) test1_object_setid();
  if (all || test == 19) test2_object_setid();
  if (all || test == 20) test3_object_setid();
  if (all || test == 21) test1_object_setmovable();
  if (all || test == 22) test2_object_setmovable();
  if (all || test == 23) test1_object_setmoved();
  if (all || test == 24) test2_object_setmoved();
  if (all || test == 25) test1_object_sethidden();
  if (all || test == 26) test2_object_sethidden();
  if (all || test == 27) test1_object_setkey();
  if (all || test == 28) test2_object_setkey();
  if (all || test == 29) test3_object_setkey();
  if (all || test == 30) test1_object_setlight();
  if (all || test == 31) test2_object_setlight();
  if (all || test == 32) test1_object_seton();
  if (all || test == 33) test2_object_seton();
  if (all || test == 34) test1_object_getmovable();
  if (all || test == 35) test2_object_getmovable();
  if (all || test == 36) test1_object_getmoved();
  if (all || test == 37) test2_object_getmoved();
  if (all || test == 38) test1_object_gethidden();
  if (all || test == 39) test2_object_gethidden();
  if (all || test == 40) test1_object_getkey();
  if (all || test == 41) test2_object_getkey();
  if (all || test == 42) test1_object_getlight();
  if (all || test == 43) test2_object_getlight();
  if (all || test == 44) test1_object_geton();
  if (all || test == 45) test2_object_geton();
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

/*-----------------------------------------------------------------*/
void test1_object_create(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(ob!=NULL);
  object_destroy(ob);
}
void test2_object_create(){
  Object *ob=NULL;
  ob=object_create(NO_ID);
  PRINT_TEST_RESULT(ob==NULL);
  object_destroy(ob);
}
/*-----------------------------------------------------------------*/
void test1_object_destroy(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_destroy(ob)==OK);
}
void test2_object_destroy(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_destroy(ob)==ERROR);
}
void test3_object_destroy(){
  Object *ob=NULL;
  ob=object_create(NO_ID);
  PRINT_TEST_RESULT(object_destroy(ob)==ERROR);
}
/*-----------------------------------------------------------------*/

void test1_object_setname(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_name(ob,"OB1")==OK);
  object_destroy(ob);
}
void test2_object_setname(){
  Object *ob=NULL;
  char *name=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_name(ob,name)==ERROR);
  object_destroy(ob);
}
void test3_object_setname(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_name(ob,"OB1")==ERROR);
}

/*-----------------------------------------------------------------*/

void test1_object_getname(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_name(ob,"OB1");
  PRINT_TEST_RESULT(object_get_name(ob)!=ERROR);
  object_destroy(ob);
}
void test2_object_getname(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_name(ob)==ERROR);
}

/*-----------------------------------------------------------------*/
void test1_object_getid(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_get_id(ob)!=ERROR);
  object_destroy(ob);
}
void test2_object_getid(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_name(ob)==ERROR);
}

/*-----------------------------------------------------------------*/
void test1_object_setdescription(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_description(ob,"descripcion")==OK);
  object_destroy(ob);
}
void test2_object_setdescription(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_description(ob,"descripcion")==ERROR);
}
void test3_object_setdescription(){
  Object *ob=NULL;
  char *name=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_description(ob,name)==ERROR);
  object_destroy(ob);
}
/*-----------------------------------------------------------------*/
void test1_object_getdescription(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_description(ob,"description");
  PRINT_TEST_RESULT(object_get_description(ob)!=ERROR);
  object_destroy(ob);
}
void test2_object_getdescription(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_description(ob)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_setid(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_id(ob,2)!=ERROR);
  object_destroy(ob);
}
void test2_object_setid(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_id(ob,NO_ID)==ERROR);
  object_destroy(ob);
}
void test3_object_setid(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_id(ob,2)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_setmovable(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_movable(ob,1)==OK);
  object_destroy(ob);
}
void test2_object_setmovable(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_movable(ob,1)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_setmoved(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_movable(ob,1);
  PRINT_TEST_RESULT(object_set_moved(ob,1)==OK);
  object_destroy(ob);
}
void test2_object_setmoved(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_moved(ob,1)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_sethidden(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_hidden(ob,1)==OK);
  object_destroy(ob);
}
void test2_object_sethidden(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_hidden(ob,1)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_setkey(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_key(ob,1)==OK);
  object_destroy(ob);
}
void test2_object_setkey(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_key(ob,1)==ERROR);
}
void test3_object_setkey(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_key(ob,NO_ID)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_setlight(){
  Object *ob=NULL;
  ob=object_create(1);
  PRINT_TEST_RESULT(object_set_light(ob,1)==OK);
  object_destroy(ob);
}
void test2_object_setlight(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_light(ob,1)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_seton(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_light(ob,1);
  PRINT_TEST_RESULT(object_set_on(ob,1)==OK);
  object_destroy(ob);
}
void test2_object_seton(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_set_on(ob,1)==ERROR);
}
/*-----------------------------------------------------------------*/
void test1_object_getmovable(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_movable(ob,1);
  PRINT_TEST_RESULT(object_get_movable(ob)!=FALSE);
  object_destroy(ob);
}
void test2_object_getmovable(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_movable(ob)==FALSE);
}
/*-----------------------------------------------------------------*/
void test1_object_getmoved(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_moved(ob,0);
  PRINT_TEST_RESULT(object_get_moved(ob)!=TRUE);
  object_destroy(ob);
}
void test2_object_getmoved(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_moved(ob)==FALSE);
}

/*-----------------------------------------------------------------*/
void test1_object_gethidden(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_hidden(ob,1);
  PRINT_TEST_RESULT(object_get_hidden(ob)!=FALSE);
  object_destroy(ob);
}
void test2_object_gethidden(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_movable(ob)==FALSE);
}
/*-----------------------------------------------------------------*/
void test1_object_getkey(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_key(ob,12);
  PRINT_TEST_RESULT(object_get_key(ob)!=NO_ID);
  object_destroy(ob);
}
void test2_object_getkey(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_key(ob)==NO_ID);
}
/*-----------------------------------------------------------------*/
void test1_object_getlight(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_light(ob,1);
  PRINT_TEST_RESULT(object_get_light(ob)!=FALSE);
  object_destroy(ob);
}
void test2_object_getlight(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_light(ob)==FALSE);
}
/*-----------------------------------------------------------------*/
void test1_object_geton(){
  Object *ob=NULL;
  ob=object_create(1);
  object_set_on(ob,0);
  PRINT_TEST_RESULT(object_get_on(ob)!=TRUE);
  object_destroy(ob);
}
void test2_object_geton(){
  Object *ob=NULL;
  PRINT_TEST_RESULT(object_get_on(ob)==FALSE);
}
