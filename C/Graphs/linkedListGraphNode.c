#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "linkedListGraphNode.h"
#include "graph.h"


void initNeighboursList(struct linkedListGraph *vecini){;
	vecini->head = (struct linkedListGraphNode*)malloc(sizeof(struct linkedListGraphNode));
	vecini->tail = (struct linkedListGraphNode*)malloc(sizeof(struct linkedListGraphNode));
	vecini->length = 0;
}

void insertNeighbour(struct linkedListGraph *lista, struct graphNode *neighbour){
	struct linkedListGraphNode *node= (struct linkedListGraphNode*)malloc(sizeof(struct linkedListGraphNode));
	struct linkedListGraphNode *temp = (struct linkedListGraphNode*)malloc(sizeof(struct linkedListGraphNode));;
	node ->dataNode = neighbour;

	//this is the first element
	if (lista->head == NULL){
		lista->head = node;
		
	//this is the second element
	}else if (lista->tail == NULL){
		lista->head->next = node;
		lista->tail = node;
		lista->tail->previous = lista->head;
	} else {
		temp = lista->tail;
		lista->tail->next = node;
		lista->tail= node;
		lista->tail->previous = temp;

	}
	lista->length = lista->length + 1;

}

