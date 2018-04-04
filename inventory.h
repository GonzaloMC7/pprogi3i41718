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
 * @author Gonzalo Martinez
 * @param Recibe el número de elementos máximo que queremos en nuestro inventario
 * @return El Inventory creado
 */
Inventory * inventory_ini(int max);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Destruye un inventario
 * @author Gonzalo Martinez
 * @param El Inventory creado anteriormente
 * @return Devuelve OK si se ha destruido correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_destroy(Inventory * inv);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Comprueba si el inventario está lleno
 * @author Gonzalo Martinez
 * @param El Inventory creado anteriormente
 * @return Devuelve TRUE si el inventario está lleno y si no devuelve FALSE
 */
BOOL inventory_isFull(Inventory * inv);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Introduce un nuevo elemento en el inventario
 * @author Gonzalo Martinez
 * @param El Inventory creado anteriormente y el Id a introducir
 * @return Devuelve OK si se ha incluido correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_push_id(Inventory * inv, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Extrae un elemento del Inventory
 * @author Gonzalo Martinez
 * @param El Inventory creado anteriormente y el Id a extraer
 * @return Devuelve OK si se ha extraído correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_pop_id(Inventory * inv, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Extrae un elemento del Inventory y devuelve su id
 * @author Juan Martin
 * @param El Inventory creado anteriormente y el Id a extraer
 * @return devuelve la id extraida
 */
Id inventory_get_id(Inventory * inv, Id id);
BOOL inventory_comprueba_objeto(Inventory* inventory, Id IdObject);
STATUS inventory_del_object(Inventory* inventory, Id IdObject);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la información de un Inventory
 * @author Gonzalo Martinez
 * @param El FILE donde se va a imprimir y el Inventory creado anteriormente
 * @return Devuelve OK si se ha imprimido correctamente y ERROR si se ha producido algún fallo
 */
STATUS inventory_print(FILE * fp, Inventory * inv);
/*-----------------------------------------------------------------------------------------------*/

#endif
