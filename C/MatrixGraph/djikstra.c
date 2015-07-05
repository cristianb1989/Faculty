#include "djikstra.h"
#include <stdio.h>
#include <stdlib.h>


void dijkstraShortestPath(int matrix[5][5], int startingPosition, int numberOfNodes){
	int *visited  =  (int *)malloc(numberOfNodes * sizeof(int));
	int *distance = (int *)malloc(numberOfNodes * sizeof(int));
	int *pathOfNode = (int *)malloc(numberOfNodes * sizeof(int));
	int row, column, minimum, nextNode, thePreviousNode;
	for (column =0; column < numberOfNodes; column++){
		visited[column]=0;
		pathOfNode[column]=0;
	}
	distance = matrix[startingPosition];
	distance[startingPosition]=0;
	visited[startingPosition]=1;
	minimum = 999;
	
	
	for (row = 0 ; row < numberOfNodes; row++){
		for (column = 0; column < numberOfNodes; column++){
			if (minimum > distance[column] && visited[column] == 0){
				minimum = distance[column];
				nextNode = column;
			}
		
		}
	  visited[nextNode] = 1;

	  for (column =0; column < numberOfNodes; column++){
		  if (visited[column] == 0){
			  if ((minimum + matrix[nextNode][column]) < distance[column]){
				distance[column] = minimum + matrix[nextNode][column];
				pathOfNode[column] = nextNode;
			  }
		
		  }
	  }

	}
	printf("Distances are:/n");
	for (column = 0; column < numberOfNodes; column++){
		printf("Distance from %d to %d is %d\n", startingPosition, column, distance[column]);

	}
    printf("Shortest paths are:/n");
	for (column = 0; column < numberOfNodes; column++){
		
		printf("Path for node: %d",  column);
		thePreviousNode = column;
		do {
			thePreviousNode = pathOfNode[thePreviousNode];
			 if (thePreviousNode == 0 && startingPosition != 0) {
                    //the starting node wasn't zero
                    printf(" <- %d", startingPosition);
               } else {
                    printf(" <- %d",  thePreviousNode);
               }
			
		}while(thePreviousNode != 0);
		printf("/n");
	}

	
}
