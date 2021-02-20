#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#define N (10)
using namespace std;

struct libr {
	char athr[10];
	char nm[10];
	int yr;
	char gr;
}book[N];

int input(int count) {
	cout << "������� ���������� ���� ������� �� ������ ��������:";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << "������� ������� ������, �������� �����, � ��� � ������: ";
		cin >> book[i].athr>>book[i].nm>>book[i].yr>>book[i].gr;
	}
	return count;
}

int r_input(int count) {
	char surname[10][10] = {"������","�������","���","�������","�����","������","�������","�������","������","������"};
	char name[10][10] = {"�����","�������","���������","��������","�������","������","�����","�������","�����","��������"};
	char group[3] = {'�','�','�'};
	cout << "������� ���� �� ������ ��������? (�� ������ 10): ";
	cin >> count;

	for (int i = 0; i < count;i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10;j++) {
			book[i].athr[j] = surname[x][j];
		}
	}

	for (int i = 0; i < count; i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10; j++) {
			book[i].nm[j] = name[x][j];
		}
	}

	for (int i = 0; i < count;i++) {
		book[i].yr =1000+ rand()%1000+20;
	}

	for (int i = 0; i < count;i++) {
		book[i].gr = group[rand()%3];
	}

	return count;
}

void sort(int count) {
	struct libr x;
	int m;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count; j++) {
			if (strcmp(book[i].athr,book[j].athr)<0) {
				x = book[i];
				book[i] = book[j];
				book[j] = x;
			}
		}
	}
}

void output(int count) {
	cout << "---------------------------------------------------"<<endl;
	cout << "|                 ������� ����������              |"<<endl;
	cout << "|-------------------------------------------------|"<<endl;
	cout << "| ����� ����� |  ��������  | ��� ������� | ������ |"<<endl;
	cout << "|-------------------------------------------------|"<<endl;
	for (int i = 0; i < count; i++)
		printf("|  %9s  | %10s |    %5d    |    %c   |\n",
			book[i].athr, book[i].nm, book[i].yr, book[i].gr);
	cout << "|-------------------------------------------------|"<<endl;
	cout << "| ����������: � - �������������� ����������;      |"<<endl;
	cout << "| � - ������� ����������; � - ���������� ������ - |"<<endl;
	cout << "| ����                                            |"<<endl;
	cout << "---------------------------------------------------" << endl;
}


int switcher(int num,int count) {

	switch (num) {
	case 1: count=input(count); break;
	case 2: count=r_input(count); break;
	case 3: cout<<"��� ���� ��� �����������!\n"; break;
	case 4:cout<<"��������� ��� �� ����������!\n"; break;
	case 0:; break;
	default: cout << "�������� �������� ��������!\n";
	}
	return count;
}

int switcher2(int num, int count) {
	switch (num) {
	case 3:sort(count); break;
	case 4:output(count); break;
	case 0:; break;
	default: cout << "�������� �������� ��������!\n";
	}
	return count;
}


int main() {
	srand(time(0));
	system("chcp 1251");
	int num,count=0;
	do {
		
		cout << "����:\n";
		cout << "���� � ���������� -> 1\n";
		cout << "���������� ���� -> 2\n";
		cout << "���������� ��������� -> 3\n";
		cout << "������ ��������� -> 4\n";
		cout << "����� �� ��������� -> 0\n";
		cout << "�������� ��������: ";
		cin >> num;
		count =switcher(num,count);
	} while (num!=0 && count==0);

	do {
		cout << "����:\n";
		cout << "���������� ��������� -> 3\n";
		cout << "������ ��������� -> 4\n";
		cout << "����� �� ��������� -> 0\n";
		cout << "�������� ��������: ";
		cin >> num;
		count = switcher2(num, count);
	} while (num != 0);

	cout << "����� �� ���������!!!\n";

	return 0;
}