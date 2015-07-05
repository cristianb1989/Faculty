#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
#include "merge_sort.h"

static int THRESHOLD = 5;

void topDownMerge(int A[], int begin, int middle, int end, int *B){
	int i0 = begin;
	int i1 = middle;
	int j;
	for (j = begin; j< end; j++){
		  // If left run head exists and is <= existing right run head.
        if (i0 < middle && (i1 >= end || A[i0] <= A[i1]))
		{
            B[j] = A[i0];
            i0 = i0 + 1;
		} else {
            B[j] = A[i1];
            i1 = i1 + 1;
		}	
	};
}

void copyArray(int A[], int iBegin, int iEnd, int *B)
{
	int k;
    for(k = iBegin; k < iEnd; k++){
        A[k] = B[k];
	}
}
void topDownMergeSort(int A[], int *B, int begin, int end){
	if (end - begin >= 2){
		if (end - begin <= THRESHOLD){
			printf("Se executa insertion sort \n");
			insertionSort(A, begin, end);
		} else {
			int middle = (begin + end) / 2;
			topDownMergeSort(A, B, begin, middle);
			topDownMergeSort(A, B, middle, end);
			topDownMerge(A, begin, middle, end, B);
			copyArray(A, begin, end, B);

		}
	}
	
}
void mergeSort(int A[] , int begin, int end){
	int *backupArray = (int *)malloc(end*sizeof(int));
	topDownMergeSort(A, backupArray, begin, end);
};
