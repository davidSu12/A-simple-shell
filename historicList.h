#ifndef HISTORIC_LIST
#define HISTORIC_LIST

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef MAX_LEN
#define MAX_LEN 256
#endif

#define LNULL NULL


typedef char item;


struct node{
	item data[MAX_LEN];
	struct node * next;
};

typedef struct node * posHistorico;
typedef posHistorico listaHistorico;


void createEmptyListHistoric();
bool insertItem(const char * cadena);
void deleteItem(const char * cadena);
posHistorico searchItem(const char * cadena);
posHistorico next(posHistorico position);
posHistorico previous(posHistorico position);
posHistorico first();
posHistorico last();
item * getItem(posHistorico position);
bool isEmptyList();
void deleteListHistoric();



#endif //HISTORIC_LIST