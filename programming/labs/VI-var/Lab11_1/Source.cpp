#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

/*

������������ 11_1.

��������� ������ �� ������������ ������ 9, �������� ��������
������ �� ������ ����� � ��������� ���������� ���������� � ������
��������� ����. ���� � ��������� ������� ������ ���� �����������
��������������.

-��������� 9_1-
VI - �������

�������� � �������� ��������� ��� ������ �� ������������ ������ 7
� ���������� ��������� ��������� ��� ������������ �������. ��������-
���� ����� ��������� � �����������-��������� ��� ���� ������� �����-
��� ������. (��� ��������� ������� ������ ����� ������ ����������).


*(������������ 7)

������������ ������ �� �������
|0 0 0..
|0 1 0..
|0 0 2...
|0 0 0 3..
*/

int outMas(int **arr, int *p) // ������� ������ ������� � ��� ����������
{
	
	int s = sizeof(arr);

	FILE *output = fopen("output.txt", "w");

	*p = 0; // ������������� ���������� ��� �������� ����� ���������

	for (int i = 0; i < s; i++) // ������ �� ������ 
	{
		for (int j = 0; j < s; j++) // �������� �� �������
		{
			fprintf(output, "%d ", arr[i][j]);
			printf("%d ",arr[i][j]); // ������� ? true : false;
			*p += arr[i][j]; // ������ ���������� ���������

		}
		fprintf(output,"\n");

		printf("\n");
	}

	fclose(output);
	return *p / s; // ���������� ������� �������������� (����� �� ���������� �����)
}



int** pushMas(int s)  // ������� �������� ���������� �������
{
	int** arr = new int*[s];
	for (int i = 0; i < s; i++)
		arr[i] = new int[s];

	return arr; // ��������� ������
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