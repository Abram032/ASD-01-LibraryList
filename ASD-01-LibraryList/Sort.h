#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int * Generate(int size)
{
	int *A = malloc(size*sizeof(*A));
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		A[i] = rand();
	}
	return A;
}

void PrintArray(int A[])
{
	int i = 0;
	int n = sizeof(A);
	for (int i = 0; i < n; i++)
	{
		printf("%d, ", A[i]);
	}
}

int * Copy(int A[])
{
	int n = sizeof(A) / sizeof(int);
	int *Copy = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		Copy[i] = A[i];
	}
	return Copy;
}