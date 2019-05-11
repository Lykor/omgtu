#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#include <locale.h>
#include <conio.h>

HANDLE Console;
HANDLE Semaphore;

COORD posx;

CRITICAL_SECTION CriticalSection;

WORD Yellow = FOREGROUND_RED | FOREGROUND_GREEN;
WORD Purple = FOREGROUND_BLUE | FOREGROUND_RED;
WORD Green = FOREGROUND_GREEN;
WORD Blue = FOREGROUND_BLUE;
WORD Red = FOREGROUND_RED;

int Delay1, Delay2;

char LBuffer[12];
char UBuffer[12];
char CBuffer[12];
char Buffer[12];

char LowerCase[] = "qwertyuiopa";
char UpperCase[] = "QWERTYUIOPA";
char Characters[] = "~!@#$%^&*_+";

bool isSix = false;
int n=0;

unsigned __stdcall WriteThread1(void *arg) {

  while (true) {

    WaitForSingleObject(Semaphore, 1);

    if (isSix == false) {
      for (n = 0; n < 6; n++) {
        Buffer[n] = LowerCase[n];
        }
      isSix = true;
    }
    else {
      for (n = 6; n < 12; n++) {
        Buffer[n] = LowerCase[n];
      }
      isSix = false;
    }
    
    ReleaseSemaphore(Semaphore, 1, NULL);
    WaitForSingleObject(Semaphore, 50);
    Sleep(300 * (int)Delay1);
    }
}
  

unsigned __stdcall WriteThread2(void *arg) {

  while (true) {
    WaitForSingleObject(Semaphore, 1);

    if (isSix == false) {
      for (n = 0; n < 6; n++) {
        Buffer[n] = UpperCase[n];
      }
      isSix = true;
    }
    else {
      for (n = 6; n < 12; n++) {
        Buffer[n] = UpperCase[n];
      }
      isSix = false;
    }

    ReleaseSemaphore(Semaphore, 1, NULL);
    WaitForSingleObject(Semaphore, 50);
    Sleep(300 * (int)Delay2);
   }    
}

unsigned __stdcall WriteThread3(void *arg) {

  while (true) {

    WaitForSingleObject(Semaphore, 1);

    if (isSix == false) {
      for (n = 0; n < 6; n++) {
        Buffer[n] = Characters[n];
      }
      isSix = true;
    }
    else {
      for (n = 6; n < 12; n++) {
        Buffer[n] = Characters[n];
      }
      isSix = false;
    }

    ReleaseSemaphore(Semaphore, 1, NULL);
    WaitForSingleObject(Semaphore, 50);
    Sleep(300 * (int)Delay2);
    }  
  }



unsigned __stdcall ReadThread(void *arg) {

  COORD pos;

  for (int i = 0; i < 23; i++) {
    WaitForSingleObject(Semaphore, INFINITE);
   
    posx.X = 20*(int)arg;
    posx.Y = i + 1;

    EnterCriticalSection(&CriticalSection);
    SetConsoleCursorPosition(Console, posx);
    
    if ((int)arg == 1)SetConsoleTextAttribute(Console, Red);
    if((int)arg==2)SetConsoleTextAttribute(Console, Purple);
    if((int)arg==3)SetConsoleTextAttribute(Console, Blue);
   
    printf(Buffer);
    printf("\n");
          
    LeaveCriticalSection(&CriticalSection);
    ReleaseSemaphore(Semaphore,1,NULL);
    
    Sleep(350 * (int)Delay2);
  }
  return 0;
}

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

  HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      
  SetConsoleScreenBufferSize(Handle, coord);            
  SetConsoleWindowInfo(Handle, TRUE, &Rect);           
}


void main(int args, char *argv[]) {

  system("cls");
  SetWindow(120, 30);
  LPCWSTR SemaphoreText = TEXT("Semaphore Created");
 
  HANDLE writeThread1, writeThread2, writeThread3;
  HANDLE readThread;
 
  unsigned int readThreadID1, readThreadID2, readThreadID3;
  unsigned int writeThreadID1, writeThreadID2, writeThreadID3;
  
  Console = GetStdHandle(STD_OUTPUT_HANDLE);
  Delay1 = 20;
  Delay2 = 3;

  InitializeCriticalSection(&CriticalSection);

  if (args >= 3) {
    sscanf_s(argv[1], "%d", &Delay1);
    sscanf_s(argv[2], "%d", &Delay2);
  }

  Semaphore = CreateSemaphore(NULL, 1, 1, SemaphoreText);
   
  writeThread1 = (HANDLE)_beginthreadex(NULL, 4096, WriteThread1, NULL, 0, &writeThreadID1);
  writeThread2 = (HANDLE)_beginthreadex(NULL, 4096, WriteThread2, NULL, 0, &writeThreadID2);
  writeThread3 = (HANDLE)_beginthreadex(NULL, 4096, WriteThread3, NULL, 0, &writeThreadID3);
  
  readThread = (HANDLE)_beginthreadex(NULL, 4096, ReadThread, (void *)1, 0, &readThreadID1);
  readThread = (HANDLE)_beginthreadex(NULL, 4096, ReadThread, (void *)2, 0, &readThreadID2);
  readThread = (HANDLE)_beginthreadex(NULL, 4096, ReadThread, (void *)3, 0, &readThreadID3);
  
  _getch();

  DeleteCriticalSection(&CriticalSection);
  CloseHandle(writeThread1);
  CloseHandle(writeThread2);
  CloseHandle(writeThread3);
  CloseHandle(readThread);
}
