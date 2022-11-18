#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode node;

struct TreeNode{
	int data;
	node * left;
	node * right;
};

node * newnode(int newData);

void insert(node ** root, int data);

void inOrder(node * root);
void preOrder(node * root);

int main(){
	node * root = NULL;
	insert(&root, 50);
	insert(&root, 5);
	insert(&root, 115);
	insert(&root, 75);
	insert(&root, 85);
	insert(&root, 20);

	printf("\n In order traversal\n");
	inOrder(root);
	printf("\n pre-order traversal\n");
	preOrder(root);

	return 0;
}

node * newnode(int newData){
	node *new = (node*)malloc(sizeof(node));
	new->data = newData;
	new->left = new->right = NULL;
	return new;
}

void insert(node ** root, int data){
	if (*root == NULL)
	{
		*root = newnode(data);
		return;
	}
	else
	{
		if (data <= (*root)->data)
			insert(&(*root)->left, data);
		else
			insert(&(*root)->right, data);
	}
}

void inOrder(node * root)
{
	if (root == NULL)
		return;
	else
	{
		inOrder(root->left);
		printf(" %d ", root->data);
		inOrder(root->right);
	}
}

void preOrder(node * root)
{
	if (root == NULL)
		return;
	else
	{
		printf(" %d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


