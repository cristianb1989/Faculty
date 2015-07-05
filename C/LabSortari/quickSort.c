#include "quickSort.h"
#include "util.h"
#include <stdio.h>


int getPivotBasedOnLeft(int A[], int begin, int end){
	int pivotPosition = begin;
	int pivot = A[pivotPosition];
	int start;
	for (start = pivotPosition + 1; start <= end; start ++){
		if (A[start] < pivot){
			pivotPosition = pivotPosition + 1;
			swap(start, pivotPosition, A);

		}
	};
   swap(pivotPosition, begin, A);
   pivotPosition = pivotPosition + 1;
   return pivotPosition;

}

void quickSort(int A[], int begin , int end){
	if (begin < end){
		int pivot = getPivotBasedOnLeft(A, begin , end);
		quickSort(A, begin, pivot -1);
		quickSort(A, pivot + 1, end);
	}

}

