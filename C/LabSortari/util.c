#include "util.h"


void swap(int position, int i, int A[]){
  int tmp = A[i];
  A[i]= A[position];
  A[position] = tmp;
};