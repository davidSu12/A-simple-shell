#include "aux_func_main.h"
#include "commands.h"

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
	const char *comando_codigo = partes_comando[0];
	int i;

	for(i = 0; comandos[i].comando != NULL; i++){
		if(!strcmp(comando_codigo, comandos[i].comando)){
			return i; 
		}
	}
	return -1; //CODIGO DE ERROR
}





void procesarEntrada(char comando[], char *partes_comando[]){
	
	const char * command = partes_comando[0];
	int codigo_comando = obtain_code_command(command);
	

	switch(codigo_comando){
		//aqui es donde ejecutamos el comando
		case 0://authors
			authors(comando, partes_comando);
			break;
		case 1://pid
			pid();
			break;
		case 2://ppid
			ppid();
			break;
		case 3://cd
			cd(comando, partes_comando);
			break;
		case 4://date
			date_aux(comando, partes_comando);
			break;
		case 5://historic
			break;
		case 6://open
			break;
		case 7://close
			break;
		case 8://dup
			break;	
		case 9://infosys
			infosys();
			break;
		case 10://help
			help_cmd(comando, partes_comando);
			break;
		case 11:case 12:case 13: //quit
			quit(); 
			break;

	}

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