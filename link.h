/**
* @brief Implementa las primitivas para link.
*
* @file link.h
* @author: Gonzalo Martinez
* @version: 1.0
* @date: 18/3/2018
*/

#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

#define MAX_LINK 100


typedef struct _Link Link;

/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Crea un link
 * @author Gonzalo Martinez
 * @param El id que le vamos a asignar al link a crear
 * @return Devuelve el Link creado
 */
Link * link_ini(Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Destruye un link creado anteriormente
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente
 * @return Esta función no devuelve nada
 */
void link_destroy(Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna un Id al link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente y el Id a asignar
 * @return Devuelve el Link con el nuevo id
 */
Link * link_set_id(Link * l, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna un nombre al link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente y el nombre a asignar
 * @return Devuelve el Link con el nuevo nombre
 */
STATUS link_set_name(Link * l, char * name);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id del link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente
 * @return Devuelve el id del link que se obtiene en la funcion
 */
Id link_get_id(Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el nombre del link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente
 * @return Devuelve el nombre del link que se obtiene en la funcion
 */
const char * link_get_name(Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id de uno de los espacios a linkear
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente
 * @return Devuelve el id de este espacio
 */
Id link_get_id1(Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id del segundo de los espacios a linkear
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente
 * @return Devuelve el id de este espacio
 */
Id link_get_id2(Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el id del segundo de los espacios a linkear
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente
 * @return Devuelve el id de este espacio
 */
BOOL link_get_idopenclose(Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime la información de un Link
 * @author Gonzalo Martinez
 * @param El Inventory creado anteriormente y el archivo en donde se va a imprimir
 * @return Devuelve el número de caracteres que se han escrito correctamente
 */
int link_print(FILE * fp, Link * l);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna un Id al link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente y el Id a asignar
 * @return Devuelve el Link con el nuevo id1
 */
Link * link_set_id1(Link * l, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna un Id al link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente y el Id a asignar
 * @return Devuelve el Link con el nuevo id2
 */
Link * link_set_id2(Link * l, Id id);
/*-----------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna un Id al link
 * @author Gonzalo Martinez
 * @param El Link creado anteriormente y el Id a asignar
 * @return Devuelve el Link con el nuevo idopenclose
 */
STATUS link_set_idopenclose(Link * l, BOOL value);
/*-----------------------------------------------------------------------------------------------*/

#endif
