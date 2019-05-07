#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include <iostream>


/*			Лабораторная 12
			программа 12_2
			VI-вариант

			Дополнить программу 12_1 заполнением и обработкой файлов. Имя
			файла вводить с клавиатуры в процессе работы программы.
*/

	struct TP
	{
		char slovo[20];
		char perevod[20];
	};
	void main()
	{

		setlocale(LC_ALL, "RUS");
		FILE *f;
		char name[15];
		printf("Введите имя файла: ");

		// ввод файла
		scanf("%s", name);
		f = fopen(name, "w"); // Открываем/создаем для записи
		
		struct TP t[20];
		char* m = new char[20];
		char p[20];
		unsigned k, i;
		printf("Ключевые слов ТСи\n");
		printf("Введите колличество слов: ");
		scanf_s("%u", &k);

		for (i = 0; i < k; ++i)
		{
			printf("Введите %u слово: ", i + 1);

			scanf("%s", &t[i].slovo);
			fprintf(f, "%s ", t[i].slovo); // записываем в файл
			
			printf("Введите перевод слова: ");
	
			scanf("%s", &t[i].perevod);
			fprintf(f, "%s\n", t[i].perevod); // записывывам в файл
		}
		fclose(f);


		printf("Колличество слов=%u\n", k);
		system("cls");

		f = fopen("text.txt", "rt"); // открываем для чтения

		for (int i = 0; i < k; i++)
		{
			fscanf(f, "%s", &t[i].slovo); // читаем с файла и записываем в структуру
			fscanf(f, "%s", &t[i].perevod); // читаем с файла и записываем в структуру
			
		}
		fclose(f);


		if (k > 0) {
			printf("Введите слово для поиска:");
			scanf("%s", &p);
			for (i = 0; i < k; ++i)
			{
				if (strcmp(t[i].slovo, p) == 0)
				{
					printf("%s-%s", p, t[i].perevod);
				}
				else if (strcmp(t[i].perevod, p) == 0)
				{
					printf("%s-%s", p, t[i].slovo);
				}
			}
		}

		_getch();

	}