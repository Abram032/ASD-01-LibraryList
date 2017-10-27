#pragma once
#include <stdio.h>
#include <stdlib.h>

void MainMenu()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. One Way Lists\n");
	printf("2. Two Way Lists\n");
	printf("3. Two Way Lists Cyclic\n");
	printf("4. Priority Queue\n");
	printf("------------------------------------------------------\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

void MainMenuOneWay()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to list front.\n");
	printf("2. Add to list back.\n");
	printf("3. Remove from front of the list.\n");
	printf("4. Remove from back of the list.\n");
	printf("5. Clear List.\n");
	printf("6. Seek Value.\n");
	printf("7. View List.\n");
	printf("8. View List Backwards.\n");
	printf("------------------------------------------------------\n");
	printf("11. Add from front until user set negative value.\n");
	printf("12. Add from back until user set negative value.\n");
	printf("13. Remove Value from the list.\n");
	printf("14. Remove Value recursive from the list.\n");
	printf("15. Find most occuring value in the list.\n");
	printf("16. Remove even values from the list.\n");
	printf("------------------------------------------------------\n");
	printf("20. Flip List.\n");
	printf("21. Flip list recursive [NOT FINISHED].\n");
	printf("22. Sort list.\n");
	printf("23. Add to list sorted (without guardian).\n");
	printf("24. Add to list sorted (with guardian).\n");
	printf("------------------------------------------------------\n");
	printf("31. Add to list A sorted (with guardian).\n");
	printf("32. Add to list B sorted (with guardian).\n");
	printf("33. View List A.\n");
	printf("34. View List B.\n");
	printf("35. Compare lists A and B.\n");
	printf("36. Connect and sort lists A and B\n");
	printf("37. Connect lists A and B\n");
	printf("------------------------------------------------------\n");
	printf("99. Go back to main menu.\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

int ChooseOption()
{
	int option;
	printf("Choose option: ");
	scanf(" %d", &option);
	return option;
}