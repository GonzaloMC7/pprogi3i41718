/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

/*COMENTADO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"
#include "command.h"


/*-------------------------------------------------------------------------------------------------------------------*/
/*Esta función va a ser el bucle de juego, y por tanto es el archivo main de todo el juego*/

int main(int argc, char *argv[]){
  Game *game=NULL;
  Graphic_engine *gengine;
  STATUS estado;
  FILE *fp;
  extern char *cmd_to_str[];

  game=game_create();


  fp=fopen(argv[3],"w");

  if (!game){
	  return 1;
  }

  if (argc < 2){
    fprintf(stderr, "Use: %s <new_data.dat>\n", argv[0]); /*Abre el archivo data.dat*/
    return 1;
  } if (game_create_from_file(game, argv[1]) == ERROR){ /*Control de errores creación juego*/
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  } if ((gengine = graphic_engine_create()) == NULL){ /*Control de errores inicialización motor gráfico*/
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }
  while (command_get_type(game_get_last_command(game))!=EXIT && !game_is_over(game)){ /*BUCLE DE JUEGO: mientras el comando no sea exit o gameisover no se produzca, se mantiene el bucle de juego*/
    graphic_engine_paint_game(gengine, game);
    command_get_user_input(game_get_last_command(game));
	game_update(game);
	estado=game_get_estado(game);
	if (estado==ERROR){
		fprintf(fp, "%s:ERROR\n",cmd_to_str[command_get_type(game_get_last_command(game))-NO_CMD]);
	}else{
		fprintf(fp, "%s:OK\n",cmd_to_str[command_get_type(game_get_last_command(game))-NO_CMD]);
	}
	}
    game_destroy(game);
	graphic_engine_destroy(gengine);
	fclose(fp);
  return 0;
}
