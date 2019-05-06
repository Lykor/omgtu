#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <GL/glut.h>



#define pi 3.141592653

using namespace std;

int x, y;
char c;
bool joob = false;

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SystemClear()
{
	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	HPEN pen = CreatePen(PS_DASHDOT, 2, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, 0, 0, 1000, 1000);
}

void Animation()
{
	int index = 0;

	system("CLS");
	do {
		SystemClear();
		HWND hwn = GetConsoleWindow();
		HDC hdc = GetDC(hwn);
		HPEN pen = CreatePen(PS_DASHDOT, 2, RGB(100, 100, 55));
		HBRUSH brush = CreateSolidBrush(RGB(255 - index, 25 + index, 15 + index));
		SelectObject(hdc, pen);
		SelectObject(hdc, brush);
		Ellipse(hdc, 90 + index, 30, 100, 100);
		index++;
		Sleep(30);
	} while (!_kbhit());
	SystemClear();
	system("CLS");
}



void Graphic()
{
	system("CLS");
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	HPEN Rpen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN Gpen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	{
		int i, d = 100, scale = 44;
		float x;
		SelectObject(hDC, Pen);

		// X ось
		MoveToEx(hDC, 0+d, 170+d, NULL);
		LineTo(hDC, 600+d, 170+d);

		// Y ось
		MoveToEx(hDC, 300+d, 0+d, NULL);
		LineTo(hDC, 300+d, 340+d);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(50, 7);
		cout << "Y";

		gotoxy(90, 22);
		cout << "X";

		double a = 0, b = pi, n = 999;
		double dx = fabs(b - a) / (n - 1);
		x = a;
		
		for (i = 0; i <= n; i++) // O(300,170) - center
		{
			//F1
			SelectObject(hDC, Rpen);
			MoveToEx(hDC, scale * x + 300+d, -scale * (exp(-x)+cos(2*x)) + 170+d, NULL);//10 - scale
			LineTo(hDC, scale * x + 300+d, -scale *(exp(-x)+ cos(2*x)) + 170+d);

			//F2
			SelectObject(hDC, Gpen);
			MoveToEx(hDC, scale * x + 300+d, -scale * exp(-2 * x)  + 170+d, NULL);//10 - scale
			LineTo(hDC, scale * x + 300+d, -scale * exp(-2 * x) + 170+d);
			x += dx;
		}
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(34, 20);
		cout << "F2=e^-2*x";
		

		SelectObject(hDC, Rpen);
		gotoxy(30, 18);
		cout << "F1=e^-x+cos2x";
		

		
			
	}while (_getch() != char(27));
	SystemClear();
	DeleteObject(Pen);
	system("CLS");
	
}

void Table()
{
	do
	{
		system("CLS");
		const int m = 20;
		int i, n=20;
		double F1, F2, x, dx, b = 3.1413, a = 0, Fone[m], Ftwo[m], F_omax=0, F_omin=0, F_tmax=0, F_tmin=1;


		gotoxy(44, 5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		
		
		dx = fabs(b - a) / (n - 1);
		x = a;
		gotoxy(40, 6);
		printf(" ______________________________ ");
		gotoxy(40, 7);
		
		printf("| I |    X   |   F1   |   F2   |");
		gotoxy(40, 8);
		printf("|---|--------|--------|--------|");


		for (i = 1; i <= n; ++i)
		{
			F1 = exp(-x) + cos(2 * x);
			F2 = exp(-2 * x);

			Fone[i] = F1;
			Ftwo[i] = F2;

			if (Fone[i] > F_omax)
			{				
				F_omax = Fone[i];
			}
			else if (Fone[i] < F_omin)
			{
				F_omin = Fone[i];
			}
			if (Ftwo[i] > F_tmax)
			{
				F_tmax = Ftwo[i];
			}
			else if (Ftwo[i] < F_tmin)
			{
				F_tmin = Ftwo[i];
			}

			//gotoxy(40, 9 + i);
			//printf("|%3d|%8.3f|%8.4f|%8.4f|", i, x, Fone[i], Ftwo[i]);
			x += dx;

		}
		
		x = 0;
		for (i = 1; i <= n; i++) {

			gotoxy(40, 8 + i);
			printf("|%3d|%8.3f|",i,x);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			if (Fone[i] == F_omax)
			{
				
				printf("%8.4f",Fone[i]);
				
			} 

			else if (Fone[i] == F_omin)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("%8.4f",Fone[i]);
				
			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%8.4f", Fone[i]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("|");
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			if (Ftwo[i] == F_tmax)
			{
				printf("%8.4f", Ftwo[i]);
										
			}
			else if (Ftwo[i] == F_tmin)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("%8.4f", Ftwo[i]);
				
			}	
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%8.4f", Ftwo[i]);
			}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("|");

			x += dx;
		}
					

		gotoxy(40, 9 + i);
		printf(" ______________________________ \n");
		gotoxy(40, 11 + i);
		printf("F1 max = %8.4f, min = %8.4f", F_omax,F_omin);
		gotoxy(40, 12 + i);
		printf("F2 max = %8.4f, min = %8.4f", F_tmax,F_tmin);
		

	} while (_getch() != char(27));
	system("CLS");
}

double F(double x)
{
	double f;
	f = pow(atan(x), 2) / x;
	return f;
}

double Integral(double x)
{
	double F;
	F = pow(atan(x), 2) / x;
	return F;
}

int IntegralTreu(double x)
{

	return x;
}

/*-----------------Метод трапеции-------------------*/

float MethodTrap(int a, int b, int n)
{
	float d, S=0;
	d = (b - a) / n;				 
	
	S = (a*exp(a)*sin(a) + b*exp(b)*sin(b)) / 2; 
	for (x = a + d; x <= b - d; x += d)	
	{
		S += pow(atan(x), 2) / x;
	}
	S *= d;				
	
	return S;
}



/*---------------Метод прямоугольника------------------*/
float MethodRect(int a, int b, int n)
{
	float h, S=0, x;
	int i;
	h = (b - a) * 1.0 / n;
	S = 0;
	for (i = 0; i<n - 1; i++)
	{
		x = a + i*h;
		S = S + (pow(atan(x), 2) / x);
	}
	S = h*S;
	return S;
	
}







void Integral()
{
	
	do
	{
		system("CLS");
		
		int choice = 2;
		int a=0, b=0, n=0;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(47, 19);
		printf("Введите A, B и шаг");
		gotoxy(53, 20);
		printf("a = ");
		scanf_s("%d", &a);
		gotoxy(53, 21);
		printf("b = ");
		scanf_s("%d", &b);
		gotoxy(43, 22);
		printf("Введите шаг интегрирования.");
		gotoxy(53, 23);
		printf("n = ");
		scanf_s("%d", &n);
		
		gotoxy(49, 27);
		printf("МЕТОД ТРАПЕЦИИ");
		gotoxy(45, 29);
		printf("МЕТОД ПРЯМОУГОЛЬНИКОВ");
		int inte = 0;
		while (c != char(13))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			gotoxy(35, 27 + choice);
			cout << "->";
			gotoxy(75, 27 + choice);
			cout << "<-";
			gotoxy(0, 0);
			c = _getch();
			gotoxy(35, 27 + choice);
			cout << "  ";
			gotoxy(75, 27 + choice);
			cout << "  ";
			if (c == 's' || c == 0x50)
			{
				if (choice<2)
				{
					choice += 2;
				}
			}
			if (c == 'w' || c == 0x48)
			{
				if (choice>0)
				{
					choice -= 2;
				}
			}
			inte++;
		}

		if (inte == 1) {
			switch (choice)
			{
			case 0:
				gotoxy(40, 41);
				printf("Интеграл f(x) равен = %f", MethodTrap(a, b, n));
				break;
			case 2:
				gotoxy(40, 41);
				printf("Интеграл f(x) равен = %f", MethodRect(a, b, n));
				break;

			}
		}
		
		
		//gotoxy(40, 41);
		//cout << "Интеграл f(x) равен = " << integral;
				

	} while (_getch() != char(27));

	system("CLS");
}

double f(double x)
{
	return pow(x, 2) - log10(x + 1) + sin(x) - 2;
}

double find(double a, double b, double e)
{
	while (fabs(f(b)) > e)
	{
		a = b - ((b - a) * f(b)) / (f(b) - f(a));
		b = a - ((a - b) * f(a)) / (f(a) - f(b));
	}
	return b;
}

void Equation()
{
	system("CLS");
	do
	{
		double a, b, e = 0.001;
		gotoxy(44, 10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Введите значение a:";
		cin >> a;
		gotoxy(44, 11);
		cout << "Введите значение b:";
		cin >> b;
		gotoxy(40, 13);
		cout << "Корень уравнения x=" << find(a, b, e) << endl;

	} while (_getch() != char(27));
	system("CLS");
}

void Author()
{
	system("CLS");
	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(49, 19);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << " Жарков Валерий Юрьевич ";
		gotoxy(32, 21);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Факультет Информационных Технологий и Компьютерных Систем";
		gotoxy(35, 23);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "    Прикладная информатика в экономике (ПИ-171)    ";

	} while (_getch() != char(27));
	system("CLS");

}



void menu()
{
	char c = '0';
	int choice = 2;
	joob = true;
	system("CLS");
	while (joob == true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(56, 14);
		cout << char(24);
		gotoxy(56, 15);
		cout << "W";

		gotoxy(56, 34);
		cout << char(25);
		gotoxy(56, 35);
		cout << "S";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(52, 19);
		cout << " ЗАСТАВКА ";
		gotoxy(53, 21);
		cout << " ГРАФИК ";
		gotoxy(52, 23);
		cout << " ТАБЛИЦА ";
		gotoxy(52, 25);
		cout << " ИНТЕГРАЛ ";
		gotoxy(51, 27);
		cout << " УРАВНЕНИЕ ";
		gotoxy(53, 29);
		cout << " АВТОР ";
		gotoxy(53, 31);
		cout << " ВЫХОД ";
		while (c != char(13))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			gotoxy(45, 19 + choice);
			cout << "->";
			gotoxy(65, 19 + choice);
			cout << "<-";
			gotoxy(0, 0);
			c = _getch();
			gotoxy(45, 19 + choice);
			cout << "  ";
			gotoxy(65, 19 + choice);
			cout << "  ";
			if (c == 's' || c == 0x50)
			{
				if (choice<12)
				{
					choice += 2;
				}
			}
			if (c == 'w' || c == 0x48)
			{
				if (choice>0)
				{
					choice -= 2;
				}
			}

		}
		switch (choice)
		{
		case 0: Animation(); break;
		case 2: Graphic(); break;
		case 4: Table(); break;
		case 6: Integral(); break;
		case 8: Equation(); break;
		case 10: Author(); break;
		case 12: joob = false; break;
		}

		choice = 2;
		c = ' ';
		system("CLS");
	}
}


int main()
{
	setlocale(0, "");
	SetWindow(113, 44);
	do {
		menu();
	} while (joob);
	return 0;
}


