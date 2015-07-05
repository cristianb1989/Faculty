#include <stdio.h>
#include "heap_sort.h"
#include "util.h"


int left(int position){
  return (2 * position + 1); 
}

int right(int position){
	return (2 * position + 2);
}

void max_heapify(int A[], int current, int heapSize){
	int largest = current;
	int l = left(current);
	int r = right(current);
	if (l<= heapSize && A[l] > A[largest]){
		largest = l;
	}else{
		largest = current;
	}
	if (r<= heapSize && A[r] > A [largest]){
		largest = r;
	}
	
	if (largest != current){
		swap(largest, current, A);
		max_heapify(A, largest , heapSize);
	}

}

void build_max_heap(int A[], int N, int *heapSize){
	int i;
	*heapSize = N - 1;
	for (i = N/2; i>=0; i--){
      max_heapify(A, i, *heapSize);
	}
	
}

void heapSort(int A[], int N, int *heapSize){
	int  i;
	build_max_heap(A,N, heapSize);
	
	for(i= N - 1; i> 0 ; i --){
		swap(0, i, A);
		*heapSize = *heapSize - 1;
		printf("heapSize %d", *heapSize);
		max_heapify(A, 0, *heapSize);
	}
}