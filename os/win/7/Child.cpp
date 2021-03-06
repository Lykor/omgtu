#define _WIN32_WINNT 0x0500
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.cpp"

STARTUPINFOA sInfo;
PROCESS_INFORMATION pInfo;
const char* gChild = "gChild.exe";
char child[100];

PVOID FreeMem(STARTUPINFOA Info)
{
	ZeroMemory(&Info, sizeof(STARTUPINFOA));
	Info.cb = sizeof(Info);
	return 0;
}

int main(int argc, char* argv[])
{
	sprintf_s(child, "gChild.exe %s %s", argv[1], argv[2]);
	FreeMem(sInfo);
	CreateProcessA(gChild, child, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sInfo, &pInfo);
	
	int Value = time(NULL);
	srand(Value);

	TextColor(10, 0);
	_tprintf(TEXT("I'm "));
	TextColor(9, 0);
	printf("%s", argv[1]);
	TextColor(10, 0);
	_tprintf(TEXT(" and I'm Child!\n"));
	_tprintf(TEXT("\n"));
	for (int i = 1; i < 16; i++)
	{
		TextColor(16 - i, 0);
		printf("(%d) ", i);
		TextColor(i, 0);
		_tprintf(TEXT("- I'm child!\n"));
		float Delay = 1000 * ((float)rand() / RAND_MAX + 1);
		Sleep(Delay);
	}
    return 0;
}

