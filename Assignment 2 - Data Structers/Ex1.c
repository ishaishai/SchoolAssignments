#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Ex1Declarations.h"
#include "Stack_arr.h"
#include <string.h>

#define SIZE 100

int check_operand(char ch)
{
	char str[] = "ABCDEFGH0123456789";
	int i = 0, len = strlen(str);
	while (i < len)
	{
		if (ch == str[i])
		{
			return 1;
		}
		i++;
	}
	printf("\n\nNO OPERAND FOUND OR WRONG SYNTAX\n");
	_getch();
	return -1;
}

int check_operator(char ch)
{
	char str[] = "+-/^*";
	int i = 0, len = strlen(str);
	while (i < len)
	{
		if (ch == str[i])
		{
			return 1;
		}
		i++;
	}
	printf("\n\nNO OPERATOR FOUND OR WRONG SYNTAX\n");
	_getch();
	return -1;
}

void input_arit(char *s)
{
	char ch = '\0';
	int i = 0;

	printf("Enter arithmetic argument to calculate (use only A->H letters, 0->9 digits and + - * / ^ signs)\nFor example -> A+B*C-D^E\n\nInput:");
	while ((ch = getchar()) != '\n' && i < 100)
		s[i++] = ch;
}

int check_prior(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 0;
	}
	else if (ch == '/' || ch == '*')
	{
		return 1;
	}
	else if (ch == '^')
	{
		return 2;
	}
	else 
	{
		return -1;
	}
}

void clear_spaces(char *s)
{
	int j = 0;
	for (int i=0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}


void calc_arit(char *arit)
{
	stack s1,s2;
	char prev_op, cur_op, oper1, oper2;
	int op_count = 0;

	system("cls");
	printf("Your expression is: %s\n\n", arit);
	printf("* or / comes before + or - and ^ is the strongest. \nif there are two ^'s it will calculate them from right to left(BONUS)\n\n");
	clear_spaces(arit);
	create_stack(&s1);
	create_stack(&s2);
	
	if (push_operand(*(arit++), &s1) == -1 || push_operator(*(arit++), &s2) == -1 || push_operand(*(arit++), &s1) == -1)
	{
		printf("ERROR on arithmetic expression\n");
		return;
	}
	stack_top(&s2, &prev_op);
	
	printf(" OPERATOR\tOPERAND1\tOPERAND2\tRESULT\n");
	while (*arit)
	{
		if (s1.top - 1 == s2.top)
		{
			if ((check_prior(*arit) <= check_prior(prev_op) && (*arit)!='^') && !stack_is_empty(&s2))
			{
				if (check_prior(*arit) == -1)
				{
					printf("ERROR on arithmetic expression %c isn't allowed\n",(*arit));
					return;
				}
				pop(&s2, &prev_op);
				pop(&s1, &oper2);
				pop(&s1, &oper1);
				printf(" %c\t\t%c\t\t%c\t\t%c\n", prev_op, oper1, oper2, 'Z' - op_count);
				push_result('Z' - (op_count++), &s1);
			
				if (!stack_is_empty(&s2))
				{
					stack_top(&s2, &cur_op);

					if (check_prior(*arit) <= check_prior(cur_op) && cur_op!='^')
					{
						pop(&s2, &cur_op);
						pop(&s1, &oper2);
						pop(&s1, &oper1);
						printf(" %c\t\t%c\t\t%c\t\t%c\n", cur_op, oper1, oper2, 'Z' - op_count);
						push_result('Z' - (op_count++), &s1);
						prev_op = *(arit++);
						if (push_operator(prev_op, &s2) == -1)
						{
							printf("ERROR on arithmetic expression %c isn't allowed\n",prev_op);
							return;
						}

					}
				}
				
			}
			else
			{
				if (push_operator(*(arit++), &s2) == -1 || push_operand(*(arit++), &s1) == -1)
				{
					printf("ERROR on arithmetic expression\n");
					return;
				}
				stack_top(&s2, &prev_op);
				
			}
		}
		else
		{
			if (push_operand(*(arit)++, &s1) == -1)
			{
				printf("ERROR on arithmetic expression\n");
				return;
			}
		}
	}

	while (s2.top >= 0)
	{
		pop(&s2, &prev_op);
		pop(&s1, &oper2);
		pop(&s1, &oper1);
		printf(" %c\t\t%c\t\t%c\t\t%c\n", prev_op, oper1, oper2, 'Z' - op_count);
		if(s1.top>=0)
			push_result('Z' - (op_count++), &s1);
	}
}


void end_Ex()
{
	printf("\n\n\t*****************************************************\n");
	printf("\t***********    END                 OF     ***********\n");
	printf("\t***********    Ex1                 RUN    ***********\n");
	printf("\t*****************************************************\n");
}

void Ex1()
{
	char *arit_str = (char*)calloc(SIZE, sizeof(char));
	rewind(stdin);
	printf("\t\t\t**Arithmetic Phrase Calculator**\n\n\n");
	input_arit(arit_str);
	calc_arit(arit_str);
	end_Ex();
	

}