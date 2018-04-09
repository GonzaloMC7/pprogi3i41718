/**
 * @brief: Implementa las funciones para crear y utilizar un dado
 *
 * @file: die.c
 * @author: Gonzalo Martinez
 * @date: 23-02-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"
#include "types.h"


struct _Die {
  Id id; /*!< id*/
  int num; /*!< numero*/
};

/*-----------------------------------------------------------------------------------------------------*/
Die * die_create(){
  Die * die = (Die*)malloc(sizeof(Die));
  srand(time(NULL));

  if (die!= NULL){
    die->id=NO_ID;
    die->num=0;
    return die;
  }else return NULL;

}

/*-----------------------------------------------------------------------------------------------------*/

void die_destroy(Die * die){
  if(!die) return;
  free(die);
}

/*-----------------------------------------------------------------------------------------------------*/

Die * die_roll(Die * die){
  int random;

  if(!die) return NULL;

  random = (rand() % 6) + 1;
  die->num=random;

  return die;
}

/*-----------------------------------------------------------------------------------------------------*/
int die_get_lastroll(Die * die){
  if(!die) return -1;
  return die->num;
}
/*-----------------------------------------------------------------------------------------------------*/

int die_print(FILE * f, const Die * die){
  if(!f) return -1;
  if(!die) return -1;

  return fprintf(f, "Last roll: %d\n", die->num);
}

/*-----------------------------------------------------------------------------------------------------*/
