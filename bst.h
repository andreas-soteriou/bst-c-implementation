#ifndef BST_H
#define BST_H

#include <stdio.h>

typedef struct node{
	int data;	
	struct node *left; 
	struct node *right;
}Node;

typedef struct bst{
	struct node *root;
	size_t size;

	void (*insert)(struct bst *, int);
	Node *(*search)(struct bst *, int);
	void (*inorder_traverse)(struct bst *);
	int (*remove)(struct bst *, int);

}BST;


BST new_bst();

#endif //BST_H