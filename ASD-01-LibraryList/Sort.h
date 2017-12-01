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

void PrintArray(int A[], int size)
{
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", A[i]);
	}
	printf(" [|]\n");
}

int * CopyArray(int A[], int size)
{
	int *Copy = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		Copy[i] = A[i];
	}
	return Copy;
}

void BubbleSort(int A[], int size)
{
	int *a = CopyArray(A, size);

	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		for (j = size - 1; j >= i; j--)
		{
			if (a[j - 1] > a[j])
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
	PrintArray(a, size);
}

void InsertionSort(int A[], int size)
{
	int *a = CopyArray(A, size);

	int i, j, x;
	for (i = 1; i < size; i++)
	{
		if (a[i] < a[0])
		{
			x = a[0];
			a[0] = a[i];
		}
		else
		{
			x = a[i];
		}
		for (j = i - 1; x < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
	PrintArray(a, size);
}

void QuickSort(int A[], int l, int r)
{
	if (l < r)
	{
		int index = Partition(A, l, r);
		QuickSort(A, l, index - 1);
		QuickSort(A, index + 1, r);
	}
}

int Partition(int A[], int l, int r)
{
	int index = ChooseSplitPoint(l, r);
	int x = A[index];
	int i, temp;
	int pos = l;
	
	temp = A[index];
	A[index] = A[r];
	A[r] = temp;
	//SwitchV(A, index, r);

	for (i = l; i < r - 1; i++)
	{
		if (A[i] < x)
		{
			temp = A[i];
			A[i] = A[r];
			A[r] = temp; 
			//SwitchV(A, i, r);
			pos++;
		}
	}
	temp = A[pos];
	A[pos] = A[r];
	A[r] = temp;
	//SwitchV(A, pos, r);
	return pos;
}

int ChooseSplitPoint(int l, int r)
{
	return l + (r - 1) / 2;
	//DIV?
}
/*
void SwitchV(int A[], int i, int r)
{
	int temp = A[i];
	A[i] = A[r];
	A[r] = temp;
}
*/