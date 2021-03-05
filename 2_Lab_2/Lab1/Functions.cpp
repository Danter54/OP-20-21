#include "Functions.h"

int Input(library book[N]) {
	DEBUG
		int count;
	cout << "������� ���� �� ������ ������: ";
	cin >> count;
		for (int i = 0; i < count;i++) {
			if (count > 10 || count < 0) break;
			cout << "������� �������, ��������, ���, ������ "<<i+1<<" �����: ";
			cin >> book[i].athr >> book[i].name >> book[i].year >> book[i].group;
		}

	DEBUG
		return count;

}


int Rand_input (library book[N]) {
	DEBUG
		char surname[10][10] = { "������","�������","���",
								"�������","�����","������",
								"�������","�������","������","������" };

		char name[10][10] = { "�����","�������","���������",
						"��������","�������","������",
						"�����","�������","�����","��������" };
	
		char group[3] = { '�','�','�' };

		int count;

	cout << "������� ���� �� ������ ������: ";
	cin >> count;

	cout << "���������� ��������� ��������� ����������...\n";

	for (int i = 0; i < count; i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10; j++) {
			book[i].athr[j] = surname[x][j];
		}
	}

	for (int i = 0; i < count; i++) {
		int x = rand() % 10;
		for (int j = 0; j < 10; j++) {
			book[i].name[j] = name[x][j];
		}
	}

	for (int i = 0; i < count; i++) {
		book[i].year = 1000 + rand() % 1000 + 20;
	}

	for (int i = 0; i < count; i++) {
		book[i].group = group[rand() % 3];
	}
	DEBUG
		return count;

}

void Output(library book[N], int count) {
	DEBUG
		cout << "---------------------------------------------------" << endl;
	cout << "|                 ������� ����������              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	for (int i = 0; i < count; i++)
		printf("|  %9s  | %10s |    %5d    |    %c   |\n",
			book[i].athr, book[i].name, book[i].year, book[i].group);
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����������: � - �������������� ����������;      |" << endl;
	cout << "| � - ������� ����������; � - ���������� ������ - |" << endl;
	cout << "| ����                                            |" << endl;
	cout << "---------------------------------------------------" << endl;
	DEBUG
}

void Sort(library book[N], int count) {
	DEBUG
		struct library x;
	int m;
	cout << "����������...\n";
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (strcmp(book[i].athr, book[j].athr) < 0) {
				x = book[i];
				book[i] = book[j];
				book[j] = x;
			}
		}
	}
	DEBUG
}