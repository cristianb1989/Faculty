#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "linkedList.h"



void initLinkedList(struct linkedList *lista){
	lista->head = (struct linkedListNode*)malloc(sizeof(struct linkedListNode));
	lista->tail = (struct linkedListNode*)malloc(sizeof(struct linkedListNode));
	lista->length = 0;
}

void insertNode(struct linkedList *lista, int data){
	struct linkedListNode *newNode = (struct linkedListNode*)malloc(sizeof(struct linkedListNode));
		struct linkedListNode *temp;
	newNode->data = data;
	//this is the first element
	if (lista->head == NULL){
		lista->head = newNode;
		
	//this is the second element
	}else if (lista->tail == NULL){
		lista->head->next = newNode;
		lista->tail = newNode;
		lista->tail->previous = lista->head;
	} else {
		temp = lista->tail;
		lista->tail->next = newNode;
		lista->tail= newNode;
		lista->tail->previous = temp;

	}
	lista->length = lista->length + 1;

}


struct linkedListNode* search(struct linkedList *lista, int data){
	struct linkedListNode *temp = lista->head;
	while(temp->data != data && temp != NULL){
		temp = temp->next;
	}
	return temp;

}

void removeNode(struct linkedList *lista, int data){
	struct linkedListNode *nodeToBeDeleted = search(lista, data);
	struct linkedListNode *temp;
	if (nodeToBeDeleted == NULL){
		printf("No element found");
		return;
	// this is the HEAD	
	}else if (nodeToBeDeleted->previous == NULL){
		temp = nodeToBeDeleted->next;
		temp->previous = NULL;
		free(nodeToBeDeleted);
	// this is the TAIL	
	} else if (nodeToBeDeleted->previous == NULL){
		temp = nodeToBeDeleted->previous;
		temp->next = NULL;
		free(nodeToBeDeleted);
	}else {
		temp = nodeToBeDeleted->previous;
		temp->next = nodeToBeDeleted->next;
		temp->next->previous = nodeToBeDeleted->next->previous;
		free(nodeToBeDeleted);

	};

	lista->length = lista->length - 1;
	
}
