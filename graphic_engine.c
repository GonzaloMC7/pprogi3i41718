/**
* @brief It implements the functions for a textual graphic engine
*
* @file graphic_engine.c
* @author Profesores PPROG
* @version 1.0
* @date 18-01-2017
* @copyright GNU Public License
*/

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"

#define ILUSTAM 8

/*Esta estructura define las diferentes partes del motor gráfico del juego*/
struct _Graphic_engine{
	Area *map, *descript, *banner, *help, *feedback;
};

/*-----------------------------------------------------------------------------------------------------*/

Graphic_engine *graphic_engine_create(){
	static Graphic_engine *ge = NULL;

	if (ge)
		return ge;

	screen_init();
	ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

	ge->map      = screen_area_init( 1, 1, 90, 35);
	ge->descript = screen_area_init(94, 1,52, 35);
	ge->banner   = screen_area_init(28,39, 43,  1);
	ge->help     = screen_area_init( 1,42, 128,  3);
	ge->feedback = screen_area_init( 1,46, 128,  3);

	return ge;
}

/*-----------------------------------------------------------------------------------------------------*/

void graphic_engine_destroy(Graphic_engine *ge){
	if (!ge)
		return;

	screen_area_destroy(ge->map);
	screen_area_destroy(ge->descript);
	screen_area_destroy(ge->banner);
	screen_area_destroy(ge->help);
	screen_area_destroy(ge->feedback);

	screen_destroy();
	free(ge);
}

/*-----------------------------------------------------------------------------------------------------*/

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
	Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, ply_loc = NO_ID, id = NO_ID, id_west = NO_ID, id_east = NO_ID;
	Space* space_act = NULL;
	Space* space_next=NULL;
	Space *space_back=NULL;
	char str[999];
	int i=0;
	T_Command last_cmd = UNKNOWN;
	extern char *cmd_to_str[];
	STATUS estado;


	/* Paint the in the map area */
	screen_area_clear(ge->map);
	if ((id_act = game_get_player_location(game)) != NO_ID){
		space_act = game_get_space(game, id_act);

		if(id_act == link_get_id1(game_get_link(game, space_get_north_link(space_act)))){
      id_back = link_get_id2(game_get_link(game, space_get_north_link(space_act)));
    }else{
      id_back = link_get_id1(game_get_link(game, space_get_north_link(space_act)));
    }


		if(id_act == link_get_id1(game_get_link(game, space_get_south_link(space_act)))){
      id_next = link_get_id2(game_get_link(game, space_get_south_link(space_act)));
    }else{
      id_next = link_get_id1(game_get_link(game, space_get_south_link(space_act)));
    }


    space_back = game_get_space(game, id_back);
    space_next = game_get_space(game, id_next);


		id=NO_ID;
		

		id_east=space_get_east_link(space_act);
		id_west=space_get_west_link(space_act);

		if (id_act != NO_ID) {
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			sprintf(str, " ");
			screen_area_puts(ge->map, str);
			if (space_back!=NULL){
			/*sprintf(str, "  		|                   %ld|",id_act);
			screen_area_puts(ge->map, str);
			for(i=1; i<=MAX_OBJ; i++){
				if(game_get_object_location(game, i) == id_back){
					sprintf(str, "  	|           O: %s    |",game_get_name_object(game,i));
					screen_area_puts(ge->map, str);
				}

			}
			if (id==NO_ID){
				sprintf(str, "  		|                     |");
				screen_area_puts(ge->map, str);
			}

			sprintf(str, "  		+---------------------+");
			screen_area_puts(ge->map, str);*/
			sprintf(str, "                                      ^%ld         ",space_get_north_link(space_act));
			screen_area_puts(ge->map, str);
		}
		id=NO_ID;
			sprintf(str, "                +------------------------------------------+");
			screen_area_puts(ge->map, str);
			if(id_east == NO_ID && id_west == NO_ID){
				sprintf(str, "                |                      8D                %2ld|",id_act);
			}
			else if(id_east != NO_ID && id_west == NO_ID){
				sprintf(str, "                |                                          |%ld",id_east);
					screen_area_puts(ge->map, str);
				sprintf(str, "                |                      8D                %2ld|->%ld ",id_act,game_get_link_id2(game,id_east));
			}
			else if(id_east != NO_ID && id_west != NO_ID){
				sprintf(str, "                %ld|                                         |%ld",id_west,id_east);
					screen_area_puts(ge->map, str);
				sprintf(str, "                %ld<-|                      8D               %2ld|->%ld",game_get_link_id2(game, id_west),id_act,game_get_link_id2(game,id_east));
			}
			else{
				sprintf(str, "                %ld |                                          |",id_west);
					screen_area_puts(ge->map, str);
				sprintf(str, "                %ld <-|                      8D                %2ld|",game_get_link_id2(game, id_west),id_act);
			}
			screen_area_puts(ge->map, str);
			for(i=1; i<=MAX_OBJ; i++){
				if(game_get_object_location(game, i) == id_act){
					sprintf(str, "                |                                O: %s    |",game_get_name_object(game,i));
					screen_area_puts(ge->map, str);
				}
			}
			if (id==NO_ID){
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
				sprintf(str, "                |                                          |");
				screen_area_puts(ge->map, str);
			}
			sprintf(str, "                |                             %s      |", space_get_ilus1(space_act));
			screen_area_puts(ge->map, str);
			sprintf(str, "                |                             %s      |", space_get_ilus2(space_act));
			screen_area_puts(ge->map, str);
			sprintf(str, "                |                             %s      |", space_get_ilus3(space_act));
			screen_area_puts(ge->map, str);
			sprintf(str, "                +------------------------------------------+");
			screen_area_puts(ge->map, str);
		}

		id=NO_ID;
		if (id_next != NO_ID) {
			sprintf(str, "                                      v%ld         ",space_get_south_link(space_act));
			screen_area_puts(ge->map, str);
			/*sprintf(str, "  		+---------------------+");
			screen_area_puts(ge->map, str);
			sprintf(str, "  		|                   %2ld|",id_next);
			screen_area_puts(ge->map, str);
			for(i=1; i<=MAX_OBJ; i++){
				if(game_get_object_location(game, i) == id_next){
					sprintf(str, "  		|           O: %s    |",game_get_name_object(game,i));
					screen_area_puts(ge->map, str);
				}
			}
			if (id==NO_ID){
				sprintf(str, "  		|                     |");
				screen_area_puts(ge->map, str);
			}*/

		}
	}


	/* Paint the in the description area */
	screen_area_clear(ge->descript);
	sprintf(str, "  Object's location:       ");
	screen_area_puts(ge->descript, str);
	for(i=1; i<=MAX_OBJ; i++){
		if(game_get_object_location(game, i) != NO_ID){
			sprintf(str, "   %s esta en espacio %ld",game_get_name_object(game,i), game_get_object_location(game, i));
			screen_area_puts(ge->descript, str);
		}
	}
	sprintf(str, " ");
	screen_area_puts(ge->descript, str);


	if ((ply_loc = game_get_player_location(game)) != NO_ID){
		sprintf(str, "  Player location:%d", (int)ply_loc);
		screen_area_puts(ge->descript, str);
	}
	sprintf(str, "  Last roll:%d", game_get_die_lastroll(game));
	screen_area_puts(ge->descript, str);
	sprintf(str, "  Descripcion:");
	screen_area_puts(ge->descript, str);
	sprintf(str, "  %s",game_get_info (game));
	screen_area_puts(ge->descript, str);
	sprintf(str, "  Player inventory:");
	screen_area_puts(ge->descript, str);

	for(i=1; i<=MAX_OBJ;i++){
    if(game_find_player_object(game, i) != FALSE){
      sprintf(str, " %s", game_get_name_object(game, i));
      screen_area_puts(ge->descript, str);
    }
  }

	/* Paint the in the banner area */
	screen_area_puts(ge->banner, "         PRISION ESCAPE: A WAY OUT ");

	/* Paint the in the help area */
	screen_area_clear(ge->help);
	sprintf(str, " The commands you can use are:");
	screen_area_puts(ge->help, str);
	sprintf(str, " following/f, previous/p, exit/e, take/t, drop/d");
	screen_area_puts(ge->help, str);
	sprintf(str, " move/m(die), go/g, check/c, turnon/n, turnoff/f ");

	screen_area_puts(ge->help, str);

	/* Paint the in the feedback area */


	last_cmd = command_get_type(game_get_last_command(game));
	estado=game_get_estado(game);
	if (estado==ERROR){
		sprintf(str, " %s: ERROR", cmd_to_str[last_cmd-NO_CMD]);
		screen_area_puts(ge->feedback, str);
	}else{
		sprintf(str, " %s: OK", cmd_to_str[last_cmd-NO_CMD]);
		screen_area_puts(ge->feedback, str);
	}



	/* Dump to the terminal */
	screen_paint();
	printf("prompt:> ");
}
