#include "bst.h"
#include <stdlib.h>

static void insert_recursive(Node **root, Node *new_node){
	if (*root == NULL){
		*root = new_node;
		return;
	}
	if (new_node->data > (*root)->data){
		insert_recursive(&(*root)->right, new_node);
	}else if (new_node->data < (*root)->data){
		insert_recursive(&(*root)->left, new_node);
	}
}
static Node *search_recursive(Node *root, int data){
	/*Not found */
	if (root == NULL){
		return NULL;
	}
	if (data == root->data){
		return root;	
	}else if (data > root->data){
		return search_recursive(root->right, data);
	}else{
		return search_recursive(root->left, data);
	}
}
static void insert(BST *tree, int data){
	Node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL){
		printf("Could not allocate memory.\n");
		return;
	}
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	insert_recursive(&tree->root, new_node);

	tree->size++;
} 
static Node *largest_from_left_subtree(Node *root){
	if (root->right == NULL) return root;	
	return largest_from_left_subtree(root->right);
}
static int delete_recursive(Node *root, int data){
	Node *delete_node = search_recursive(root, data);	
	/* leaf node */
	if (delete_node->left == NULL && delete_node->right == NULL){
		free(delete_node);
		delete_node = NULL;
	}else{
		Node *n = largest_from_left_subtree(root->left);
		delete_node->data = n->data;
		free(n);
		n = NULL;
	}
}
static int delete_data(BST *tree, int data){
	return delete_recursive(tree->root, data);
}
static Node *search(BST *tree, int data){
	return search_recursive(tree->root, data);
}
static void inorder_recursive(Node *root){
	if (root == NULL) return;
	inorder_recursive(root->left);
	printf("%d ", root->data);
	inorder_recursive(root->right);

}
static void inorder(BST *tree){
	inorder_recursive(tree->root);
}

BST new_bst(){ 
	BST tree;
	tree.root = NULL; 
	tree.size = 0;
	tree.insert = insert;
	tree.search = search;
	tree.inorder_traverse = inorder;
	tree.remove = delete_data;
	return tree;
}

