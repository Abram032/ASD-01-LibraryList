#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Lists.h"

int ** LoadMatrixGraph(int n)
{
	int p, q, i, m;
	int ** M;
	printf("Amount of connections: ");
	scanf(" %d", &m);
	M = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		M[i] = calloc(n, sizeof(int));
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &p, &q);
		M[p][q] = 1;
	}
	return M;
}

ListEl * LoadListGraph(int n)
{
	int m, p, q, i;
	ListEl * ML;
	printf("Amount of connections: ");
	scanf(" %d", &m);
	ML = calloc(n, sizeof(ListEl));
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &p, &q);
		AddToListFront(&ML[p], q);
	}
	return ML;
}

void ViewMatrix(int ** M, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

void ViewMLists(ListEl * ML, int nl)
{
	int i, j;
	for (i = 0; i < nl; i++)
	{
		printf("List %d:\n", i);
		ViewList(&ML[i]);
		printf("\n");
	}
}

int ** TransformL2M(ListEl * ML, int n)
{
	int p, q, i;
	int ** M;
	M = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		M[i] = calloc(n, sizeof(int));
	}
	for (i = 0; i < n; i++)
	{
		q = PopValue(&ML[i]);
		while (q != INT_MAX)
		{
			M[i][q] = 1;
			q = PopValue(&ML[i]);
		}
	}
	return M;
}

int PopValue(ListEl *list_el)
{
	if (*list_el != NULL)
	{
		int value;
		ListEl current_element = *list_el;
		value = current_element->value;
		*list_el = current_element->next;
		free(current_element);
		return value;
	}
	return INT_MAX;
}

int ** ReverseMatrix(int ** M, int n)
{
	int p, q, i, j;
	int ** MR;
	MR = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		MR[i] = calloc(n, sizeof(int));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (M[i][j] == 1)
			{
				MR[i][j] = 0;
			}
			else
			{
				MR[i][j] = 1;
			}
		}
	}
	return MR;
}

ListEl * TransformM2L(int ** MR, int n)
{
	int p, q, i, j;
	ListEl * MLR;
	MLR = calloc(n, sizeof(ListEl));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (MR[i][j] == 1)
			{
				AddToListFront(&MLR[i], j);
			}
		}
	}
	return MLR;
}