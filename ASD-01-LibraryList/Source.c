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
#include "ONP.h"

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

	char operand;
	int x, p, key;
	int loop = 1;
	int ow_loop = 1;
	int owc_loop = 1;
	int tw_loop = 1;
	int twc_loop = 1;
	int prior_loop = 1;
	
	int pd_loop = 1;

	int bintree_loop = 1;

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
					x = SetValue();
					AddToBinTree(&b_tree, x);
					system("pause");
					break;
				case 2:
					ViewBinTree(&b_tree);
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
					x = SetValue();
					TWList *result;
					result = PDSeekValueTWC(&twc_pd, x);
					if (result != NULL)
					{
						printf("Value = %d \n", result->value);
						printf("Address = %p \n", result);
					}
					else
					{
						printf("No value.\n");
					}
					system("pause");
					break;
				case 2:
					PDConnectTWCLists(&twc_pd_a, &twc_pd_b);
					system("pause");
					break;
				case 4:
					x = SetValue();
					AddToTWCList(&twc_pd, x);
					system("pause");
					break;
				case 5:
					x = SetValue();
					AddToTWCList(&twc_pd_a, x);
					system("pause");
					break;
				case 6:
					x = SetValue();
					AddToTWCList(&twc_pd_b, x);
					system("pause");
					break;
				case 10:
					ViewTWCList(&twc_pd);
					system("pause");
					break;
				case 11:
					ViewTWCList(&twc_pd_a);
					system("pause");
					break;
				case 12:
					ViewTWCList(&twc_pd_b);
					system("pause");
					break;
				case 20:
					key = SetKey();
					operand = NULL;
					AddToONPStack(&onp_el, key, operand);
					system("pause");
					break;
				case 21:
					key = SetKey();
					operand = NULL;
					AddToONPStackBack(&onp_el, key, operand);
					system("pause");
					break;
				case 22:
					operand = SetOperand();
					key = NULL;
					AddToONPStack(&onp_el, key, operand);
					system("pause");
					break;
				case 23:
					operand = SetOperand();
					key = NULL;
					AddToONPStackBack(&onp_el, key, operand);
					system("pause");
					break;
				case 24:
					RemoveFromONPStack(&onp_el);
					system("pause");
					break;
				case 25:
					ViewONPStack(&onp_el);
					system("pause");
					break;
				case 26:
					key = ExecuteEquation(&onp_el);
					printf("Result: %d\n", key);
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