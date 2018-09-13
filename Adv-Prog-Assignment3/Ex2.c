#define _CRT_SECURE_NO_WARNINGS
#include "Ex2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void displayBits(unsigned num, int n)
{
	unsigned counter;
	unsigned displayMask = 1 << ((unsigned)n - 1);
	for (counter = 1; counter <= ((unsigned)n); counter++)
	{
		putchar(num & displayMask ? '1' : '0');
		num <<= 1;
	}
	putchar(' ');
}

char* CodingToShortString(char *dig_str)
{
	int len = strlen(dig_str), flag = 0;
	int binlen = ((len + 1) / 2) + 1;
	unsigned char *short_dig_str = (char*)calloc(binlen, sizeof(char));
	unsigned int mask = 1 << 3;
	unsigned int digit;
	unsigned int res, finalres = 0;
	int i = 0, j = 0, k = 0; //index for new str
	
	if (len % 2==1)
	{
		flag = 1;
	}
	for (; i < len; i++)
	{
		if ((flag == 1) && (i == 0))
		{
			res = 0;
			digit = dig_str[i] - '0';
			res = res << 4;
			res = res | digit;

			short_dig_str[j++] = res + '0';
		}
		else
		{
			res = dig_str[i] - '0';
			digit = dig_str[i + 1] - '0';
			res <<= 4;
			res = res | digit;

			short_dig_str[j++] = res + '0';
			i++;
		}
	}
	
	short_dig_str[j] = '\0';

	printf("The number you entered displayed as binary with 8bit seperate: ");
	for (i = 0; i < j; i++)
	{
		displayBits(short_dig_str[i] - '0', 8);
	}

	return short_dig_str;
}

void Ex2_1(char **binstr)
{
	char *str = (char*)calloc(MAXSTR+1, sizeof(char));
	printf("Ex2_1 - Function takes digits string and turns into binary string\n\n");
	
	printf("Please enter digits string: ");
	rewind(stdin);
	gets_s(str, MAXSTR);
	
	(*binstr) = CodingToShortString(str);

	free(str);
}

unsigned bintonum(unsigned num, int n)
{
	unsigned counter;
	char *s;
	unsigned displayMask = 1 << ((unsigned)(n - 1));

	s = (char*)calloc(n + 1, sizeof(char));

	for (counter = 0; counter < ((unsigned)n); counter++)
	{
		s[counter] = (num & displayMask ? '1' : '0');
		num <<= 1;
	}
	s[n] = '\0';

	num = 0;

	if (s[0] == '1')
		num = num + 8;
	if (s[1] == '1')
		num = num + 4;
	if (s[2] == '1')
		num = num + 2;
	if (s[3] == '1')
		num = num + 1;

	free(s);
	return num;
}


void displayShortString(char* short_dig_str)
{
	
	unsigned int num1 = 0, num2 = 0, Unsigned_num = 0;
	int i = 0,j=0, flag = 0;
	int len = strlen(short_dig_str);
	char *total = (char*)calloc((len * 2) + 1, sizeof(char));

	for (; i < len; i++)
	{
		num1 = short_dig_str[i] - '0';
		num1 >>= 4;
		
		num1 = bintonum(num1, 4);
		if (i == 0 && num1 == 0)
			flag = 1;
		num2 = bintonum(short_dig_str[i], 4);
		if (num1 == 0 && i == 0)
		{
			total = (char*)realloc(total, len * 2);
		}
		else
		{
			total[j++] = num1 + '0';
		}

		total[j++] = num2 + '0';
		Unsigned_num = ((Unsigned_num * 10) + num1) * 10 + num2;
	}

	printf("Your number in Decimal is: %s\n", total);
	printf("as unsigned int: %u\n", Unsigned_num);
	printf("as binary seperated by 4bit: ");

	for (i = 0; i < len; i++)
	{
		num1 = short_dig_str[i] - '0';
		num1 = num1 >> 4;

		if ((flag == 1) && (i == 0))
		{
			displayBits(short_dig_str[i] - '0', 4);
		}
		else
		{
			displayBits(num1, 4);
			displayBits(short_dig_str[i], 4);
		}
	}

	printf("\n");
	
	free(total);
}

void Ex2_2(char *binstr)
{
	displayShortString(binstr);
}


void Ex2_Menu()
{
	printf("Ex2 - Menu for Bit string create and print\n\n");
	int select = 1, all_Ex_in_loop = 0;
	char *binstr=NULL;
	void(*menu[])() = { Ex2_1, Ex2_2 };


	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
	{
		do
		{
			rewind(stdin);
			system("cls");
			printf("Ex2 - Menu for Bit string create and print\n\n");
			printf("Ex2_1: Creating bit string --->1\n");
			printf("Ex2_2: Printing in Decimal or binary --->2\n");
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-2 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 2));
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

				(*menu[0])(&binstr); break;
			}
			case 2:
			{
				(*menu[1])(binstr); break;
			}
			}

			if (select>0)
			{

				printf("\n\nPress enter to continue\n");
				_getch();
			}
		} while (all_Ex_in_loop != 0 && select != 0);
	}
	return;
}