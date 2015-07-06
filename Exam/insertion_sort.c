#include <stdio.h>
#include "insertion_sort.h"

void insertionSort(int A[], int left, int right){
	int i;
	for(i = left; i < right; i++){
		int j=i-1;
		int current = A[i];
		while(j >= 0 && A[j] > current){
			A[j+1] = A[j];
			j= j - 1;
		};

		A[j+1] = current;
	}


}