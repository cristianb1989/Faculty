#ifndef __TABELADISPERSIEINLANTUITA
#define __TABELADISPERSIEINLANTUITA
#include "listaInlantuita.h"

typedef struct tabelaDispersie{
	struct listaInlantuita *lista;
	int size;
	
};

void initializareTabelaDispersie(struct tabelaDispersie *tabela, int nr);

int inserareTabelaDispersie(struct tabelaDispersie *tabela, int element, int nr);

int cautareTabelaDispersie(struct tabelaDispersie *tabela, int element, int nr);

int stergereTabelaDispersie(struct tabelaDispersie *tabela, int element, int nr);


#endif