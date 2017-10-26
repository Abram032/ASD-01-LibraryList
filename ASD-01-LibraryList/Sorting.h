#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"
#include "Sorting.h"
#include "Functions.h"
#include "Menu.h"

void SortList(ListEl *list_el)
{
	if (ListEmpty(list_el) == 0)
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
				}
				minimal_element = minimal_element->next;
			}
			temp_value = current_element->value;
			current_element->value = minimum->value;
			minimum->value = temp_value;
			current_element = current_element->next;
			minimal_element = current_element;
		}
	}
}

void AddToListSortedNG(ListEl *list_el, int x)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		ListEl future_element = current_element->next;
		ListEl new_element = malloc(sizeof(List));
		if (current_element->value >= x)
		{
			AddToListFront(list_el, x);
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
			future_element = current_element->next;
			new_element->value = x;
			current_element->next = new_element;
			new_element->next = future_element;
		}
	}
	else
	{
		AddToListFront(list_el, x);
	}
}

void AddToListSortedWG(ListEl *list_el, int x)
{
	if (ListEmpty(*list_el) == 0)
	{
		AddToListBack(list_el, x);
		ListEl current_element = *list_el;
		ListEl future_element = current_element->next;
		ListEl new_element = malloc(sizeof(List));
		if (current_element->value >= x)
		{
			AddToListFront(list_el, x);
			RemoveFromListBack(list_el);
		}
		else
		{
			while (future_element->value < x)
			{
				current_element = future_element;
				future_element = future_element->next;
			}
			future_element = current_element->next;
			new_element->value = x;
			current_element->next = new_element;
			new_element->next = future_element;
			RemoveFromListBack(list_el);
		}
	}
	else
	{
		AddToListFront(list_el, x);
	}
}

void CompareLists(ListEl *list_a, ListEl *list_b, ListEl *list_aw, ListEl *list_bw)
{
	if (ListEmpty(list_a) && ListEmpty(list_b) == 1)
	{
		return;
	}
	else
	{
		if (ListEmpty(list_a) == 1)
		{
			ViewList(list_b);
			return;
		}
		if (ListEmpty(list_b) == 1)
		{
			ViewList(list_a);
			return;
		}
		//Sprawdzania listy a -> b
		ListEl current_element_a = *list_a;
		ListEl current_element_b = *list_b;
		int value;
		while (current_element_a != NULL)
		{
			value = current_element_a->value;
			AddToListBack(list_aw, value);
			while (current_element_b != NULL)
			{
				if (current_element_b->value == value)
				{
					RemoveFromListBack(list_aw);
					break;
				}
				current_element_b = current_element_b->next;
			}
			current_element_a = current_element_a->next;
			current_element_b = *list_b;
		}
		//Sprawdzanie lista b -> a
		current_element_a = *list_a;
		current_element_b = *list_b;
		while (current_element_b != NULL)
		{
			value = current_element_b->value;
			AddToListBack(list_bw, value);
			while (current_element_a != NULL)
			{
				if (current_element_a->value == value)
				{
					RemoveFromListBack(list_bw);
					break;
				}
				current_element_a = current_element_a->next;
			}
			current_element_b = current_element_b->next;
			current_element_a = *list_a;
		}
		printf("List A\n");
		ViewList(list_a);
		printf("List AW\n");
		ViewList(list_aw);
		printf("List B\n");
		ViewList(list_b);
		printf("List BW\n");
		ViewList(list_bw);
	}
}

void ConnectAndSortLists(ListEl *list_a, ListEl *list_b) 
{
	if (ListEmpty(*list_a) == 1)
	{
		ViewList(list_b);
	}
	if (ListEmpty(*list_b) == 1)
	{
		ViewList(list_a);
	}
	if (ListEmpty(*list_a) == 0 && ListEmpty(*list_b) == 0)
	{
		ListEl current_element_a = *list_a;
		ListEl head_a = *list_a;
		ListEl head_b = *list_b;
		while (current_element_a->next != NULL)
		{
			current_element_a = current_element_a->next;
		}
		current_element_a->next = head_b;
		*list_a = head_a;
		SortList(list_a);
		ViewList(list_a);
		ClearList(list_a);
		ClearList(list_b);
	}
}

void ConnectLists(ListEl *list_a, ListEl *list_b)
{
	if (ListEmpty(list_a) == 1)
	{
		ViewList(list_b);
	}
	if (ListEmpty(list_b) == 1)
	{
		ViewList(list_a);
	}
	if (ListEmpty(list_a) == 0 && ListEmpty(list_b) == 0)
	{
		ListEl current_element_a = *list_a;
		ListEl current_element_b = *list_b;
		ListEl future_element_a = current_element_a->next;
		ListEl future_element_b = current_element_b->next;
		ListEl head;
		if (current_element_a->value <= current_element_b->value)
		{
			head = *list_a;
		}
		else
		{
			head = *list_b;
		}
		while (current_element_a != NULL || current_element_b != NULL)
		{
			if (current_element_b->value <= current_element_a->value)
			{
				current_element_a = future_element_a;
				if (future_element_a != NULL)
				{
					future_element_a = future_element_a->next;
				}

				if (current_element_b->value >= current_element_a->value)
				{
					current_element_a->next = current_element_b;
					current_element_a = future_element_a;
					if (future_element_a != NULL)
					{
						future_element_a = future_element_a->next;
					}	
				}
			}
			else if (current_element_a->value <= current_element_b->value)
			{
				current_element_b = future_element_b;
				if (future_element_b != NULL)
				{
					future_element_b = future_element_b->next;
				}

				if (current_element_a->value >= current_element_b->value)
				{
					current_element_b->next = current_element_a;
					current_element_b = future_element_b;
					if (future_element_b != NULL)
					{
						future_element_b = future_element_b->next;
					}
				}
			}
		}
		*list_a = head;
		*list_b = head;
		ViewList(list_a);
	}
}