#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Queue_arr.h"

Tnode* CreateTreeNode(tree_type value)
{
	Tnode *temp = (Tnode*)calloc(1, sizeof(Tnode));
	temp->key = value;
	return temp;
}

Tnode* CreateBST()
{
	Tnode *mytree = NULL;
	tree_type num = 0;

	printf("\nEnter numbers to tree (-1 to stop): ");
	scanf("%d", &num);
	while (num != -1)
	{
		mytree = insertBST(mytree, num);
		printf("Another one: ");
		scanf("%d", &num);
	}

	return mytree;
}

Tnode* insertBST(Tnode *tree, tree_type value)
{
	if (tree == NULL)
	{
		return CreateTreeNode(value);
	}
	if (value < tree->key)
	{
		tree->left = insertBST(tree->left, value);
		tree->left->root = tree;
	}
	else
	{
		tree->right = insertBST(tree->right, value);
		tree->right->root = tree;
	}
	return tree;
}

void Ex1(Tnode **root)
{
	printf("\t\t** Ex1 - Function creates and initiliaze a binary search tree**\n\n");

	if ((*root))
	{
		printf("Already initiliazed tree\n");
		return;
	}
	
	(*root) = CreateBST();
}

void InOrder(Tnode *tree) //non-recursive using parent
{
	Tnode *current = tree;
	int printleft = 0;
	
	printf("Inorder without recursion: ");

	while (current)
	{
		if (!printleft)
		{
			while(current->left)
				current = current->left;
		}

		printf("%d, ", current->key);
		printleft = 1;
		
		if (current->right)
		{
			current = current->right;
			printleft = 0;
		}
		else if (current->root) //got parent
		{
			while (current->root && current == current->root->right) //  got parent and came from right
			{
				current = current->root;
			}
			if (!(current->root))
				break;
			current = current->root;
		}
		else //no parent and came from left
		{ 
			break;
		}
	}
}

void Ex2(Tnode *root)
{
	printf("\t\t** Ex2 - Function prints tree by in-order method **\n\n");
	if(!root)
	{
		printf("\n\n-->First initialize tree\n");
		return;
	}
	InOrder(root);
}


void printByLevel(Tnode *root)
{
	Tnode temp;
	if (root == NULL)
	{
		printf("Nothing to print\n");
		return;
	}
	queue q1;
	create_queue(&q1);

	enqueue(root, &q1);
	while (!queue_is_empty(&q1))
	{
		dequeue(&q1, &temp);


		printf("%d ", temp.key);

		if (temp.left)
			enqueue(temp.left, &q1);
		if (temp.right)
			enqueue(temp.right, &q1);
	}
}

void Ex3(Tnode *root)
{
	printf("\t\t** Ex3 - Function prints tree by levels **\n\n");
	if (!root)
	{
		printf("\n\n-->First initialize tree\n\n");
		return;
	}	
	printByLevel(root);
}


void FreeBST(Tnode *root)
{
	if (root != NULL)
	{
		FreeBST(root->left);
		FreeBST(root->right);
		printf("\n%d node is being freed\n", root->key);
		free(root);
	}
	return;
}


void Ex4(Tnode **root)
{
	printf("\t\t** Ex3 - Function free binary search tree by using post-order method **\n\n");

	if (!(*root))
	{
		printf("Nothing to free\n\n");
		return;
	}

	FreeBST((*root));
	(*root) = NULL;

}