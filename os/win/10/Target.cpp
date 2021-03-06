#include "stdafx.h"
#include "Graphics.cpp"
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 1024
TCHAR szName[] = TEXT("SharedMem");
TCHAR vaName[] = TEXT("VMAlloc");
LPCWSTR Semaphore = (LPCWSTR)"Semaphore";

int _tmain()
{
	HANDLE hMapFile;
	LPCTSTR pBuf, NewMem;

	HANDLE hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, 0, Semaphore);

	TextColor(9, 0);
	_tprintf(TEXT("Target App \n"));

	if (hSemaphore != NULL)
	{
		TextColor(2, 0);
		_tprintf(TEXT("Semaphore successfully opened\n"));
	}
	else
	{
		TextColor(2, 0);
		_tprintf(TEXT("Error: (%d)\n", GetLastError()));
		_getch();
		return 1;
	}

	hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,   
		FALSE,                 
		szName);  


	if (hMapFile != NULL)
	{
		TextColor(4, 0);
		_tprintf(TEXT("Mapping file successfuly open! \n"));
		TextColor(6, 0);
		_tprintf(TEXT("Handle Value: "));
		TextColor(5, 0);
		_tprintf(TEXT("(%d)\n"), hMapFile);
	}

	else
	{
		TextColor(4, 0);
		_tprintf(TEXT("Mapping file wasn't open! \n"));
		GetLastError();
		TextColor(5, 0);
		_tprintf(TEXT("Error: (%d)", GetLastError()));
		_getch();
		return 1;
	}

	pBuf = (LPTSTR)MapViewOfFile(hMapFile, 
		FILE_MAP_ALL_ACCESS,  
		0,
		0,
		BUF_SIZE);

	if (pBuf != NULL)
	{
		TextColor(6, 0);
		_tprintf(TEXT("View of file successfuly mapped! \n"));
	}
	else
	{
		TextColor(6, 0);
		_tprintf(TEXT("View of file wasn't mapped! \n"));
		GetLastError();
		TextColor(7, 0);
		_tprintf(TEXT("Error: (%d)", GetLastError()));
		CloseHandle(hMapFile);
		_getch();
		return 1;
	}

	TextColor(10, 0);
	_tprintf(TEXT("Messages from Shared Mem will be printed in MBoxes!"));
	MessageBox(NULL, pBuf, TEXT("Process2 - First String"), MB_OK);

	WaitForSingleObject(hSemaphore, INFINITE);

	MessageBox(NULL, pBuf, TEXT("Process2 - MapView"), MB_OK);

	TextColor(12, 0);
	_tprintf(TEXT("Press ESC to unmap File and close the app"));

	while (true)
	{
		if (GetAsyncKeyState(27))
		{
			UnmapViewOfFile(pBuf);
			CloseHandle(hMapFile);
			CloseHandle(hSemaphore);
			break;
		}
	}


    return 0;
}

