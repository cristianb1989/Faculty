#include <stdlib.h>
#include <stdio.h>

void printSolution(int matrix[4][4], int length){
	int column,  row;

	for (row = 0 ; row< length; row++){
		for (column = 0; column < length; column++){
			printf(" %d", matrix[row][column]);
		}
		printf("\n");
	};

	printf("\n");

}

int isValid(int matrix[4][4], int column, int row, int length){
	int r,c;
	for (c = 0; c < column; c++){
		if(matrix[row][c] == 1){
			return 0;
		}
	};
	//topleft
	for (c = column, r = row; c >= 0, r >= 0; r--, c--){
		if (matrix[r][c] == 1){
			return 0;
		}
		
	};
	
	//bottomleft
	for (c = column, r = row; r < length, c>=0; c--, r++){
			if (matrix[r][c] == 1){
			return 0;
		}
	};
	return 1;


};


void quuenSolver(int matrix[4][4], int column, int length, int *solutionNumber){
	int row;
	if (column >= length){
		solutionNumber++;
		printf("\n");
		printSolution(matrix, length);

	}
	
	for (row = 0; row < length; row++){
		if (isValid(matrix, column, row, length) == 1){
			matrix[row][column] = 1;
			quuenSolver(matrix, column + 1, length, solutionNumber);
			matrix[row][column] = 0;

		}
	}

}