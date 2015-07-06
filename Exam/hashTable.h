#ifndef __HASHTABLE
#define __HASHTABLE
#include "lista.h"	

typedef struct hashTable{
	t_lista *lista;
	int size;
}t_hashTable;

void init_hashTable(t_hashTable *table, int size);

int chained_hashInsert(t_hashTable *table, int key);

int chained_hashDelete(t_hashTable *table, int key);

void printHashTableDispersie(t_hashTable *table);


int search_hashTable(t_hashTable *table, int key);

#endif