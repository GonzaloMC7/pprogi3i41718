/**
 * @brief Fichero de prueba para game_management
 *
 * Se encarga de comprobar el funcionamiento de game_management
 * @file game_management_test.c
 * @author: Javier Martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"
#include "game_management_test.h"
#include "game.h"
#include "space.h"
#include "object.h"
#include "link.h"
#include "types.h"
#include "test.h"

#define MAX_TESTS 9


int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module game_management:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }
    if (all || test == 1) test1_gameManagement_load_spaces();
    if (all || test == 2) test2_gameManagement_load_spaces();
    if (all || test == 3) test3_gameManagement_load_spaces();
    if (all || test == 4) test1_gameManagement_load_objects();
    if (all || test == 5) test2_gameManagement_load_objects();
    if (all || test == 6) test3_gameManagement_load_objects();
    if (all || test == 7) test1_gameManagement_load_links();
    if (all || test == 8) test2_gameManagement_load_links();
    if (all || test == 9) test3_gameManagement_load_links();
    PRINT_PASSED_PERCENTAGE;

    return 1;
}


/*-----------------------------------------------------------------*/
void test1_gameManagement_load_spaces(){
    Game *game = game_create();
    PRINT_TEST_RESULT(game_management_load_spaces(game,"new_data.dat")==OK);
    game_destroy(game);
}
void test2_gameManagement_load_spaces(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_management_load_spaces(game,"new_data.dat")==ERROR);
}
void test3_gameManagement_load_spaces(){
    Game *game = NULL;
    char *nombre = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_management_load_spaces(game,nombre)==ERROR);
    game_destroy(game);
}
/*-----------------------------------------------------------------*/

void test1_gameManagement_load_objects(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_management_load_objects(game,"new_data.dat")==OK);
    game_destroy(game);
}
void test2_gameManagement_load_objects(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_management_load_objects(game,"new_data.dat")==ERROR);
    game_destroy(game);
}
void test3_gameManagement_load_objects(){
  Game *game = NULL;
  char *nombre = NULL;
  game = game_create();
  PRINT_TEST_RESULT(game_management_load_objects(game,nombre)==ERROR);
  game_destroy(game);
}
/*-----------------------------------------------------------------*/

void test1_gameManagement_load_links(){
    Game *game = NULL;
    game = game_create();
    PRINT_TEST_RESULT(game_management_load_links(game,"new_data.dat")==OK);
    game_destroy(game);
}
void test2_gameManagement_load_links(){
    Game *game = NULL;
    PRINT_TEST_RESULT(game_management_load_links(game,"new_data.dat")==ERROR);
    game_destroy(game);
}
void test3_gameManagement_load_links(){
  Game *game = NULL;
  char *nombre = NULL;
  game = game_create();
  PRINT_TEST_RESULT(game_management_load_links(game,nombre)==ERROR);
  game_destroy(game);
}
