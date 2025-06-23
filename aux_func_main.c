#include "aux_func_main.h"



static struct {
	char * comando;
	int code_command;
} comandos[] = {
	{"authors", 0},
	{"pid", 1},
	{"ppid", 2},
	{"cd", 3},
	{"date", 4},
	{"historic", 5},
	{"open", 6},
	{"close", 7},
	{"dup", 8},
	{"infosys", 9},
	{"help", 10},
	{"bye", 11},
	{"exit", 12},
	{"quit", 13},
	{NULL, -1}
};



static int obtain_code_command(char *partes_comando){
	const char *comando_codigo = partes_comando[1];
	int i;

	for(i = 0; comandos[i].comando != NULL; i++){
		if(!strcmp(comando_codigo, comandos[i].comando)){
			return i; 
		}
	}
	return -1; //CODIGO DE ERROR
}





void procesarEntrada(char comando[], char *partes_comando[]){
	//aqui es donde elegimos basicamente el comando a buscar

}

int leerEntrada(char comando[], char *partes_comando[]){
	
	fgets(comando, MAX_LEN, stdin);
	char *ini = comando, *fin = ini;
	int i = 0;
	int pivot = 0;
	//comprobamos primero si el comando se encuentra vacio;

	if(!strlen(comando)){
		return 0;
	}
	
	//hasta que no nos encontremos con null

	while(*fin){

		fin = strchr(comando + pivot, ' ');

		if(fin){
			*fin = '\0';
			partes_comando[i++] = ini;
			fin++;
			//comprobamos si hay mas espacios de por medio
			while(*fin == ' ') fin ++;
			ini = fin;
			pivot = fin - comando;
		}else{

			if(*ini == '\n') continue;

			//we finished to read the entry
			fin = ini;
			while(*(++fin));
			partes_comando[i] = ini;

		}

	}

	return 1;
}




void prompt(void){
	fprintf(stdout, "$>");
}