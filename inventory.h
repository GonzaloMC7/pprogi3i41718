/**
 * @brief Define las primitivas de las funciones para el inventory.c
 *
 * @file inventory.h
 * @author Gonzalo Martinez
 * @version 1.0
 * @date 12/03/2018
 */
 #ifndef INVENTORY_H
 #define INVENTORY_H

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "set.h"
#include "types.h"



typedef struct _Inventory Inventory;
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Crea un inventario
 *
 * inventory_ini(int max);
 * @author Gonzalo Martinez
 * @param max Recibe el número de elementos máximo que queremos en nuestro inventario
 * @return El Inventory creado
 */
Inventory * inventory_ini(int max);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Destruye un inventario
 *
 * inventory_destroy(Inventory * inv);
 * @author Gonzalo Martinez
 * @param inv El Inventory creado anteriormente
 * @return Devuelve OK si se ha destruido correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_destroy(Inventory * inv);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Comprueba si el inventario está lleno
 *
 * inventory_isFull(Inventory * inv);
 * @author Gonzalo Martinez
 * @param inv El Inventory creado anteriormente
 * @return Devuelve TRUE si el inventario está lleno y si no devuelve FALSE
 */
BOOL inventory_isFull(Inventory * inv);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Introduce un nuevo elemento en el inventario
 *
 * inventory_push_id(Inventory * inv, Id id);
 * @author Gonzalo Martinez
 * @param inv El Inventory creado anteriormente
 * @param id el Id a introducir
 * @return Devuelve OK si se ha incluido correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_push_id(Inventory * inv, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Extrae un elemento del Inventory
 *
 * inventory_pop_id(Inventory * inv, Id id);
 * @author Gonzalo Martinez
 * @param inv El Inventory creado anteriormente
 * @param id el Id a extraer
 * @return Devuelve OK si se ha extraído correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_pop_id(Inventory * inv, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Extrae un elemento del Inventory y devuelve su id
 *
 * inventory_get_id(Inventory * inv, Id id);
 * @author Juan Martin
 * @param inv El Inventory creado anteriormente
 * @param id el Id a extraer
 * @return devuelve la id extraida
 */
Id inventory_get_id(Inventory * inv, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Comprueba que exista un id determinado en el conjunto (inventario)
 * inventory_find_id(Inventory* inv, Id id);
 *
 * @author Javier Martin
 * @param inv El Inventory creado anteriormente
 * @param id el Id a buscar
 * @return TRUE en caso de que se haya encontrado o FALSE en caso contrario
 */
BOOL inventory_find_id(Inventory* inv, Id id);

/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la información de un Inventory
 * @author Gonzalo Martinez
 * @param fp FILE donde se va a imprimir
 * @param inv el Inventory creado anteriormente
 * @return Devuelve OK si se ha imprimido correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_print(FILE * fp, Inventory * inv);
/*-----------------------------------------------------------------------------------------------*/

#endif
