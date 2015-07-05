#ifndef _LINKEDLIST
#define _LINKEDLIST

typedef struct nod_lista{
	int cheie;
	struct nod_lista *next
} t_nod_lista;

typedef struct lista{
	t_nod_lista *head;
	t_nod_lista *tail;
} t_lista;

void makenull(t_lista *lista);
t_nod_lista* list_search(t_lista lista, int k);
void list_insert(t_lista *lista, t_nod_lista *x);
void list_delete(t_lista *lista, t_nod_lista *x);
void list_free(t_lista *lista);
void list_print(t_lista *lista);
t_nod_lista* list_next(t_lista *lista);
t_nod_lista* list_previous(t_lista *lista);

#endif 