#include "stack.h"
#include "queue.h"
#include "collections_io.h"
#include <stdio.h>
#include <stdlib.h>


void main(){
		char selectie = 0;
		int k;
		int z;
		int dimensiuneArray = 15;
		t_stack stackArray;
		t_queue queueArray; 
		init(&stackArray, dimensiuneArray);

		while (selectie != 'x')
		{
			printf("\n");
			printf("1 pentru inserare in stiva\n");
			printf("2 pentru stergere din stiva\n");
			printf("3 pentru afisarea stivei\n");
			printf("x pentru iesire din program\n");
			printf("introduceti optiunea dvs: "); scanf("%c", &selectie);
		switch (selectie)
			{
			case '1':
				printf("introduceti cheia care se insereaza: "); scanf("%d", &k);
				push(&stackArray, k);
				print(stackArray.data, stackArray.top + 1);
			break;
			case '2':
				printf("Elementul pop-uit este %d: ", 	pop(&stackArray));
			
				print(stackArray.data, stackArray.top + 1);
				
			break;
			case '4':
				print(stackArray.data, stackArray.top + 1 );
				break;
			}
		}

		selectie = 0;
	
		dimensiuneArray = 15;
	
		initQueue(&queueArray, dimensiuneArray);

		while (selectie != 'x')
		{
			printf("\n");
			printf("1 pentru inserare in coada\n");
			printf("2 pentru stergere din coada\n");
			printf("3 pentru afisarea cozii\n");
			printf("x pentru iesire din program\n");
			printf("introduceti optiunea dvs: "); scanf("%c", &selectie);
		switch (selectie)
			{
			case '1':
				printf("introduceti cheia care se insereaza: "); scanf("%d", &k);
				enqueue(&queueArray, k);
				printQueue(queueArray.data, queueArray.head, queueArray.tail);
			break;
			case '2':
				printf("Elementul scos din coada este %d: ", dequeue(&queueArray));
			
					printQueue(queueArray.data, queueArray.head, queueArray.tail);
				
			break;
			case '4':
				printQueue(queueArray.data, queueArray.head, queueArray.tail);
				break;
			}
		}
	
}