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

int CountLeaves(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return 0;
	}
	if ((*b_tree)->left == NULL && (*b_tree)->right == NULL)
	{
		return 1;
	}
	else
	{
		return CountLeaves(&(*b_tree)->right) + CountLeaves(&(*b_tree)->left);
	}
}

int MaxDepth(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return NULL;
	}
	else
	{
		int depth_left = 0;
		int depth_right = 0;
		int depth;
		depth_left = depth_left + MaxDepth(&(*b_tree)->left);
		depth_right = depth_right + MaxDepth(&(*b_tree)->right);
		if (depth_left > depth_right)
		{
			depth = depth_left;
		}
		else
		{
			depth = depth_right;
		}
		return depth++;
	}
}
/*
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
}*/

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
	if ((*b_tree)->left != NULL)
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
			left_branch = current_element->left;
			right_branch = current_element->right;
			if (current_element->value > left_branch)
			{
				max = MaxTree(&current_element->right);
				//max->parent->right = NULL;
				parent->left = max;
				max->parent = parent;
			}
			else
			{
				max = MaxTree(&current_element->left);
				//max->parent->left = NULL;
				parent->right = max;
				max->parent = parent;
			}
			right_branch->parent = max;
			left_branch->parent = max;
			max->right = right_branch;
			max->left = left_branch;
			free(remove);
		}
	}
}

BinTreeEl * GetNext(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return NULL;
	}
	if ((*b_tree)->right != NULL)
	{
		return MinTree(&(*b_tree)->right);
	}
	BinTreeEl last = *b_tree;
	do
	{
		last = b_tree;
		b_tree = (*b_tree)->parent;
	} while ((*b_tree) != NULL && (*b_tree)->right == last);
	return b_tree;
}

BinTreeEl * GetLast(BinTreeEl *b_tree)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return NULL;
	}
	if ((*b_tree)->left != NULL)
	{
		return MaxTree(&(*b_tree)->left);
	}
	BinTreeEl last = *b_tree;
	do
	{
		last = b_tree;
		b_tree = (*b_tree)->parent;
	} while ((*b_tree) != NULL && (*b_tree)->left == last);
	return b_tree;
}

void ViewTree0(BinTreeEl *b_tree, int depth)
{
	if (TreeEmpty(b_tree) == 1)
	{
		return;
	}
	ViewTree0(&(*b_tree)->left, depth++);
	for (int i = 0; i < depth; i++) 
	{
		putchar(' ');
	}
	printf("%d\n", (*b_tree)->value);
	ViewTree0(&(*b_tree)->right, depth++);
}
void ViewTree(BinTreeEl *b_tree)
{
	ViewTree0(&(*b_tree), 0);
	putchar('\n');
}
//strcmp

//strcpy

//2x free
//usuwanie
//ONP zabezpieczone