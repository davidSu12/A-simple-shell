#include "libmain.h"
#include "historicList.h"



#define MAX_LEN 256
#define MAX_ARG 32

void prompt(void);
int leerEntrada(char comando[], char *partes_comando[]);

int main(int argc, char **argv){


	char comando[MAX_LEN];
	char *partes_comando[MAX_ARG] = {NULL};

	bool terminado;
	int partes;

	createEmptyListHistoric();
	assert(isEmptyList());
	insertItem("hola que tal");
	insertItem("vale");
	posHistorico m = first();
	posHistorico l = next(m);
	printf("%s", l->data);
	deleteListHistoric();
	assert(isEmptyList());
	
#ifdef INIT_SHELL
	while(!terminado){
		prompt();
		partes = leerEntrada(comando, partes_comando);
		//procesamos la en
		proces
		
	}
#endif //INIT_SHELL
	
	

#ifdef DEBUG
	if(partes){
		for(int i = 0; i < MAX_ARG && partes_comando[i] != NULL; i++){
			printf("EL : %s\n", partes_comando[i]);
		}
	}else{
		printf("Error");
	}
#endif //DEBUG

	return 0;
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