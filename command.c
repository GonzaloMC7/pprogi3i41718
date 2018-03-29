/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 19-12-2014
 * @copyright GNU Public License
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

#define CMD_LENGTH 999
#define N_CMD 10 /*Dependerá del número de comandos diferentes que se pueden introducir en el juego, en este caso 5*/
#define MAX 200

/*Enumeración de los posibles comandos a introducir y debajo sus correspondientes abreviaturas, incluido el incorrrecto*/
char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Following", "Previous","Take","Drop","Move","Left","Right"};

struct _Command{
	char vrb[MAX]; /*cadena de caracteres referido al comando enumerado que introduce el usuario*/
	char ob[MAX]; /* cadena de caracteres que se introduce al complementar un comando*/
	T_Command command; /*tipo enumerado de comando*/
};


/*-----------------------------------------------------------------------------------------------------*/
void command_get_user_input(Command* cmd) {

    char input[CMD_LENGTH] = "";
    int x;

    if (cmd == NULL) {
        return;
    }
    do {
        fgets(input, CMD_LENGTH - 1, stdin);
        x = strlen(input);
    } while (x <= 1);
	
    input[x - 1] = '\0';
    command_interpret_input(cmd, input);
}
/*-----------------------------------------------------------------------------------------------------*/

Command *command_ini(){
	Command *c=NULL;
	
	c=(Command*)malloc(sizeof(Command));
	
	if (!c){
		return NULL;
	}
	c->command=NO_CMD;
	c->vrb[0]='\0';
	c->ob[0]='\0';
	return c;
}

void command_destroy(Command* cmd) {
    if (!cmd) {
        return;
    }
    free(cmd);
    return;
}
/*-----------------------------------------------------------------------------------------------------*/

STATUS command_interpret_input(Command* cmd, char* input) {

	int i,cont=0;
    if (!cmd)
        return ERROR;

    cmd->command = NO_CMD;
    strcpy(cmd->ob, "");
	strcpy(cmd->vrb,"");

    if (!strcmp(input, "E") || !strcmp(input, "e") || !strcmp(input, "exit")) {
        cmd->command = EXIT;
		strcpy(cmd->vrb,"exit");
		
    } else if ((strncmp("following", input, 9) == 0)
            || (strncmp("f", input, 1) == 0) || (strncmp("F", input, 1) == 0)) {

        cmd->command = FOLLOWING;
        strcpy(cmd->vrb,"following");

    } else if ((strncmp("previous", input, 8) == 0)
            || (strncmp("p ", input, 1) == 0) || (strncmp("P ", input, 1) == 0)) {

        cmd->command = PREVIOUS;
        strcpy(cmd->vrb,"previous");

    } else if ((strncmp("take", input, 4) == 0)
            || (strncmp("t", input, 1) == 0) || (strncmp("T", input, 1) == 0)) {

        cmd->command = TAKE;
		
		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;
		if (input[cont]!='O'){
			cmd->command = UNKNOWN;
		}
		else{
			strcpy(cmd->vrb,"take");
			strcpy(cmd->ob,input+cont);
		}

    } else if (!strcmp(input, "M") || !strcmp(input, "m") || !strcmp(input, "move")) {
        cmd->command = MOVE;
		strcpy(cmd->vrb,"move");
		
    } else if ((strncmp("drop", input, 4) == 0)
            || (strncmp("d", input, 1) == 0) || (strncmp("D", input, 1) == 0)) {

        cmd->command = DROP;
       	strcpy(cmd->vrb,"drop");

    } else if ((strncmp("left", input, 4) == 0)
            || (strncmp("l", input, 1) == 0) || (strncmp("L", input, 1) == 0)) {

        cmd->command = LEFT;
        strcpy(cmd->vrb,"left");

    } else if ((strncmp("right", input, 5) == 0)
            || (strncmp("r", input, 1) == 0) || (strncmp("R", input, 1) == 0)) {

        cmd->command = RIGHT;
       	strcpy(cmd->vrb,"right");
		
    }  else {
        cmd->command = UNKNOWN;
    }

    return OK;
}
/*-----------------------------------------------------------------------------------------------------*/

char* command_get_ob(Command* cmd) {
    if (!cmd) {
        return NULL;
    }
    return cmd->ob;
}
/*-----------------------------------------------------------------------------------------------------*/

T_Command command_get_type(Command* cmd) {

    if (!cmd) {
        return UNKNOWN;
    }
    return cmd->command;
}
/*-----------------------------------------------------------------------------------------------------*/
char* command_get_vrb(Command* cmd) {
    if (!cmd) {
        return NULL;
    }
    return cmd->vrb;
}

