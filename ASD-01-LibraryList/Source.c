#define _CRT_SECURE_NO_WARNINGS
#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

/*
	One way list with functions.

	TODO:
	- Flip List recursive.
	- Sorting with guardian.
	- ADD COMMENTS !!!
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
		ListEl current_element = *list_el;
		if (current_element->value == x)
		{
			if (current_element == previous_element)
			{
				previous_element = current_element->next;
				*list_el = previous_element;
				free(current_element);
				current_element = previous_element;
				RemoveValueRecursive(&(*list_el), x);
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

void SortListNG(ListEl *list_el)
{
	ListEl current_element = *list_el;
	ListEl minimal_element = *list_el;
	ListEl minimum = *list_el;
	int temp_value;
	while (current_element != NULL)
	{
		minimum = current_element;
		while (minimal_element != NULL)
		{
			if (minimal_element->value <= minimum->value)
			{
				minimum = minimal_element;
				minimal_element = minimal_element->next;
			}
			else
			{
				minimal_element = minimal_element->next;
			}		
		}
		temp_value = current_element->value;
		current_element->value = minimum->value;
		minimum->value = temp_value;
		current_element = current_element->next;
		minimal_element = current_element;
	}
}

void SortListWG(ListEl *list_el)
{
	return;
}

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
	printf("22. Sort list (without guard).\n");
	printf("23. Sort list (with guard) WIP.\n");
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
		case 22:
			SortListNG(&list_el);
			system("pause");
			break;
		case 23:
			//SortListWG(&list_el);
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