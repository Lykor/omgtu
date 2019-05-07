#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>

/*
					Лабораторная 9
					программа 9_2
					 VI-вариант

Составить подпрограмму для переменных двух квадратных матриц,
с помощью которой вычислить вторую, третью и четвертую степени мат-
рицы M [1..5,1..5]. Для каждой матрицы вычислить сумму и среднее ариф-
метическое значение элементов.


*/
const int m = 5;

void MatrixPow(int arr[m][m], int pow)
{

	int res[m][m] = { 0 };
	int p = 0;
	while (++p <= pow)
	{
		for (int i = 0; i < m; i++)
		{

			for (int j = 0; j < m; j++)
			{

				for (int k = 0; k < m; k++)
				{

					res[i][j] += arr[i][k] * arr[k][j];

				}


			}
		}

	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = res[i][j];

}


void vvodkv(int arr[m][m])
{
	printf("Want generate? - (Press Enter - yes)\n");
	if (_getch() == 13)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = (i == j) ? rand() % 10 : rand() % 10;
	}
	else
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j += 5)
				scanf("%d %d %d %d %d", &arr[i][j], &arr[i + 1][j + 1], &arr[i + 2][j + 2], &arr[i + 3][j + 3], &arr[i + 4][j + 4]);
	}
}


float outArrkv(int arr[m][m],int *p)
{
	*p = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
			*p += arr[i][j];
		}
		
		printf("\n");
	}
	
	return (float)*p / (float)m;
}


void main()
{
	int mas[m][m];
	int res;

	vvodkv(mas);
	printf("\n%f - sr arif, ", outArrkv(mas, &res));
	printf("%i - summa elementov\n", res);

	
	printf("Array 3 pow:\n");
	MatrixPow(mas, 3);
	printf("\n%f - sr arif, ",outArrkv(mas,&res));
	printf("%i - summa elementov\n", res);


	printf("Array 4 pow:\n");
	MatrixPow(mas, 4);
	printf("\n%f - sr arif, ", outArrkv(mas, &res));
	printf("%i - summa elementov\n", res);


	_getch();


}