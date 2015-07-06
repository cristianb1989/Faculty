#include <stdio.h>
#include "selection_sort.h"
#include "util.h"


int getMinimumPosition(int start, int A[], int n){
	int minimum = start;
	int i;
	for (i = start + 1; i < n; i++){
		if (A[i] < A[minimum] ){
			minimum = i;	
		}
	};
	return minimum;
};



void selectionSort(int A[], int n){
	int i;
	for(i = 0; i < n; i++){
		
		int position = getMinimumPosition(i, A, n);
	    swap( position, i ,A);
	}
};
