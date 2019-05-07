#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

/*

			Лабораторная 11
			программа 11_2
			6 - вариант

			Даны два файла F1, F2. Сформировать третий файл F, в который
			сначала записать все элементы файла F1, а затем – элементы файла F2.

*/



int outMas(int **arr,FILE *output) // функция вывода массива и его заполнения
{

	int s = sizeof(arr);

	

	for (int i = 0; i < s; i++) // проход по строке 
	{
		for (int j = 0; j < s; j++) // проходим по столбцу
		{
			if (arr[i][j] >=0 ) {
				fprintf(output, "%d ", arr[i][j]);
				printf("%d ", arr[i][j]); // условие ? true : false;
			}

		}
		
		printf("\n");
	}
	fprintf(output, "\n");

	fclose(output);
	return 0; // возвращаем среднее афирметическое (сумму на количество делим)
}



int** pushMas(int s)  // функция создания двумерного массива
{
	int** arr = new int*[s];
	for (int i = 0; i < s; i++)
		arr[i] = new int[s];

	return arr; // возврщаем массив
}


int** zapolnen(char *name)
{
	FILE *input;
	input = fopen(name, "rt");

	int** mat = pushMas(sizeof(input));
	for (int i = 0; i<sizeof(input); i++)
		for (int j = 0; j<sizeof(input); j++)
			fscanf(input, "%d", &mat[i][j]);

	fclose(input);
	return mat;
}



void main()
{
	int **file_one = zapolnen("file1.txt");
	int **file_two = zapolnen("file2.txt");
	
	FILE *out = fopen("file3.txt", "w");
	outMas(file_one,out);
	out = fopen("file3.txt", "a+");
	outMas(file_two,out);


	_getch();
}