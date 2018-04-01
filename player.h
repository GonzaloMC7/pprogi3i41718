/**
 * @brief Define las primitivas de las funciones que se van a desarrollar en player.c, así como la definición
 * de la estructura a utilizar en este módulo player.c
 *
 * @file player.h
 * @author Gonzalo Martinez
 * @version 1.0
 * @date 7-01-2018
 * @copyright GNU Public License
 */

 #ifndef PLAYER_H
 #define PLAYER_H

 #include "types.h"
 #include "inventory.h"


 typedef struct _Player Player;


/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief CreatePlayer
 * @author Gonzalo Martinez
 * @param Id que se le atribuye
 * @return El nuevo jugador creado
 */

 Player * player_create (Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Destruye un jugador creado previamente
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return OK si se ha destruido correctamente y ERROR si no se ha destruido correctamente
 */

 STATUS player_destroy (Player * pl);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna un nombre al Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente y un char con el nombre que queremos asignarle al Player
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_set_name (Player * pl, char * name);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna un id al Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente y un Id con el id que queremos asignarle al Player
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_set_id (Player * pl, Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna una posición al Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente y un Space con la localización que queremos asignarle al Player
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_set_location (Player * pl, Id location);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief
 * @author Gonzalo Martinez
 * @param
 * @return
 */
 STATUS player_set_object (Player * pl, Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene el nombre del Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return Char con el nombre del Player
 */

 char * player_get_name (Player * pl);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene el id del Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return Id con el id del Player
 */

 Id player_get_id (Player * pl);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene la localización del Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return Space con la localización del Player
 */

 Id player_get_location (Player * pl);
 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief
 * @author Gonzalo Martinez
 * @param
 * @return
 */

 Id player_get_object (Player * pl, Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Imprime la información del Player
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_print(Player * pl);

#endif
