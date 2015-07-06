#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void makeRoot(struct arbore_struct *arbore, int key){
	arbore->root = (struct nod_arbore*)malloc(sizeof(struct nod_arbore));
	arbore->root->key = key;
	arbore->root->left = NULL;
	arbore->root->right = NULL;
	arbore->root->parent = NULL;
}

struct nod_arbore* treeSearch(struct nod_arbore *radacina, int key){
	if (radacina == NULL){
		return NULL;
	} else if (radacina->key == key) {
		return radacina;
	} else if (key < radacina->key){
		return treeSearch(radacina->left, key);
	} else{
		return treeSearch(radacina->right, key);
	}

}

struct nod_arbore* iterativeTreeSearch(struct nod_arbore *radacina, int key){
	struct nod_arbore *temp = radacina;
	while (temp != NULL){
		if (temp->key == key){
			return temp;	
		} else if ( key < temp->key){
			temp = temp->left;
		} else{
			temp = temp->right;
		}

	};
	return NULL;
}

struct nod_arbore* MIN_TREE(struct nod_arbore *radacina){
	struct nod_arbore *temp = radacina;
	while (temp->left != NULL){
		temp = temp->left;
	};

	return temp;
}


struct nod_arbore* create_node(int key){
	struct nod_arbore *n = (struct nod_arbore*)malloc(sizeof(struct nod_arbore));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	
	return n;
}
struct nod_arbore* MAX_TREE(struct nod_arbore *radacina){
	struct nod_arbore *temp = radacina;
	while (temp->right != NULL){
		temp = temp->right;
	};

	return temp;
}

void treeInsertByValue(struct arbore_struct *arbore, int key){
	struct nod_arbore *noulNod = create_node(key);
	treeInsertByNode(arbore, noulNod);
}

void treeInsertByNode(struct arbore_struct *arbore, struct nod_arbore *noulNod){
	struct nod_arbore *radacina = arbore->root;
	struct nod_arbore *temp = NULL;
	while (radacina != NULL){
		temp = radacina;
		if (noulNod->key < temp->key){
			radacina = radacina->left;
		}else{
			radacina = radacina->right;
		}
	}
	noulNod->parent = temp;
	if (temp == NULL){
		arbore->root = noulNod;
	};
	if (noulNod->key < temp->key){
		temp->left = noulNod;
	}else{
		temp->right = noulNod;
	}


}

struct nod_arbore* tree_delete(struct nod_arbore *radacina, int data){
	if (radacina == NULL){
		return NULL;
	} else if (data < radacina->key){
		radacina->left =  tree_delete(radacina->left, data);
	} else if (data > radacina->key){
		radacina->right = tree_delete(radacina->right, data);
	} else{
		//we found the item to delete
		//case 1: No child a.k.a leaf node
		if (radacina->left == NULL && radacina->right == NULL){
			free(radacina);
			radacina = NULL;
			//case 2: No left child 
		} else if (radacina->left == NULL){
			struct nod_arbore *temp = radacina;
			radacina = radacina->right;
			free(temp);
			//case 2: No right child 
		} else if (radacina->right == NULL){
			struct nod_arbore *temp = radacina;
			radacina = radacina->left;
			free(temp);
		} else{
			//case 3 : 2 children 
			struct nod_arbore *temp = MIN_TREE(radacina->right);
			radacina->key = temp->key;
			radacina->right = tree_delete(radacina->right,temp->key);
		}
	}

	return radacina;
}

void inorderWalk(struct nod_arbore *radacina){
	if (radacina != NULL){
		inorderWalk(radacina->left);
		printf("%d ", radacina->key);
		inorderWalk(radacina->right);
	}
}

void postorder_walk(struct nod_arbore *radacina){
	if (radacina != NULL){
		postorder_walk(radacina->left);
		postorder_walk(radacina->right);
		printf("%d ", radacina->key);
		
	}
}

void preorder_walk(struct nod_arbore *radacina){
	if (radacina != NULL){
		printf("%d ", radacina->key);
		preorder_walk(radacina->left);
		preorder_walk(radacina->right);
		
	}
}



struct nod_arbore* treeSuccessor(struct nod_arbore *nodulCautat){
	struct nod_arbore *temp;
	if (nodulCautat->right != NULL){
		return MIN_TREE(nodulCautat);
	}
	temp = nodulCautat->parent;
	while (temp != NULL && nodulCautat == temp->right){
		nodulCautat = temp;
		temp = temp->parent;
	};

	return temp;

}


