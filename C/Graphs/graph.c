#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "linkedListGraphNode.h"


void initGraph(struct graph *graful, int numarNoduri){
	printf("position %d: ", numarNoduri);
	graful->nodes = (struct graphNode*) malloc(numarNoduri * sizeof(struct graphNode));
	graful->nr = numarNoduri;
}

void insertVecin(struct graph *graful, int position, struct graphNode *vecin){
	insertNeighbour(&graful->nodes[position].neighbours, vecin);
}
void createNewNode(struct graph *graful, int position, int data){
	struct linkedListGraph *vecini = (struct linkedListGraph*) malloc(sizeof(struct linkedListGraph));
	initNeighboursList(&vecini);
	//newNode->neighbours =  &vecini;
	//newNode->data = data;
	//newNode->visited = 0;
	//printf("position %d : " + position);
	graful->nodes[0].data = data;
	graful->nodes[0].neighbours = &vecini;
	graful->nodes[0].visited = 0;
}

void breadthFirstSearch(struct graph *graful, int startingPosition){
	 
		
	
}

void depthFirstSearch(struct graph *graful, int staringPosition){
	struct graph *stack;
	struct graphNode *nodeStack;
	struct linkedListGraph *neighbours;
	struct linkedListGraphNode *first;
	int topOfStack = 0;
	stack->nodes  = (struct graphNode*) malloc(graful->nr * sizeof(struct graphNode));
	stack[topOfStack].nodes = graful[staringPosition].nodes;
	while (topOfStack >=0){
		nodeStack = stack[topOfStack--].nodes;
		//not visited
		if (nodeStack->visited == 0){
			printf("Node discovered %d: /n", nodeStack->data);
			nodeStack->visited = 1;
		};
		neighbours = nodeStack->neighbours;
		first = neighbours->head;
		while(first != NULL){
			// the neighbour was not visited push it to the stack
			if (first->dataNode->visited == 0){
				stack[++topOfStack].nodes = first->dataNode->neighbours;
			};
			first = first->next;
		}
		
	}



}