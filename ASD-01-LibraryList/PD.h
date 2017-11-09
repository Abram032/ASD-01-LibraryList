#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Lists_twc.h"
#include "Lists_tw.h"

TWListEl * PDSeekValueTWC(TWListEl *twc_list_el, int x)
{
	if (*twc_list_el != NULL)
	{
		TWListEl flag = *twc_list_el;
		TWListEl current_element = *twc_list_el;
		int i = 1;
		do
		{
			if (current_element->value == x)
			{
				printf(" %d is on the %d position.\n", x, i);
				break;
			}
			else
			{
				current_element = current_element->next;
				i++;
			}
		} while (flag != current_element);
		return current_element;
	}
	else
	{
		return NULL;
	}
}

void PDConnectTWCLists(TWListEl *pd_twc_a, TWListEl *pd_twc_b)
{
	if (*pd_twc_a != NULL && *pd_twc_b != NULL)
	{
		TWListEl current_a = *pd_twc_a;
		TWListEl current_b = *pd_twc_b;
		TWListEl prev_a = current_a->prev;
		TWListEl prev_b = current_b->prev;
		prev_a->next = current_b;
		current_b->prev = prev_a;
		current_a->prev = prev_b;
		prev_b->next = current_a;
	}
}