/**
 * @brief Fichero de prueba de set
 * 
 * Comprueba el funcionamiento de set.c
 * @file player_test.c
 * @author: Javier Martin 
 * @date: 6-3-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "types.h"


void test_set_create();
void test_set_destroy();
void test1_set_add_id();
void test2_set_add_id();
void test_set_destroy_id();
void test_set_print();
void test_set_get_top();
void test_set_get_id();
void test_set_find_id();



int main(int argc, char** argv){
    printf("Pasando todas la pruebas del modulo Test:\n");
	test_set_create();
	test_set_destroy();
	test1_set_add_id();
	test2_set_add_id();
	test_set_destroy_id();
	test_set_print();
	test_set_get_top();	 
	test_set_get_id();
	test_set_find_id();
	
	exit(EXIT_SUCCESS);
}

void test_set_create(){
    Set* set = NULL;
    set = set_create();
    if(set!=NULL){
        printf("test_set_create superado\n");
    }
    else{
        printf("test_set_create no superado\n");
    }
    set_destroy(set);
}
void test_set_destroy(){
    Set* set = NULL;
    set = set_create();
    if(set_destroy(set)!=ERROR){
        printf("test_set_destroy superado\n");
    }
    else{
        printf("test_set_destroy no superado\n");
    }
}

void test1_set_add_id(){
    Set* set = NULL;
    set = set_create();
    if(set_add_id(set, 5)!=NULL){
        printf("test1_set_add_id superado\n");
    }
    else{
        printf("test1_set_add_id no superado\n");
    }
    set_destroy(set);
}
void test2_set_add_id(){
    Set* set = NULL;
    
    if(set_add_id(set, 5)==NULL){
        printf("test2_set_add_id superado\n");
    }
    else{
        printf("test2_set_add_id no superado\n");
    }
}


void test_set_destroy_id(){
    Set* set = NULL;
    set = set_create();
    set_add_id(set, 4);
    if(set_destroy_id(set, 4)!=ERROR){
        printf("test_set_destroy_id superado\n");
    }
    else{
        printf("test_set_destroy_id no superado\n");
    }
    set_destroy(set);
}

void test_set_print(){
    Set * set = NULL;
    set = set_create();
    
    if(set_print(set)!=ERROR){
        printf("test_set_print superado\n");
    }
    else{
        printf("test_set_print no superado\n");
    }
    set_destroy(set);
}

void test_set_get_top(){
    Set * set = NULL;
    set = set_create();
    set_add_id(set, 4);
    
    if(set_get_top(set)!=0){
        printf("test_set_get_top superado\n");
    }
    else{
        printf("test_set_get_top no superado\n");
    }
    set_destroy(set);
}


void test_set_get_id(){
    Set* set = NULL;
    set = set_create();
    set_add_id(set, 5);
    if(set_get_id(set, 5)!=NO_ID){
        printf("test_set_get_id superado\n");
    } else {
        printf("test_set_get_id no superado\n");
    }
    set_destroy(set);
}

void test_set_find_id(){
    Set* set = NULL;
    set = set_create();
    set_add_id(set, 5);
    if(set_find_id(set, 5)!=NO_ID){
        printf("test_find_set_index superado\n");
    } else {
        printf("test_find_set_index no superado\n");
    }
    set_destroy(set);
}



