#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct BinaryTreeElement
{
	int value;
	int counter;
	struct BinaryTreeElement *left;
	struct BinaryTreeElement *right;
	struct BinaryTreeElement *parent;
};
typedef struct BinaryTreeElement BinTree;
typedef BinTree *BinTreeEl;

int TreeEmpty(BinTreeEl *b_tree)
{
	if (*b_tree != NULL)
	{
		return 0;
	}
	else
	{
		//printf("Binary Tree is empty.\n");
		return 1;
	}
}

void AddToBinTree(BinTreeEl *b_tree, int x)
{
	BinTreeEl new_element = malloc(sizeof(BinTree));
	new_element->left = NULL;
	new_element->right = NULL;
	new_element->value = x;
	new_element->counter = 1;

	if (TreeEmpty(b_tree) == 1)
	{
		new_element->parent = NULL;
		*b_tree = new_element;
	}
	else
	{
		BinTreeEl current_element = *b_tree;
		BinTreeEl parent = *b_tree;
		int loop = 1;
		do
		{
			if (current_element->value > x)
			{
				if (current_element->left != NULL)
				{
					parent = current_element;
					current_element = current_element->left;
				}
				else
				{
					current_element->left = new_element;
					new_element->parent = current_element;
					break;
				}
			}
			else if (current_element->value < x)
			{
				if (current_element->right != NULL)
				{
					parent = current_element;
					current_element = current_element->right;
				}
				else
				{
					current_element->right = new_element;
					new_element->parent = current_element;
					break;
				}
			}
			else
			{
				current_element->counter++;
				break;
			}
		} while (loop == 1);
	}
}


void ViewTree(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return;
	}
	BinTreeEl current_element = *b_tree;
	BinTreeEl parent = current_element->parent;
	int depth = 0;
	int last = 0;
	while (current_element->left != NULL)
	{
		current_element = current_element->left;
		depth++;
	}

	while (current_element != NULL)
	{
		if (current_element->right != NULL && last < current_element->right->value)
		{
			current_element = current_element->right;
			depth++;
			while (current_element->left != NULL)
			{
				current_element = current_element->left;
				depth++;
			}
			last = current_element->value;
		}
		else
		{
			last = current_element->value;
			current_element = current_element->parent;
			depth--;
		}
	}
}

void CountLeaves(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return;
	}
	BinTreeEl current_element = *b_tree;
	BinTreeEl parent = current_element->parent;
	int depth = 0;
	int leaves = 0;
	int last = 0;
	while (current_element->left != NULL)
	{
		current_element = current_element->left;
		depth++;
	}

	while (current_element != NULL)
	{
		if (current_element->right == NULL && current_element->left == NULL)
		{
			leaves++;
		}
		if (current_element->right != NULL && last < current_element->right->value)
		{
			current_element = current_element->right;
			depth++;
			while (current_element->left != NULL)
			{
				current_element = current_element->left;
				depth++;
			}
			last = current_element->value;
		}
		else
		{
			last = current_element->value;
			current_element = current_element->parent;
			depth--;
		}
	}
	printf("Amount of leaves: %d\n", leaves);
}

void MaxDepthInTree(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return;
	}
	BinTreeEl current_element = *b_tree;
	BinTreeEl parent = current_element->parent;
	int depth = 0;
	int max_depth = 0;
	int last = 0;
	while (current_element->left != NULL)
	{
		current_element = current_element->left;
		depth++;
	}

	max_depth = depth;

	while (current_element != NULL)
	{
		if (current_element->right != NULL && last < current_element->right->value)
		{
			current_element = current_element->right;
			depth++;
			while (current_element->left != NULL)
			{
				current_element = current_element->left;
				depth++;
			}
			if (depth > max_depth)
			{
				max_depth = depth;
			}
			last = current_element->value;
		}
		else
		{
			last = current_element->value;
			current_element = current_element->parent;
			depth--;
		}
	}
	printf("Max depth: %d\n", max_depth);
}

BinTreeEl * SearchTree(BinTreeEl *b_tree, int x)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return;
	}
	BinTreeEl current_element = *b_tree;
	while (current_element != NULL)
	{
		if (x < current_element->value)
		{
			current_element = current_element->left;
		}
		else if (x > current_element->value)
		{
			current_element = current_element->right;
		}
		else
		{
			printf("Wartosc %d znajduje sie w drzewie.\n", x);
			return current_element;
		}
	}
	printf("Wartosc %d nie zostala znaleziona w drzewie.\n", x);
	return NULL;
}

BinTreeEl * MinTree(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return NULL;
	}
	if((*b_tree)->left != NULL)
	{
		MinTree(&(*b_tree)->left);
	}
	else
	{
		return (*b_tree);
	}
}

BinTreeEl * MaxTree(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return NULL;
	}
	if ((*b_tree)->right != NULL)
	{
		MaxTree(&(*b_tree)->right);
	}
	else
	{
		return (*b_tree);
	}
}

void RemoveFromTree(BinTreeEl *b_tree, int x)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return;
	}
	BinTreeEl parent, current_element, left_branch, right_branch, remove, max;
	current_element = SearchTree(b_tree, x);
	if (current_element == NULL)
	{
		return;
	}
	if (current_element->counter > 1)
	{
		current_element->counter--;
		return;
	}
	
	//Do poprawy ponizej i sprawdzic
	if (current_element->left == NULL && current_element->right == NULL)
	{
		parent = current_element->parent;
		if (parent->left == current_element)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
		free(current_element);
	}
	else
	{
		parent = current_element->parent;
		if (current_element->right == NULL)
		{
			remove = current_element;
			left_branch = current_element->left;
			left_branch->parent = parent;
			parent->left = left_branch;
			free(remove);
		}
		else
		{
			//Do fixnienica
			remove = current_element;
			max = MaxTree(&current_element->right);
			max->parent->right = NULL;
			right_branch = current_element->right;
			parent->left = max;
			max->parent = parent;
			max->right = right_branch;
			right_branch->parent = max;
			free(remove);
		}
	}
}
//usuwanie
//ONP zabezpieczone