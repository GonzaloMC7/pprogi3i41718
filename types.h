/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NAME_SIZE 100
#define NO_ID -1
 
/*Definicion de tipo Id*/
typedef long Id;

/*Definicion de la enumeracion de BOOL, com FALSE o TRUE*/
typedef enum {
  FALSE, TRUE
} BOOL;

/*Definicion de la enumeracion de STATUS como OK o ERROR*/
typedef enum {
  ERROR, OK
} STATUS;

/*Definicion de la enumeracion de la direccion como Norte, Sur, Este o Oeste*/
typedef enum {
  N, S, E, W
} DIRECTION;

#endif
