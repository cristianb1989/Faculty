#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximum(int a, int b){
	if (a > b){
		return a;
	} else {
		return b;
	};
};

int cutRod(int p[], int  n){
	int i;
	int q;
	if (n == 0 ){
		return 0;	
	};
	
    q = INT_MIN;
	for (i=1; i < n; i++)
	{
		q = maximum(q, p[i] + cutRod(p, n - i));
	}
	return q;

}

