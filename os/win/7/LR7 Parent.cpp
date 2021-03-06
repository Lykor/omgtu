#define _WIN32_WINNT 0x0500
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.cpp"

HANDLE JobObject;
STARTUPINFOA sInfo1, sInfo2;
PROCESS_INFORMATION pInfo1, pInfo2;

const char* Child = "Child.exe";
char* Child1 = (char*)"Child.exe Alexey Viktor\0";
char* Child2 = (char*)"Child.exe Maria Natalya\0";

PVOID FreeMem(STARTUPINFOA Info)
{
	ZeroMemory(&Info, sizeof(STARTUPINFOA));
	Info.cb = sizeof(Info);
	return 0;
}

int main(int argc, char* argv[])
{
	JobObject = CreateJobObject(NULL, NULL);

	FreeMem(sInfo1);
	CreateProcessA(Child, Child1, NULL, NULL, FALSE, CREATE_NEW_CONSOLE|CREATE_SUSPENDED, NULL, NULL, &sInfo1, &pInfo1);
	
	FreeMem(sInfo2);
	CreateProcessA(Child, Child2, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sInfo2, &pInfo2);
	AssignProcessToJobObject(JobObject, pInfo2.hProcess);

	ResumeThread(pInfo1.hThread);
	ResumeThread(pInfo2.hThread);

	int Value = time(NULL);
	srand(Value);
	TextColor(12, 0);
	_tprintf(TEXT("Parent Process - Created 2 childs!\n"));
	_tprintf(TEXT("\n"));

	for (int i = 1; i < 16; i++)
	{
		TextColor(16 - i, 0);
		printf("(%d) ", i);
		TextColor(i, 0);
		_tprintf(TEXT("- I'm Parent\n"));

		if (i == 7)
		{
			TerminateProcess(pInfo1.hProcess, NULL);
			CloseHandle(pInfo1.hProcess);
			TextColor(4, 0);
			_tprintf(TEXT("First object has been Destroyed!\n"));
		}

		if (i == 11)
		{
			TextColor(7, 0);
			TerminateJobObject(JobObject, NULL);
			CloseHandle(pInfo2.hProcess);
			_tprintf(TEXT("Second object has been Destroyed!\n"));
		}

		float Delay = 1000*((float)rand() / RAND_MAX + 1);
		Sleep(Delay);
	}

	TextColor(9, 0);
	CloseHandle(JobObject);
	_tprintf(TEXT("\nPress ESC to EXIT"));

	while (true)
	{
		if (GetAsyncKeyState(27))
			break;
	}
    return 0;
}

