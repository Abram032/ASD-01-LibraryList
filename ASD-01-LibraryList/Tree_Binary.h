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

int TreeEmpty(BinTreeEl b_tree)
{
	if (b_tree != NULL)
	{
		return 0;
	}
	else
	{
		printf("Binary Tree is empty.\n");
		return 1;
	}
}

void ViewBinTree0(BinTreeEl b_tree, int depth)
{
	if (TreeEmpty(b_tree) == 0)
	{
		ViewBinTree0((b_tree)->left, depth + 1);
		for (int i = 0; i < depth; i++)
		{
			putchar(' ');
			printf("%d\n", (b_tree)->value);
			ViewBinTree0((b_tree)->right, depth + 1);
		}
	}
}

void ViewBinTree(BinTreeEl b_tree)
{
	if (TreeEmpty(b_tree) == 0)
	{
		ViewBinTree0(b_tree, 0);
		putchar('\n');
	}
}

void AddToBinTree(BinTreeEl *b_tree, int x)
{
	if (TreeEmpty(b_tree) == 1)
	{
		BinTreeEl new_element = malloc(sizeof(BinTree));
		new_element->counter = 1;
		new_element->value = x;
		new_element->parent = NULL;
		new_element->left = NULL;
		new_element->right = NULL;
		*b_tree = new_element;
	}
	else if (x < (*b_tree)->value)
	{
		AddToBinTree(&(*b_tree)->left, x);
	}
	else if (x > (*b_tree)->value)
	{
		AddToBinTree(&(*b_tree)->right, x);
	}
	else
	{
		(*b_tree)->counter++;
	}
}
