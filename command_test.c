#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command_test.h"

#define MAX_TESTS 19

/**
 * @brief Fichero de prueba para game_management
 *
 * Se encarga de comprobar el funcionamiento de game_management
 * @file command_test.c
 * @author: Juan Martin
 */

int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Command:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) test_command_ini();
    if (all || test == 2) test_command_interpretInput();
    if (all || test == 3) test_command_getOb();
    if (all || test == 4) test_command_getOb2();
    if (all || test == 5) test_command_getVrb();
    if (all || test == 6) test_command_getType();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

    void test_command_ini()
    {
      Command * c = command_ini();
      PRINT_TEST_RESULT(c != NULL);
      command_destroy(c);
    }

/******************************************************************************/

    void test_command_interpretInput()
    {
      Command * c = command_ini();
      char input[10];
      strcpy(input, "speak");
      PRINT_TEST_RESULT(command_interpret_input(c, input) == OK);
      command_destroy(c);
    }

/******************************************************************************/

void test_command_getOb()
{
  Command * c = command_ini();
  PRINT_TEST_RESULT(command_get_ob(c) != NULL);
  command_destroy(c);
}

/******************************************************************************/

void test_command_getOb2()
{
  Command * c = command_ini();
  PRINT_TEST_RESULT(command_get_ob2(c) != NULL);
  command_destroy(c);
}

/******************************************************************************/

void test_command_getVrb()
{
  Command * c = command_ini();
  PRINT_TEST_RESULT(command_get_vrb(c) != NULL);
  command_destroy(c);
}

/******************************************************************************/

void test_command_getType()
{
  Command * c = command_ini();
  PRINT_TEST_RESULT(command_get_type(c) != UNKNOWN);
  command_destroy(c);
}

/******************************************************************************/
