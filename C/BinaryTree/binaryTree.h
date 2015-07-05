#ifndef __BINARYTREE
#define __BINARYTREE

typedef struct nod_arbore{
	int key;
	struct nod_arbore *left, *right, *parent;
};

typedef struct arbore_struct{
	struct nod_arbore  *root;
};

void makeRoot(struct arbore_struct *arbore, int key);


struct nod_arbore* create_node(int key);

struct nod_arbore* treeSearch(struct nod_arbore *radacina, int key);

struct nod_arbore* iterativeTreeSearch(struct nod_arbore *radacina, int key);

struct nod_arbore* MIN_TREE(struct nod_arbore *radacina);

struct nod_arbore* MAX_TREE(struct nod_arbore *radacina);

void treeInsertByValue(struct arbore_struct *arbore, int key);

void treeInsertByNode(struct arbore_struct *arbore, struct nod_arbore *noulNod);

struct nod_arbore* tree_delete(struct nod_arbore *radacina, int data);

void inorderWalk(struct nod_arbore *radacina);

void postorder_walk(struct nod_arbore *radacina);

void preorder_walk(struct nod_arbore *radacina);

struct nod_arbore* treeSuccessor(struct nod_arbore *nodulCautat);



#endif