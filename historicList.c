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

void deleteListHistoric(){

	posHistorico prev = lista, curr = prev -> next;
	
	if(isEmptyList()){
		return;
	}
	while(curr != LNULL){
		free(prev);
		prev = curr;
		curr = curr -> next;
	}
}
void createEmptyList(){
	lista = LNULL;
}

bool isEmptyList(){
	return lista == LNULL; 
}

bool insertItem(const char * cadena){

	posHistorico temp = malloc(sizeof(struct node));
	posHistorico i;
	if(temp){
		strcpy(temp -> data, cadena);
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
