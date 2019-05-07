#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

/*

			������������ 11
			��������� 11_2
			6 - �������

			���� ��� ����� F1, F2. ������������ ������ ���� F, � �������
			������� �������� ��� �������� ����� F1, � ����� � �������� ����� F2.

*/



int outMas(int **arr,FILE *output) // ������� ������ ������� � ��� ����������
{

	int s = sizeof(arr);

	

	for (int i = 0; i < s; i++) // ������ �� ������ 
	{
		for (int j = 0; j < s; j++) // �������� �� �������
		{
			if (arr[i][j] >=0 ) {
				fprintf(output, "%d ", arr[i][j]);
				printf("%d ", arr[i][j]); // ������� ? true : false;
			}

		}
		
		printf("\n");
	}
	fprintf(output, "\n");

	fclose(output);
	return 0; // ���������� ������� �������������� (����� �� ���������� �����)
}



int** pushMas(int s)  // ������� �������� ���������� �������
{
	int** arr = new int*[s];
	for (int i = 0; i < s; i++)
		arr[i] = new int[s];

	return arr; // ��������� ������
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