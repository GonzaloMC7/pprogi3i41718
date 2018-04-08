  /**
  * @brief Prueba las funciones de link.c
  *
  * @file link_test.c
  * @author: Gonzalo Martinez
  * @version: 1.0
  * @date: 14/3/2018
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 25

/**
 * @brief Funcion principal de pruebas para el modulo Link.
 *
 *
 *
 */
int main(int argc, char** argv){

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Link:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	      if (test < 1 && test > MAX_TESTS) {
	         printf("Error: unknown test %d\t", test);
	         exit(EXIT_SUCCESS);
         }
    }


    if (all || test == 1)  test1_link_create();
    if (all || test == 2)  test2_link_create();
    if (all || test == 3)  test3_link_create();

    if (all || test == 4)  test1_link_set_name();
    if (all || test == 5)  test2_link_set_name();

    if (all || test == 6)  test1_link_get_name();
    if (all || test == 7)  test2_link_get_name();

    if (all || test == 8)  test1_link_set_id();
    if (all || test == 9)  test2_link_set_id();

    if (all || test == 10) test1_link_get_id();
    if (all || test == 11) test2_link_get_id();

    if (all || test == 12) test1_link_set_id1();
    if (all || test == 13) test2_link_set_id1();
    if (all || test == 14) test3_link_set_id1();

    if (all || test == 15) test1_link_set_id2();
    if (all || test == 16) test2_link_set_id2();
    if (all || test == 17) test3_link_set_id2();

    if (all || test == 18) test1_link_get_id1();
    if (all || test == 19) test2_link_get_id1();

    if (all || test == 20) test1_link_get_id2();
    if (all || test == 21) test2_link_get_id2();

    if (all || test == 22) test1_link_set_open();
    if (all || test == 23) test2_link_set_open();

    if (all || test == 24) test1_link_get_open();
    if (all || test == 25) test2_link_get_open();
    /*if (all || test == 27) test1_link_print();
    if (all || test == 28) test2_link_print();*/

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/*----------------------------------------------------------------------------------*/

void test1_link_create(){
  int res = link_create(5)!=NULL;
  PRINT_TEST_RESULT(res);
}

void test2_link_create(){
    Link * l;
    l = link_create(4);
    PRINT_TEST_RESULT(link_get_id(l) == 4);
}

void test3_link_create(){
  int res = link_create(-3)!=NULL;
  PRINT_TEST_RESULT(res);
}

/*----------------------------------------------------------------------------------*/

void test1_link_set_name(){
    Link * l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_name(l,"prueba")==OK);
}

void test2_link_set_name(){
    Link * l = NULL;
    PRINT_TEST_RESULT(link_set_name(l,"prueba")==ERROR);
}

/*----------------------------------------------------------------------------------*/
void test1_link_get_name() {
  Link * l;
  l = link_create(1);
  link_set_name(l,"prueba");
  PRINT_TEST_RESULT(strcmp(link_get_name(s),"prueba")==0);

}

void test2_link_get_name() {
  Link * l = NULL;
  PRINT_TEST_RESULT(link_get_name(l)==NULL);

}
/*----------------------------------------------------------------------------------*/

void test1_link_set_id(){
  Link * l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id(l,4)==OK);
}

void test2_link_set_id(){
  Link * l= NULL;
  PRINT_TEST_RESULT(link_set_id(l,4)==ERROR);
}

/*----------------------------------------------------------------------------------*/

void test1_link_get_id(){
  Link * l;
  l = link_create(5);
  link_set_id(l, 4);
  PRINT_TEST_RESULT(link_get_id(l)==4);
}

void test2_link_get_id(){
  Link * l= NULL;
  PRINT_TEST_RESULT(link_get_id(l)==NO_ID);
}

/*----------------------------------------------------------------------------------*/

void test1_link_set_id1(){
  Link * l=NULL;
  l=link_create(5);
  link_set_id1(l,4);
  PRINT_TEST_RESULT(link_set_id2(l,5) == OK);
}

void test2_link_set_id1(){
  Link * l = NULL;
  link_set_id1(l,4);
  PRINT_TEST_RESULT(link_set_id2(l,5) == ERROR);
}

void test3_link_set_id1(){
  Link * l = NULL;
  l= link_create(5);
  PRINT_TEST_RESULT(link_set_id1(l,NO_ID) == ERROR);
}

/*----------------------------------------------------------------------------------*/

void test1_link_set_id2(){
  Link * l=NULL;
  l=link_create(5);
  link_set_id2(l,6);
  PRINT_TEST_RESULT(link_set_id1(l,5) == OK);
}

void test2_link_set_id2(){
  Link * l = NULL;
  link_set_id2(l,4);
  PRINT_TEST_RESULT(link_set_id1(l,3) == ERROR);
}

void test3_link_set_id2(){
  Link * l=NULL;
  l= link_create(5);
  PRINT_TEST_RESULT(link_set_id2(l,NO_ID) == ERROR);
}

/*----------------------------------------------------------------------------------*/

void test1_link_get_id1(){
  Link * l;
  l = link_create(5);
  link_set_id1(l,5);
  PRINT_TEST_RESULT(link_get_id1(l) == 5);
}

void test2_link_get_id1(){
  Link * l = NULL;
  PRINT_TEST_RESULT(link_get_id1(l) == NO_ID);
}

/*----------------------------------------------------------------------------------*/

void test1_link_get_id2(){
  Link * l;
  l = link_create(5);
  link_set_id2(l,5);
  PRINT_TEST_RESULT(link_get_id2(l) == 5);
}

void test2_link_get_id2(){
  Link * l = NULL;
  PRINT_TEST_RESULT(link_get_id2(l) == NO_ID);
}

/*----------------------------------------------------------------------------------*/

void test1_link_set_open(){
  Link * l =NULL;
  PRINT_TEST_RESULT(link_set_open(l,TRUE) == FALSE);
}

void test2_link_set_open(){
  Link * l =NULL;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_open(l,TRUE) == link);
}

/*----------------------------------------------------------------------------------*/

void test1_link_get_open(){
  Link * l=NULL;
  link_set_open(link,TRUE);
  PRINT_TEST_RESULT(link_get_open(l) == FALSE);
}

void test2_link_get_open(){
  Link * l=NULL;
  l=link_create(5);
  link_set_open(link,TRUE);
  PRINT_TEST_RESULT(link_get_open(l) == TRUE);
}

/*----------------------------------------------------------------------------------*/