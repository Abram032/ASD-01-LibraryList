#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"
#include "Sorting.h"
#include "Functions.h"
#include "Menu.h"

void AddUntilNegativeFront(ListEl *list_el)
{
	int x;
	int loop = 1;
	do
	{
		x = SetValue();
		if (x >= 0)
		{
			AddToListFront(list_el, x);
		}
		else
		{
			loop = 0;
		}
	} while (loop == 1);
}

void AddUntilNegativeBack(ListEl *list_el)
{
	int x;
	int loop = 1;
	do
	{
		x = SetValue();
		if (x >= 0)
		{
			AddToListBack(list_el, x);
		}
		else
		{
			loop = 0;
		}
	} while (loop == 1);
}

void RemoveValue(ListEl *list_el, int x)
{
	//Sprawdzamy czy lista jest pusta.
	if (ListEmpty(*list_el) == 0)
	{
		//Tworzymy wskazniki na obecny i poprzedni element struktury.
		ListEl current_element = *list_el;
		ListEl previous_element = *list_el;
		//Sprawdzamy czy obecny element jest pusty.
		while (current_element != NULL)
		{
			//Sprawdzamy czy wartosc elementu szukanego jest na obecnej pozycji
			if (current_element->value == x)
			{
				//Warunek sprawdzajacy czy nasza wartoscia nie jest 1 element listy, kluczowe poniewaz trzeba przesunac glowe.
				if (current_element == previous_element)
				{
					previous_element = current_element->next;
					*list_el = previous_element;
					free(current_element);
					current_element = previous_element;
				}
				//Jesli nie to ustawiamy nastepny element poprzedniego jako obecny nastepny, usuwamy obecny element
				//Przesuwamy nasz wskaznik na obecny element na element poprzedni
				else
				{
					previous_element->next = current_element->next;
					free(current_element);
					current_element = previous_element;
				}
			}
			//Jesli na obecnej pozycji nie ma naszej wartosci to przechodzimy dalej.
			else
			{
				previous_element = current_element;
				current_element = current_element->next;
			}
		}
	}
}

void RemoveValueRecursive(ListEl *list_el, int x)
{
	//Sprawdzamy czy lista jest pusta.
	if (ListEmpty(*list_el) == 0)
	{
		//Tworzymy wskazniki na obecny i poprzedni element struktury.
		ListEl previous_element = *list_el;
		ListEl current_element = *list_el;
		//Sprawdzamy czy wartosc elementu szukanego jest na obecnej pozycji
		if (current_element->value == x)
		{
			//Warunek sprawdzajacy czy nasza wartoscia nie jest 1 element listy, kluczowe poniewaz trzeba przesunac glowe.
			if (current_element == previous_element)
			{
				previous_element = current_element->next;
				*list_el = previous_element;
				free(current_element);
				current_element = previous_element;
				RemoveValueRecursive(&(*list_el), x);
			}
		}
		//Jesli na obecnej pozycji nie ma naszej wartosci to przechodzimy dalej.
		else
		{
			RemoveValueRecursive(&(*list_el)->next, x);
		}
	}
}

void MostFrequentValue(ListEl *list_el)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		int array_size = 0;
		int *value_array, *count_array;
		int value, count;
		int position = 0;
		int value_exists, value_position;
		while (current_element != NULL)
		{
			array_size++;
			current_element = current_element->next;
		}
		current_element = *list_el;
		value_array = (int*)malloc(array_size * sizeof(*value_array));
		count_array = (int*)malloc(array_size * sizeof(*count_array));
		while (current_element != NULL)
		{
			value = current_element->value;
			value_exists = 0;
			for (int i = 0; i < array_size; i++)
			{
				if (value == value_array[i])
				{
					value_exists = 1;
					value_position = i;
					break;
				}
			}
			if (value_exists == 1)
			{
				count_array[value_position]++;
			}
			else
			{
				value_array[position] = value;
				count_array[position] = 1;
			}
			position++;
			current_element = current_element->next;
		}
		count = 0;
		for (int i = 0; i < array_size; i++)
		{
			if (count_array[i] > count)
			{
				count = count_array[i];
				value_position = i;
			}
		}
		value = value_array[value_position];
		count = count_array[value_position];
		printf("The most occuring value is %d. It appeared %d times in list.\n", value, count);
	}
}

/*
void GetMostFrequnet(lista l)
{
    if(l != 0)
    {
    lista w = 0, c = 0;
    lista p = (lista)malloc(sizeof(elListy));
    int found = 0, max = 0, value = 0;
    while(l)
    {
        found = 0;
        while(c)
        {
            if(c->klucz == l->klucz)
            {
                c->licznik++;
                found = 1;
            }
            c = c->nast;
        }
        if(found == 0)
        {
            AddElement(&w, l->klucz);
        }
        l = l->nast;
        c = w;
    }
    
    while(w)
    {
        if(max < w->licznik)
        {
            max = w->licznik;
            value = w->klucz;
        }
        w=w->nast;
    }
    
        printf("Most frequent number in a list is: %d with %d repetitions!\n", value, max);
    }
    else
        printf("List empty!\n");
    system("pause");
}
*/

void RemoveEven(ListEl *list_el)
{
	if (ListEmpty(*list_el) == 0)
	{
		ListEl current_element = *list_el;
		ListEl previous_element = *list_el;
		while (current_element != NULL)
		{
			if (current_element->value % 2 == 0)
			{
				if (current_element == previous_element)
				{
					previous_element = current_element->next;
					*list_el = previous_element;
					free(current_element);
					current_element = previous_element;
				}
				else
				{
					previous_element->next = current_element->next;
					free(current_element);
					current_element = previous_element;
				}
			}
			else
			{
				previous_element = current_element;
				current_element = current_element->next;
			}
		}
	}
}

/*
void SortListWG(ListEl *list_el)
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
			AddToListBack(list_el, NULL);
			while (minimal_element->value != NULL)
			{
				if (minimal_element->value <= minimum->value)
				{
					minimum = minimal_element;
				}
				minimal_element = minimal_element->next;
			}
			RemoveFromListBack(list_el);
			temp_value = current_element->value;
			current_element->value = minimum->value;
			minimum->value = temp_value;
			current_element = current_element->next;
			minimal_element = current_element;
		}
	}
}
*/