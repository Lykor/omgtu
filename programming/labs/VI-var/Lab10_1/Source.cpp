#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iostream>

/*			Лабораторная 10
			программа 10_1
			  VI-вариант

Дана последовательность символов. Определить в ней символ, ко-
торый по алфавиту предшествует другим.*/

int min(int x, int y)
{
	int min;

		if (x > y)
			min=y;
		else min=x;

		return min;

}


void main()
{
	char st[255]; 
	int k = 256; 

	do{
		printf("enter string: ");
		gets_s(st);
		
		for (int i = 0; i < strlen(st); i++)
		{
			k = min(k, (int)st[i]);
		}

		printf("%c\n", (char)k);
		_getch();

	} while (st[0]!='.');
	
}