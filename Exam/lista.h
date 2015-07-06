#ifndef __LISTA
#define __LISTA
typedef struct nod_lista {
	int cheie;
	struct nod_lista *next, *prev;
}t_nod_lista;
typedef struct {
	t_nod_lista *head;
}t_lista;
void makenull(t_lista *lista);

t_nod_lista* list_search(t_lista lista, int k);

void list_insert(t_lista *lista, t_nod_lista *x);

void list_delete(t_lista *lista, t_nod_lista *x);

void list_free(t_lista *lista);

void list_print(t_lista lista);

#endif