/**
 * @brief Interfaz de set
 * 
 * Se encarga de implementar el conjunto (set)
 * @file set.c
 * @author: Javier Martin 
 * @version: 2.0
 * @date: 5-3-2018
 */


#ifndef SET_H
#define SET_H
#include "types.h"

#define MAX_IDS 600


typedef struct _Set Set;

/*Primitivas de las funciones de set*/

/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de crear el set
 * @author Javier Martin
 * @param 
 * @return puntero a set creado o NULL si ha habido algun error
 */
Set * set_create();
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de destruir los conjuntos(eliminar sus recursos)
 * @author Javier Martin
 * @param Puntero al Set que queremos destruir
 * @return OK si se ha eliminado todo correctamente o ERROR en caso contrario
 */
STATUS set_destroy(Set * set);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga añadir un id determinado al conjunto
 * @author Javier Martin
 * @param Puntero al Set y el Id que queremos añadir
 * @return Puntero a set o NULL en caso de fallo
 */
Set * set_add_id(Set * set, Id id);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de eliminar un id del conjunto
 * @author Javier Martin
 * @param Puntero al Set y el Id que queremos eliminar
 * @return OK si se ha eliminado correctamente o ERROR en caso contrario
 */
STATUS set_destroy_id(Set * set, Id id);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de devolver el id en un conjunto determinado
 * @author Javier Martin
 * @param Puntero al Set y la posicion del id que queremos en el array
 * @return Id en la posicion determinada o NO_ID en caso de error
 */
Id set_get_id(Set *set, int i);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de devolver la posicion del array en la que se encuentra un id determinado
 * @author Javier Martin
 * @param Puntero al Set y el id que queremos buscar
 * @return entero con la posicion en el array del id, o -1 en caso de fallo o que no se encuentre el id en el conjunto
 */
int set_find_id(Set *set, Id id);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de obtener el numero de ids de un conjunto determinado
 * @author Javier Martin
 * @param Puntero al Set 
 * @return Numeor de ids, o -1 en caso de error
 */
int set_get_top(Set *set);
/*---------------------------------------------------------------------------------------------*/
/**
 * @brief Se encarga de imprimir el set determinado con sus ids
 * @author Javier Martin
 * @param Puntero al Set que se quiere imprimir 
 * @return OK si se ha impreso correctamente o ERROR en caso contrario
 */
STATUS set_print(Set * set);

#endif 

