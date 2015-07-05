#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(t_stack *initStack){
	
	if (initStack->top >= 0){
		return 1;
	} else{
		return 0;
	}
}

void init (t_stack *initStack, int size){
	initStack->data = (int*)malloc(size*sizeof(int));
	initStack->top=-1;
}

void push(t_stack *initStack, int element){
	initStack->top = initStack->top +1;
	initStack->data[initStack->top] = element;
}

int pop(t_stack *initStack){
	int element = initStack->data[initStack->top];
	initStack->top = (initStack->top - 1);
	return element;
}