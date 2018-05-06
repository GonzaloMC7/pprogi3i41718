#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_test.h"

#define MAX_TESTS 19

/**
 * @brief Funcion principal de pruebas para el modulo Game.
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
        printf("Running all test for module Game:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_game_create();
    if (all || test == 2) test1_game_addspace();
    if (all || test == 3) test1_game_setObjectLocation();
    if (all || test == 4) test1_game_addObject();
    if (all || test == 5) test1_game_addLink();
    if (all || test == 6) test1_game_getNameLink();
    if (all || test == 7) test1_game_getLink();
    if (all || test == 8) test1_game_getLinkId2();
    if (all || test == 9) test1_game_createFromFile();
    if (all || test == 10) test1_game_destroy();
    if (all || test == 11) test1_game_getDieLastRoll();
    if (all || test == 11) test1_game_isOver();
    if (all || test == 13) test1_game_getSpace();
    if (all || test == 14) test1_game_getObjectLocation();
    if (all || test == 15) test1_game_getDie();
    if (all || test == 16) test1_game_getLastCommand();
    if (all || test == 17) test1_game_getinfo();
    if (all || test == 18) test1_game_getDialogue();
    if (all || test == 19) test1_game_getEncendido();
    if (all || test == 20) test1_game_getApagado();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}


void test1_game_create() {
  Game * g = game_create();
  PRINT_TEST_RESULT(g != NULL);
  game_destroy(g);
}

/*-----------------------------------------------------------------*/

void test1_game_addspace() {
  Game * g = game_create();
  Space * sp = space_create(1);
  PRINT_TEST_RESULT(game_add_space(g, sp) != ERROR);
  game_destroy(g);
}

/*-----------------------------------------------------------------*/

void test1_game_setObjectLocation() {
  Game * g = game_create();
  Space * sp = space_create(1);
  game_add_space(g, sp);
  PRINT_TEST_RESULT(game_set_object_location(g, 2, 1) != ERROR);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_addObject() {
  Game * g = game_create();
  Object * o = object_create(1);
  PRINT_TEST_RESULT(game_add_object(g, o) != ERROR);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_addLink() {
  Game * g = game_create();
  Link * l = link_ini(1);
  PRINT_TEST_RESULT(game_add_link(g, l) != ERROR);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getNameLink() {
  Game * g = game_create();
  Link * l = link_ini(1);
  game_add_link(g, l);
  PRINT_TEST_RESULT(game_get_name_link(g, 1) != NULL);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getLink() {
  Game * g = game_create();
  Link * l = link_ini(1);
  game_add_link(g, l);
  PRINT_TEST_RESULT(game_get_link(g, 1) != NULL);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getLinkId2() {
  Game * g = game_create();
  Link * l = link_ini(1);
  game_add_link(g, l);
  link_set_id2(l, 1);
  PRINT_TEST_RESULT(game_get_link_id2(g, 1) != NO_ID);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_createFromFile() {
  Game * g = game_create();
  char fn[20];
  strcpy(fn, "new_data.dat");
  PRINT_TEST_RESULT(game_create_from_file(g, fn) != ERROR);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_destroy() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_destroy(g) != ERROR);
}

/*---------------------------------------------------------------*/

void test1_game_getDieLastRoll() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_die_lastroll(g) == 0);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_isOver() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_is_over(g) == FALSE);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getSpace() {
  Game * g = game_create();
  Space* sp = space_create(1);
  game_add_space(g, sp);
  PRINT_TEST_RESULT(game_get_space(g, 1) != NULL);
  game_destroy(g);
}


/*---------------------------------------------------------------*/

void test1_game_getObjectLocation() {
  Game * g = game_create();
  Space* sp = space_create(1);
  Object * o = object_create(2);
  game_add_object(g, o);
  game_add_space(g, sp);
  space_set_object(sp, 2);
  PRINT_TEST_RESULT(game_get_object_location(g, 1) == NO_ID);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getDie() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_die(g) != NULL);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getLastCommand() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_last_command(g) != NULL);
  game_destroy(g);
}


/*---------------------------------------------------------------*/

void test1_game_getinfo() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_info(g) != NULL);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getDialogue() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_dialogue(g) != NULL);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getEncendido() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_encendido(g) == OK);
  game_destroy(g);
}

/*---------------------------------------------------------------*/

void test1_game_getApagado() {
  Game * g = game_create();
  PRINT_TEST_RESULT(game_get_apagado(g) == OK);
  game_destroy(g);
}
