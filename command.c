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
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 
#define N_CMD 10 /*Dependerá del número de comandos diferentes que se pueden introducir en el juego, en este caso 5*/


/*Enumeración de los posibles comandos a introducir y debajo sus correspondientes abreviaturas, incluido el incorrrecto*/
char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Following", "Previous","Take","Drop","Move","Left","Right"};
char *short_cmd_to_str[N_CMD] =  {"","","e","f","p","t","d","m","l","r"};


T_Command get_user_input(){
	T_Command cmd = NO_CMD;
	char input[CMD_LENGHT] = "";
	int i=UNKNOWN - NO_CMD + 1;


	if (scanf("%s", input) > 0){
		cmd = UNKNOWN;
		
		while(cmd == UNKNOWN && i < N_CMD){
			if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input,cmd_to_str[i])){
				cmd = i + NO_CMD;
			} /*Este bucle while se repetirá hasta que el comando coincida con los definidos previamente, y si llega a N_CMD también se detendrá*/
			else {
				i++;
			}
		}
	}
	return cmd; /*Se retornará el comando que se ha introducido sea uno válido o sea uno desconocido (unknown)*/
	
}


