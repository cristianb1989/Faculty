#include <stdlib.h>
#include <stdio.h>
#include "listaInlantuita.h"



void initializareListaInlantuita(struct listaInlantuita *lista){
	lista->head = (struct listaNod*)malloc(sizeof(struct listaNod));
	lista->tail = (struct listaNod*)malloc(sizeof(struct listaNod));
};

void inserareElementListaInlantuita(struct listaInlantuita *lista, int element){
	struct listaNod *noulNod = (struct listaNod*)malloc(sizeof(struct listaNod));
	noulNod->valoare = element;
	if (lista->head == NULL){
		lista->head = noulNod;
	}else if (lista->tail == NULL){
		lista->tail = noulNod;
		lista->tail->prev = lista->head;
		lista->head->next = lista->tail;
	}else{
		noulNod->prev = lista->tail;
		lista->tail->next = noulNod;
		lista->tail = lista->tail->next;
	};

};

struct listaNod* cautaElementListaInlantuita(struct listaInlantuita *lista, int element){
	struct listaNod *start = lista->head;
	while (start != NULL){
		if (start->valoare == element){
			return start;
		}
		start = start->next;
	}
	return NULL;
};


void stergereElementListaInlantuita(struct listaInlantuita *lista, int element){
	struct listaNod *elementSters = cautaElementListaInlantuita(lista, element);
	if (elementSters == NULL){
		return;
	}else if (elementSters->prev == NULL){
		elementSters = elementSters->next;
		elementSters->prev = NULL;
		free(elementSters);
	}else if (elementSters->next == NULL){
		elementSters = elementSters->prev;
		elementSters  ->next = NULL;
		free(elementSters);
	}else{
		elementSters->prev->next = elementSters->next;
		elementSters->next->prev = elementSters->prev;
		free(elementSters);
	}

}