#ifndef __GRAPH
#define __GRAPH
#include "linkedListGraphNode.h"

typedef struct graphNode{
	int data;
	int visited;
	struct linkedListGraph *neighbours;
};


typedef struct graph{
	int nr;	
	struct graphNode *nodes;
};


void initGraph(struct graph *graful, int numarNoduri);

void insertVecin(struct graph *graful, int position, struct graphNode *vecin);

void createNewNode(struct graph *graful, struct graphNode *newNode, int position, int data);

void breadthFirstSearch(struct graph *graful, int startingPosition);

void depthFirstSearch(struct graph *graful, int startingPosition);

#endif