#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

/*			������������ 14
			��������� 14_2
����������� ������ � �������������� ������ ������������ �����-
���� ��� ��������� ���� ������, �������� � �������� ��� ��� ���������.
*/




struct Node                             //���������, ���������� ������ ������
{
	int x;                             //�������� x ����� ������������ � ������
	Node *Next, *Prev;                 //��������� �� ������ ���������� � ����������� ��������� ������
};

class List                              //������� ��� ������ ������
{
	Node *Head, *Tail;                 //��������� �� ������ ������ ������ � ��� �����
public:
	List() :Head(NULL), Tail(NULL) {};    //�������������� ������ ��� ������
	~List();                           //�������� �����������
	void Show();                       //�������� ������� ����������� ������ �� ������
	void Add(int x);                   //�������� ������� ���������� ��������� � ������
};

List::~List()                           //����������
{
	while (Head)                       //���� �� ������ �� ������ ������ ���-�� ����
	{
		Tail = Head->Next;             //��������� ����� ������ ���������� ����� ������
		delete Head;                   //������� ������ �� ������� �����
		Head = Tail;                   //����� ������ ������ �� ����� ���������� ��������
	}
}

void List::Add(int x)
{
	Node *temp = new Node;               //��������� ������ ��� ����� ������� ���������
	temp->Next = NULL;                   //���������, ��� ���������� �� ���������� ������ �����
	temp->x = x;                         //���������� �������� � ���������

	if (Head != NULL)                    //���� ������ �� ����
	{
		temp->Prev = Tail;               //��������� ����� �� ���������� ������� � �����. ����
		Tail->Next = temp;               //��������� ����� ���������� �� ������� ��������
		Tail = temp;                     //������ ����� ������
	}
	else //���� ������ ������
	{
		temp->Prev = NULL;               //���������� ������� ��������� � �������
		Head = Tail = temp;              //������=�����=��� �������, ��� ������ ��������
	}
}

void List::Show()
{
	//������� ������ � �����
	Node *temp = Tail;                   //��������� ��������� �� ����� ���������� ��������

	while (temp != NULL)               //���� �� ���������� ������ ��������
	{
		printf("%d ", temp->x);        //�������� �������� �� �����
		temp = temp->Prev;             //���������, ��� ����� ����� ����������� ��������
	}
	printf("\n");

	//������� ������ � ������
	temp = Head;                       //�������� ��������� �� ����� ������� ��������
	while (temp != NULL)              //���� �� �������� ������ ��������
	{
		printf("%d ",temp->x);        //������� ������ ��������� �������� �� �����
		temp = temp->Next;             //����� ������ �� ����� ���������� ��������
	}
	printf("\n");
}

int main()
{
	system("CLS");
	List lst; //��������� ����������, ��� ������� ���� ������
	lst.Add(999); //��������� � ������ ��������
	lst.Add(666);
	lst.Add(6969);
	lst.Add(9696);

	lst.Show(); //���������� ������ �� ������
	system("PAUSE");
	return 0;
}