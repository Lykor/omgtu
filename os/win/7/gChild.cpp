#define _WIN32_WINNT 0x0500
#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "Graphics.cpp"

int main(int argc, char* argv[])
{
	int Value = time(NULL);
	srand(Value);

	TextColor(5, 0);
	printf("I'm ");
	TextColor(10, 0);
	printf("%s", argv[2]);
	TextColor(5, 0);
	_tprintf(TEXT(" and I'm gChild!\n"));

	TextColor(4, 0);
	_tprintf(TEXT("My father is: "));
	TextColor(9, 0);
	printf("%s\n", argv[1]);
	_tprintf(TEXT("\n"));
	for (int i = 1; i < 16; i++)
	{
		TextColor(16 - i, 0);
		printf("(%d) ", i);
		TextColor(i, 0);
		_tprintf(TEXT("- I'm gChild!\n"));
		float Delay = 1000 * ((float)rand() / RAND_MAX + 1);
		Sleep(Delay);
	}
    return 0;
}

