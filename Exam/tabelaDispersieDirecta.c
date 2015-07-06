#include "tabelaDispersieDirecta.h"

int hash(int element, int lungime){
	return element % lungime;
}

int calculateHashIndex(int element, int index, int lungime){
	return (hash(element, lungime) + index) % lungime;
}

void initializareTabelaDispersie(int tabela[], int nr){
	int index;
	for (index = 0; index< nr; index++){
		tabela[index] = -1;
	};
}

int inserareElementTabelaDispersie(int tabela[], int element, int lungime){
	int i, hashIndex;
	i=0;
	do {
		hashIndex = calculateHashIndex(element, i, lungime);
		if (tabela[hashIndex] == -1){
			tabela[hashIndex] = element;
			return hashIndex;
		} else{
			i++;
		}
	
	}while (i != lungime);
	return -1;

}

int cautareElementTabelaDispersie(int tabela[], int element, int lungime){
	int i, hashIndex;
	i=0;
	do {
		hashIndex = calculateHashIndex(element, i, lungime);
		if (tabela[hashIndex] == element){
			
			return hashIndex;
		} else{
			i++;
		}
	
	}while (tabela[hashIndex] != -1 && i != lungime);
	return -1;

}


int stergereElementTabelaDispersie(int tabela[], int element, int lungime){
	int hashIndex = cautareElementTabelaDispersie(tabela, element, lungime);
	if (hashIndex > -1){
		tabela[hashIndex] = -1;
		return hashIndex;
	}else{
		return -1;
	}


}