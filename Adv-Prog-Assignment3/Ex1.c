#define _CRT_SECURE_NO_WARNINGS
#include "Ex1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* create_Employee()
{
	Employee *emp = (Employee*)calloc(1, sizeof(Employee));

	printf("Enter emplyee code (-1 to stop): ");
	scanf("%d", &emp->code);
	rewind(stdin);
	if (emp->code == -1)
	{
		free(emp);
		return NULL;
	}
	printf("Enter employee name: ");
	gets_s(emp->name, sizeof(char) * 15);
	rewind(stdin);
	printf("Enter employee salary: ");
	scanf("%f", &emp->salary);
	rewind(stdin);
	
	return emp;
}
void WriteEmpToFile(char *filename)
{
	Employee *emp;
	FILE *fp;
	printf("This func is to write employees to file: \n");

	fp = fopen(filename, "ab+");
	if (!fp)
	{
		printf("Couldnt open file...going back\n\n");
		_getch();
		return;
	}
	
	emp = create_Employee();
	
	while (emp)
	{
		fwrite(emp, sizeof(Employee), 1, fp);
		free(emp);
		
		emp = create_Employee();
	}
	
	fclose(fp);
	printf("\n\n***Finished writing to file***\n\n");
}
void Ex1_1()
{
	char *filename = (char*)calloc(MAXSTR, sizeof(char));
	rewind(stdin);
	printf("Ex1 - func adds employees to the files\n\n");
	printf("Enter filename: ");
	gets_s(filename, MAXSTR*(sizeof(char)));

	WriteEmpToFile(filename);
	
}

void UpdateEmpFromFile(char *filename,float threshold)
{
	Employee emp;
	int count = 0;
	float bonus = 0;
	FILE *fsrc = fopen(filename, "rb+");
	FILE *fdst;
	char *dest = (char*)calloc(MAXSTR,sizeof(char));
	strcat(dest, filename);
	strcat(dest, "_tmp");
	fdst = fopen(dest, "wb");

	if (!fsrc || !fdst)
	{
		printf("Couldnt open file...going back\n\n");
		_getch();
		return;
	}
	

	while (fread(&emp, sizeof(Employee), 1, fsrc) ==1)
	{
		printf("Employee code: %d, Employee Name: %s, Employee Salaray: %f, how much to add: ",emp.code,emp.name,emp.salary);
		scanf("%f", &bonus);
		emp.salary += bonus;
		if (emp.salary > threshold)
		{
			printf("Employee %s has exceeded his salary and would be deleted from file\n", emp.name);
		}
		else
		{
			fwrite(&emp, sizeof(Employee), 1, fdst);
			count++;
		}
	}

	fclose(fsrc);
	remove(filename);
	fclose(fdst);
	rename(dest, filename);

	printf("\nFinished updating file...\n\n");
	
}
void Ex1_2()
{
	char *filename = (char*)calloc(MAXSTR, sizeof(char));
	float threshold = 0;
	rewind(stdin);
	printf("Ex2 - func updates employees from file\n\n");
	printf("Enter filename: ");
	gets_s(filename, sizeof(char)*MAXSTR);
	printf("Enter salary threshold: ");
	scanf("%f", &threshold);
	UpdateEmpFromFile(filename,threshold);

	printf("\nFinished updating\n\n");
}

void ReadEmpFromFile(char *filename)
{
	FILE *fp = fopen(filename, "rb");
	Employee emp;
	if (!fp)
	{
		printf("Cannot open file...quitting back to menu...\n\n");
		_getch();
		return;
	}

	while (fread(&emp, sizeof(Employee), 1, fp)==1)
	{
		printf("Employee Code: %d, Employee Name: %s, Employee Salary: %.2f\n", emp.code, emp.name, emp.salary);
	}

	fclose(fp);
}
void Ex1_3()
{
	char *filename = (char*)calloc(MAXSTR, sizeof(char));
	rewind(stdin);
	printf("Ex3 - func reads employees from file\n\n");
	printf("Enter filename: ");
	gets_s(filename, MAXSTR*(sizeof(char)));

	ReadEmpFromFile(filename);

	printf("\nFinised reading file\n\n");
}


void Ex1_Menu()
{
	printf("Ex1 - Menu for Employees register in bin file\n\n");
	int select = 1, all_Ex_in_loop = 0;

	void (*menu[])() = { Ex1_1, Ex1_2 ,Ex1_3 };


	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
	{
		do
		{
			rewind(stdin);
			system("cls");
			printf("Ex1 - Menu for Employees register in bin file\n\n");
			printf("Ex1_1: Creating file with records --->1\n");
			printf("Ex1_2: Updating file with records depends on salary threshold --->2\n");
			printf("Ex1_3: Printing records in file --->3\n");
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-3 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 3));
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
				(*menu[0])(); break;
			}
			case 2:
			{
				(*menu[1])(); break;
			}
			case 3:
			{
				(*menu[2])(); break;
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