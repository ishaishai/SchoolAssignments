#pragma once

#define MAXSTR 100
typedef struct employee
{
	int  code;
	char  name[15];
	float  salary;
} Employee;

Employee* create_Employee();
void WriteEmpToFile(char *filename);
void Ex1_1();

void UpdateEmpFromFile(char *filename, float threshold);
void Ex1_2();

void ReadEmpFromFile(char *filename);
void Ex1_3();

void Ex1_Menu();