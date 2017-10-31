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

/*
	One way list with functions.

	TODO:
	- Flip List recursive.
	- Check sorting algorithms.
	- ADD COMMENTS !!!
*/

int main()
{
	List *list_el = NULL;
	List *list_a = NULL;
	List *list_b = NULL;
	List *list_aw = NULL;
	List *list_bw = NULL;
	TWList *tw_list_el = NULL;
	TWList *twc_list_el = NULL;

	int x;
	int loop = 1;
	int ow_loop = 1;
	int tw_loop = 1;
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
					system("pause");
					break;
				default:
					printf("\nUnknown option.");
					break;
				}
			} while (ow_loop == 1);
			break;
		case 2:
			do
			{
				system("cls");
				int option_tw = ChooseOption();
			} while (tw_loop == 1);
			system("pause");
			break;
		case 3:
			system("pause");
			break;
		case 4:
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