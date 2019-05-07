#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

/*

ООП
лабораторная 5
6 - вариант

Создать класс "номер геометрической фигуры" и реализовать:
а) член-функцию печати названия фигуры по её номеру;
б) дружественную функцию определяющую по количеству параметров, с
по-мощью которых можно построить известные фигуры.




*/

int nums=0;



typedef class Geometric
{


public:
	int num;
	char *name;
	int center, radius=0, leftTop=0, rightTop, lenght;


	void setParam(int leftTop, int rightTop, int lenght)
	{
		this->name = "box";
		this->leftTop = leftTop;
		this->rightTop = rightTop;
		this->lenght = lenght;
	}

	void setParam(int center, int radius)
	{
		this->name = "circle";
		this->center = center;
		this->radius = radius;

	}

	Geometric()
	{
		this->num = nums++;
		this->name = "point";
	}

	void getName()
	{
		printf("%s\n", name);
	}

	void getValue()
	{
		printf("%i\n", num);
	}

	
	friend void getgeom(Geometric s[],int x);
	friend void geomPara(Geometric s[]);
};





void getgeom(Geometric s[],int x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x == s[i].num)
			printf("%s\n", s[i].name);
	}
}

void geomPara(Geometric s[])
{
	for (int i = 0; i < 3; i++)
	{
		if (s[i].leftTop!=0) 
		{
			s[i].getValue();
			printf(" - rectangle\n"); 
		}

		else if (s[i].radius!=0) 
		{
			s[i].getValue();
			printf(" - circle\n"); 
		}

		else
		{
			s[i].getValue();
			printf(" - points\n"); 
		}

		


	}
}





void main()
{
	Geometric figures[3];
	
	figures[1].setParam(4, 10);
	figures[2].setParam(10, 20, 30);

	int x = 0;

	do{
		printf("Enter your number for search figure - ");
		scanf("%i", &x);
		getgeom(figures, x);
	} while (x < 3);

	geomPara(figures);


	_getch();
}