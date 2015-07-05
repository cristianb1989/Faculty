#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initQueue(t_queue *initQueue, int size){
	initQueue->data = (int*)malloc(size * sizeof(int));
	initQueue->tail = -1;
	initQueue->head = -1;
}

void enqueue(t_queue *theQueue, int element)
{
	if (theQueue->tail == -1){
		theQueue->tail = (theQueue->tail + 1);
		theQueue->head = (theQueue->head + 1);
		theQueue->data[theQueue->head] = element;
	}

	theQueue->data[theQueue->tail] = element;
	theQueue->tail = (theQueue->tail + 1);
}

int dequeue(t_queue *theQueue)
{	
	int element;
	if ((theQueue->head >= 0) && (theQueue->head >= theQueue->tail)){
		return -1;
	}
	element = theQueue->data[theQueue->head];
	theQueue->head = (theQueue->head + 1);
	return element;

}