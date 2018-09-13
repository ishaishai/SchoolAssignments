#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include "Ex2Declarations.h"


void Ex2_1(Polynomial *lst) //create Poly
{
	initPoly(lst);
	printf("Polynom has been initialized\n\n");
}

void Ex2_2(Polynomial *lst)
{
	if (!(*lst))
	{
		printf("\n***NO POLYNOMIAL WAS ALLOCATED***\n");
		return;
	}
	int exp = 0, coef = 0;
	int count = 0;

	printf("How many nodes would you like to add? (0 or less to exit)\nAmount: ");
	scanf("%d", &count);
		
	if (count <= 0)
	{
		printf("Going back to main menu...\n\n");
	}
	for (int i = 0; i < count; i++)
	{
		do
		{
			printf("Enter poly coef and exp:\n");
			scanf("%d%d", &coef, &exp);
			if(exp<0)
				printf("Enter only exponent that is equal to 0 or more\n");
		} while (exp < 0);
		AddtoPoly(lst, coef, exp);
	}
}

void AddtoPoly(Polynomial *lst, poly_type coef, poly_type exp)
{
	if (coef == 0)
	{
		printf("Cannot add a node with 0 as coef\n");
		return;
	}
	Node *item = allocItem(coef, exp);
	Node *temphead = (*lst)->head;
	Node *temptail = (*lst)->tail;

	if (!temphead)
		insertFirst(lst, item);
	else
	{
		while (temphead)
		{
			if (temphead->exp == item->exp)
			{
				temphead->coef += item->coef;
				if (temphead->coef == 0)
					deleteLink(lst, temphead);
				return;
			}
			else if (temphead->exp > item->exp)
			{
				insertBefore(lst, item, temphead);
				return;
			}
			else if(temphead == temptail)
			{
				insertAfter(lst, item, temphead);
				return;
			}
			else
			{
				temphead = temphead->next;
			}
		}
	}
}

void Ex2_3(Polynomial *A, Polynomial *B)
{
	Polynomial C;
	
	C = Sum_Poly(A, B);
	printf("Printing Result of summarization: \n\n");
	PrintPoly(A);
	printf("    +    ");
	if ((*B)->tail && (*B)->tail->coef < 0)
	{
		printf("(");
		PrintPoly(B);
		printf(")");
	}
	else
	{
		PrintPoly(B);
	}
	printf(" = ");
	PrintPoly(&C);
	printf("\n");

	Reset_Poly(&C);
	free(C);
	printf("\n\n\tFreed allocation for result\n\n");
}

Polynomial Sum_Poly(Polynomial *A, Polynomial *B)
{
	Polynomial res = (PolyStruct*)calloc(1, sizeof(PolyStruct));
	Node *tempheadA = (*A)->head;
	Node *tempheadB = (*B)->head;
	Node *tempheadC = res->head;
	Node *item = NULL;
	poly_type sumcoef = 0;
	while (tempheadA && tempheadB)
	{
		if (tempheadA->exp == tempheadB->exp)
		{
			sumcoef = (tempheadA->coef) + (tempheadB->coef);
			if (sumcoef != 0)
			{
				item = allocItem(sumcoef, tempheadA->exp);
				insertLast(&res, item);
			}
			tempheadA = tempheadA->next;
			tempheadB = tempheadB->next;
		}
		else if (tempheadA->exp < tempheadB->exp)
		{
			item = allocItem(tempheadA->coef, tempheadA->exp);
			insertLast(&res, item);
			tempheadA = tempheadA->next;
		}
		else
		{
			item = allocItem(tempheadB->coef, tempheadB->exp);
			insertLast(&res, item);
			tempheadB = tempheadB->next;
		}
	}

	while (tempheadA)
	{
		item = allocItem(tempheadA->coef, tempheadA->exp);
		insertLast(&res, item);
		tempheadA = tempheadA->next;
	}

	while (tempheadB)
	{
		item = allocItem(tempheadB->coef, tempheadB->exp);
		insertLast(&res, item);
		tempheadB = tempheadB->next;
	}

	return res;
}

void Ex2_4(Polynomial *A, Polynomial *B)
{
	Polynomial C;
	int choice = 0;
	

	do
	{
		printf("1 to subtract B from A, 2 to subtract A from B, 0 or less to go back\n");
		scanf("%d", &choice);
	} while (choice > 2);
	if (choice == 1)
	{
		PrintPoly(A);
		printf("   -   (");
		PrintPoly(B);
		printf(")   =   ");
		Negative_sign(B); //turn into negative signes
		C = Sum_Poly(A, B);
		PrintPoly(&C);
		Negative_sign(B); //turn back to original
		
	}
	else if (choice == 2)
	{
		PrintPoly(B);
		printf("   -   (");
		PrintPoly(A);
		printf(")   =   ");
		Negative_sign(A); //turn into negative signes
		C = Sum_Poly(A, B);
		PrintPoly(&C);
		Negative_sign(A); //turn back to original
	}
	else
	{
		printf("Going back to menu...\n");
		return;
	}

	Reset_Poly(&C);
	free(C);
	printf("\n\n\tFreed allocation for result\n\n");
}

void Negative_sign(Polynomial *p)
{
	Node *temphead = (*p)->head;
	while (temphead)
	{
		temphead->coef *= (-1);
		temphead = temphead->next;
	}
}

void Ex2_5(Polynomial *lst)
{
	int mul = 0;
	Polynomial C;

	printf("Enter a number to multiply your polynomial by: ");
	scanf("%d", &mul);

	C = Multi_By_C(lst, mul);
	printf("\nYour origin polynomial is: ");
	PrintPoly(lst);
	printf("\n\nResult of multiplying it by %d is: ", mul);
	PrintPoly(&C);

	Reset_Poly(&C);
	free(C);
	printf("\n\n\tFreed allocation for result\n\n");
}

Polynomial Multi_By_C(Polynomial *lst, int C)
{
	Polynomial res = (PolyStruct*)calloc(1, sizeof(PolyStruct));
	Node *temphead = (*lst)->head, *item;

	if (C == 0)
	{
		return res;
	}

	while (temphead)
	{
		item = allocItem((temphead->coef)*C, temphead->exp);
		insertLast(&res, item);
		temphead = temphead->next;
	}

	return res;
}

void Ex2_6(Polynomial *lst)
{
	printf("Order of growth of the following polynomial is it's biggest exponent: ");
	PrintPoly(lst);
	printf("\n\n-------> %d\n\n", Growth_Order(lst));
}

int Growth_Order(Polynomial *lst)
{
	if (!(*lst)->head)
		return -1;
	return (*lst)->tail->exp;
}

void Ex2_7(Polynomial *lst)
{
	if (!(*lst)->head)
	{
		printf("Zero (Empty Polynomial) can't be reseted\n");
		return;
	}
	
	Reset_Poly(lst);

	printf("**Reseted polynomial***\n\n");
}

void Reset_Poly(Polynomial *lst)
{
	Node *temphead = (*lst)->head;
	temphead = temphead->next;

	while (temphead || (*lst)->head)
	{
		free((*lst)->head);
		(*lst)->head = temphead;
		if (temphead)
			temphead = temphead->next;
	}
}

void Ex2_8(Polynomial *lst)
{
	PrintPoly(lst);
}

void PrintPoly(Polynomial *lst)
{
	Node *temptail;

	if (!(*lst)->head)
	{
		printf("Zero (Empty Polynomial)");
		return;
	}
	temptail = (*lst)->tail;
	do
	{
		if (temptail->coef >= 1 && temptail!=(*lst)->tail)
			printf("+");
		if (temptail->exp > 1 && temptail->coef!=1)
		{
			if (temptail->coef == -1)
				printf("-x^%d", temptail->exp);
			else
				printf("%dx^%d", temptail->coef, temptail->exp);
		}
		else if(temptail->exp > 1 && temptail->coef==1)
		{
			printf("x^%d", temptail->exp);
		}
		else if (temptail->exp == 0 && temptail->coef != 1)
		{
			printf("%d", temptail->coef);
		}
		else if(temptail->exp ==1 && temptail->coef==1)
		{
			printf("x");
		}
		else
		{
			printf("%dx", temptail->coef);
		}
		temptail = temptail->prev;
	} while (temptail);
}


void Ex2_Bonus(Polynomial *A, Polynomial *B)
{
	Polynomial C;

	C = MulPoly(A, B);
	printf("Printing Result of multiplication: \n\n(");
	PrintPoly(A);
	printf(")    *    (");
	PrintPoly(B);
	printf(") = ");
	PrintPoly(&C);
	printf("\n");
	
	Reset_Poly(&C);
	free(C);
	printf("\n\n\tFreed allocation for result\n\n");
}

Polynomial MulPoly(Polynomial *A, Polynomial *B)
{
	Polynomial finalres = (PolyStruct*)calloc(1, sizeof(PolyStruct));
	Polynomial tempres;
	Node *tempheadA = (*A)->head;
	Node *tempheadB = (*B)->head;
	tempres = (PolyStruct*)calloc(1, sizeof(PolyStruct));
	Node *item = NULL;

	for (; tempheadA != NULL; tempheadA = tempheadA->next)
	{
		initPoly(&tempres);
		for (tempheadB = (*B)->head; tempheadB != NULL; tempheadB = tempheadB->next)
		{
			item = allocItem((tempheadB->coef)*(tempheadA->coef), (tempheadB->exp) + (tempheadA->exp));
			insertLast(&tempres, item);
		}
		finalres = Sum_Poly(&finalres, &tempres);
		Reset_Poly(&tempres); //free the allocation to set from beginning
	}

	free(tempres);

	return finalres;
}

void end_Ex2(int num)
{
	printf("\n\n\t*****************************************************\n");
	printf("\t***********    END                 OF     ***********\n");
	printf("\t***********    Ex2_%d               RUN    ***********\n",num);
	printf("\t*****************************************************\n");
}

void Ex2Menu()
{
	Polynomial p1 = NULL, p2 = NULL;
	int choice = 0;
	int select = 1, i, all_Ex_in_loop = 0;
	printf("\t\t\t--Ex2---\n\n");
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");

	if (scanf("%d", &all_Ex_in_loop) == 1)
	{
		do
		{
			rewind(stdin);
			system("cls");
			printf("\t\t\t--Asignment 2 - Data Structers---\n\n\t\tEx2 Menu:\n\n");
			for (i = 1; i <= 9; i++)
				printf("Sub Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-9 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 9));
			system("cls");
			switch (select) {
				case 0:
				{
					if (p1)
					{
						Ex2_7(&p1);
						free(p1);
					}
					if (p2)
					{
						Ex2_7(&p2);
						free(p2);
					}
					select = 0;
					all_Ex_in_loop = 0;
					break;
				}
				case 1:
				{
					printf("\t\t*** Ex2_1 -> Initiliaze Polynomials Function ***\n\n");
					if (p1 && p2)
					{
						printf("Both Already initialized\n");
						end_Ex2(1);
						break;
					}
					printf("Enter 1 or 2 (or 3 to initiliaze both) to select polynomial to initialize: ");
					scanf("%d", &choice);
					if (choice==1 && !p1)
						Ex2_1(&p1);
					else if (choice==2 && !p2)
						Ex2_1(&p2);
					else if (choice == 3 && !p1 && !p2)
					{
						Ex2_1(&p1);
						Ex2_1(&p2);
						printf("\nInitialized both polynomials\n\n");
					}
					else
						printf("NOT AN OPTION...Going back to main menu\n");
					end_Ex2(1);
					break;
				}
				case 2:
				{
					printf("\t\t*** Ex2_2 -> Add nodes to Polynomials Function ***\n\n");
					if (!p1 && !p2)
					{
						printf("Go back and initiliaze at least 1 polynomial\n");
						break;
					}
					printf("Enter 1 or 2 to select polynomial to add node to: ");
					scanf("%d", &choice);
					if (choice==1 && p1)
						Ex2_2(&p1);
					else if (choice==2 && p2)
						Ex2_2(&p2);
					else
						printf("NOT AN OPTION...Going back to main menu\n");
					end_Ex2(2);
					break;
				}
				case 3:
				{
					printf("\t\t*** Ex2_3 -> Summarize 2 Polynomials Function ***\n\n");
					if (!p1 || !p2)
					{
						printf("Allocation needed for both polynomials\n\n");
					}
					else
					{
						Ex2_3(&p1, &p2);
					}
					end_Ex2(3);
					break;
				}
				case 4:
				{
					printf("\t\t*** Ex2_4 -> Subtract 2 Polynomials Function ***\n\n");
					if (!p1 || !p2)
					{
						printf("Allocation needed for both polynomials\n\n");
					}
					else
					{
						Ex2_4(&p1, &p2);
					}
					end_Ex2(4);
					break;
				}
				case 5:
				{
					printf("\t\t*** Ex2_5 -> Multiply by number Function ***\n\n");
					printf("Enter 1 or 2 to select polynomial to multiply by a number: ");
					scanf("%d", &choice);
					if (choice == 1 && p1)
						Ex2_5(&p1);
					else if (choice == 2 && p2)
						Ex2_5(&p2);
					else
						printf("NOT AN OPTION or Allocation needed first...Going back to main menu\n");
					end_Ex2(5);
					break;
				}
				case 6:
				{
					printf("\t\t*** Ex2_6 -> Order of Growth Function ***\n\n");
					printf("Enter 1 or 2 to select polynomial to get it's order of growth: ");
					scanf("%d", &choice);
					if (choice == 1 && p1)
						Ex2_6(&p1);
					else if (choice == 2 && p2)
						Ex2_6(&p2);
					else
						printf("NOT AN OPTION or Allocation needed first...Going back to main menu\n");
					end_Ex2(6);
					break;

				}
				case 7:
				{
					printf("\t\t*** Ex2_7 -> Reset Polynomial Function ***\n\n");
					printf("Enter 1 or 2 to select polynomial to reset (delete only its list of nodes): ");
					scanf("%d", &choice);
					if (choice == 1 && p1)
						Ex2_7(&p1);
					else if (choice == 2 && p2)
						Ex2_7(&p2);
					else if (!p1 && !p2)
					{
						printf("Allocation needed first...Going back to main menu\n");
					}
					else
					{
						printf("NOT AN OPTION...Going back to main menu\n");
					}
					end_Ex2(7);
					break;
				}
				case 8:
				{
					printf("\t\t*** Ex2_8 -> Print Polynomials Function ***\n\n");
					if (!p1 && !p2)
					{
						printf("Nothing to print yet, go back and initiliaze polynomials\n");
						break;
					}
					printf("Enter 1 or 2 or 3(to both) to select polynomial to print: ");
					scanf("%d", &choice);
					if (choice == 1 && p1)
					{
						printf("\nPolynomial 1:\n\n");
						Ex2_8(&p1);
					}
					else if (choice == 2 && p2)
					{
						printf("\nPolynomial 2:\n\n");
						Ex2_8(&p2);
					}
					else if (choice == 3 && p1 && p2)
					{
						printf("\nPolynomial 1\n\n");
						Ex2_8(&p1);
						printf("\n\nPolynomial 2\n\n");
						Ex2_8(&p2);

					}
					else
						printf("NOT AN OPTION...Going back to main menu\n");
					end_Ex2(8);
					break;
				}

				case 9:
				{
					printf("\t\t*** Ex2_9 -> Bonus: Multiply 2 Polynomials Function ***\n\n");
					if (!p1 || !p2)
					{
						printf("Allocation needed for both polynomials\n\n");
					}
					else
					{
						Ex2_Bonus(&p1, &p2);
					}
					end_Ex2(9);
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