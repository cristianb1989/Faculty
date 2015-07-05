#include "collections_io.h"
#include <stdio.h>

void print(int *data, int size){
	int i;
	printf("Colectia este de dimensiunea %d: \n", size);
	for (i = 0; i < size; i++){
		printf("Elementul %d: %d \n", i, data[i]);
	}
};

void printQueue(int *data, int head,  int tail){
	int i;
	printf("Colectia este de dimensiunea %d: \n", tail - head);
	for (i = head; i < tail; i++){
		printf("Elementul %d: %d \n", i, data[i]);
	}
}