#include <iostream>
#include "Library.h"
#include"Functions.h"

using namespace std;

int main() {

	system("chcp 1251");
	int count = 0;

	printf("������� ���� �� ������ ������: ");
	scanf_s("%d",&count);

	Library* books = new Library[count];

	printf("������ ������ Set:\n");
	Write(books,count);

	printf("������ ������ Show:\n");
	cout << "---------------------------------------------------" << endl;
	cout << "|                 ������� ����������              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	Print(books, count);
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����������: � - �������������� ����������;      |" << endl;
	cout << "| � - ������� ����������; � - ���������� ������ - |" << endl;
	cout << "| ����                                            |" << endl;
	cout << "---------------------------------------------------" << endl;

	printf("������ ������ Get and Show:\n");
	cout << "---------------------------------------------------" << endl;
	cout << "|                 ������� ����������              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	Print_and_Get(books,count);
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����������: � - �������������� ����������;      |" << endl;
	cout << "| � - ������� ����������; � - ���������� ������ - |" << endl;
	cout << "| ����                                            |" << endl;
	cout << "---------------------------------------------------" << endl;


	return 0;
}