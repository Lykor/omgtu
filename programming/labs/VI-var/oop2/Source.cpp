#include <stdio.h>
#include <conio.h>

/*

���
������������ 2
6 - �������

���������� ����� cyl ��� �������� ���������� � ��������.
����� ������ ��������� ����������� �������� ������ � 
������ �������� � ������� ������������ ����� � ������ ������� ��������


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