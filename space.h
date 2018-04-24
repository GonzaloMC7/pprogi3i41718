/**
 * @brief It defines a space
 *
 * @file space.h
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


/*COMENTADO EN SPACE.C*/

#ifndef SPACE_H
#define SPACE_H

#include <string.h>
#include "types.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Iniciliza y crea el espacio del juego y todas sus posiciones
 * @author Profesores PPROG
 * @param Id con el que se quiere inicializar el espacio del juego
 * @return Puntero a la EdD Space con sus valores inicializados
 */
Space* space_create(Id id);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Elimina los recursos del espacio que se define como argumento
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere eliminar recursos
 * @return Devuelve OK si se ha liberado todo correctamente, o ERROR en caso contrario
 */
STATUS space_destroy(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de un espacio seleccionado
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere obtener su Id
 * @return Devuelve el Id requerido del espacio seleccionado
 */
Id space_get_id(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Determina el nombre que se le define al espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere definir el nombre, y cadena de caracteres del nombre que se le queire poner
 * @return Devuelve OK si se ha establecido correctamente el nombre, o ERROR en caso contrario
 */
STATUS space_set_name(Space* space, char* name);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el nombre de un espacio seleccionado
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere obtener el nombre
 * @return Devuelve la cadena de caracteres del nombre del espacio seleccionado
 */
const char* space_get_name(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un espacio que se encuentra en en la posicion norte
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_north_link(Space* space, Id idlink);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de la posicion norte de un espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere obtener el Id
 * @return Devuelve el Id norte del espacio seleccionado
 */
Id space_get_north_link(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un espacio que se encuentra en en la posicion sur
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_south_link(Space* space, Id idlink);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de la posicion sur de un espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere obtener el Id
 * @return Devuelve el Id sur del espacio seleccionado
 */
Id space_get_south_link(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un espacio que se encuentra en en la posicion este
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_east_link(Space* space, Id id);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de la posicion este de un espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere obtener el Id
 * @return Devuelve el Id este del espacio seleccionado
 */
Id space_get_east_link(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un espacio que se encuentra en en la posicion oeste
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_west_link(Space* space, Id id);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de la posicion oeste de un espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere obtener el Id
 * @return Devuelve el Id este del espacio seleccionado
 */
Id space_get_west_link(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un espacio que se encuentra en en la posicion superior
 * @author Miguel Manzano
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_up_link(Space* space, Id id);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de la posicion superior de un espacio
 * @author Miguel Manzano
 * @param Puntero a Space el cual se quiere obtener el Id
 * @return Devuelve el Id este del espacio seleccionado
 */
Id space_get_up_link(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un espacio que se encuentra en en la posicion inferior
 * @author Miguel Manzano
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_down_link(Space* space, Id id);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de la posicion inferior de un espacio
 * @author Miguel Manzano
 * @param Puntero a Space el cual se quiere obtener el Id
 * @return Devuelve el Id este del espacio seleccionado
 */
Id space_get_down_link(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna la parte superior de la ilus3acion leida a un espacio
 * @author Juan Martin
 * @param Puntero a Space y cadena de caracteres a establecer
 * @return Devuelve un status segun el exito de la funcion
 */
STATUS space_set_ilus1(Space* space, char* ilus1);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna la parte superior de la ilus3acion leida a un espacio
 * @author Juan Martin
 * @param Puntero a Space y cadena de caracteres a establecer
 * @return Devuelve un status segun el exito de la funcion
 */
const char* space_get_ilus1(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna la parte media de la ilus3acion leida a un espacio
 * @author Juan Martin
 * @param Puntero a Space y cadena de caracteres a establecer
 * @return Devuelve un status segun el exito de la funcion
 */
STATUS space_set_ilus2(Space* space, char *ilus2);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna la parte superior de la ilus3acion leida a un espacio
 * @author Juan Martin
 * @param Puntero a Space y cadena de caracteres a establecer
 * @return Devuelve un status segun el exito de la funcion
 */
const char* space_get_ilus2(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna la parte inferior de una ilus3acion leida a un espacio
 * @author Juan Martin
 * @param Puntero a Space y cadena de caracteres a establecer
 * @return Devuelve un status segun el exito de la funcion
 */
STATUS space_set_ilus3(Space* space, char *ilus3);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna la parte superior de la ilus3acion leida a un espacio
 * @author Juan Martin
 * @param Puntero a Space y cadena de caracteres a establecer
 * @return Devuelve un status segun el exito de la funcion
 */
const char* space_get_ilus3(Space* space);

/**
 * @brief Establece una descripcion a un espacio determinado
 * @author Juan Martin
 * @param espacio y descripcion a establecer
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */
 STATUS space_set_description(Space* space, char* description1);

 /**
  * @brief Devuelve la descrición de un espacio determinado
  * @author Juan Martin
  * @param espacio del que se quiere la descrición
  * @return la descripción del espacio
  */
 const char * space_get_description(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Asigna el Id que se le proporciona a un objeto determinado en un espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere asignar el Id, y el Id determinado que se le quiere dar
 * @return Devuelve OK si se ha asignado correctamente, o ERROR en caso contrario
 */
STATUS space_set_object(Space* space, Id value);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de un objeto en el espacio determinado
 * @author Gonzalo Martinez
 * @param Puntero a Space el cual se quiere obtener el Id del objeto
 * @return Devuelve el Id del objeto seleccionado
 */
int space_get_object(Space* space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el Id de un objeto en el espacio determinado
 * @author Javier Martin
 * @param Puntero a Space el cual se quiere obtener el Id del objeto
 * @return Devuelve el Id del objeto seleccionado
 */
Id space_get_object_id(Space* space, int i);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Determina si se encuentra un objeto en un conjunto determinado
 * @author Javier Martin
 * @param Puntero a Space, y el Id del objeto que se quiere comprobar
 * @return Devuelve TRUE en el caso de que se encuentre entre el conjunto de objetos, o FALSE en caso contrario
 */
BOOL space_find_id(Space *space, Id IdObject);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Elimina el objeto del espacio
 * @author Javier Martin
 * @param Puntero a Space, i el Id del objeto que se quiere eliminar
 * @return Devuelve OK si se ha eliminado correctamente o ERROR en caso contrario
 */
STATUS space_destroy_object(Space* space, Id IdObject);

/*-----------------------------------------------------------------------------------------------------------------------*/
/**
 * @brief Pone la iluminación a encendido
 * @author Gonzalo Martinez
 * @param Puntero a Space
 * @return Devuelve OK si se ha asignado correctamente o ERROR en caso contrario
 */
STATUS space_set_lightON(Space * space);

/*-----------------------------------------------------------------------------------------------------------------------*/
/**
 * @brief Pone la iluminación a apagado
 * @author Gonzalo Martinez
 * @param Puntero a Space
 * @return Devuelve OK si se ha asignado correctamente o ERROR en caso contrario
 */
STATUS space_set_lightOFF(Space * space);

/*-----------------------------------------------------------------------------------------------------------------------*/
/**
 * @brief Obtiene el estado de la iluminación (encendido/apagado)
 * @author Gonzalo Martinez
 * @param Puntero a Space
 * @return Devuelve OK si se ha asignado correctamente o ERROR en caso contrario
 */
BOOL space_get_light(Space * space);

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Imprime el estado en el que se encuentra un espacio
 * @author Profesores PPROG
 * @param Puntero a Space el cual se quiere imprimir el espacio
 * @return Devuelve Ok si se ha impreso todo correctamente, o ERROR en caso contrario
 */
STATUS space_print(Space* space);

#endif
