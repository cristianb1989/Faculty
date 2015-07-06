#include "tabelaDispersieInlantuita.h"
#include "listaInlantuita.h"
#include <stdlib.h>
#include <stdio.h>



int main(){
	printf("HELLO WORLD");
}

int hashFunction(int element, int lungime){
	return element % lungime;
};

void initializareTabelaDispersie(struct tabelaDispersie *tabela, int nr){
	int index;
	tabela->lista = (struct listaInlantuita*)(nr * sizeof(struct listaInlantuita));
	for (index = 0; index< nr; index++){
		initializareListaInlantuita(&tabela->lista[index]);
	}

}

int inserareTabelaDispersie(struct tabelaDispersie *tabela, int element, int nr){
	int hash = hashFunction (element, nr);
	inserareElementListaInlantuita(&tabela->lista[hash], element);
	return hash;
}

int cautareTabelaDispersie(struct tabelaDispersie *tabela, int element, int nr){
	struct listaNod *nod = cautaElementListaInlantuita(&tabela->lista[hashFunction (element, nr)], element);
	if (nod){
		printf("Elementul %d a fost gasit pe pozitia %d\n", nod->valoare, hashFunction (element, nr));
			return hashFunction(element, nr);
	}else{
		printf("Elementul %d a fost gasit\n", element);
		return -1;
	}

};

int stergereTabelaDispersie(struct tabelaDispersie *tabela, int element, int nr){
	int hash = hashFunction (element, nr);
	stergereElementListaInlantuita(&tabela->lista[hash], element);
	return hashFunction(element, nr);

}