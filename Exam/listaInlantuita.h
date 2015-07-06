#ifndef __TABELADISPERSIEINLANTUITA
#define __TABELADISPERSIEINLANTUITA

typedef struct listaNod{
	int valoare;
	struct listaNod *next, *prev;
};

typedef struct listaInlantuita{
	
	struct listaNod *head, *tail;
};


void initializareListaInlantuita(struct listaInlantuita *lista);

void inserareElementListaInlantuita(struct listaInlantuita *lista, int element);

struct listaNod* cautaElementListaInlantuita(struct listaInlantuita *lista, int element);

void stergereElementListaInlantuita(struct listaInlantuita *lista, int element);

#endif