/**
 * @brief Se encarga de pasar el test al die.c
 * @file die_test.c
 * @author: Gonzalo Martinez 
 * @version: 1.0
 * @date: 3-3-2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "die.h"
#include "types.h"


void test_die_create();
void test_die_destroy();
void test_die_get_lastroll();
void test_die_roll();
void test_die_print();


int main(int argc, char** argv){
    
	printf("Pasando todas la pruebas del modulo Die:\n");
    
    test_die_create();
    test_die_destroy();
    test_die_get_lastroll();
    test_die_roll();
    test_die_print();
	
	
    exit(EXIT_SUCCESS);
}

void test_die_create(){
    Die* die = NULL;
    die = die_create();
    if(die!=NULL){
        printf("test1_die_create superado\n");
    }
    else{
        printf("test1_die_create no superado\n");
    }
	die_destroy(die);
}
void test_die_destroy(){
    Die* die = NULL;
    die = die_create();
    die_destroy(die);
        printf("test_die_destroy superado\n");
}

void test_die_get_lastroll(){
    Die* die= NULL;
    die = die_create();
	die_roll(die);
    if(die_get_lastroll(die)>=1  || die_get_lastroll(die)<=6 ){
        printf("test_die_get_lastroll superado\n");
    } else {
        printf("test_die_get_lastroll no superado\n");
    }
    die_destroy(die);
}


void test_die_roll(){
    Die* die= NULL;
    die = die_create();
    if(die_roll(die)!=NULL){
        printf("test_die_roll superado\n");
    }
    else{
        printf("test_die_roll no superado\n");
    }
    die_destroy(die);
}

void test_die_print(){
    Die * die = NULL;
    die = die_create();
    
    if(die_print(stdout,die)!=-1){
        printf("test_die_print superado\n");
    }
    else{
        printf("test_die_print no superado\n");
    }
    die_destroy(die);
}


