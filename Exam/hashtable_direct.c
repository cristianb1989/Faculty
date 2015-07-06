#include "hashtable_direct.h"
#include <stdio.h>
#include <stdlib.h>

int hashPrim( int size , int key){
	return key%size;
};

int hashLinearProbe(int i, int key, int size){
	return (hashPrim(size, key) + i) % size;   
};

void init(hTable *hashT, int m){
	int i=0;
	hashT->data = (int*)malloc(m * sizeof(int));
	hashT->size = m;;
	for (i=0; i<hashT->size;i++){
		 hashT->data[i] = -1;
	};
}

int insert(hTable *hashT, int key){
	int i=0;
	do{
		int h = hashLinearProbe(i , key, hashT->size);
		if (hashT->data[h] == -1){
			hashT->data[h] = key;
			return h;
		}else {
			i = i+1;
		}

	}while(i < hashT->size);
	return -1;

}

int search(hTable *hashT, int key){
	int i=0;
	int h;
	do {
		h = hashLinearProbe(i , key, hashT->size);
		if (hashT->data[h] == key){
			return h;
		};
		i++;
	} while (i < hashT->size && hashT->data[h] != -1);

	return -1;
};

int removeFromHashTable(hTable *hashT, int key)
{
 int h = search(hashT, key);
 if (h > -1){
	hashT->data[h] = -1;
	return h;
 }else{
	return -1;
 }
};

void printHashTable(hTable *hashT){
	int i=0;
	printf("Elementele hashTablelului sunt");
	for (i=0; i<hashT->size;i++){
		printf("Elementul [%d] este %d\n", i, hashT->data[i]);
	}
};