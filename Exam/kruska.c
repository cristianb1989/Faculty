#include "krusca.h"
#include <stdlib.h>
#include <stdio.h>
void kruskalSpanningTree(int matrix[5][5], int startingPosition, int numberOfNodes){
	int *visited = (int*)malloc(numberOfNodes * sizeof(int));
	int startNode,  temp1,  temp2,  endNode,  noOfEdges,  row,  column,  min, total;
	for (row = 0; row < numberOfNodes; row++){
		visited[row]=0;
	};
	min = MAX;
	noOfEdges = 1;
	while(noOfEdges < numberOfNodes){
		for( row = 0; row< numberOfNodes; row++){
			for (column = 0 ; column < numberOfNodes; column++){
				if ( matrix[row][column] < min){
					startNode = row;
					endNode = column;
					min = matrix[row][column];
				};
			};
		};
		temp1 = startNode;
		temp2 = endNode;
		while(visited[startNode] !=0){
			startNode = visited[startNode] ;

		};
		while(visited[endNode] !=0){
			endNode = visited[endNode] ;

		};
		
		if(startNode != endNode){
			visited[endNode] = startNode;
			noOfEdges++;
			printf("Edge found from %d to %d with cost %d\n", startNode, endNode, min);
			total+=min;
			matrix[startNode][endNode] = matrix[endNode][startNode] = 999;

		}else{
			matrix[temp1][temp2] = matrix[temp2][temp1] = 999;
		
		}
	};

	printf("total este %d\n", total);

}