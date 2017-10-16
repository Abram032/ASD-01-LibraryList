#define _CRT_SECURE_NO_WARNINGS
#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

/*
	One way list with functions.

	TODO:
	- Remove Value recursive.
	- Flip List recursive.

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
	} while (loop == 1);
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

void RemoveValue(ListEl *list_el, int x)
{
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

void RemoveValueRecursive(ListEl *list_el, int x)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl previous_element = *list_el;
		ListEl current_element = previous_element->next;
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
			RemoveValueRecursive(&(*list_el)->next, x);
		}
	}
}

void MostFrequentValue(ListEl *list_el)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		int array_size = 0;
		int *value_array, *count_array;
		int value, count;
		int position = 0;
		int value_exists, value_position;
		while (current_element != NULL)
		{
			array_size++;
			current_element = current_element->next;
		}
		current_element = *list_el;
		value_array = (int*)malloc(array_size * sizeof(*value_array));
		count_array = (int*)malloc(array_size * sizeof(*count_array));
		while (current_element != NULL)
		{
			value = current_element->value;
			value_exists = 0;
			for (int i = 0; i < array_size; i++)
			{
				if (value == value_array[i])
				{
					value_exists = 1;
					value_position = i;
					break;
				}
			}
			if (value_exists == 1)
			{
				count_array[value_position]++;
			}
			else
			{
				value_array[position] = value;
				count_array[position] = 1;
			}
			position++;
			current_element = current_element->next;
		}
		count = 0;
		for (int i = 0; i < array_size; i++)
		{
			if (count_array[i] > count)
			{
				count = count_array[i];
				value_position = i;
			}
		}
		value = value_array[value_position];
		count = count_array[value_position];
		printf("The most occuring value is %d. It appeared %d times in list.\n", value, count);
	}
}

void RemoveEven(ListEl *list_el)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		ListEl previous_element = *list_el;
		while (current_element != NULL)
		{
			if (current_element->value % 2 == 0)
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

/*
void ASDHwMyWay(ListEl *list_el)
{
	ListEl previous_element = *list_el;
	ListEl current_element = *list_el;
	ListEl future_element = *list_el;
	while (current_element->next != NULL)
	{
		previous_element = malloc(sizeof(List));
		future_element = future_element->next;
		previous_element->value = future_element->value - 1;
		previous_element->next = future_element;
		current_element->next = previous_element;
		current_element = previous_element->next;
	}
}
*/

void MainMenu()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to list front.\n");
	printf("2. Add to list back.\n");
	printf("3. Remove from front of the list.\n");
	printf("4. Remove from back of the list.\n");
	printf("5. Clear List.\n");
	printf("6. Seek Value.\n");
	printf("7. View List.\n");
	printf("8. View List Backwards.\n");
	printf("------------------------------------------------------\n");
	printf("11. Add from front until user set negative value.\n");
	printf("12. Add from back until user set negative value.\n");
	printf("13. Remove Value from the list.\n");
	printf("14. Remove Value recursive from the list.\n");
	printf("15. Find most occuring value in the list.\n");
	printf("16. Remove even values from the list.\n");
	printf("------------------------------------------------------\n");
	printf("20. Flip List.\n");
	printf("------------------------------------------------------\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
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

	//List *l, *p, *n;  //Used in menu option 99

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
			/*
		case 98:
			ASDHwMyWay(&list_el);
			ViewList(&list_el);
			system("pause");
			break;
		case 99:
			l = list_el;
			p = list_el;
			n = l;
			while (l->next != NULL)
			{
				p = malloc(sizeof(List));
				n = n->next;
				p->value = n->value - 1;
				p->next = n;
				l->next = p;
				l = p->next;
			}
			ViewList(&list_el);
			system("pause");
			break;
			*/
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