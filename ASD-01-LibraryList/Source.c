#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

/*
	One way list with functions.

	TODO:
	-

*/

void MainMenu()
{
	printf("1. Add to list front.\n");
	printf("2. Add to list back.\n");
	printf("3. Remove from front of the list.\n");
	printf("4. Remove from back of the list.\n");
	printf("5. Clear List.\n");
	printf("6. Seek Value.\n");
	printf("7. View List.\n");
	printf("8. View List Backwards.\n");
	printf("//------------------------------------------------------//\n");
	printf("0. Exit.\n");
}

int ChooseOption()
{
	int option;
	printf("Choose option: ");
	scanf(" %d", &option);
	return option;
}

int main()
{
	List *list_el = NULL;

	int x;
	int loop = 1;
	do
	{
		system("cls");
		MainMenu();
		int option = ChooseOption();
		switch (option)
		{
		case 1:
			x = SetValue();
			AddToListFront(&list_el, x);
			break;
		case 2:
			x = SetValue();
			AddToListBack(&list_el, x);
			break;
		case 3:
			RemoveFromListFront(&list_el);
			system("pause");
			break;
		case 4:
			RemoveFromListBack(&list_el);
			system("pause");
			break;
		case 5:
			ClearList(&list_el);
			system("pause");
			break;
		case 6:
			x = SetValue();
			SeekValue(&list_el, x);
			system("pause");
			break;
		case 7:
			ViewList(&list_el);
			system("pause");
			break;
		case 8:
			ViewListBackwards(&list_el);
			system("pause");
			break;
		case 0:
			loop = 0;
			system("pause");
			break;
		default:
			printf("\nUnknown option.");
			break;
		}
	} while (loop == 1);

	ClearList(&list_el);
	return 0;
}