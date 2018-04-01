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

	ge->map      = screen_area_init( 1, 1, 48, 13);
	ge->descript = screen_area_init(50, 1, 29, 13);
	ge->banner   = screen_area_init(28,15, 23,  1);
	ge->help     = screen_area_init( 1,16, 78,  2);
	ge->feedback = screen_area_init( 1,19, 78,  3);

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
	char str[999];
	int i=0;
	T_Command last_cmd = UNKNOWN;
	extern char *cmd_to_str[];
	STATUS estado;


	/* Paint the in the map area */
	screen_area_clear(ge->map);
	if ((id_act = game_get_player_location(game)) != NO_ID){
		space_act = game_get_space(game, id_act);
		id_back = space_get_north(space_act);
		id_next = space_get_south(space_act);
		id_east = space_get_east(space_act);
		id_west = space_get_west(space_act);
		

		id=NO_ID;

		if (id_back != NO_ID) {
			sprintf(str, "  |                   %2d|",(int) id_back);
			screen_area_puts(ge->map, str);
			for(i=1; i<=MAX_OBJ; i++){
				if(game_get_object_location(game, i) == id_back){
					sprintf(str, "  |           O: %s    |",game_get_name_object(game,i));
					screen_area_puts(ge->map, str);
				}

			}
			if (id==NO_ID){
				sprintf(str, "  |                     |");
				screen_area_puts(ge->map, str);
			}

			sprintf(str, "  +---------------------+");
			screen_area_puts(ge->map, str);
			sprintf(str, "        ^");
			screen_area_puts(ge->map, str);
		}
		id=NO_ID;

		if (id_act != NO_ID) {
			sprintf(str, "  +---------------------+");
			screen_area_puts(ge->map, str);
			if(id_east == NO_ID && id_west == NO_ID){
				sprintf(str, "  | 8D                %2d|",(int) id_act);
			}
			else if(id_east != NO_ID && id_west == NO_ID){
				sprintf(str, "  | 8D                %2d|>",(int) id_act);
			}
			else if(id_east != NO_ID && id_west != NO_ID){
				sprintf(str, " <| 8D                %2d|>",(int) id_act);
			}
			else{
				sprintf(str, " <| 8D                %2d|",(int) id_act);
			}
			screen_area_puts(ge->map, str);
			for(i=1; i<=MAX_OBJ; i++){
				if(game_get_object_location(game, i) == id_act){
					sprintf(str, "  |           O: %s    |",game_get_name_object(game,i));
					screen_area_puts(ge->map, str);
				}
			}
			if (id==NO_ID){
				sprintf(str, "  |                     |");
				screen_area_puts(ge->map, str);
			}				
			sprintf(str, "  |        %s      |", space_get_ilus1(space_act));
			screen_area_puts(ge->map, str);
			sprintf(str, "  |        %s      |", space_get_ilus2(space_act));
			screen_area_puts(ge->map, str);
			sprintf(str, "  |        %s      |", space_get_ilus3(space_act));
			screen_area_puts(ge->map, str);
			sprintf(str, "  +---------------------+");
			screen_area_puts(ge->map, str);
		}

		id=NO_ID;
		if (id_next != NO_ID) {
			sprintf(str, "        v");
			screen_area_puts(ge->map, str);
			sprintf(str, "  +---------------------+");
			screen_area_puts(ge->map, str);
			sprintf(str, "  |                   %2d|",(int) id_next);
			screen_area_puts(ge->map, str);
			for(i=1; i<=MAX_OBJ; i++){
				if(game_get_object_location(game, i) == id_next){
					sprintf(str, "  |           O: %s    |",game_get_name_object(game,i));
					screen_area_puts(ge->map, str);
				}
			}
			if (id==NO_ID){
				sprintf(str, "  |                     |");
				screen_area_puts(ge->map, str);
			}

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

	/* Paint the in the banner area */
	screen_area_puts(ge->banner, " The game of the Goose ");

	/* Paint the in the help area */
	screen_area_clear(ge->help);
	sprintf(str, " The commands you can use are:");
	screen_area_puts(ge->help, str);
	sprintf(str, " following/f, previous/p, exit/e, take/t, drop/d, move/m(die), left/l, right/r");
	screen_area_puts(ge->help, str);
	
	/* Paint the in the feedback area */
	
	
	last_cmd = command_get_type(game_get_last_command(game));
	estado=game_estado(game);
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
