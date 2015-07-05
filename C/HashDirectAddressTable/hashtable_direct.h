#ifndef __HASHTABLEDIRECT
#define __HASHTABLEDIRECT

typedef struct hashTableDirect{
	int *data;
	int size;
}hTable;



void init(hTable *hashT, int m);

int insert(hTable *hashT, int key);

int search(hTable *hashT, int key);

int removeFromHashTable(hTable *hashT, int key);

void printHashTable(hTable *hashT);

#endif