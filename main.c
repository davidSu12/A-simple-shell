#include "libmain.h"
#include "historicList.h"
#include "firstlib.h"
#include "fileList.h"
#include "aux_func_main.h"



#define INIT_SHELL

int main(int argc, char **argv){


	char comando[MAX_LEN] = {'\0'};
	char *partes_comando[MAX_ARG] = {NULL};

	bool terminado = false;
	int partes;

	createEmptyListHistoric();

	/*ya tengo el error*/
#ifdef DEBUG
	prompt();
	partes = leerEntrada(comando, partes_comando);
	procesarEntrada(comando, partes_comando);

#endif //DEBUG


#ifdef INIT_SHELL
	while(!terminado){
		prompt();
		partes = leerEntrada(comando, partes_comando);
		//procesamos la en
		procesarEntrada(comando, partes_comando);
		
	}
#endif //INIT_SHELL


#ifdef DEBUG_1
	if(partes){
		for(int i = 0; i < MAX_ARG && partes_comando[i] != NULL; i++){
			printf("EL : %s\n", partes_comando[i]);
		}
	}else{
		printf("Error");
	}
#endif //DEBUG

	return 0;
} //end_main
