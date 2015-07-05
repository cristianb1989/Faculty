#ifndef __LISTASIR
#define __LISTASIR

typedef struct lista_sir{
	int top;
	int* data;
}t_lista_sir ;


void init(t_lista_sir *sir, int size);

int search_arraylist(t_lista_sir *sir, int key);

void insert_arraylist(t_lista_sir *sir, int key);

void delete_arraylist(t_lista_sir *sir, int position);

void free_arraylist(t_lista_sir *sir);

void print_arraylist(t_lista_sir *sir);

#endif