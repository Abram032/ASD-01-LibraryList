#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct ListElement
{
	int value;
	struct ListElement *next;
};

typedef struct ListElement List;
typedef List *ListEl;

int ListEmpty(ListEl *list_el)
{
	if (list_el != NULL)
	{
		return 0;
	}
	else
	{
		printf("List is empty!\n");
		return 1;
	}
}

int SetValue()
{
	int x;
	printf("Set value: ");
	scanf(" %d", &x);
	return x;
}

void AddToListFront(ListEl *list_el, int x)
{
	ListEl new_element = malloc(sizeof(List));
	new_element->value = x;
	new_element->next = *list_el;
	*list_el = new_element;
}

void AddToListBack(ListEl *list_el, int x)
{
	if (*list_el != NULL)
	{
		ListEl current_element = *list_el;
		while (current_element->next != NULL)
		{
			current_element = current_element->next;
		}
		ListEl new_element = malloc(sizeof(List));
		new_element->value = x;
		new_element->next = NULL;
		current_element->next = new_element;
	}
	else
	{
		AddToListFront(list_el, x);
	}

}

void ViewList(ListEl *list_el)
{
	int i = 0;
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		while (current_element != NULL)
		{
			i++;
			printf(" [%d]. %d\n", i, current_element->value);
			current_element = current_element->next;
		}
		free(current_element);
	}
}

void ViewListBackwards(ListEl *list_el)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		int size = 0;
		int i = 0;
		int *reversed_array;
		while (current_element != NULL)
		{
			size++;
			current_element = current_element->next;
		}
		current_element = *list_el;
		reversed_array = (int*)malloc(size * sizeof(*reversed_array));
		while (current_element != NULL)
		{
			reversed_array[i] = current_element->value;
			current_element = current_element->next;
			i++;
		}
		for (i = size - 1; i >= 0; i--)
		{
			printf(" [%d]. %d\n", size - i, reversed_array[i]);
		}
		free(reversed_array);
		free(current_element);
	}
}

void SeekValue(ListEl *list_el, int x)
{
	if (ListEmpty(*list_el) == 0)
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
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		*list_el = current_element->next;
		free(current_element);
	}
}

void RemoveFromListBack(ListEl *list_el)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		ListEl last_element = *list_el;
		while (current_element->next != NULL)
		{
			last_element = current_element;
			current_element = current_element->next;
		}
		if (last_element->next != NULL)
		{
			last_element->next = NULL;
			free(current_element);
		}
		else
		{
			*list_el = NULL;
			free(current_element);
		}
	}
}

void ClearList(ListEl *list_el)
{
	while (*list_el != NULL)
	{
		ListEl current_element = *list_el;
		*list_el = current_element->next;
		free(current_element);
	}
}