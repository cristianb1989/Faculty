#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
void makenull(t_lista *lista)
{
	lista->head = (t_nod_lista*)malloc(sizeof(t_nod_lista));
	lista->head->next = lista->head->prev = NULL;
}
t_nod_lista* list_search(t_lista lista, int k)
{
	t_nod_lista* x = lista.head;
	while (x && (x->cheie!=k))
	x = x->next;
	return x;
}
void list_insert(t_lista *lista, t_nod_lista *x)
{
	if (x == NULL) return;
	x->next = lista->head->next;
	if (lista->head->next != NULL)
	lista->head->next->prev = x;
	lista->head->next = x;
	x->prev = lista->head;
}
void list_delete(t_lista *lista, t_nod_lista *x)
{
	if (x->prev != NULL)
		x->prev->next = x->next;
	else
	lista->head = x->next;
	if (x->next != NULL)
	x->next->prev = x->prev;
}
void list_print(t_lista lista)
{
	t_nod_lista *x = lista.head->next;
	if (x == NULL)
	printf("lista vida\n");
	while (x)
	{
		printf("%d, ", x->cheie);
		x = x->next;
	}
}
void list_free(t_lista *lista)
{
t_nod_lista *x = lista->head->next;
while (x)
{
list_delete(lista, x);
free(x);
x = lista->head->next;
}
free (lista->head);
}
