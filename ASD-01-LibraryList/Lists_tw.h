#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct TWListElement
{
	int value;
	struct TWListElement *next;
	struct TWListElement *prev;
};

typedef struct TWListElement TWList;
typedef TWList *TWListEl;

int TWListEmpty(TWListEl *tw_list_el)
{
	if (tw_list_el != NULL)
	{
		return 0;
	}
	else
	{
		printf("List is empty!\n");
		return 1;
	}
}

void AddToTWList(TWListEl *tw_list_el, int x)
{
	TWListEl new_element = malloc(sizeof(TWList));
	new_element->value = x;

	if (TWListEmpty(*tw_list_el) == 1)
	{
		new_element->next = NULL;
		new_element->prev = NULL;
		*tw_list_el = new_element;
	}
	else
	{
		TWListEl current_element = *tw_list_el;
		TWListEl future_element = current_element->next;
		if (current_element->value >= x)
		{
			new_element->next = current_element;
			new_element->prev = NULL;
			current_element->prev = new_element;
			*tw_list_el = new_element;
		}
		else
		{
			while (current_element->next != NULL)
			{
				if (future_element->value >= x)
				{
					break;
				}
				else
				{
					current_element = future_element;
					future_element = future_element->next;
				}
			}
			current_element->next = new_element;
			new_element->prev = current_element;
			if (future_element != NULL)
			{
				future_element->prev = new_element;
				new_element->next = future_element;
			}
			else
			{
				future_element = new_element;
				future_element->next = NULL;
			}
		}
	}
}

void SeekValueTW(TWListEl *tw_list_el, int x)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl current_element = *tw_list_el;
		int i = 1;
		while (current_element != NULL)
		{
			if (current_element->value == x)
			{
				printf(" %d is on the %d position.\n", x, i);
				current_element = current_element->next;
				i++;
			}
			else
			{
				current_element = current_element->next;
				i++;
			}
		}
	}
}

void RemoveElementTW(TWListEl *tw_list_el)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl current_element = *tw_list_el;
		TWListEl previous_element = current_element->prev;
		TWListEl future_element = current_element->next;
		if (previous_element != NULL)
		{
			previous_element->next = future_element;
		}
		else
		{
			*tw_list_el = future_element;
		}
		if (future_element != NULL)
		{
			future_element->prev = previous_element;
		}
		free(current_element);
	}
}

void RemoveValueTW(TWListEl *tw_list_el, int x)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl current_element = *tw_list_el;
		while (current_element != NULL)
		{
			if (current_element->value == x)
			{
				if (current_element == *tw_list_el)
				{
					*tw_list_el = (*tw_list_el)->next;
					free(current_element);
				}
				else
				{
					RemoveElementTW(&current_element);
				}
				break;
			}
			else
			{
				current_element = current_element->next;
			}
		}
	}
}

void ViewTWList(TWListEl *tw_list_el)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl current_element = *tw_list_el;
		int x, i = 1;
		while (current_element != NULL)
		{
			x = current_element->value;
			printf("[%d]. %d\n", i, x);
			i++;
			current_element = current_element->next;
		}
	}
}

void ClearTWList(TWListEl *tw_list_el)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		while (*tw_list_el != NULL)
		{
			RemoveElementTW(tw_list_el);
		}
	}
}