#include "listainlantuita.h"
#include <stdlib.h>
#include <stdio.h>

void makenull(t_lista *lista)
{
	lista->head = (t_nod_lista*)malloc(sizeof(t_nod_lista));
	lista->head->next =  NULL;
}

t_nod_lista* search_linkedlist(t_lista *lista, int k)
{
	t_nod_lista* x = lista->head;
	while (x && (x->cheie != k))
	{
		x = x->next;
	}

	printf("%d ", x->cheie);

	return x;
}
void insert_linkedlist(t_lista *lista, t_nod_lista *x)
{
	if (x == NULL) return;
	//first element to be added
	if (lista->head->next == NULL){
		lista->tail = (t_nod_lista*)malloc(sizeof(t_nod_lista));
		lista->head->next = lista->tail = x;
	} else{
	    lista->tail->next = x;
		lista->tail= x;
	}
}
void delete_linkedlist(t_lista *lista, t_nod_lista *x)
{
	t_nod_lista* y = lista->head;
	while (y && (&y->next!=&x))
	{
		y = y->next;
	}
	if ((y != lista->head) || (y != NULL)) {
       y->next = x->next;
	   free(x);
	}

}
void print_linkedlist(t_lista *lista)
{
	t_nod_lista *x = lista->head->next;
	if (x == NULL)
	printf("lista vida\n");
	while (x)
	{
		printf("%d ", x->cheie);
		x = x->next;
	}
}
void free_linkedlist(t_lista *lista)
{
	t_nod_lista *x = lista->head->next;
	while (x)
	{
	delete_linkedlist(lista, x);
	free(x);
	x = lista->head->next;
	}
	free (lista->head);
}


t_nod_lista* next_linkedlist(t_lista *lista, t_nod_lista *x)
{
	
 return x->next; 
}

t_nod_lista* previous_linkedlist(t_lista *lista, t_nod_lista *x){
	t_nod_lista* previous = lista->head;
	while (previous && (previous->next != x))
	{
		previous = previous->next;
	}
	
	return previous;
  
}

t_nod_lista* first_linkedlist(t_lista *lista){


	t_nod_lista* x = lista->head;

	return x = x->next;
	
}

