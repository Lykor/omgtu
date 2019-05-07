#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

/*

Лабораторная 11_1.

Выполнить задачу из лабораторной работы 9, считывая исходные
данные из одного файла и записывая полученные результаты в другой
текстовый файл. Файл с исходными данными должен быть подготовлен
предварительно.

-программа 9_1-
VI - Вариант

Написать и отладить программу для задачи из лабораторной работы 7
с выделением алгоритма обработки или формирования массива. Организо-
вать вызов процедуры с параметрами-массивами для двух наборов исход-
ных данных. (Для ускорения отладки массив можно задать константой).


*(Лабораторная 7)

Сформировать массив по правилу
|0 0 0..
|0 1 0..
|0 0 2...
|0 0 0 3..
*/

int outMas(int **arr, int *p) // функция вывода массива и его заполнения
{
	
	int s = sizeof(arr);

	FILE *output = fopen("output.txt", "w");

	*p = 0; // инициализация переменной для подсчета суммы элементов

	for (int i = 0; i < s; i++) // проход по строке 
	{
		for (int j = 0; j < s; j++) // проходим по столбцу
		{
			fprintf(output, "%d ", arr[i][j]);
			printf("%d ",arr[i][j]); // условие ? true : false;
			*p += arr[i][j]; // запись количества элементов

		}
		fprintf(output,"\n");

		printf("\n");
	}

	fclose(output);
	return *p / s; // возвращаем среднее афирметическое (сумму на количество делим)
}



int** pushMas(int s)  // функция создания двумерного массива
{
	int** arr = new int*[s];
	for (int i = 0; i < s; i++)
		arr[i] = new int[s];

	return arr; // возврщаем массив
}


int** zapolnen()
{
	FILE *input;
	input = fopen("input.txt", "r");

	int** mat = pushMas(sizeof(input));
	for (int i = 0; i<sizeof(input); i++)
		for (int j = 0; j<sizeof(input); j++)
			fscanf(input, "%d", &mat[i][j]);

	fclose(input);
	return mat;
}



void main()
{
	int **arr = zapolnen();
	int p;
	int sr = outMas(arr,&p);
	
	printf("%i - sr, %i - summ of elements", sr, p);

	_getch();
}