#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Lists.h"

void AddToListCyclic(ListEl *list_elc, int x)
{
	ListEl new_element = malloc(sizeof(List));
	new_element->value = x;
	if (ListEmpty(*list_elc) == 1)
	{
		new_element->next = new_element;
		*list_elc = new_element;
	}
	else
	{
		ListEl flag = *list_elc;
		ListEl current_element = *list_elc;
		do
		{
			current_element = current_element->next;
		} while (current_element->next != flag);
		current_element->next = new_element;
		new_element->next = *list_elc;
	}
}

void ViewListCyclic(ListEl *list_elc)
{
	int i = 0;
	if (ListEmpty(*list_elc) == 0)
	{
		ListEl current_element = *list_elc;
		ListEl flag = *list_elc;
		do
		{
			i++;
			printf(" [%d]. %d\n", i, current_element->value);
			current_element = current_element->next;
		} while (current_element != flag);
	}
}

void RemoveFromListCyclic(ListEl *list_elc)
{
	if (ListEmpty(*list_elc) == 0)
	{
		ListEl previous_element = *list_elc;
		ListEl current_element = *list_elc;
		ListEl flag = *list_elc;
		do
		{
			previous_element = current_element;
			current_element = current_element->next;
		} while (current_element->next != flag);
		if (current_element->next == current_element)
		{
			*list_elc = NULL;
		}
		previous_element->next = flag;
		free(current_element);
	}
}

void RemoveValueFromListCyclic(ListEl *list_elc, int x)
{
	if (ListEmpty(*list_elc) == 0)
	{
		ListEl current_element = *list_elc;
		ListEl previous_element = *list_elc;
		ListEl flag = *list_elc;
		while (previous_element->next != flag)
		{
			previous_element = previous_element->next;
		}
		do
		{
			if (current_element->next == previous_element)
			{
				previous_element = current_element;
				current_element = current_element->next;
			}
			if (current_element->value == x)
			{
				while (current_element->value == x)
				{
					if (current_element == *list_elc)
					{
						*list_elc = (*list_elc)->next;
						if (current_element == *list_elc)
						{
							*list_elc = NULL;
						}
						flag = *list_elc;
					}
					previous_element->next = current_element->next;
					free(current_element);
					current_element = previous_element->next;
				}
			}
			else
			{
				previous_element = current_element;
				current_element = current_element->next;
			}
		} while (flag != NULL && current_element->next != flag);
	}
}


void ClearListCyclic(ListEl *list_elc)
{
	while (*list_elc != NULL)
	{
		RemoveFromListCyclic(list_elc);
	}
}

void RemoveValuesFromLists(ListEl *list_el_ca, ListEl *list_el_cb)
{
	int x;
	ListEl flag = *list_el_ca;
	ListEl current_element = *list_el_ca;
	do
	{
		x = current_element->value;
		RemoveValueFromListCyclic(list_el_cb, x);
		current_element = current_element->next;
	} while (current_element != flag);
}