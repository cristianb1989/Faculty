#ifndef __QUEUEC
#define __QUEUEC

typedef struct queueType{
	int  *data;
	int tail;
	int head;
}t_queue;

void initQueue(t_queue *initQueue, int size);

void enqueue(t_queue *theQueue, int element);

int dequeue(t_queue *theQueue);

#endif