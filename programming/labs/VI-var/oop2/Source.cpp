#include <stdio.h>
#include <conio.h>

/*

ООП
лабораторная 2
6 - вариант

Определите класс cyl для хранения информации о цилиндре.
Класс должен содержать конструктор задающий радиус и 
высоту цилиндра и функции вычисляю¬щие объем и полную площадь цилиндра


*/
typedef class cyl
{
private:
	int radius;
	int height;

public:
	cyl(int radius, int height)
	{
		this->radius = radius;
		this->height = height;
	}
	cyl()
	{
		cyl(1, 1);
	}

	void getArea()
	{
		printf("%2f - Area\n", (2 * 3.1415*radius*(radius+height)));
	}

	void getVolume()
	{
		printf("%2f - Volume\n", (3.1415*radius*radius*height));
	}

};



void main()
{
	cyl celka(10,5);

	celka.getArea();
	celka.getVolume();

	_getch();
}