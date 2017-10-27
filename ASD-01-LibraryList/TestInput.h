#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"
#include "Sorting.h"
#include "Functions.h"
#include "Menu.h"

void Input(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 3);
	AddToListSortedWG(list_a, 5);
	AddToListSortedWG(list_a, 6);
	AddToListSortedWG(list_a, 8);
	AddToListSortedWG(list_a, 10);
	AddToListSortedWG(list_a, 12);
	AddToListSortedWG(list_a, 13);
	AddToListSortedWG(list_a, 14);
	AddToListSortedWG(list_a, 18);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
	AddToListSortedWG(list_a, 25);

	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 4);
	AddToListSortedWG(list_b, 5);
	AddToListSortedWG(list_b, 7);
	AddToListSortedWG(list_b, 9);
	AddToListSortedWG(list_b, 11);
	AddToListSortedWG(list_b, 12);
	AddToListSortedWG(list_b, 13);
	AddToListSortedWG(list_b, 15);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
}

void Input2(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 3);
	AddToListSortedWG(list_a, 5);
	AddToListSortedWG(list_a, 6);
	AddToListSortedWG(list_a, 8);
	AddToListSortedWG(list_a, 10);
	AddToListSortedWG(list_a, 12);
	AddToListSortedWG(list_a, 13);
	AddToListSortedWG(list_a, 14);
	AddToListSortedWG(list_a, 18);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
	AddToListSortedWG(list_a, 30);

	AddToListSortedWG(list_b, 4);
	AddToListSortedWG(list_b, 7);
	AddToListSortedWG(list_b, 9);
	AddToListSortedWG(list_b, 11);
	AddToListSortedWG(list_b, 15);
	AddToListSortedWG(list_b, 16);
	AddToListSortedWG(list_b, 17);
	AddToListSortedWG(list_b, 19);
	AddToListSortedWG(list_b, 21);
	AddToListSortedWG(list_b, 22);
	AddToListSortedWG(list_b, 23);
	AddToListSortedWG(list_b, 26);
	AddToListSortedWG(list_b, 27);
	AddToListSortedWG(list_b, 28);
	AddToListSortedWG(list_b, 29);
}

void Input3(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 3);
	AddToListSortedWG(list_a, 13);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
	AddToListSortedWG(list_a, 25);

	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 12);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
}

void Input4(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 3);
	AddToListSortedWG(list_b, 5);
	AddToListSortedWG(list_b, 6);
	AddToListSortedWG(list_b, 8);
	AddToListSortedWG(list_b, 10);
	AddToListSortedWG(list_b, 12);
	AddToListSortedWG(list_b, 13);
	AddToListSortedWG(list_b, 14);
	AddToListSortedWG(list_b, 18);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
	AddToListSortedWG(list_b, 30);

	AddToListSortedWG(list_a, 4);
	AddToListSortedWG(list_a, 7);
	AddToListSortedWG(list_a, 9);
	AddToListSortedWG(list_a, 11);
	AddToListSortedWG(list_a, 15);
	AddToListSortedWG(list_a, 16);
	AddToListSortedWG(list_a, 17);
	AddToListSortedWG(list_a, 19);
	AddToListSortedWG(list_a, 21);
	AddToListSortedWG(list_a, 22);
	AddToListSortedWG(list_a, 23);
	AddToListSortedWG(list_a, 26);
	AddToListSortedWG(list_a, 27);
	AddToListSortedWG(list_a, 28);
	AddToListSortedWG(list_a, 29);
}

void Input5(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 3);
	AddToListSortedWG(list_b, 5);
	AddToListSortedWG(list_b, 6);
	AddToListSortedWG(list_b, 8);
	AddToListSortedWG(list_b, 10);
	AddToListSortedWG(list_b, 12);
	AddToListSortedWG(list_b, 13);
	AddToListSortedWG(list_b, 14);
	AddToListSortedWG(list_b, 18);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
	AddToListSortedWG(list_b, 25);

	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 4);
	AddToListSortedWG(list_a, 5);
	AddToListSortedWG(list_a, 7);
	AddToListSortedWG(list_a, 9);
	AddToListSortedWG(list_a, 11);
	AddToListSortedWG(list_a, 12);
	AddToListSortedWG(list_a, 13);
	AddToListSortedWG(list_a, 15);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
}

void Input6(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 3);
	AddToListSortedWG(list_a, 5);
	AddToListSortedWG(list_a, 6);
	AddToListSortedWG(list_a, 8);

	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 4);
	AddToListSortedWG(list_b, 5);
	AddToListSortedWG(list_b, 7);
	AddToListSortedWG(list_b, 9);
	AddToListSortedWG(list_b, 11);
	AddToListSortedWG(list_b, 12);
	AddToListSortedWG(list_b, 13);
	AddToListSortedWG(list_b, 15);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
}

void Input7(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 3);
	AddToListSortedWG(list_a, 5);
	AddToListSortedWG(list_a, 6);
	AddToListSortedWG(list_a, 8);
	AddToListSortedWG(list_a, 10);
	AddToListSortedWG(list_a, 12);
	AddToListSortedWG(list_a, 13);
	AddToListSortedWG(list_a, 14);
	AddToListSortedWG(list_a, 18);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
	AddToListSortedWG(list_a, 25);

	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 4);
	AddToListSortedWG(list_b, 5);
	AddToListSortedWG(list_b, 7);
}

void Input8(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 14);
	AddToListSortedWG(list_a, 18);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
	AddToListSortedWG(list_a, 25);

	AddToListSortedWG(list_b, 1);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 2);
	AddToListSortedWG(list_b, 4);
	AddToListSortedWG(list_b, 5);
	AddToListSortedWG(list_b, 7);
	AddToListSortedWG(list_b, 9);
	AddToListSortedWG(list_b, 11);
	AddToListSortedWG(list_b, 12);
	AddToListSortedWG(list_b, 13);
	AddToListSortedWG(list_b, 15);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
}

void Input9(ListEl *list_a, ListEl *list_b)
{
	AddToListSortedWG(list_a, 1);
	AddToListSortedWG(list_a, 2);
	AddToListSortedWG(list_a, 3);
	AddToListSortedWG(list_a, 5);
	AddToListSortedWG(list_a, 6);
	AddToListSortedWG(list_a, 8);
	AddToListSortedWG(list_a, 10);
	AddToListSortedWG(list_a, 12);
	AddToListSortedWG(list_a, 13);
	AddToListSortedWG(list_a, 14);
	AddToListSortedWG(list_a, 18);
	AddToListSortedWG(list_a, 20);
	AddToListSortedWG(list_a, 24);
	AddToListSortedWG(list_a, 25);
	AddToListSortedWG(list_a, 25);

	AddToListSortedWG(list_b, 15);
	AddToListSortedWG(list_b, 20);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 24);
	AddToListSortedWG(list_b, 25);
}