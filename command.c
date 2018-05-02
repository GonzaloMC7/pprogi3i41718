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
#define N_CMD 12 /*Dependerá del número de comandos diferentes que se pueden introducir en el juego, en este caso 11*/
#define MAX 200

/*Enumeración de los posibles comandos a introducir y debajo sus correspondientes abreviaturas, incluido el incorrrecto*/
char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit","Take","Drop","Move","Go","Check", "Turnon", "Turnoff","Open","Speak"};

struct _Command{
	char vrb[MAX]; /*!< cadena de caracteres referido al comando enumerado que introduce el usuario*/
	char ob[MAX]; /*!< cadena de caracteres que se introduce al complementar un comando*/
	char ob2[MAX]; /*!< cadena de caracteres que se introduce al complementar un comando*/
	T_Command command; /*!<tipo enumerado de comando*/
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
	c->ob2[0]='\0';
	return c;
}
/*-----------------------------------------------------------------------------------------------------*/
void command_destroy(Command* cmd) {
	if (!cmd) {
		return;
	}
	free(cmd);
	return;
}
/*-----------------------------------------------------------------------------------------------------*/

STATUS command_interpret_input(Command* cmd, char* input) {

	int i,cont=0,x=0,l=0,m;
	char auxiliar[CMD_LENGTH]="";
	char auxiliar2[CMD_LENGTH]="";

	if (!cmd)
	return ERROR;

	cmd->command = NO_CMD;
	strcpy(cmd->ob, "");
	strcpy(cmd->ob2, "");
	strcpy(cmd->vrb,"");

	if (strncmp("E", input, 1) == 0 || strncmp("e", input, 1) == 0 || strncmp("exit", input, 4) == 0|| strncmp("Exit", input, 4) == 0) {
		cmd->command = EXIT;
		strcpy(cmd->vrb,"exit");

	} else if ((strncmp("take", input, 4) == 0)
	|| (strncmp("t", input, 1) == 0) || (strncmp("T", input, 1) == 0)||(strcmp(input, "Take")==0)) {

		cmd->command = TAKE;

		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;


			strcpy(cmd->vrb,"take");
			strcpy(cmd->ob,input+cont);

	}else if ((strncmp("check", input, 5) == 0)
	|| (strncmp("c", input, 1) == 0) || (strncmp("C", input, 1) == 0)||(strcmp(input, "Check")==0)) {

		cmd->command = CHECK;

		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;
		if (input[cont]!='O' && input[cont]!='s'){
			cmd->command = UNKNOWN;
		}
		else{
			strcpy(cmd->vrb,"check");
			strcpy(cmd->ob,input+cont);
		}

	}else if ((strncmp("turnon", input, 4) == 0)
	|| (strncmp("n", input, 1) == 0) || (strncmp("N", input, 1) == 0)||(strcmp(input, "Turnon")==0)) {

		cmd->command = TURNON;

		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;
		if (input[cont]!='O'){
			cmd->command = UNKNOWN;
		}
		else{
			strcpy(cmd->vrb,"turnon");
			strcpy(cmd->ob,input+cont);
		}
	}else if ((strncmp("turnoff", input, 4) == 0)
	|| (strncmp("f", input, 1) == 0) || (strncmp("F", input, 1) == 0)||(strcmp(input, "Turnoff")==0)) {

		cmd->command = TURNOFF;

		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;
		if (input[cont]!='O'){
			cmd->command = UNKNOWN;
		}
		else{
			strcpy(cmd->vrb,"turnoff");
			strcpy(cmd->ob,input+cont);
		}


	} else if ((strncmp("go", input, 2) == 0)
	|| (strncmp("g", input, 1) == 0) || (strncmp("G", input, 1) == 0)||(strcmp(input, "Go")==0)) {

		cmd->command = GO;

		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;

		strcpy(cmd->vrb,"go");
		strcpy(cmd->ob,input+cont);


	} else if (!strcmp(input, "M") || !strcmp(input, "m") || !strcmp(input, "move")||(strcmp(input, "Move")==0)) {
		cmd->command = MOVE;
		strcpy(cmd->vrb,"move");

	} else if ((strncmp("drop", input, 4) == 0)
	|| (strncmp("d", input, 1) == 0) || (strncmp("D", input, 1) == 0)||(strcmp(input, "Drop")==0)) {

		cmd->command = DROP;

		for (i=0;input[i]!=' ';i++){
			cont++;
		}
		cont++;
		if (input[cont]!='O'){
			cmd->command = UNKNOWN;
		}
		else{
			strcpy(cmd->vrb,"drop");
			strcpy(cmd->ob,input+cont);
		}

	}else if ((strncmp("open", input, 4) == 0)
	|| (strncmp("o", input, 1) == 0) || (strncmp("O", input, 1) == 0)||(strcmp(input, "Open")==0)) {

		cmd->command = OPEN;

		strcpy(cmd->vrb,"open");

		for ( i = 0; input[i]!=' '; i++) {
			cont++;
		}
		cont++;


		for ( i = cont,x=0; input[i]!=' '; i++,x++) {
			auxiliar[x]=input[i];
		}
		if (auxiliar[x]==' '){
			cmd->command = UNKNOWN;
		}
		strcpy(cmd->ob,auxiliar);

		i++;

		for ( l = i;input[l]!=' '; l++) {
		}
		l++;

		for (m=l,x=0;input[m]!='\0';m++,x++){
			auxiliar2[x]=input[m];
		}
		if (auxiliar2[x]==' '){
			cmd->command = UNKNOWN;
		}
		strcpy(cmd->ob2,auxiliar2);
	}else if ((strncmp("speak", input, 5) == 0)
	|| (strncmp("s", input, 2) == 0) || (strncmp("S", input, 2) == 0)||(strcmp(input, "Speak")==0)) {

		cmd->command = SPEAK;
		strcpy(cmd->vrb,"speak");

	}else {
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

char* command_get_ob2(Command* cmd) {
	if (!cmd) {
		return NULL;
	}
	return cmd->ob2;
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
