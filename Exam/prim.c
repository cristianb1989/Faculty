#include <stdlib.h>
#include <stdio.h>
#include "prim.h"




void primSpanningTree(int matrix[5][5], int startingPosition, int numberOfNodes){
	int MAX_VALUE = 999;
	int *visited = (int*)malloc(numberOfNodes * sizeof(int));
	int startNode, endNode, min, row, column, noOfEdges, total;
	total = 0;
	noOfEdges = 1;
	min = MAX_VALUE;
	for (row = 0 ; row < numberOfNodes; row++){
		visited[row] = 0;
	};
	visited[startingPosition] = 1;
	while (noOfEdges < numberOfNodes){
			min = MAX_VALUE;
		for (row = 0; row < numberOfNodes; row++){
			if (visited[row] == 0){
				for (column = 0; column < numberOfNodes; column++){
					if (visited[column]==0 && matrix[row][column] < min){
						startNode = row;
						endNode = column;
						min = matrix[row][column];
					}
				}

		};
	
	}

			visited[endNode] = 1;
		printf("Found edge from %d to %d with cost %d \n", (startNode + 1), (endNode + 1), min);
		total+=min;
		noOfEdges++;
	}
	printf("Shortest path is %d\n", total);
}