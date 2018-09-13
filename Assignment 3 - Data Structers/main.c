/*
Assignment 3 - Data structers

Ishai Yaish - 305101560 - Group number: 61104-61
Gal Ya'akobi - 205634926 - Group number: 61104-61

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


void main()
{
	Tnode *tree = NULL;
	printf("\t\t\tBST - Assignment 3\n\n");
	int select = 1, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
	{
		do
		{
			rewind(stdin);
			system("cls");
			printf("\t\t\tBST - Assignment 3\n\n");
			for (i = 1; i <= 4; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-4 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 4));
			system("cls");
			switch (select) {
			case 0:
			{
				if (tree)
				{
					printf("Freeing tree first before quiting...\n");
					FreeBST(tree);
				}
				select = 0;
				all_Ex_in_loop = 0;
				break;
			}
			case 1:
			{
				Ex1(&tree); break;
			}
			case 2:
			{
				Ex2(tree); break;
			}
			case 3:
			{
				Ex3(tree); break;
			}
			case 4:
			{
				Ex4(&tree); 
				break;
			}
			}
			if (select>0)
			{
				printf("\n\nPress enter to continue\n");
				_getch();
			}
		} while (all_Ex_in_loop != 0 && select != 0);
	}
	
}