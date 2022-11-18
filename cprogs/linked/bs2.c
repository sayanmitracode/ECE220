#include<stdio.h>
#include<stdlib.h>

typedef struct TreenNode node;

struct TreenNode{
	int data;
	node * left;
	node * right;
	// int depth;
};


node *  newNode(int data);
// function creates a new

void add(node ** cur, int data);
void inOrder(node * root);
void preOrder(node * root);
void postOrder(node * root);

node * find(node * root, int data);


int main(){
	node * root = NULL;
	add(&root, 7);
	add(&root, 63);
	add(&root, 10);
	add(&root, 16);
	add(&root, 53);
	printf(" \n In order traversal");
	inOrder(root);
	printf(" \n Pre-order traversal");
	preOrder(root);
	printf(" \n Post-order traversal");
	postOrder(root);
	find(root, 16);

}

node * find(node * cur, int xdata){
	if (cur==NULL)
		return NULL;
	else
	{
		if (cur->data == xdata)
			return cur;
		else if (xdata <= cur->data)
			return find(cur->left, xdata);
		else
			return find(cur->right, xdata);
	}
}

node * findMin(node * cur, int xdata){
	if (cur==NULL)
	{
		return cur;
	}

}

node *  newNode(int newdata){
	// Create a new node and initialize it
	node * new;
	new = (node *)malloc(sizeof(node));
	new->data = newdata;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void inOrder(node * cur){
	if (cur == NULL)
		return;
	else{		
	inOrder(cur->left);
	printf(" %d", cur->data);
	inOrder(cur->right);
	}
}


void preOrder(node * cur){
	// visit left subtree, right subtree, this node
	if (cur == NULL)
		return;
	else{		
	printf(" %d", cur->data);
	preOrder(cur->left);
	preOrder(cur->right);
	}
}


void postOrder(node * cur){
	// visit left subtree, right subtree, this node
	if (cur == NULL)
		return;
	else{		
	postOrder(cur->left);
	postOrder(cur->right);
	printf(" %d", cur->data);
	}
}

void add(node ** cur, int newdata)
{
	if (*cur == NULL){
		// we have found the right place for the node
		*cur = newNode(newdata);
	}
	else 
	{
		if ((*cur)->data >= newdata)
			add(&(*cur)->left, newdata);
		else
			add(&(*cur)->right, newdata);
	}
}


