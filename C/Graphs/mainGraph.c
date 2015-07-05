#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "linkedListGraphNode.h"

void main(){
	int N = 5;
	struct graph *graful;
	struct linkedListGraph *vecini;
	struct graphNode *nod1 = (struct graphNode*) malloc(sizeof(struct graphNode));
	struct graphNode *nod2 = (struct graphNode*) malloc(sizeof(struct graphNode));
	struct graphNode *nod3= (struct graphNode*) malloc(sizeof(struct graphNode));
	struct graphNode *nod4= (struct graphNode*) malloc(sizeof(struct graphNode));
	struct graphNode *nod5= (struct graphNode*) malloc(sizeof(struct graphNode));
	initGraph(&graful, N);
	
	vecini = (struct linkedListGraph*) malloc(sizeof(struct linkedListGraph));
	initNeighboursList(&vecini);

	graful->nodes[0].data = 1;
	graful->nodes[0].neighbours = &vecini;
	graful->nodes[0].visited = 0;
	vecini = (struct linkedListGraph*) malloc(sizeof(struct linkedListGraph));
	initNeighboursList(&vecini);

	graful->nodes[1].data = 2;
	graful->nodes[1].neighbours = &vecini;
	graful->nodes[1].visited = 0;
	vecini = (struct linkedListGraph*) malloc(sizeof(struct linkedListGraph));
	graful->nodes[2].data = 3;
	graful->nodes[2].neighbours = &vecini;
	graful->nodes[2].visited = 0;
	vecini = (struct linkedListGraph*) malloc(sizeof(struct linkedListGraph));
	initNeighboursList(&vecini);
	graful->nodes[3].data = 4;
	graful->nodes[3].neighbours = &vecini;
	graful->nodes[3].visited = 0;
	vecini = (struct linkedListGraph*) malloc(sizeof(struct linkedListGraph));
	initNeighboursList(&vecini);;
	graful->nodes[4].data = 6;
	graful->nodes[4].neighbours = &vecini;
	graful->nodes[4].visited = 0;

	 //createNewNode(&graful, &nod1, 0, 1);
	 //createNewNode(&graful, &nod2, 1, 2);
	 //createNewNode(&graful, &nod3, 2, 3);
	 //createNewNode(&graful, &nod4, 3, 4);
	 //createNewNode(&graful, &nod5, 4, 6);
	//insertVecin(&graful, 0, &nod2);
	insertVecin(&graful, 0, &nod3);
	insertVecin(&graful, 1, &nod1);
	insertVecin(&graful, 1, &nod3);
	insertVecin(&graful, 2, &nod1);
	insertVecin(&graful, 2, &nod2);
	insertVecin(&graful, 2, &nod4);
	insertVecin(&graful, 2, &nod5);
	insertVecin(&graful, 3, &nod3);
	insertVecin(&graful, 4, &nod3);
	depthFirstSearch(&graful, 0);

}