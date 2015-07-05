#include<stdio.h>
#include<limits.h>
#include "array_io.h"
#include "merge_sort.h"

void main()
{	

	int n;
	
	int arrayMergeInsertionSort[20];
	
	printf("n= ");
	scanf("%d", &n);

	read_array(arrayMergeInsertionSort, n);
	
	mergeSort(arrayMergeInsertionSort, 0, n);

	printf("\n Sirul sortat este:\n");
	 
    print_array(arrayMergeInsertionSort, n);

	printf("\n");
 
}