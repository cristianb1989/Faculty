#include "listasir.h"
#include <stdio.h>
#include <stdlib.h>
/*void main()
{
	//t_lista_sir lista;
	//int *z;
	//char selectie = 0;
	//int k;
	//makenull(&lista);
/*	while (selectie != 'x')
	{
		printf("\n");
		printf("1 pentru cautare in lista\n");
		printf("2 pentru inserare in lista\n");
		printf("3 pentru stergere din lista\n");
		printf("4 pentru afisarea listei\n");
		printf("5 pentru afisarea urmatorului element\n");
		printf("6 pentru afisarea elementului anterior\n");
		printf("7 pentru afisarea primului element\n");
		printf("x pentru iesire din program\n");
		printf("introduceti optiunea dvs: "); scanf("%c", &selectie);
	switch (selectie)
	{
		case '1':
			printf("introduceti cheia de cautare: "); scanf("%d", &k);
			z = search_linkedlist(&lista, k);
			if (z != NULL)
				printf("cheia %d a fost gasita la adresa %ld\n", k, z);
			else printf("cheia %d nu a fost gasita\n", k);
		break;
		case '2':
			printf("introduceti cheia care se insereaza: "); scanf("%d", &k);
			z = (t_nod_lista*) malloc (sizeof(t_nod_lista));
			z->cheie = k;
			printf("adresa %d a fost gasita \n", &z);
			printf("adresa liste %d a fost gasita \n", &lista);
			insert_linkedlist(&lista, z);
		break;
		case '3':
		printf("introduceti cheia care se sterge: "); scanf("%d", &k);
			z = search_linkedlist(&lista, k);
		//if (z)
				//nod_lista *g = z->next;
				//g = g->next->next;
			//
			delete_linkedlist(&lista, z);
			printf("cheia %d nu a fost gasita \n", k);
		break;
		case '4':
			print_linkedlist(&lista);
			break;
		case '5':
			printf("introduceti cheia la care se doreste urmatorul element: "); scanf("%d", &k);
		    z = search_linkedlist(&lista, k);
			break;
		case '6' :
			printf("introduceti cheia la care se doreste urmatorul element: "); scanf("%d", &k);
		    z = search_linkedlist(&lista, k);
		    
			break;
		case '7' :
			printf("P: "); scanf("%d", &k);
		    z = search_linkedlist(&lista, k);
			break;
		}
	}
	free_linkedlist(&lista);

}
*/
