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

bool insertItem(const char * cadena, const char * partes_cadena[]){

	posHistorico temp = malloc(sizeof(struct node));
	posHistorico i;
	if(temp){
		strcpy(temp -> data, cadena);
		memcpy(temp -> data_parts, partes_cadena, sizeof(temp -> data_parts));
		temp -> next = LNULL;

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

void imprimirListaHistorico(int n){

	posHistorico temp = lista;
	int i = 0;

	/*
	si n = -1 imprimimos la lsita entera
	en otro caso imprimimos los n-esimos primeros
	*/

	if(n == -1){
		for(;temp != LNULL; temp = temp -> next){
			printf("%d->%s\n",++i,temp->data);
		}
	}else{
		for(;temp != LNULL && i <= n; temp = temp -> next){
			printf("%d->%s\n",++i, temp->data);
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
