#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include <iostream>


/*			������������ 12
			��������� 12_2
			VI-�������

			��������� ��������� 12_1 ����������� � ���������� ������. ���
			����� ������� � ���������� � �������� ������ ���������.
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
		printf("������� ��� �����: ");

		// ���� �����
		scanf("%s", name);
		f = fopen(name, "w"); // ���������/������� ��� ������
		
		struct TP t[20];
		char* m = new char[20];
		char p[20];
		unsigned k, i;
		printf("�������� ���� ���\n");
		printf("������� ����������� ����: ");
		scanf_s("%u", &k);

		for (i = 0; i < k; ++i)
		{
			printf("������� %u �����: ", i + 1);

			scanf("%s", &t[i].slovo);
			fprintf(f, "%s ", t[i].slovo); // ���������� � ����
			
			printf("������� ������� �����: ");
	
			scanf("%s", &t[i].perevod);
			fprintf(f, "%s\n", t[i].perevod); // ����������� � ����
		}
		fclose(f);


		printf("����������� ����=%u\n", k);
		system("cls");

		f = fopen("text.txt", "rt"); // ��������� ��� ������

		for (int i = 0; i < k; i++)
		{
			fscanf(f, "%s", &t[i].slovo); // ������ � ����� � ���������� � ���������
			fscanf(f, "%s", &t[i].perevod); // ������ � ����� � ���������� � ���������
			
		}
		fclose(f);


		if (k > 0) {
			printf("������� ����� ��� ������:");
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