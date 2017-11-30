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
	printf("4. One Way Cyclic\n");
	printf("5. Priority Lists\n");
	printf("------------------------------------------------------\n");
	printf("6. Binary Trees\n");
	printf("------------------------------------------------------\n");
	printf("90. PD.\n");
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

void MainMenuTwoWay()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to two way list.\n");
	printf("2. Remove from two way list.\n");
	printf("3. Seek value in two way list.\n");
	printf("4. Remove value from two way list.\n");
	printf("5. View two way list.\n");
	printf("6. Clear two way list.\n");
	printf("------------------------------------------------------\n");
	printf("99. Go back to main menu.\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

void MainMenuTwoWayCyclic()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to cyclic two way list.\n");
	printf("2. Move forward in cyclic two way list.\n");
	printf("3. Remove from cyclic two way list.\n");
	printf("4. Seek value in cyclic two way list.\n");
	printf("5. Remove value from cyclic two way list.\n");
	printf("6. View cyclic two way list.\n");
	printf("7. Clear cyclic two way list.\n");
	printf("8. Scroll cyclic two way list.\n");
	printf("------------------------------------------------------\n");
	printf("9. Remove from two way list until one element left.\n");
	printf("------------------------------------------------------\n");
	printf("99. Go back to main menu.\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

void MainMenuOneWayCyclic()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to cyclic one way A list.\n");
	printf("2. Remove from cyclic one way A list.\n");
	printf("3. Remove value from cyclic one way A list.\n");
	printf("4. View cyclic list A.\n");
	printf("5. Clear list A.\n");
	printf("------------------------------------------------------\n");
	printf("6. Add to cyclic one way B list.\n");
	printf("7. Remove from cyclic one way B list.\n");
	printf("8. Remove value from cyclic one way B list.\n");
	printf("9. View cyclic list B.\n");
	printf("10. Clear list B.\n");
	printf("------------------------------------------------------\n");
	printf("11. Remove values from A list, from B list.\n");
	printf("------------------------------------------------------\n");
	printf("99. Go back to main menu.\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

void MainMenuPriorList()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to priority list.\n");
	printf("2. Remove from priority list.\n");
	printf("3. Change priority of element.\n");
	printf("4. View priority list.\n");
	printf("5. Clear priortiy list.\n");
	printf("------------------------------------------------------\n");
	printf("99. Go back to main menu.\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

void MainMenuBinaryTree()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add to binary tree.\n");
	printf("2. View binary tree.\n");
	printf("3. Search binary tree.\n");
	printf("4. Minmum in binary tree.\n");
	printf("5. Maximum in binary tree.\n");
	printf("6. Remove from binary tree.\n");
	printf("------------------------------------------------------\n");
	printf("7. Max depth of binary tree.\n");
	printf("8. Count leaves of binary tree.\n");
	printf("------------------------------------------------------\n");
	printf("11. Find next.\n");
	printf("12. Find last.\n");
	printf("------------------------------------------------------\n");
	printf("20. Compare Trees.\n");
	printf("------------------------------------------------------\n");
	printf("99. Go back to main menu.\n");
	printf("0. Exit.\n");
	printf("------------------------------------------------------\n");
}

void MainMenuPD()
{
	printf("------------------------------------------------------\n");
	printf("----------------------/ASD Lists/---------------------\n");
	printf("------------------------------------------------------\n");
	printf("1. Add Equation.\n");
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