#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "PD.h"

struct ONPStack
{
	int key;
	char operand;
	struct ONPStack *next;
};

typedef struct ONPStack ONPS;
typedef ONPS *ONPel;

int ONPStackEmpty(ONPel *onp_el)
{
	if (onp_el != NULL)
	{
		return 0;
	}
	else
	{
		printf("List is empty!\n");
		return 1;
	}
}

char SetOperand()
{
	char operand;
	printf("Set char: ");
	scanf(" %c", &operand);
	return operand;
}

int SetKey()
{
	int key;
	printf("Set key: ");
	scanf(" %d", &key);
	return key;
}

void AddToONPStack(ONPel *onp_el, int key, char operand)
{
	ONPel new_el = malloc(sizeof(ONPS));
	new_el->key = key;
	new_el->operand = operand;
	new_el->next = *onp_el;
	*onp_el = new_el;
}

void AddToONPStackBack(ONPel *onp_el, int key, char operand)
{
	if (*onp_el != NULL)
	{
		ONPel current_el = *onp_el;
		while (current_el->next != NULL)
		{
			current_el = current_el->next;
		}
		ONPel new_el = malloc(sizeof(ONPS));
		new_el->key = key;
		new_el->operand = operand;
		new_el->next = NULL;
		current_el->next = new_el;
	}
	else
	{
		AddToONPStack(onp_el, key, operand);
	}
}

int RemoveFromONPStack(ONPel *onp_el)
{
	if (ONPStackEmpty(*onp_el) == 0)
	{
		ONPel current_el = *onp_el;
		int key = current_el->key;
		char operand = current_el->operand;
		*onp_el = current_el->next;
		free(current_el);
		if (key != NULL)
		{
			return key;
		}
		else
		{
			return operand;
		}
	}
}

void ViewONPStack(ONPel *onp_el)
{
	if (ONPStackEmpty(*onp_el) == 0)
	{
		ONPel current_el = *onp_el;
		while (current_el != NULL)
		{
			if (current_el->key != NULL)
			{
				printf(" %d ", current_el->key);
			}
			else
			{
				printf(" %c ", current_el->operand);
			}
			current_el = current_el->next;
		}
		printf("\n");
	}
}

int ExecuteEquation(ONPel *onp_el)
{
	int a, b;
	char operand;
	ONPel current = *onp_el;
	if (current->next == NULL)
	{
		return current->key;
	}
	else
	{
		a = RemoveFromONPStack(onp_el);
		b = RemoveFromONPStack(onp_el);
		operand = RemoveFromONPStack(onp_el);
		switch (operand)
		{
		case '+':
			a = a + b;
			AddToONPStack(onp_el, a, NULL);
			break;
		case '-':
			a = a - b;
			AddToONPStack(onp_el, a, NULL);
			break;
		case '*':
			a = a * b;
			AddToONPStack(onp_el, a, NULL);
			break;
		case '/':
			a = a / b;
			AddToONPStack(onp_el, a, NULL);
			break;
		case '%':
			a = a % b;
			AddToONPStack(onp_el, a, NULL);
			break;
		case '^':
			a = pow(a, b);
			AddToONPStack(onp_el, a, NULL);
			break;
		}
		ExecuteEquation(onp_el);
	}
}