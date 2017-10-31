#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Lists_tw.h"

void MoveTWC(TWListEl *twc_list_el)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		*twc_list_el = (*twc_list_el)->next;
		printf("Current value: %d\n", (*twc_list_el)->value);
	}
}

void ScrollTWC(TWListEl *twc_list_el)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		int x = (*twc_list_el)->value;
		while ((*twc_list_el)->next->value >= x)
		{
			*twc_list_el = (*twc_list_el)->next;
			x = (*twc_list_el)->value;
		}
		*twc_list_el = (*twc_list_el)->next;
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
		TWListEl flag = *twc_list_el;
		TWListEl previous_element;
		if (x >= current_element->value)
		{
			while (current_element->value <= x)
			{
				current_element = current_element->next;
				if (current_element == flag)
				{
					break;
				}
			}
		}
		previous_element = current_element->prev;
		new_element->next = current_element;
		current_element->prev = new_element;
		previous_element->next = new_element;
		new_element->prev = previous_element;
		ScrollTWC(twc_list_el);
	}
}

void SeekValueTWC(TWListEl *twc_list_el, int x)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		TWListEl flag = *twc_list_el;
		TWListEl current_element = *twc_list_el;
		int i = 1;
		do
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
		} while (flag != current_element);
	}
}

void RemoveElementTWC(TWListEl *twc_list_el)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		TWListEl current_element = *twc_list_el;
		TWListEl previous_element = current_element->prev;
		TWListEl future_element = current_element->next;
		previous_element->next = future_element;
		future_element->prev = previous_element;
		*twc_list_el = future_element;
		if (current_element == future_element)
		{
			*twc_list_el = NULL;
		}
		free(current_element);
	}
}

void RemoveValueTWC(TWListEl *twc_list_el, int x)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		TWListEl current_element = *twc_list_el;
		TWListEl flag = *twc_list_el;
		do
		{
			if (current_element->value == x)
			{
				if (current_element == *twc_list_el)
				{
					*twc_list_el = (*twc_list_el)->next;
				}
				RemoveElementTWC(&current_element);
				if (current_element == NULL)
				{
					*twc_list_el = NULL;
				}
				break;
			}
			else
			{
				current_element = current_element->next;
			}
		} while (current_element != flag);
	}
}

void ViewTWCList(TWListEl *twc_list_el)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		TWListEl current_element = *twc_list_el;
		TWListEl flag = *twc_list_el;
		int x, i = 1;
		do
		{
			x = current_element->value;
			printf("[%d]. %d\n", i, x);
			i++;
			current_element = current_element->next;
		} while (current_element != flag);
	}
}

void ClearTWCList(TWListEl *twc_list_el)
{
	if (TWListEmpty(*twc_list_el) == 0)
	{
		while (*twc_list_el != NULL)
		{
			RemoveElementTWC(twc_list_el);
		}
	}
}