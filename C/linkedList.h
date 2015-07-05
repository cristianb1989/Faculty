#ifndef __LINKEDLIST
#define __LINKEDLIST


typedef struct linkedList{
	int length;
	struct linkedListNode *head;
	struct linkedListNode *tail;
};

typedef struct linkedListNode{
	int data;
	struct linkedListNode *next;
	struct linkedListNode *previous;

};


void initLinkedList(struct linkedList *lista);

void insertNode(struct linkedList *lista, int data);

void removeNode(struct linkedList *lista, int data);

struct linkedListNode* search(struct linkedList *lista, int data);

#endif