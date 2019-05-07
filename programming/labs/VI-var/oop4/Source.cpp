#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

/*

ќќѕ
лабораторна€ 4
6 - вариант

¬вести класс дл€ работы с пр€моугольной матрицей. –еализовать операции:
а) проверка наличи€ заданного числа в заданной матрице (операци€ !=);
б) вычитание двух матриц (операци€ Ц).
„леном класса сделать функцию с именем printf() дл€ вывода конечной матрицы и ее модул€.



*/





typedef class Matrix
{
protected:
	int mat[4][4];


public:
	Matrix()
	{
		for (int i = 0; i < 4; i++)
			for(int j = 0 ; j < 4 ; j++) 
				mat[i][j] = i;
	}
	Matrix(int mat[][4])
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				this->mat[i][j] = mat[i][j];
	}

	bool Matrix::operator!() const
	{
		return !mat[0][0];
	}

	bool operator!=(const int x) 
	{
		for(int i=0;i<4;i++)
			for (int j = 0; j < 4; j++)
			{
				if (mat[i][j] == x) return true;
			}
		return false;
	}

	

	Matrix operator- ( Matrix b)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				this->mat[i][j] = this->mat[i][j] - b.mat[i][j];
		return b;
	}

	void printf()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << mat[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";

	}


};




void main()
{
	Matrix a, b;

	printf("a:\n");
	a.printf();

	printf("b:\n");
	b.printf();

	a - b;
	printf("a-b\n");
	a.printf();

	const int x = 1;
	
	printf("%d -  ' %d ' number in B Matrix\n", b != x, x);
	printf("%d -  ' %d ' number in A Matrix\n", a != x, x);


	_getch();
}