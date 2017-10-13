#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	One way list with functions.
*/

struct ListElement
{
	int value;
	struct element *next;
};

typedef struct ListElement List;
typedef List *ListEl;

int ListEmpty(ListEl list_el)
{
	if ((list_el) == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int SetValue()
{
	int x;
	printf("Put value: ");
	scanf(" %d", &x);
	return x;
}

void AddToListFront(ListEl *list_el, int x)
{
	ListEl new_element = malloc(sizeof(ListEl));
	new_element->value = x;
	new_element->next = *list_el;
	*list_el = new_element;
}

void AddToListBack(ListEl *list_el, int x)
{
	ListEl current_element = *list_el;
	while (current_element->next != NULL)
	{
		current_element = current_element->next;
	}
	ListEl new_element = malloc(sizeof(ListEl));
	new_element->value = x;
	new_element->next = NULL;
	current_element->next = new_element;
}

void ViewList(ListEl *list_el)
{
	int i = 0;
	if (ListEmpty(list_el) == 0)
	{
		ListEl current_element = *list_el;
		while (current_element != NULL)
		{
			i++;
			printf(" %d - %d\n", i, current_element->value);
			current_element = current_element->next;
		}
	}
}

void ViewListBackwards(ListEl *list_el)
{
	ListEl current_element = *list_el;
	int size = 0;
	int i = 0;
	int *reversed_array;
	while (current_element->next != NULL)
	{
		size++;
		current_element = current_element->next;
	}
	current_element = *list_el;
	reversed_array = (int*)malloc(size * sizeof(*reversed_array));
	for (i = size; i >= 0; i--)
	{
		reversed_array[i] = current_element->value;
		current_element = current_element->next;
	}
	for (i = 0; i <= size; i++)
	{
		printf(" %d. %d\n", i + 1, reversed_array[i]);
	}
	free(reversed_array);
}

void SeekValue(ListEl *list_el, int x)
{
	if (ListEmpty(list_el) == 0)
	{
		int i = 0;
		ListEl current_element = *list_el;
		while (current_element != NULL)
		{
			if (current_element->value == x)
			{
				i++;
				printf("Value %d is at %d position in the list.\n", x, i);
			}
			i++;
			current_element = current_element->next;
		}
	}
}

void RemoveFromListFront(ListEl *list_el)
{
	if (ListEmpty(list_el) == 0)
	{
		ListEl current_element = *list_el;
		*list_el = current_element->next;
		free(current_element);
	}
}

void RemoveFromListBack(ListEl *list_el)
{
	if (ListEmpty(list_el) == 0)
	{
		ListEl current_element = *list_el;
		ListEl last_element = *list_el;
		while (current_element->next != NULL)
		{
			last_element = current_element;
			current_element = current_element->next;
		}
		last_element->next = NULL;
		free(current_element);
	}
}

void MainMenu()
{
	printf("1. Add to list front.\n");
	printf("2. Add to list back.\n");
	printf("3. Remove from front of the list.\n");
	printf("4. Remove from back of the list.\n");
	printf("5. View List Backwards.\n");
	printf("6. Seek Value.\n");
	printf("10. View List.\n");
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
	List *prev = NULL;

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
			break;
		case 4:
			RemoveFromListBack(&list_el);
			break;
		case 5:
			ViewListBackwards(&list_el);
			system("pause");
			break;
		case 6:
			x = SetValue();
			SeekValue(&list_el, x);
			system("pause");
			break;
		case 10:
			ViewList(&list_el);
			system("pause");
			break;
		case 0:
			loop = 0;
			break;
		default:
			printf("\nUnknown option.");
			break;
		}
	} while (loop == 1);

	return 0;
}