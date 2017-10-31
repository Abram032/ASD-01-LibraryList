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

void MoveTWC(TWListEl *tw_list_el, int x)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		*tw_list_el = (*tw_list_el)->next;
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
			future_element->prev = new_element;
			new_element->prev = current_element;
			new_element->next = future_element;
		}
	}
}

void AddToTWCList(TWListEl *twc_list_el, int x)
{
	TWListEl new_element = malloc(sizeof(TWList));
	new_element->value = x;

	if (TWListEmpty(*twc_list_el) == 1)
	{
		new_element->next = new_element;
		new_element->prev = new_element;
		*twc_list_el = new_element;
	}
	else
	{
		TWListEl current_element = *twc_list_el;
		TWListEl future_element = current_element->next;
		while (future_element->value < x)
		{
			current_element = future_element;
			future_element = future_element->next;
		}
		current_element->next = new_element;
		future_element->prev = new_element;
		new_element->prev = current_element;
		new_element->next = future_element;
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
				printf(" %d is on the %d position", x, i);
			}
			else
			{
				current_element = current_element->next;
				i++;
			}
		}
	}
}

void SeekValueTWC(TWListEl *tw_list_el, int x)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl flag = *tw_list_el;
		TWListEl current_element = *tw_list_el;
		int i = 1;
		do
		{
			if (current_element->value == x)
			{
				printf(" %d is on the %d position", x, i);
			}
			else
			{
				current_element = current_element->next;
				i++;
			}
		} while (flag != current_element);
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
				RemoveElementTW(current_element);
				break;
			}
			else
			{
				current_element = current_element->next;
			}
		}
	}
}

void RemoveValueTWC(TWListEl *tw_list_el, int x)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl current_element = *tw_list_el;
		TWListEl flag = *tw_list_el;
		do
		{
			if (current_element->value == x)
			{
				RemoveElementTWC(current_element);
				break;
			}
			else
			{
				current_element = current_element->next;
			}
		} while (current_element != flag);
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
			printf("[%d]. %d", i, x);
			i++;
			current_element = current_element->next;
		}
	}
}

void ViewTWCList(TWListEl *tw_list_el)
{
	if (TWListEmpty(*tw_list_el) == 0)
	{
		TWListEl current_element = *tw_list_el;
		TWListEl flag = *tw_list_el;
		int x, i = 1;
		do
		{
			x = current_element->value;
			printf("[%d]. %d", i, x);
			i++;
			current_element = current_element->next;
		} while (current_element != flag);
	}
}