#include <stdio.h>
#include "activitySelector.h"

int recursiveActivitySelector(int S[], int F[], int i, int j, int A[]){
	int start = i + 1;
	static int k = 0;
	while (start < j && S[start] < F[i]){
		start++;
	}
	if (start < j ){
		A[k] = start;
		k++;
		recursiveActivitySelector(S, F, start, j, A);
	}
	return k;

}

int greedyActivitySelector(int S[], int F[], int length, int A[]){
	int m;
	int n = length, i=0, k=0;
	for (m=1; m < n; m++){
		if (S[m] >= F[i]){
			A[k] = m;
			k++;
			i = m;
		}
	}

 return k;

}