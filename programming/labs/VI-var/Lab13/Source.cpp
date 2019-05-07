#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iostream>
#include "Header.h"


/*			Ћабораторна€ 13
	

		ƒл€ задач 8_3 и 9_2 разработать программы, скрыв подпрограммы в
	отдельном файле (модуле), использовать ссылки на переменные, объ€в-
		ленные в другом модуле.
*/

void main()
{
	int arr[n][m];
	printf("Enter firsr array:\n\n");
	vvod(arr);

	printf("your array:\n");
	outArr(arr);

	printf("%d - otricatelnyx v 1 massive\n\n", otric(arr));

	int arr2[n][m];
	printf("Enter second array:\n");
	vvod(arr2);

	printf("your array:\n");
	outArr(arr2);

	printf("%d - otricatelnyx v 2 massive\n\n", otric(arr2));
	
	int arr3[m][m];
	vvodkv(arr3);
	printf("Matrix for pow:\n");
	
	outArrkv(arr3);

	printf("Matrix pow 3:\n");
	MatrixPow(arr3, 3);
	outArrkv(arr3);

	printf("Matrix pow 4:\n");
	MatrixPow(arr3, 4);
	outArrkv(arr3);
	

	_getch();
}