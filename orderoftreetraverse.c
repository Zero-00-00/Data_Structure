#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int item)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data=item;
	node->right=node->left=NULL;
	return node;
}

void inorder(struct node* root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}

void preorder(struct node* root)
{
	if (root!=NULL)
	{
		
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}

void postorder(struct node* root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}	
}

int main()
{
	struct node* root=NULL;
	
	//creating tree
	/*
	
	         45
	        /  \
	      34    12
	     / \   /  \
	   78  69 89  20
	   
	*/
	//tree
	root = newnode(45);
	root->left = newnode(34);
	root->right = newnode(12);
	root->left->left = newnode(78);
	root->left->right = newnode(69);
	root->right->left = newnode(89);
	root->right->right = newnode(20);
	
	//order
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPreorder:\n");
	preorder(root);
	printf("\nPostorder:\n");
	postorder(root);
	printf("\n\n");
}
