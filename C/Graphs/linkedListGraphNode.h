#ifndef __LINKEDLISTGRAPHNODE
#define __LINKEDLISTGRAPHNODE
#include "graph.h"


typedef struct linkedListGraph{
	int length;
	struct linkedListGraphNode *head;
	struct linkedListGraphNode *tail;
};

typedef struct linkedListGraphNode{
	struct graphNode *dataNode;
	struct linkedListGraphNode *next;
	struct linkedListGraphNode *previous;

};

void initNeighboursList(struct linkedListGraph *vecini);

void insertNeighbour(struct linkedListGraph *lista, struct graphNode *neighbour);


#endif