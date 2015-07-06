#include "hashtable.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int hashFunction(int k, int size){
	int hash = k % size;
	printf("Hash pentru k %d si marimea size %d este %d\n", k, size, hash);
	return hash;
};

void init_hashTable(t_hashTable *table, int size){
	int start = 0;
	table->lista = (t_lista*)malloc(size * sizeof(t_lista));
	table->size = size;
	for(start = 0; start< size; start++){
		makenull(&table->lista[start]);
	};

};

int chained_hashInsert(t_hashTable *table, int key){
	int h; 
	t_nod_lista *nod = (t_nod_lista*) malloc(sizeof(t_nod_lista)) ;
	nod->cheie = key;
	h = hashFunction(key, table->size);
	list_insert(&table->lista[h], nod);
	return h;

};

int search_hashTable(t_hashTable *table, int key){
	int h;
	t_nod_lista *nod;
	h = hashFunction(key, table->size);
	nod = list_search(table->lista[h], key);
	if (nod){
		printf("Elementul a fost gasit pe pozitia %d\n", h);
		return h;
	}else{
		printf("Elementul %d nu a fost gasit\n", key);
		return -1;
	};
	
};

int chained_hashDelete(t_hashTable *table, int key){
	int h;
	t_nod_lista *nod;
	h = hashFunction(key, table->size);
	nod = list_search(table->lista[h], key);
	if (nod){
		printf("Elementul a fost gasit pe pozitia %d\n", h);
		list_delete(&table->lista[h], nod);
		printf("Elementul a fost %d sters\n", key);
		return h;
	}else{
		printf("Elementul %d nu a fost gasit\n", key);
		return -1;
	};
 
};



void printHashTableDispersie(t_hashTable *table){
	int i=0;
	printf("Elementele hashTablelului sunt\n:");
	for (i=0; i<table->size;i++){
		if (table->lista[i].head->next != NULL){
			printf("Elementul [%d] este \n", i);
			list_print(table->lista[i]);
		}
	};
};

