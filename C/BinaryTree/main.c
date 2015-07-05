#include "activityselector.h"
#include <stdio.h>
#include <limits.h>
#include "binaryTree.h"

void print_array(int A[], int length){
	int i =0;
	for (i = 0; i< length; i++){
		printf("A[%d]=%d \n", i, A[i]);
	};
}

int main(){

	int sol_rec[11], sol_iter[11];
	int n = 11; int sn;
	int s[11] = {1,3,0,5,3,5,6,8,8,2,12};
	int f[11] = {4,5,6,7,8,9,10,11,12,13,14};
	int bara = 10;
	int p[10] = {1,5,8,9,10,17,17,20,24,30};
	struct arbore_struct *arbore;
	struct nod_arbore *nod;
	int nodValue;
	

	printf("Int minumum este : %d", INT_MIN);

	sn = recursiveActivitySelector(s, f, 0, n, sol_rec);
	printf("Recursive solution : %d\n", sn);
	print_array(sol_rec, sn);
	
	sn = greedyActivitySelector(s,f,n,sol_iter);
	printf("Iterative solution : %d\n", sn);
	print_array(sol_iter, sn);
	
	printf("Solutia cea mai buna este : %d", cutRod(p, bara));
	

	printf("Arbori binari de cautare\n");
	printf("root=");scanf("%d", &nodValue);
	makeRoot(&arbore, nodValue);
	printf("Introduceti numere pentru introducerea in arbore pana la citirea tastei 0\n");
	printf("Valoare nod=\n");scanf("%d", &nodValue);
	while(nodValue !=0){
		treeInsertByValue(&arbore, nodValue);
		printf("Valoare nod=\n");scanf("%d", &nodValue);
	}
	printf("Inorder walk:\n");
	inorderWalk(&arbore->root);
	printf("Preorder walk:\n");
	preorder_walk(&arbore->root);
	printf("Postorder walk:\n");
	postorder_walk(&arbore->root);
	printf("\n");
	printf("\n regasire nod: Valoare nod:");scanf("%d", &nodValue);
	nod = iterativeTreeSearch(&arbore->root, nodValue);
	if (nod != NULL){
		printf("Nodul cu cheia %d si adresa %d a fost gasit iterativ in arbore\n", nod->key, nod);
	}else{
	    printf("Nodul nu a fost gasit iterativ in arbore !\n");
	}
	nod=treeSearch(&arbore->root, nodValue);
		if (nod != NULL){
		printf("Nodul cu cheia %d si adresa %d a fost gasit recursiv in arbore\n", nod->key, nod);
	}else{
	    printf("Nodul nu a fost gasit recursiv in arbore !\n");
	}
	nod = MIN_TREE(&arbore->root);
	printf("Tree minimum este %d: \n", nod->key);
	nod = MAX_TREE(&arbore->root);
	printf("Tree maximum este %d: \n", nod->key);
	printf("Introduceti nodul la care doriti sa aflati succesorul\n");
	scanf("%d", &nodValue);

	nod = iterativeTreeSearch(&arbore->root, nodValue);
	nod = treeSuccessor(nod);
	printf("Succesorul este %d:\n", nod->key);
	printf("Introduceti nodul care doriti sa il stergeti\n");
	scanf("%d", &nodValue);
	tree_delete(&arbore->root, nodValue);
	printf("Inorder walk:\n");
	inorderWalk(&arbore->root);

};


