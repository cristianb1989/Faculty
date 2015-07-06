#ifndef __STACK
#define __STACK

typedef struct stack {
	int *data;
	int top; 
	
} t_stack;

int isEmpty(t_stack *initStack);

void init(t_stack *initStack, int size);

void push(t_stack *initStack, int element);

int pop(t_stack *initStack);

#endif
