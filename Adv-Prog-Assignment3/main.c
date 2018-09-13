#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Ex1.h"
#include "Ex2.h"

int main()
{
	int select = 1, i, all_Ex_in_loop = 0;
	printf("\t\t\t---Assignment 2 - Advanced Programming---\n\n");
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
	{
		do
		{
			rewind(stdin);
			system("cls");
			printf("\t\t\t---Assignment 2 - Advanced Programming---\n\n");
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 5));
			system("cls");
			switch (select) {
			case 0:
			{
				select = 0;
				all_Ex_in_loop = 0;
				break;
			}
			case 1:
			{
				Ex1_Menu(); break;
			}
			case 2:
			{
				Ex2_Menu(); break;
			}
			//case 3:
			//{
			//	Ex3(); break;
			//}
			//case 4:
			//{
			//	Ex4(); break;
			//}
			//case 5:
			//{
			//	Ex5(); break;
			//}
			}
			if (select>0)
			{
				printf("\n\nPress enter to continue\n");
				_getch();
			}
		} while (all_Ex_in_loop != 0 && select != 0);
	}
	return 0;
}
