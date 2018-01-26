#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Lists_prior.h"

PriorListEl * LoadPriorListGraph(int n)
{
	int m, p, q, i, prior;
	PriorListEl * ML;
	printf("Amount of connections: ");
	scanf(" %d", &m);
	ML = (PriorListEl*)calloc(n, sizeof(PriorListEl));
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &p, &q, &prior);
		AddToPriorList(&ML[p], q, prior);
	}
	return ML;
}

void ViewPriorLists(PriorListEl * PL, int nl)
{
	int i, j;
	for (i = 0; i < nl; i++)
	{
		printf("List %d:\n", i);
		ViewPriorList(&PL[i]);
		printf("\n");
	}
}

PriorListEl * Init_Distance(int n)
{
	int i;
	PriorListEl distance = NULL;
	for (i = 0; i < n; i++)
	{
		AddToPriorList(&distance, i, INT_MAX);
	}
	return distance;
}

int * Init_PrevPath(int n)
{
	int i;
	int * p;
	p = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		p[i] = -1;
	}
	return p;
}

int *d = NULL;
int *p = NULL;
int *r = NULL;

void Init_Single_Source(int n, int s)
{
	int i;
	d = malloc(n * sizeof(int));
	p = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		d[i] = INT_MAX;
		p[i] = -1;
	}
	d[s] = 0;
}

int ExtractMin(PriorListEl * Q)
{
	int value;
	PriorListEl current = *Q;
	value = current->value;
	RemoveFromPriorList(Q);
	return value;
}

void Relax(int u, int v, int w, PriorListEl * Q)
{
	if (d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		p[v] = u;
		ChangePriortiy(Q, v, d[v]);
	}
}

void Dijkstra(PriorListEl * Graph, int n, int source, int target)
{
	int i, u, t;
	int rn = 0;
	PriorListEl Q = NULL;
	Init_Single_Source(n, source);
	for (i = 0; i < n; i++)
	{
		AddToPriorList(&Q, i, d[i]);
	}
	while (Q != NULL)
	{
		u = ExtractMin(&Q);
		PriorListEl S = Graph[u];
		while (S != NULL)
		{
			Relax(u, S->value, S->priority, &Q);
			S = S->next;
		}
	}
	t = target;
	while (t != -1)
	{
		t = p[t];
		rn++;
	}
	r = malloc(rn * sizeof(int));
	t = target;
	for (i = rn-1; i >= 0; i--)
	{
		r[i] = t;
		t = p[t];
	}
	printf("\nPath: ");
	for (i = 0; i < rn; i++)
	{
		if (i + 1 != rn)
			printf("%d -> ", r[i]);
		else
			printf("%d", r[i]);
	}
	printf("\n");
}

PriorListEl * Init_Test_Graph()
{
	int n = 5;
	PriorListEl * ML;
	ML = (PriorListEl*)calloc(n, sizeof(PriorListEl));
	AddToPriorList(&ML[0], 1, 2);
	AddToPriorList(&ML[0], 4, 4);
	AddToPriorList(&ML[1], 3, 4);
	AddToPriorList(&ML[1], 2, 6);
	AddToPriorList(&ML[3], 2, 1);
	AddToPriorList(&ML[4], 1, 3);
	AddToPriorList(&ML[4], 3, 6);
	return ML;
}