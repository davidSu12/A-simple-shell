#ifndef HISTORIC_LIST
#define HISTORIC_LIST

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef MAX_LEN
#define MAX_LEN 256
#endif
#ifndef MAX_ARG
#define MAX_ARG 32
#endif


#define LNULL NULL


typedef char item;


struct node{
	item data[MAX_LEN];
	item * data_parts[MAX_ARG]; 
	struct node * next;
};

typedef struct node * posHistorico;
typedef posHistorico listaHistorico;


void createEmptyListHistoric();
bool insertItem(const char * cadena, const char * partes_cadena[]);
void deleteItem(const char * cadena);
posHistorico searchItem(const char * cadena);
posHistorico next(posHistorico position);
posHistorico previous(posHistorico position);
posHistorico first();
posHistorico last();
item * getItem(posHistorico position);
bool isEmptyList();
void deleteListHistoric();
void imprimirListaHistorico(int n);
posHistorico buscarN(int n);


	/*

	debug messages
	
	createEmptyListHistoric();
	assert(isEmptyList());
	insertItem("hola que tal");
	insertItem("vale");
	posHistorico m = first();
	posHistorico l = next(m);
	printf("%s", l->data);
	deleteListHistoric();
	assert(isEmptyList());
	*/
	

#endif //HISTORIC_LIST