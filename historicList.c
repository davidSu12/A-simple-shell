#include "historicList.h"




static listaHistorico lista;

/*
void createEmptyList();
bool insertItem(const char * cadena);
void deleteItem(const char * cadena);
posHistorico searchItem(const char * cadena);
posHistorico next(posHistorico position);
posHIstorico previous(posHistorico position);
posHistorico first();
posHistorico last();
item * getItem(posHistorico position);
bool isEmptyList()
*/


item * getItem(posHistorico position){
	return position -> data;
}
posHistorico searchItem(const char * cadena){

	posHistorico temp;
	for(
		temp = lista;
	 	temp != LNULL && strcmp(temp -> data, cadena); 
	 	temp = temp -> next);
	return temp;
}
posHistorico first(){
	return lista;
}
posHistorico last(){
	posHistorico temp;
	if(isEmptyList()){
		return LNULL;
	}
	for(temp = lista; temp -> next != LNULL; temp = temp -> next);
	return temp;
}
posHistorico previous(posHistorico position){
	posHistorico temp;
	for(temp = lista; 
		temp != LNULL && temp -> next != position; 
		temp = temp -> next);
	return temp;
}

posHistorico next(posHistorico position){
	return position -> next;
}
void deleteItem(const char * cadena){
	posHistorico prev, curr;

	for(prev = LNULL, curr = lista; 
		(curr != LNULL) && strcmp(curr -> data, cadena); 
		prev = curr, curr = curr -> next);

	if(curr == LNULL){
		//el elemento no se encuentra en la lista
		return;
	}else if(prev == LNULL){
		lista = lista -> next;
	}else{
		prev -> next = curr -> next;
	}
	free(curr);
}

void deleteListHistoric(){

	//tenemos que considerar tambien cuando la lista tiene un unico elemento.

	posHistorico prev = lista, curr = prev -> next;
	
	if(isEmptyList()){
		return;
	}
	while(prev != LNULL){
		free(prev);
		prev = curr;
		if(curr == LNULL){
			break;
		}
		curr = curr -> next;
	}

	lista = LNULL;
}
void createEmptyListHistoric(){
	lista = LNULL;
}

bool isEmptyList(){
	return lista == LNULL; 
}


bool insertItem(const char * cadena, char *partes_cadena[]){

	posHistorico temp = malloc(sizeof(struct node));
	posHistorico i;


#ifdef DEBUG

	int a = 0;
	printf("Estoy aqui\n");
	while(partes_cadena[a] != NULL){
		printf("%s\n", partes_cadena[a]);
		a++;
	}
#endif	 

	if(temp){

		int j = 1;
		char *fin;
		const char *ini;
		int distance;

		memcpy(temp -> data, cadena, sizeof(char) * MAX_LEN);
		
		char * aux = temp -> data;
		
		ini = partes_cadena[0];
		temp -> data_parts[0] = temp -> data;



		while(fin != NULL){
			
				ini = partes_cadena[j-1];
				fin = partes_cadena[j];

				if(fin){
				
					distance = fin - ini;
					aux += distance;

					temp -> data_parts[j] = aux;

					j++;
				}

			}

		temp -> next = LNULL;

#ifdef DEBUG
		
		int b = 0;

		printf("Estoy en insertar elemento\n");

		while(temp -> data_parts[b] != LNULL){
			printf("%s\n", temp ->data_parts[b]);
			b++;
		}
#endif
	
		if(isEmptyList()){
			lista = temp;
		}else{
			for(i = lista; i -> next != LNULL; i = i -> next);
			i -> next = temp;
		}
		return true;

	
	}
	fprintf(stderr, "There is no more memory for historicList\n");
	fprintf(stderr, "Flushing historic list...\n");
	deleteListHistoric();
	return false;
}


static void imprimirPartesCadena(char *cadena_partes[]){

	int j = 0;
	while(cadena_partes[j] != NULL){
		printf("%s ", cadena_partes[j++]);
	}
	printf("\n");

}

void imprimirListaHistorico(int n){

	posHistorico temp = lista;
	int i = 0;

	/*
	si n = -1 imprimimos la lsita entera
	en otro caso imprimimos los n-esimos primeros
	*/
	if(isEmptyList()){
		return;
	}
	if(n == -1){

	
		for(;temp != LNULL; temp = temp -> next){
			printf("%d->",i++);
			imprimirPartesCadena(temp -> data_parts);
		}

	}else{
		for(;temp != LNULL && i <= n; temp = temp -> next){
			printf("%d->",i++);
			imprimirPartesCadena(temp -> data_parts);
		}
	}
}

posHistorico buscarN(int n){
	posHistorico temp = lista;
	int i = 0;

	for(;temp != LNULL && i<n; temp = temp -> next) i++;
	if(!temp){// n es mas grande que el tamaño total de la lista
		return NULL;
	}else{
		return temp;
	}

}
