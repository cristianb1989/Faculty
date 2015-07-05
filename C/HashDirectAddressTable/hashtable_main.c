#include "hashtable_direct.h"
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
	char selectie = 0;
		int k;
		int z;
		int dimensiuneArray = 15;
		hTable tabel;
		t_hashTable table;
		
		init(&tabel, dimensiuneArray);

		while (selectie != 'x')
		{
			printf("\n");
			printf("1 pentru cautare in tabela\n");
			printf("2 pentru inserare in tabela\n");
			printf("3 pentru stergere din tabelei\n");
			printf("4 pentru afisarea tabelei\n");
			printf("x pentru iesire din program\n");
			printf("introduceti optiunea dvs: "); scanf("%c", &selectie);
		switch (selectie)
		{
			case '1':
				printf("introduceti cheia de cautare: "); scanf("%d", &k);
				z = search(&tabel, k);
				if (z != -1)
					printf("cheia %d a fost gasita la pozitia %ld\n", k, z);
				else printf("cheia %d nu a fost gasita\n", k);
			break;
			case '2':
				printf("introduceti cheia care se insereaza: "); scanf("%d", &k);
				insert(&tabel, k);
				printHashTable(&tabel);
			break;
			case '3':
				printf("introduceti cheia care se sterge: "); scanf("%d", &k);
				removeFromHashTable(&tabel, k);
				printHashTable(&tabel);
			break;
			case '4':
				printHashTable(&tabel);
				break;
			}
		};


			
		selectie = 0;
		dimensiuneArray = 15;
	
		init_hashTable(&table, dimensiuneArray);

		while (selectie != 'x')
		{
			printf("\n");
			printf("1 pentru cautare in tabela\n");
			printf("2 pentru inserare in tabela\n");
			printf("3 pentru stergere din tabelei\n");
			printf("4 pentru afisarea tabelei\n");
			printf("x pentru iesire din program\n");
			printf("introduceti optiunea dvs: "); scanf("%c", &selectie);
		switch (selectie)
		{
			case '1':
				printf("introduceti cheia de cautare: "); scanf("%d", &k);
				z = search(&tabel, k);
				if (z != -1)
					printf("cheia %d a fost gasita la pozitia %ld\n", k, z);
				else printf("cheia %d nu a fost gasita\n", k);
			break;
			case '2':
				printf("introduceti cheia care se insereaza: "); scanf("%d", &k);
				chained_hashInsert(&table, k);
				printHashTableDispersie(&table);
			break;
			case '3':
				printf("introduceti cheia care se sterge: "); scanf("%d", &k);
				removeFromHashTable(&table, k);
				printHashTableDispersie(&table);
			break;
			case '4':
				printHashTableDispersie(&table);
				break;
			}
		}
}