#include<stdio.h>
#include<limits.h>
#include "array_io.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "quickSort.h"

void main()
{	

	int n;
	
	int selectionArraySort[20];

	int hSort = 0;
    int m;
	int heapArraySort[20];
	int quickSortArray[20];

	
	printf("n= ");
	scanf("%d", &n);

	read_array(selectionArraySort, n);
	
	selectionSort(selectionArraySort, n);
	printf("\n Sirul sortat cu selection sort este:\n");
	 
    print_array(selectionArraySort, n);

	printf("\n");

	printf("m= ");
	scanf("%d", &m);

	read_array(heapArraySort, m);
	
    heapSort(heapArraySort, m, &hSort);

	printf("\n Sirul sortat cu heap sort este:\n");
	 
    print_array(heapArraySort, m);

	printf("\n");

	printf("n= ");
	scanf("%d", &n);

	read_array(quickSortArray, n);
	
	quickSort(quickSortArray, 0 ,  n-1);

	printf("\n Sirul sortat cu quick sort este:\n");
	 
    print_array(quickSortArray, n);

	printf("\n");
 
}