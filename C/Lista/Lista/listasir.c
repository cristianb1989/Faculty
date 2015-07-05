#include "listasir.h"
#include <stdlib.h>
#include <stdio.h>


int size(t_lista_sir *sir)
{
	if (sir->data[0] == 0){
		return 0;
	}
	return sizeof(sir->data) / sizeof(sir->data[0]);
}


void init(t_lista_sir *sir, int size)
{
	sir->data = (int *)malloc(size*sizeof(int));
	sir->top=0;
};

int search_arraylist(t_lista_sir *sir, int key){
	int start=0;
	int length = sir->top;

	while((start <= length)){
		if (sir->data[start] == key){
			return start;	
		}
		start = start + 1;	
	}
	if (start <= length){
		return start;
	}else{
		return -1;
	}

}

void insert_arraylist(t_lista_sir *sir, int key){
	sir->data[sir->top] = key;
	sir->top = sir->top + 1;

}

void delete_arraylist(t_lista_sir *sir, int position){
	int start;
	int begin=0;
	int* newArray = (int *)malloc((sir->top - 1)*sizeof(int));
	for(start=0; start<= sir->top; start++){
		if (start != position){
			newArray[begin] = sir->data[start];
			begin=begin+1;
		}
	}
	sir->top = sir->top - 1;
		
	for(start=0; start<= sir->top; start++){
		sir->data[start] = newArray[start];		
	};

}


void free_arraylist(t_lista_sir *sir){
	free(sir->data);
	sir->data = NULL;
	sir->top=0;
}

void print_arraylist(t_lista_sir *sir){
	int i;
	printf("\n Lista: \n");
	for (i = 0; i< sir->top;i++)
	{
		printf("%d ", sir->data[i]);
	}
}


