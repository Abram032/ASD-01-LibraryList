#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

struct ONPStack
{
	int key;
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

void SetEquation()
{
	int i = 0;
	char equation[2048];
	printf("Put equation: ");
	fseek(stdin, 0, SEEK_END);
	fgets(&equation, 2048, stdin);
	while (equation[i] != '\0')
	{
		printf("%c", equation[i]);
		sscanf()
		i++;
	}
	//return key;
}