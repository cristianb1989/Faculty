#include <stdio.h>
#include "array_io.h"

	void read_array(int A[], int N){
		int i=0;
		for (i = 0;i<N; i++)
		{
			printf("Elementul %d din array este: ", i);
			scanf("%d", &A[i]);
		}
	}
	void print_array(int A[], int N){
			int i=0;
		for (i = 0; i<N; i++)
		{
			printf("Vector[%d]=%d \n" ,i , A[i]);
		}
	}