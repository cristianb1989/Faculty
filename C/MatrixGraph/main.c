#include <stdlib.h>
#include <stdio.h>
#include "djikstra.h"

static int MAX_VALUE = 999;

void main(){
	 int matrix[5][5]={/* first node*/ {MAX_VALUE, 20, 70, MAX_VALUE, 50},
        /* second node*/{20, MAX_VALUE, 15, 40, MAX_VALUE},
        /* third node*/ {10, 15, MAX_VALUE, 70, MAX_VALUE},
        /* fourth node*/{MAX_VALUE, 40, 70, MAX_VALUE, 16},
        /* fifth node*/ {50, MAX_VALUE, MAX_VALUE, 16, MAX_VALUE}
	 };
	dijkstraShortestPath(matrix, 0, 5);
		
}