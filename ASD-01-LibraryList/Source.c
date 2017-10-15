#define _CRT_SECURE_NO_WARNINGS
#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

/*
	One way list with functions.

	TODO:
	- Remove Value recursive.

*/

void AddUntilNegativeFront(ListEl *list_el)
{
	int x;
	int loop = 1;
	do
	{
		x = SetValue();
		if (x >= 0)
		{
			AddToListFront(list_el, x);
		}
		else
		{
			loop = 0;
		}
	} 
	while (loop == 1);
}

void AddUntilNegativeBack(ListEl *list_el)
{
	int x;
	int loop = 1;
	do
	{
		x = SetValue();
		if (x >= 0)
		{
			AddToListBack(list_el, x);
		}
		else
		{
			loop = 0;
		}
	} while (loop == 1);
}

void RemoveValue(ListEl *list_el)
{
	int x;
	x = SetValue();
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		ListEl previous_element = *list_el;
		while (current_element != NULL)
		{
			if (current_element->value == x)
			{
				if (current_element == previous_element)
				{
					previous_element = current_element->next;
					*list_el = previous_element;
					free(current_element);
					current_element = previous_element;
				}
				else
				{
					previous_element->next = current_element->next;
					free(current_element);
					current_element = previous_element;
				}
			}
			else
			{
				previous_element = current_element;
				current_element = current_element->next;
			}
		}
	}
}

void MainMenu()
{
	printf("1. Add to list front.\n");
	printf("2. Add to list back.\n");
	printf("3. Remove from front of the list.\n");
	printf("4. Remove from back of the list.\n");
	printf("5. Clear List.\n");
	printf("6. Seek Value.\n");
	printf("7. View List.\n");
	printf("8. View List Backwards.\n");
	printf("//------------------------------------------------------//\n");
	printf("11. Add from front until user set negative value.\n");
	printf("12. Add from back until user set negative value.\n");
	printf("13. Remove Value from the list.\n");
	printf("0. Exit.\n");
}

int ChooseOption()
{
	int option;
	printf("Choose option: ");
	scanf(" %d", &option);
	return option;
}

int main()
{
	List *list_el = NULL;

	int x;
	int loop = 1;
	do
	{
		system("cls");
		MainMenu();
		int option = ChooseOption();
		switch (option)
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
			RemoveValue(&list_el);
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
	return 0;
}