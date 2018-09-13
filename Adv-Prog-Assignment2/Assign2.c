#define _CRT_SECURE_NO_WARNINGS

#include "Assign2.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXSTR 100
#define MAXDEC 10

char** firstChrStr(char ch, char *str, int *size)
{
	char *word = (char*)calloc(strlen(str) + 1, sizeof(char));
	int cwords = 0, cletter = 0, i = 0;
	char **words = (char**)calloc(1, sizeof(char*));

	if (ch >= 65 && ch <= 90)
	{
		ch = ch + 32;
	}

	while (str[i] != '\0')
	{
		if (str[i] == ch || str[i] == ch - 32)
		{
			if (i == 0 || (str[i - 1] == ' '))
			{
				cwords++;
				while (str[i] != ' ' && str[i] != '\0')
				{
					word[cletter++] = str[i];
					i++;
				}
				word[cletter] = '\0';
				if (cwords > 1)
				{
					words = (char**)realloc(words, cwords * sizeof(char*));
				}
				words[cwords - 1] = (char*)calloc(cletter + 1, sizeof(char));
				strcpy(words[cwords - 1], word);
				cletter = 0;
			}
		}
		i++;
	}

	*size = cwords;
	return words;
}

void printArrayChr(char **A, int size)
{
	for (int i = 0; i < size; i++)
	{
		puts(A[i]);
	}
}

void Ex1()
{
	char *str = (char*)calloc(MAXSTR, sizeof(char));
	char **newstr;
	int size = 0;
	char ch;
	rewind(stdin);
	printf("\t\t***Ex1 - Array of words start from specific letter of your choose***\n\n");

	printf("Enter string of your choice (MAXLENGTH=%d): ", MAXSTR);
	gets_s(str,sizeof(char)*MAXSTR);
	printf("Enter char: ");
	rewind(stdin);
	scanf("%c", &ch);


	newstr = firstChrStr(ch, str, &size);

	printf("The following are the words that start with the letter '%c':\n", ch);

	printArrayChr(newstr, size);

	printf("number of words: %d\n", size);

	for (int i = 0; i < size; i++)
	{
		free(newstr[i]);
	}
	
	free(newstr);
	free(str);

	printf("\nFreed array\n");
}

char* removeNumSpace(char *str)
{
	int size = 0;
	int len = strlen(str);
	char *newstr = (char*)calloc(len, sizeof(char));

	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
		{
			newstr[size++] = str[i];
		}
	}

	newstr[size] = '\0';

	newstr = (char*)realloc(newstr, (size + 1) * sizeof(char));

	return newstr;
}

void Ex2()
{
	char *str = (char*)calloc(MAXSTR, sizeof(char));
	char *newstr;
	printf("\t\t***Ex2 - This func gets string with digits and spaces and remove them***\n\n");

	printf("Enter your string(MAXLENGTH=%d): ", MAXSTR);
	rewind(stdin);
	gets_s(str,sizeof(char)*MAXSTR);

	newstr = removeNumSpace(str);

	printf("New string is: ");
	puts(newstr);

	free(str);
	free(newstr);

	printf("\n\nFreed strings\n");
}

char commonestChar(char *filename)
{
	char ch = 0;
	int *letters;
	int maxch = 0;
	FILE *fp = fopen(filename, "w+");
	if (!fp)
	{
		printf("Cannot create file: %s\nback to main menu\n\n", filename);
		return 0;
	}
	printf("Keep entering chars (only alphabetic), to stop press ctrl+Z: \n\n");
	while ((ch = getchar()) != EOF)
	{
		fputc(ch, fp);
	}

	fseek(fp, 0, SEEK_SET);
	letters = (int*)calloc(26, sizeof(int));

	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch >= 'A' && ch <= 'Z')
		{
			letters[ch - 'A']++;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			letters[ch - 'a']++;
		}
	}
	ch = 0; //re-assign ch as NULL for the commonest char find

	for (int i = 0; i < 26; i++)
	{
		if (letters[i] > maxch)
		{
			maxch = letters[i];
			ch = 'A' + i;
		}
		else if (letters[i] == maxch && maxch>0)
		{
			ch = 'A' + i;
		}
	}

	free(letters);
	fclose(fp);
	return ch;
}

void Ex3()
{
	char *filename = (char*)calloc(MAXSTR, sizeof(char));
	char ch;
	printf("\t\t*** Ex3 - Function counts for commonest char, if several chars has same count return biggest one***\n\n");

	printf("Enter file name to write to: ");
	rewind(stdin);
	gets_s(filename,sizeof(char)*MAXSTR);
	
	ch = commonestChar(filename);
	if (ch != 0)
		printf("\n\nThe commonest char with biggest value is: '%c'\n\n", ch);
	else
		printf("\n\nNo commonest char was found\n\n");

	free(filename);
}


void reduceToCyph(char *str)
{
	int i = 0;
	int cletter = 1;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			str[i] -= cletter++;
		}
		else
		{
			cletter = 1;
		}
		i++;
	}
}

void Ex4()
{
	char *str = (char*)calloc(MAXSTR, sizeof(char));

	rewind(stdin);
	printf("\t\t*** Ex4 - This function reduce every char by it's position in the word and you get a new string***\n\n");
	printf("Enter string to be reduced(MAXLENGTH=%d): ", MAXSTR);
	gets_s(str,sizeof(char)*MAXSTR);

	reduceToCyph(str);

	printf("New string is: ");
	puts(str);
}


void printFile(FILE *fp)
{
	char ch;
	fseek(fp, 0, SEEK_SET);
	while ((ch=(fgetc(fp)))!=EOF)
	{
		putchar(ch);
	}
}

void WriteDecToFile(char *filename, char *declaration)
{
	char *p;
	int i = 0;
	int var_value = 0;
	int countArr = 0;

	FILE *fp = fopen(filename, "w+");
	if (fp == NULL)
	{
		printf("Error creating file\n");
		return;
	}
	
	
	switch (declaration[i])
	{
	case 'i':
	{
		p = &declaration[i];
		if (strncmp(p, "int", sizeof(char) * 3) != 0)
		{
			printf("Wrong type\n");
			return;
		}
		var_value = sizeof(int);
		i += 3;
		printf("%d is size of one integer\n", var_value);
		break;
	}
	case 'c':
	{
		p = &declaration[i];
		if (strncmp(p, "char", sizeof(char) * 4) != 0)
		{
			printf("Wrong type\n");
			return;
		}
		var_value = sizeof(char);
		i += 4;
		printf("%d is size of one char\n", var_value);
		break;
	}
	case 's':
	{
		p = &declaration[i];
		if (strncmp(p, "short", sizeof(char) * 5) != 0)
		{
			printf("Wrong type\n");
			return;
		}
		var_value = sizeof(short);
		i += 5;
		printf("%d is size of one short\n", var_value);
		break;
	}
	case 'd':
	{
		p = &declaration[i];
		if (strncmp(p, "double", sizeof(char) * 6) != 0)
		{
			printf("Wrong type\n");
			return;
		}
		var_value = sizeof(double);
		i += 6;
		printf("%d is size of one double\n", var_value);
		break;
	}
	case 'f':
	{
		p = &declaration[i];
		if (strncmp(p, "float", sizeof(char) * 5) != 0)
		{
			printf("Wrong type\n");
			return;
		}
		var_value = sizeof(float);
		i += 5;
		printf("%d is size of one float\n", var_value);
		break;
	}
	case 'l':
	{
		p = &declaration[i];
		if (strncmp(p, "long", sizeof(char) * 4) != 0)
		{
			printf("Wrong type\n");
			return;
		}
		var_value = sizeof(long);
		i += 4;
		printf("%d is size of one long\n", var_value);
		while (declaration[i] == ' ')
		{
			i++;
		}
		p = &declaration[i];
		if (strncmp(p, "long", sizeof(char) * 4) == 0)
		{
			var_value = sizeof(long long);
			i += 4;
			printf("%d is size of one long long\n", var_value);
		}
		break;
	}
	default:
	{
		printf("Wrong type\n");
		return;
	}
	}

	while (declaration[i] != '\0')
	{
		if (declaration[i] == ' ' || declaration[i] == ',' || declaration[i] == ';')
		{
			i++;
		}
		else
		{
			if (declaration[i] == '*')
			{
				i++;
				while (declaration[i] != ',' && declaration[i] != ';' && declaration[i] != '\0')
				{
					//printf("writing %c into file\n", declaration[i]); //only prints to screen the char needed to be written to file
					fputc(declaration[i], fp);
					i++;
				}
				fprintf(fp, " requires 4 bytes\n");
			}
			else
			{
				while (declaration[i] != ',' && declaration[i] != ';' && declaration[i] != '\0')
				{
					//printf("writing %c into file\n", declaration[i]); //only prints to screen the char needed to be written to file
					fputc(declaration[i], fp);
					i++;
					if (declaration[i] == '[')
					{
						i++;
						while (declaration[i] != ']')
						{
							countArr *= 10;
							countArr += (declaration[i] - '0');
							i++;
						}
						i++;
					}
				}
				if (!countArr)
					fprintf(fp, " requires %d bytes\n", var_value);
				else
					fprintf(fp, " requires %d bytes\n", var_value*countArr);
			}
		}
		
	}

	printf("\n\n--->Printing file: \n\n");
	printFile(fp);
	fclose(fp);
	
}

void Ex5()
{
	char *filename = (char*)calloc(MAXSTR, sizeof(char));
	char *declaration = (char*)calloc(MAXSTR, sizeof(char));
	
	printf("\t\t*** Ex5 - This func gets file name and declaration of vars and puts the size that need into the file given ***\n\n");
	printf("Enter file name: ");
	rewind(stdin);
	gets_s(filename,sizeof(char)*MAXSTR);
	printf("Enter declaration: ");
	rewind(stdin);
	gets_s(declaration,sizeof(char)*MAXSTR);

	WriteDecToFile(filename, declaration);

	
}
