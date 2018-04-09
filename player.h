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
 *
 * player_create (Id id);
 * @author Gonzalo Martinez
 * @param Id que se le atribuye
 * @return El nuevo jugador creado
 */

 Player * player_create (Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Destruye un jugador creado previamente
 *
 * player_destroy (Player * pl);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return OK si se ha destruido correctamente y ERROR si no se ha destruido correctamente
 */

 STATUS player_destroy (Player * pl);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna un nombre al Player
 *
 * player_set_name (Player * pl, char * name);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente y un char con el nombre que queremos asignarle al Player
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_set_name (Player * pl, char * name);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna un id al Player
 *
 * player_set_id (Player * pl, Id id);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente y un Id con el id que queremos asignarle al Player
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_set_id (Player * pl, Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna una posición al Player
 *
 * player_set_location (Player * pl, Id location);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente y un Space con la localización que queremos asignarle al Player
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_set_location (Player * pl, Id location);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Asigna un objeto al inentario
 *
 * player_set_object(Player*pl, Id id);
 * @author Gonzalo Martinez
 * @param pl player al que se le asigna el objeto
 * @param id del objeto que se le asigna
 * @return OK o ERROR
 */
 STATUS player_set_object (Player * pl, Id id);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene el nombre del Player
 * player_get_name (Player * pl);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return Char con el nombre del Player
 */

 char * player_get_name (Player * pl);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene el id del Player
 * player_get_id (Player * pl);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return Id con el id del Player
 */

 Id player_get_id (Player * pl);

 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene la localización del Player
 *
 * player_get_location (Player * pl);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return Space con la localización del Player
 */

 Id player_get_location (Player * pl);
 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Obtiene el id del objeto que tiene el jugador
 *
 * player_get_object (Player * pl, Id id);
 * @author Gonzalo Martinez
 * @param pl jugador determinado
 * @param id id del objeto determinado
 * @return Id del inventario
 */

 Id player_get_object (Player * pl, Id id);
 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Busca en el jugador el objeto determinado
 *
 *  player_find_object(Player *player, Id IdObject);
 * @author Gonzalo Martinez
 * @param pl jugador determinado
 * @param idObject id del objeto determinado
 * @return 0 en el caso de que no se haya encontrado o 1 en caso contrario
 */
BOOL player_find_object(Player *player, Id IdObject);
/*-----------------------------------------------------------------------------------------------------*/
/**
* @brief Elimina del jugador un objeto determinado
*
*  player_del_object(Player *player, Id IdObject);
* @author Gonzalo Martinez
* @param player jugador determinado
* @param idObject id del objeto determinado
* @return OK o ERROR
*/
STATUS player_destroy_object(Player *player, Id IdObject);
 /*-----------------------------------------------------------------------------------------------------*/
 /**
 * @brief Imprime la información del Player
 *
 *  player_print(Player * pl);
 * @author Gonzalo Martinez
 * @param El Player creado anteriormente
 * @return OK si se ha asignado correctamente y ERROR si no se ha asignado correctamente
 */

 STATUS player_print(Player * pl);

#endif
