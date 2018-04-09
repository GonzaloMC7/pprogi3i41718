#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "inv_test.h"
#include "test.h"

#define MAX_TESTS 19

/**
 * @brief Funcion principal de pruebas para el modulo Space.
 *
 * Dos modos de ejecucion:
 *   1.-Si se ejecuta sin parametros se ejecutan todas las pruebas
 *   2.-Si se ejecuta con un numero entre 1 y el numero de pruebas solo ejecuta
 *      la prueba indicada
 *
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Inventory:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_inv_create();
    if (all || test == 2) test2_inv_create();
    if (all || test == 3) test3_inv_create();
    if (all || test == 4) test4_inv_create();
    if (all || test == 5) test1_inv_add();
    if (all || test == 6) test2_inv_add();
    if (all || test == 7) test3_inv_add();
    if (all || test == 8) test4_inv_add();
    if (all || test == 9) test5_inv_add();
    if (all || test == 10) test6_inv_add();
    if (all || test == 11) test7_inv_add();
    if (all || test == 12) test1_inv_remove();
    if (all || test == 13) test2_inv_remove();
    if (all || test == 14) test3_inv_remove();
    if (all || test == 15) test4_inv_remove();
    if (all || test == 16) test1_inv_full();
    if (all || test == 17) test2_inv_full();
    if (all || test == 18) test3_inv_full();
    if (all || test == 19) test4_inv_full();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_inv_create() {
  Inventory * i = inventory_ini(5);
  PRINT_TEST_RESULT(i != NULL);
  inventory_destroy(i);
}

void test2_inv_create() {
    Inventory * i = inventory_ini(0);
    PRINT_TEST_RESULT(i != NULL);
    inventory_destroy(i);
}

void test3_inv_create() {
    Inventory * i = inventory_ini(-2);
    PRINT_TEST_RESULT(i == NULL);
    inventory_destroy(i);
}

void test4_inv_create() {
    Inventory * i = inventory_ini(MAX_IDS);
    PRINT_TEST_RESULT(i!=NULL);
    inventory_destroy(i);
}

/*-----------------------------------------------------------------*/

void test1_inv_add() {
    Inventory * i = inventory_ini(6);
    PRINT_TEST_RESULT(inventory_push_id(i,NO_ID) == ERROR);
    inventory_destroy(i);
}

void test2_inv_add() {
    Inventory * i = NULL;
    PRINT_TEST_RESULT(inventory_push_id(i,6) == ERROR);
}

void test3_inv_add() {
    Inventory * i = NULL;
    PRINT_TEST_RESULT(inventory_push_id(i,NO_ID) == ERROR);
    inventory_destroy(i);
}

void test4_inv_add() {
    Inventory * i = inventory_ini(6);
    PRINT_TEST_RESULT(inventory_push_id(i,2) == OK);
    inventory_destroy(i);
}

void test5_inv_add() {
    Inventory * i = inventory_ini(7);
    inventory_push_id(i,4);
    PRINT_TEST_RESULT(inventory_push_id(i,5) == OK);
    inventory_destroy(i);
}

void test6_inv_add() {
    Inventory * i = inventory_ini(5);
    inventory_push_id(i,3);
    PRINT_TEST_RESULT(inventory_push_id(i,3) == OK);
    inventory_destroy(i);
}

void test7_inv_add() {
    Inventory * i = inventory_ini(3);
    PRINT_TEST_RESULT(inventory_push_id(i,8) == OK);
    inventory_destroy(i);
}

/*-----------------------------------------------------------------*/

void test1_inv_remove() {
    Inventory * i = inventory_ini(4);
    inventory_push_id(i,NO_ID);
    PRINT_TEST_RESULT(inventory_pop_id(i,NO_ID) == ERROR);
    inventory_destroy(i);
}

void test2_inv_remove() {
    Inventory * i = inventory_ini(5);
    inventory_push_id(i,3);
    PRINT_TEST_RESULT(inventory_pop_id(i,3) == OK);
    inventory_destroy(i);
}

void test3_inv_remove() {
    Inventory * i = NULL;
    inventory_push_id(i,NO_ID);
    PRINT_TEST_RESULT(inventory_pop_id(i,NO_ID) == ERROR);
    inventory_destroy(i);

}

void test4_inv_remove() {
    Inventory * i = NULL;
    inventory_push_id(i,3);
    PRINT_TEST_RESULT(inventory_pop_id(i,3) == ERROR);
    inventory_destroy(i);
}

/*-----------------------------------------------------------------*/

void test1_inv_full() {
    Inventory * i = inventory_ini(16);
    int j=0;
    for(j=0; j<16; j++){
      inventory_push_id(i,j+100);
    }
    PRINT_TEST_RESULT(inventory_isFull(i) == TRUE);
    inventory_destroy(i);
}

void test2_inv_full() {
    Inventory * i = inventory_ini(16);
    int j=0;
    for(j=0; j<17; j++){
      inventory_push_id(i,j+100);
    }
    PRINT_TEST_RESULT(inventory_isFull(i) == TRUE);
    inventory_destroy(i);
}

void test3_inv_full() {
    Inventory * i = NULL;
    PRINT_TEST_RESULT(inventory_isFull(i) == FALSE);
    inventory_destroy(i);
}

void test4_inv_full() {
    Inventory * i = inventory_ini(16);
    PRINT_TEST_RESULT(inventory_isFull(i) == FALSE);
    inventory_destroy(i);
}
