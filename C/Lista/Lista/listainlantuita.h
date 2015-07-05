#ifndef __LISTAINLANTUITA
#define __LISTAINLANTUITA

typedef struct nod_lista {
	int cheie;
	struct nod_lista *next;
}t_nod_lista;

typedef struct lista{
	t_nod_lista *head;
	t_nod_lista *tail;
}t_lista ;

void makenull(t_lista *lista);

t_nod_lista* search_linkedlist(t_lista *lista, int k);

void insert_linkedlist(t_lista *lista, t_nod_lista *x);

void delete_linkedlist(t_lista *lista, t_nod_lista *x);

void free_linkedlist(t_lista *lista);

void print_linkedlist(t_lista *lista);

t_nod_lista* next_linkedlist(t_lista *lista, t_nod_lista *x);
t_nod_lista* previous_linkedlist(t_lista *lista, t_nod_lista *x);

t_nod_lista* first_linkedlist(t_lista *lista);

#endif