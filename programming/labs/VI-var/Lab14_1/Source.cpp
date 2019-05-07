#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iostream>


/*			Лабораторная 14
			программа 14_1
			VI-вариант

Найти сумму четных элементов списка, состоящего не менее чем из
двух элементов.
*/

typedef struct ls
{
	int i;
	struct ls* next;

}LS;


void main()
{

	LS *p;
	LS *t;
	
	int k=0;
	int max = 10;
	int summ = 0;

	printf("summa of \n");

	p = NULL;
	do
	{
		t = new LS;
		t->next = p;
		p = t;
		t->i = k;
		printf("+%i", k);
		k++;
	} while (k < max);
	
	printf("\n");

	t = p;

	while (t != 0)
	{
		if(t->i%2==0)
		summ += t->i;

		t = t->next;
	}

	printf("=%i", summ);
	_getch();




}