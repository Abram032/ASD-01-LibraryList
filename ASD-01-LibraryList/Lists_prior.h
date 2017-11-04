#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct PriorListElement
{
	int value;
	int priority;
	struct PriorListElement *next;
	struct PriorListElement *prev;
};

typedef struct PriorListElement PriorList;
typedef PriorList *PriorListEl;

int PriorListEmpty(PriorListEl *prior_list_el)
{
	if (prior_list_el != NULL)
	{
		return 0;
	}
	else
	{
		printf("List is empty!\n");
		return 1;
	}
}

void AddToPriorList(PriorListEl *prior_list_el, int x, int p)
{
	PriorListEl new_element = malloc(sizeof(PriorList));
	new_element->value = x;
	new_element->priority = p;
	if (PriorListEmpty(*prior_list_el) == 1)
	{
		*prior_list_el = new_element;
		new_element->next = NULL;
		new_element->prev = NULL;
	}
	else
	{
		PriorListEl current_element = *prior_list_el;
		PriorListEl future_element = current_element->next;
		if (current_element->priority <= p)
		{
			new_element->next = current_element;
			new_element->prev = NULL;
			current_element->prev = new_element;
			*prior_list_el = new_element;
		}
		else
		{
			while (current_element->next != NULL)
			{
				if (future_element->priority <= p)
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

void RemoveFromPriorList(PriorListEl *prior_list_el)
{
	if (PriorListEmpty(*prior_list_el) == 0)
	{
		TWListEl current_element = *prior_list_el;
		TWListEl previous_element = current_element->prev;
		TWListEl future_element = current_element->next;
		if (previous_element != NULL)
		{
			previous_element->next = future_element;
		}
		else
		{
			*prior_list_el = future_element;
		}
		if (future_element != NULL)
		{
			future_element->prev = previous_element;
		}
		free(current_element);
	}
}

void ChangePriortiy(PriorListEl *prior_list_el, int x, int p)
{
	if (PriorListEmpty(*prior_list_el) == 0)
	{
		TWListEl current_element = *prior_list_el;
		while (current_element != NULL)
		{
			if (current_element->value == x)
			{
				if (current_element == *prior_list_el)
				{
					*prior_list_el = (*prior_list_el)->next;
					free(current_element);
				}
				else
				{
					RemoveFromPriorList(&current_element);
				}
				break;
			}
			else
			{
				current_element = current_element->next;
			}
		}
		AddToPriorList(prior_list_el, x, p);
	}
}

void ViewPriorList(PriorListEl *prior_list_el)
{
	if (PriorListEmpty(*prior_list_el) == 0)
	{
		int x, p, i = 1;
		PriorListEl current_element = *prior_list_el;
		printf("[i]. value | priority\n\n");
		while (current_element != NULL)
		{
			x = current_element->value;
			p = current_element->priority;
			printf("[%d]. %d | %d\n", i, x, p);
			current_element = current_element->next;
			i++;
		}
	}
}

void ClearPriorList(PriorListEl *prior_list_el)
{
	if (PriorListEmpty(*prior_list_el) == 0)
	{
		while (*prior_list_el != NULL)
		{
			RemoveFromPriorList(prior_list_el);
		}
	}
}