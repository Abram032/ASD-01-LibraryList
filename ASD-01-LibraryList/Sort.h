#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)

int substitutions = 0;
int comparisons = 0;

int * Generate(int size)
{
	int *A = malloc(size * sizeof(*A));
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		A[i] = rand();
	}
	return A;
}

float * GenerateFloat(int size)
{
	float *A = malloc(size * sizeof(*A));
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		A[i] = (float)rand() + (float)rand() / (float)RAND_MAX;
	}
	return A;
}

void PrintArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", A[i]);
	}
	printf(" [|]\n");
}

void PrintArrayFloat(float A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%f, ", A[i]);
	}
	printf(" [|]\n");
}

void PrintStats(int sub, int comp)
{
	printf("Substitutions: %d\n", sub);
	printf("Comparisons: %d\n", comp);
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

float * CopyFloatArray(float A[], int size)
{
	float *Copy = malloc(size * sizeof(float));
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
	int sub = 0, comp = 0;
	for (i = 1; i < size; i++)
	{
		comp++;
		for (j = size - 1; j >= i; j--)
		{
			comp++;
			if (a[j - 1] > a[j])
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				comp++;
				sub = sub + 3;
			}
			sub++;
		}
		sub++;
	}
	//PrintArray(a, size);
	//PrintArray(A, size);
	PrintStats(sub, comp);
}

void InsertionSort(int A[], int size)
{
	int *a = CopyArray(A, size);

	int i, j, x;
	int sub = 0, comp = 0;
	for (i = 1; i < size; i++)
	{
		if (a[i] < a[0])
		{
			x = a[0];
			a[0] = a[i];
			sub = sub + 2;
		}
		else
		{
			x = a[i];
			sub++;
		}
		comp = comp + 2;
		for (j = i - 1; x < a[j]; j--)
		{
			a[j + 1] = a[j];
			comp++;
			sub = sub + 2;
		}
		a[j + 1] = x;
		sub = sub + 2;
	}
	//PrintArray(a, size);
	//PrintArray(A, size);
	PrintStats(sub, comp);
}

void Swap(int A[], int a, int b)
{
	int t = A[a];
	A[a] = A[b];
	A[b] = t;
	substitutions = substitutions + 3;
}

int Partition(int A[], int l, int r)
{
	int pivot = A[r];
	int i = l - 1;
	substitutions = substitutions + 2;
	for (int j = l; j < r; j++)
	{
		if (A[j] <= pivot)
		{
			i++;
			Swap(A, i, j);
			substitutions++;
		}
		comparisons = comparisons + 2;
		substitutions++;
	}
	Swap(A, i + 1, r);
	return i + 1;
}

void QuickSort(int A[], int l, int r)
{
	comparisons++;
	if (l < r)
	{
		int index = Partition(A, l, r);
		substitutions++;
		QuickSort(A, l, index - 1);
		QuickSort(A, index + 1, r);
	}
}

void QuickSortStart(int A[], int size)
{
	int *a = CopyArray(A, size);
	QuickSort(a, 0, size - 1);
	//PrintArray(a, size);
	//PrintArray(A, size);
	PrintStats(substitutions, comparisons);
}

int Partition2(int A[], int p, int r)
{
	int _r = rand() % (r - p + 1) + p;
	int x, i, j;
	x = A[p];
	A[p] = A[_r];
	A[_r] = x;
	x = A[p];
	i = p - 1;
	j = r + 1;
	do
	{
		do
		{
			j--;
		} while (A[j] > x);
		do
		{
			i++;
		} while (A[i] < x);
		if (i < j)
		{
			x = A[i];
			A[i] = A[j];
			A[j] = x;
		}
	} while (i < j);
	return j;
}

void QSort(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = Partition2(A, p, r);
		QSort(A, p, q);
		QSort(A, q + 1, r);
	}
}

void QSortStart(int A[], int size)
{
	int *a = CopyArray(A, size);
	QSort(a, 0, size - 1);
	PrintArray(a, size);
	PrintArray(A, size);
	PrintStats(substitutions, comparisons);
}

void ShellSort(int A[], int size)
{
	int *a = CopyArray(A, size);
	int h, i, j, temp;
	int sub = 0, comp = 0;

	for (h = size; h /= 2;)
	{
		comp++;
		for (i = h; i < size; i++)
		{
			comp++;
			for (j = size - 1; j >= i; j--)
			{
				comp++;
				if (a[j - 1] > a[j])
				{
					temp = a[j - 1];
					a[j - 1] = a[j];
					a[j] = temp;
					comp++;
					sub = sub + 3;
				}
				sub++;
			}
			sub++;
		}
		sub++;
	}
	//PrintArray(a, size);
	//PrintArray(A, size);
	PrintStats(sub, comp);
}

void Heapify(float A[], int i, int HeapSize)
{
	int l, r, largest;
	float x;
	l = LEFT(i);
	r = RIGHT(i);
	if (l < HeapSize && A[l] > A[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < HeapSize && A[r] > A[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		x = A[i];
		A[i] = A[largest];
		A[largest] = x;
		Heapify(A, largest, HeapSize);
	}
}

void BuildHeap(float A[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
	{
		Heapify(A, i, n);
	}
}

void HeapSort(float A[], int n)
{
	int i, HeapSize = n;
	float x;
	float *af = CopyFloatArray(A, n);
	BuildHeap(af, n);
	for (i = n - 1; i > 0; i--)
	{
		x = af[0];
		af[0] = af[i];
		af[i] = x;
		Heapify(af, 0, --HeapSize);
	}
	PrintArrayFloat(af, n);
}