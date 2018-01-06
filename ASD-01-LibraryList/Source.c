#define _CRT_SECURE_NO_WARNINGS
#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"
#include "Functions.h"
#include "Menu.h"
#include "Sorting.h"
#include "TestInput.h"
#include "Lists_tw.h"
#include "Lists_twc.h"
#include "Lists_prior.h"
#include "Tree_Binary.h"
#include "PD.h"
#include "ONP2.h"
#include "TestInput_Tree.h"
#include "Sort.h"
#include "Graphs.h"

/*
	One way list with functions.

	TODO:
	- ADD COMMENTS !!!
*/

int main()
{
	List *list_el = NULL;
	List *list_el_ca = NULL;
	List *list_el_cb = NULL;
	List *list_a = NULL;
	List *list_b = NULL;
	List *list_aw = NULL;
	List *list_bw = NULL;
	TWList *tw_list_el = NULL;
	TWList *twc_list_el = NULL;
	PriorList *prior_list_el = NULL;

	TWList *twc_pd = NULL;
	TWList *twc_pd_a = NULL;
	TWList *twc_pd_b = NULL;
	ONPS *onp_el = NULL;

	BinTree *b_tree = NULL;
	BinTree *b_tree_a = NULL;
	BinTree *b_tree_re = NULL;
	BinTreeEl *nul = NULL;
	char buffer[2048];

	char operand;
	int x, p, key;
	int n, nl;
	int loop = 1;
	int ow_loop = 1;
	int owc_loop = 1;
	int tw_loop = 1;
	int twc_loop = 1;
	int prior_loop = 1;
	int graph_loop = 1;
	
	int pd_loop = 1;

	int bintree_loop = 1;

	int sort_loop = 1;
	int *A, *a, *b;
	float *AF;

	int ** M;
	int ** MR;
	List *ML = NULL;
	List *MLR = NULL;

	Input_Tree(&b_tree);
	Input_Tree2(&b_tree_a);
	
	do
	{
		system("cls");
		MainMenu();
		int option = ChooseOption();
		switch (option)
		{
		case 1:
			ow_loop = 1;
			do
			{
				system("cls");
				MainMenuOneWay();
				int option_ow = ChooseOption();
				switch (option_ow)
				{
				case 1:
					x = SetValue();
					AddToListFront(&list_el, x);
					break;
				case 2:
					x = SetValue();
					AddToListBack(&list_el, x);
					break;
				case 3:
					RemoveFromListFront(&list_el);
					system("pause");
					break;
				case 4:
					RemoveFromListBack(&list_el);
					system("pause");
					break;
				case 5:
					ClearList(&list_el);
					system("pause");
					break;
				case 6:
					x = SetValue();
					SeekValue(&list_el, x);
					system("pause");
					break;
				case 7:
					ViewList(&list_el);
					system("pause");
					break;
				case 8:
					ViewListBackwards(&list_el);
					system("pause");
					break;
				case 11:
					AddUntilNegativeFront(&list_el);
					ViewList(&list_el);
					printf("---\n");
					ViewListBackwards(&list_el);
					system("pause");
					break;
				case 12:
					AddUntilNegativeBack(&list_el);
					ViewList(&list_el);
					printf("---\n");
					ViewListBackwards(&list_el);
					system("pause");
					break;
				case 13:
					x = SetValue();
					RemoveValue(&list_el, x);
					system("pause");
					break;
				case 14:
					x = SetValue();
					RemoveValueRecursive(&list_el, x);
					system("pause");
					break;
				case 15:
					MostFrequentValue(&list_el);
					system("pause");
					break;
				case 16:
					RemoveEven(&list_el);
					system("pause");
					break;
				case 20:
					FlipList(&list_el);
					system("pause");
					break;
				case 21:
					FlipListRecursive(&list_el);
					system("pause");
					break;
				case 22:
					SortList(&list_el);
					system("pause");
					break;
				case 23:
					x = SetValue();
					AddToListSortedNG(&list_el, x);
					system("pause");
					break;
				case 24:
					x = SetValue();
					AddToListSortedWG(&list_el, x);
					system("pause");
					break;
				case 31:
					x = SetValue();
					AddToListSortedWG(&list_a, x);
					system("pause");
					break;
				case 32:
					x = SetValue();
					AddToListSortedWG(&list_b, x);
					system("pause");
					break;
				case 33:
					ViewList(&list_a);
					system("pause");
					break;
				case 34:
					ViewList(&list_b);
					system("pause");
					break;
				case 35:
					CompareLists(&list_a, &list_b, &list_aw, &list_bw);
					system("pause");
					break;
				case 36:
					ConnectAndSortLists(&list_a, &list_b);
					system("pause");
					break;
				case 37:
					ConnectLists(&list_a, &list_b);
					system("pause");
					break;
				case 99:
					ow_loop = 0;
					system("pause");
					break;
				case 0:
					ow_loop = 0;
					loop = 0;
					break;
				default:
					printf("\nUnknown option.\n");
					break;
				}
			} while (ow_loop == 1);
			break;
		case 2:
			tw_loop = 1;
			do
			{
				system("cls");
				MainMenuTwoWay();
				int option_tw = ChooseOption();
				switch (option_tw)
				{
				case 1:
					x = SetValue();
					AddToTWList(&tw_list_el, x);
					system("pause");
					break;
				case 2:
					RemoveElementTW(&tw_list_el);
					system("pause");
					break;
				case 3:
					x = SetValue();
					SeekValueTW(&tw_list_el, x);
					system("pause");
					break;
				case 4:
					x = SetValue();
					RemoveValueTW(&tw_list_el, x);
					system("pause");
					break;
				case 5:
					ViewTWList(&tw_list_el);
					system("pause");
					break;
				case 6:
					ClearTWList(&tw_list_el);
					system("pause");
					break;
				case 99:
					tw_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					tw_loop = 0;
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (tw_loop == 1);
			system("pause");
			break;
		case 3:
			twc_loop = 1;
			do
			{
				system("cls");
				MainMenuTwoWayCyclic();
				int option_twc = ChooseOption();
				switch (option_twc)
				{
				case 1:
					x = SetValue();
					AddToTWCList(&twc_list_el, x);
					system("pause");
					break;
				case 2:
					MoveTWC(&twc_list_el);
					system("pause");
					break;
				case 3:
					RemoveElementTWC(&twc_list_el);
					system("pause");
					break;
				case 4:
					x = SetValue();
					SeekValueTWC(&twc_list_el, x);
					system("pause");
					break;
				case 5:
					x = SetValue();
					RemoveValueTWC(&twc_list_el, x);
					system("pause");
					break;
				case 6:
					ViewTWCList(&twc_list_el);
					system("pause");
					break;
				case 7:
					ClearTWCList(&twc_list_el);
					system("pause");
					break;
				case 8:
					ScrollTWC(&twc_list_el);
					system("pause");
					break;
				case 9:
					x = SetValue();
					RemoveUntilOne(&twc_list_el, x);
					system("pause");
					break;
				case 99:
					twc_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					twc_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (twc_loop == 1);
			system("pause");
			break;
		case 4:
			owc_loop = 1;
			do
			{
				system("cls");
				MainMenuOneWayCyclic();
				int option_twc = ChooseOption();
				switch (option_twc)
				{
				case 1:
					x = SetValue();
					AddToListCyclic(&list_el_ca, x);
					system("pause");
					break;
				case 2:
					RemoveFromListCyclic(&list_el_ca);
					system("pause");
					break;
				case 3:
					x = SetValue();
					RemoveValueFromListCyclic(&list_el_ca, x);
					system("pause");
					break;
				case 4:
					ViewListCyclic(&list_el_ca);
					system("pause");
					break;
				case 5:
					ClearListCyclic(&list_el_ca);
					system("pause");
					break;
				case 6:
					x = SetValue();
					AddToListCyclic(&list_el_cb, x);
					system("pause");
					break;
				case 7:
					RemoveFromListCyclic(&list_el_cb);
					system("pause");
					break;
				case 8:
					x = SetValue();
					RemoveValueFromListCyclic(&list_el_cb, x);
					system("pause");
					break;
				case 9:
					ViewListCyclic(&list_el_cb);
					system("pause");
					break;
				case 10:
					ClearListCyclic(&list_el_cb);
					system("pause");
					break;
				case 11:
					RemoveValuesFromLists(&list_el_ca, &list_el_cb);
					system("pause");
					break;
				case 99:
					owc_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					owc_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (owc_loop == 1);
			system("pause");
			break;
		case 5:
			prior_loop = 1;
			do
			{
				system("cls");
				MainMenuPriorList();
				int option_prior = ChooseOption();
				switch (option_prior)
				{
				case 1:
					x = SetValue();
					printf("Set priority: \n");
					p = SetValue();
					AddToPriorList(&prior_list_el, x, p);
					system("pause");
					break;
				case 2:
					RemoveFromPriorList(&prior_list_el);
					system("pause");
					break;
				case 3:
					x = SetValue();
					printf("Set priority: \n");
					p = SetValue();
					ChangePriortiy(&prior_list_el, x, p);
					system("pause");
					break;
				case 4:
					ViewPriorList(&prior_list_el);
					system("pause");
					break;
				case 5:
					ClearPriorList(&prior_list_el);
					system("pause");
					break;
				case 99:
					prior_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					prior_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (prior_loop == 1);
			system("pause");
			break;
		case 6:
			bintree_loop = 1;
			do
			{
				system("cls");
				MainMenuBinaryTree();
				int option_bintree = ChooseOption();
				switch (option_bintree)
				{
				case 1:
					printf("Put data: ");
					scanf("%s", buffer);
					AddToBinTree(&b_tree, &nul, buffer);
					memset(buffer, 0, sizeof buffer);
					system("pause");
					break;
				case 2:
					ViewTree(&b_tree);
					system("pause");
					break;
				case 3:
					printf("Put data: ");
					scanf("%s", buffer);
					b_tree_re = SearchTree(&b_tree, buffer);
					memset(buffer, 0, sizeof buffer);
					system("pause");
					break;
				case 4:
					b_tree_re = MinTree(&b_tree);
					printf("%s", b_tree_re->data);
					system("pause");
					break;
				case 5:
					b_tree_re = MaxTree(&b_tree);
					system("pause");
					break;
				case 6:
					printf("Put data: ");
					scanf("%s", buffer);
					RemoveFromTree(&b_tree, buffer);
					memset(buffer, 0, sizeof buffer);
					system("pause");
					break;
				case 7:
					x = MaxDepth(b_tree);
					printf("Max depth in tree: %d\n", x);
					system("pause");
					break;
				case 8:
					x = CountLeaves(&b_tree);
					printf("Amount of leaves: %d\n", x);
					system("pause");
					break;
				case 11:
					b_tree_re = GetNext(&b_tree);
					system("pause");
					break;
				case 12:
					b_tree_re = GetLast(&b_tree);
					system("pause");
					break;
				case 20:
					CompareTrees(b_tree, b_tree_a);
					system("pause");
					break;
				case 99:
					bintree_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					bintree_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (bintree_loop == 1);
			system("pause");
			break;
		case 7:
			sort_loop = 1;
			do
			{
				system("cls");
				MainMenuSorting();
				int sort_option = ChooseOption();
				switch (sort_option)
				{
				case 1:
					x = SetValue();
					A = Generate(x);
					BubbleSort(A, x);
					PrintArray(A, x);
					system("pause");
					break;
				case 2:
					x = SetValue();
					A = Generate(x);
					InsertionSort(A, x);
					PrintArray(A, x);
					system("pause");
					break;
				case 3:
					x = SetValue();
					A = Generate(x);
					ShellSort(A, x);
					PrintArray(A, x);
					system("pause");
					break;
				case 4:
					x = SetValue();
					A = Generate(x);
					a = CopyArray(A, x);
					QuickSort(a, 0, x - 1);
					PrintArray(A, x);
					PrintArray(a, x);
					system("pause");
					break;
				case 5:
					x = SetValue();
					A = Generate(x);
					a = CopyArray(A, x);
					QSort(a, 0, x - 1);
					PrintArray(A, x);
					PrintArray(a, x);
					system("pause");
					break;
				case 6:
					x = SetValue();
					A = Generate(x);
					printf("Bubble Sort:\n");
					BubbleSort(A, x);
					printf("Insertion Sort:\n");
					InsertionSort(A, x);
					printf("Shell Sort:\n");
					ShellSort(A, x);
					printf("Quick Sort:\n");
					QuickSortStart(A, x);
					//printf("Quick Sort (ASD):\n");
					//QSortStart(A, x);
					system("pause");
					break;
				case 10:
					x = SetValue();
					AF = GenerateFloat(x);
					HeapSort(AF, x);
					PrintArrayFloat(AF, x);
					system("pause");
					break;
				case 99:
					sort_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					sort_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (sort_loop == 1);
			system("pause");
			break;
		case 8:
			graph_loop = 1;
			do
			{
				system("cls");
				MainMenuGraphs();
				int graph_option = ChooseOption();
				switch (graph_option)
				{
				case 1:
					printf("Matrix size [n][n]: ");
					scanf(" %d", &n);
					M = LoadMatrixGraph(n);
					system("pause");
					break;
				case 2:
					printf("Amount of lists [n]->[l]: ");
					scanf(" %d", &nl);
					ML = LoadListGraph(nl);
					system("pause");
					break;
				case 3:
					ViewMatrix(M, n);
					system("pause");
					break;
				case 4:
					ViewMLists(ML, nl);
					system("pause");
					break;
				case 10:
					M = TransformL2M(ML, nl);
					ViewMatrix(M, nl);
					system("pause");
					break;
				case 11:
					ViewMLists(ML, nl);
					printf("\n");
					M = TransformL2M(ML, nl);
					//ViewMatrix(M, nl);
					//printf("\n");
					MR = ReverseMatrix(M, nl);
					//ViewMatrix(MR, nl);
					//printf("\n");
					MLR = TransformM2L(MR, nl);
					ViewMLists(MLR, nl);
					system("pause");
					break;
				case 99:
					graph_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					graph_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (graph_loop == 1);
			system("pause");
			break;
		case 90:
			pd_loop = 1;
			do
			{
				system("cls");
				MainMenuPD();
				int option_PD = ChooseOption();
				switch (option_PD)
				{
				case 1:
					//SetEquation();
					system("pause");
					break;
				case 99:
					pd_loop = 0;
					system("pause");
					break;
				case 0:
					loop = 0;
					pd_loop = 0;
					system("pause");
					break;
				default:
					printf("\nUnknown option.\n");
					system("pause");
					break;
				}
			} while (pd_loop == 1);
			system("pause");
			break;
		case 0:
			loop = 0;
			system("pause");
			break;
		default:
			printf("\nUnknown option.");
			break;
		}
	} while (loop == 1);
	ClearList(&list_el);
	ClearList(&list_a);
	ClearList(&list_b);
	ClearList(&list_aw);
	ClearList(&list_bw);
	return 0;
}