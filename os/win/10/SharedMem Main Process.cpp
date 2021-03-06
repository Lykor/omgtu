#include "stdafx.h"
#include "Graphics.cpp"

#define _WIN32_WINNT 0x0500
#define BUF_SIZE 15000

TCHAR szName[] = TEXT("SharedMem");
TCHAR fMsg[] = TEXT("Hello from SharedMem");
TCHAR szMsg[] = TEXT("Message from first process.");
LPCWSTR Semaphore = (LPCWSTR)"Semaphore";

char AllocText[] = "abcdefghijklmno";

int _tmain()
{
	SetWindow(120, 30);
	TextColor(9, 0);
	_tprintf(TEXT(" Main Application\n"));

	HANDLE hSemaphore = CreateSemaphore(NULL, 0, 1, Semaphore);

	if (hSemaphore != NULL)
	{
		TextColor(2, 0);
		_tprintf(TEXT(" Semaphore successfully created\n"));
	}
	else
	{
		TextColor(2, 0);
		_tprintf(TEXT(" Semaphore wasn't created \n"));
		TextColor(3, 0);
		GetLastError();
		_tprintf(TEXT(" Error: (%d)", GetLastError()));
		_getch();
		return 1;
	}


	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,                    
		PAGE_READWRITE,          
		0,                       
		BUF_SIZE,               
		szName);         

	if (hMapFile != NULL)
	{
		TextColor(4, 0);
		_tprintf(TEXT(" Mapping file successfuly created \n"));
		TextColor(5, 0);
		_tprintf(TEXT(" Handle Value: "));
		TextColor(6, 0);
		_tprintf(TEXT("(%d)\n"), hMapFile);
	}

	else 
	{
		TextColor(7, 0);
		_tprintf(TEXT(" Mapping file wasn't created \n"));
		TextColor(8, 0);
		GetLastError();
		_tprintf(TEXT(" Error: (%d)", GetLastError()));
		_getch();
		return 1;
	}

	LPTSTR pBuf = (LPTSTR)MapViewOfFile(hMapFile,   
		FILE_MAP_ALL_ACCESS, 
		0,
		0,
		0);

	if (pBuf != NULL)
	{
		TextColor(10, 0);
		_tprintf(TEXT(" View of file successfuly mapped \n"));
		TextColor(14, 0);
		_tprintf(TEXT(" Address of Mapped File: "));
		_tprintf(TEXT("(0x%X)\n", +(PVOID)Addr));
	}
	else
	{
		TextColor(11, 0);
		_tprintf(TEXT(" View of file wasn't mapped \n"));
		TextColor(12, 0);
		GetLastError();
		_tprintf(TEXT(" Error: (%d)", GetLastError()));
		CloseHandle(hMapFile);
		_getch();
		return 1;
	}

	TextColor(12, 0);
	_tprintf(TEXT(" Writing 1st MSG to SharedMem\n"));
	CopyMemory((PVOID)pBuf, fMsg, (_tcslen(fMsg) * sizeof(TCHAR)));
	Sleep(2000);
	TextColor(6, 0);

	STARTUPINFO sInfo;
	PROCESS_INFORMATION pInfo;
	ZeroMemory(&sInfo, sizeof(STARTUPINFO));
	sInfo.cb = sizeof(sInfo);
	TCHAR path[MAX_PATH] = _T("Target.exe");
	if (CreateProcess(NULL, path, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sInfo, &pInfo) == 0)
	{
		_tprintf(TEXT("Error!!!"));
	}

	_tprintf(TEXT(" Wait 10 seconds\n"));
	Sleep(10000);
	TextColor(13, 0);
	_tprintf(TEXT(" Writing: "));
	TextColor(1, 0);
	_tprintf(TEXT("(Message from first process) "));
	TextColor(13, 0);
	_tprintf(TEXT("to SharedMem\n"));

	CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));


	ReleaseSemaphore(hSemaphore, 1, NULL);
	LPTSTR NewMem = (LPTSTR)VirtualAlloc(
		NULL,
		BUF_SIZE,
		MEM_COMMIT | MEM_RESERVE,
		PAGE_READWRITE
	);

	if (NewMem != NULL)
	{
		TextColor(12, 0);
		_tprintf(TEXT(" VirtualMemory Successfuly Allocated!\n"));
	}
	else
	{
		_tprintf(TEXT(" VirtualMemory wasn't Allocated! \n"));
		GetLastError();
		_tprintf(TEXT(" Error: (%d)", GetLastError()));
		_getch();
		return 1;
	}

	LPTSTR Address = NewMem;
	;
	_tprintf(TEXT("\n"));
	for (int i = 0; i < 15; i++)
	{
		CopyMemory((LPVOID)Address, (PVOID)AllocText, sizeof(char));
		TextColor(9, 0);
		_tprintf(TEXT(" Address: "));
		TextColor(15 - i, 0);
		_tprintf(TEXT("(0x%X) "), + Address);
		TextColor(10, 0);
		_tprintf(TEXT("Value: "));
		TextColor(i + 1, 0);
		_tprintf(TEXT("(%c)\n"), + AllocText[i]);
		Address += 400;
		Sleep(200);
	}

	TextColor(7, 0);
	_tprintf(TEXT("\n Press ESC to unmap File and close the app"));
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
