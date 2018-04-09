/**
 * @brief Define las primitivas de las funciones para el die.c
 *
 * @file   die.h
 * @author Gonzalo Martinez
 * @version 1.0
 * @date 24/02/2018
 */

#ifndef DIE_H
#define DIE_H


/*Estructura del dado, que tiene un Id para poder identificarlo y un int para guardar el último valor del dado*/
typedef struct _Die Die;

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Crea un Die d
 * @author Gonzalo Martinez
 * @param No recibe nada
 * @return El Die d creado
 */
Die * die_create();

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Destruye el Die d que recibe
 * @author Gonzalo Martinez
 * @param El Die d que se va a destruir
 * @return No devuelve nada ya que es una función void
 */
void die_destroy(Die * die);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Función que hace rodar el dado
 * @author Gonzalo Martinez
 * @param El Die d a rodar
 * @return El Die d después de que se haya rodado
 */
Die *die_roll(Die * die);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Devuelve el último valor del dado
 * @author Gonzalo Martinez
 * @param El Die die creado anteriormente
 * @return die->num que hace referencia al último valor del dado
 */
int die_get_lastroll(Die * die);
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime el último valor del dado
 * @author Gonzalo Martinez
 * @param f FILE donde se va a imprimir el Die
 * @param die dado a imprimir
 * @return Devuelve el número de caracteres que se han escrito en el archivo correctamente
 */
int die_print(FILE * f, const Die * die);
/*-----------------------------------------------------------------------------------------------------*/

#endif /* DIE_H */
