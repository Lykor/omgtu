#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iostream>

/*			������������ 10
			��������� 10_1
			  VI-�������

���� ������������������ ��������. ���������� � ��� ������, ��-
����� �� �������� ������������ ������.*/

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