#include "Functions.h"

using namespace std;
void add_book(int *counter) {
	FILE* libr_f = NULL;
	int count = 0;
	Library book;

	libr_f = fopen("Library.txt", "w");
	if (libr_f==NULL) {
		printf("�� ������� ������� ����");
	}
	*counter = 0;
	printf("������� �� ������ �������� ����: ");
	scanf_s("%d", &count);
	while (true) {
		if (count <= 0) {
			cout << "������� ��������� �����!!!\n";
			cout << "����� �����: ";
			scanf_s("%d", &count);

		}
		else {
			for (int i = 0; i < count; i++) {
				cout << "������� ������, ��������, ���, � ������ " << i+1 << " �����: ";
				cin >> book.surname >> book.title >> book.year >> book.group;
				fprintf_s(libr_f, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
			}
			break;
		}
	};
	*counter += count;
	fclose(libr_f);
}

void rand_add_book(int* counter) {
	srand(time(NULL));


	char author [10][10]  { "������","�������","���",
							"�������","�����","������",
							"�������","�������","������","������" };

	char name [10][10] { "�����","�������","���������",
						"��������","�������","������",
						"�����","�������","�����","��������" };

	char group [3] = { '�','�','�' };
	
	FILE* libr_f = NULL;
	int count = 0;
	*counter = 0;
	Library book;

	libr_f = fopen("Library.txt", "w");
	if (libr_f == NULL) {
		printf("�� ������� ������� ����");
	}

	printf("������� �� ������ �������� ����: ");
	scanf_s("%d", &count);

	while (true) {
		if (count <= 0) {
			cout << "������� ��������� �����!!!\n";
			cout << "����� �����: ";
			scanf_s("%d", &count);
		}
		else {
			*counter = count;
			cout << "��������� ����������...\n";

			for (int i = 0; i < count; i++ ) {
				int x = rand() % 10;
				for (int j = 0; j < 10; j++) {
					book.surname[j] = author[x][j];
					book.title[j] = name[x][j];
				}
					book.year = 1000 + rand() % 1000 + 20;
					book.group = group[rand() % 3];

					fprintf_s(libr_f, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
			}
			break;
		}
	};
	fclose(libr_f);
}

void beg_add(int* counter) {

	FILE* libr_f = NULL, *tmp = NULL;
	Library book;
	libr_f = fopen("Library.txt", "r");
	if (libr_f == NULL) {
		printf("�� ������� ������� ����");
		tmp = fopen("Library.txt", "w");
	}

	tmp = fopen("temp.txt", "w");


	cout << "������� ������, ��������, ���, � ������ �����: ";
	cin >> book.surname >> book.title >> book.year >> book.group;
	fprintf_s(tmp, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);

	if (*counter>0) {
		for (int i = 0; i < *counter; i++) {
			fscanf(libr_f, "%s %s %d %c\n", book.surname, book.title, &book.year, &book.group);
			fprintf_s(tmp, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
		}
	}


	fclose(libr_f);
	fclose(tmp);

	if (*counter != 0) {
		remove("Library.txt");
	}

	rename("temp.txt","Library.txt");

	

	


	(*counter)++;
	
}

void end_add(int* counter) {
	*counter = *counter + 1;

	FILE* libr_f = NULL;
	Library book;

	libr_f = fopen("Library.txt", "at");
	if (libr_f == NULL) {
		printf("�� ������� ������� ����");
	}

	cout << "������� ������, ��������, ���, � ������ �����: ";
	cin >> book.surname >> book.title >> book.year >> book.group;
	fprintf_s(libr_f, "%s %s %d %c\n", book.surname, book.title, book.year, book.group);
	fclose(libr_f);
}

int print_one(int* counter) {
	FILE* libr_f = NULL;
	Library book;
	libr_f = fopen("Library.txt", "r");
	int count = 0;

	if (libr_f == NULL) {
		printf("�� ������� ������� ����");
		return 1;
	}

	if (*counter == 0) {
		printf("��� ������� � ����������!!!\n");
		return 0;
	}

	while (true) {
		cout << "������� ����� �����: ";
		cin >> count;
		if (count > 0 && count <= (*counter)) {
			break;
		}
		else cout << "������� ������� �����!!!\n";
	}

	

	cout << "---------------------------------------------------" << endl;
	cout << "|                 ������� ����������              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	for (int i = 0; i < *counter; i++) {
		fscanf(libr_f, "%s %s %d %c\n", book.surname, book.title, &book.year, &book.group);
		if (count==i+1) {


			printf("|  %9s  | %10s |    %5d    |    %c   |\n",
				book.surname, book.title, book.year, book.group);
		}
	}
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����������: � - �������������� ����������;      |" << endl;
	cout << "| � - ������� ����������; � - ���������� ������ - |" << endl;
	cout << "| ����                                            |" << endl;
	cout << "---------------------------------------------------" << endl;
	fclose(libr_f);

}

int printf_all(int* counter) {

	FILE* libr_f=NULL;
	Library book;
	libr_f = fopen("Library.txt", "r");
	if (libr_f == NULL) {
		printf("�� ������� ������� ����");
		return 1;
	}

	if (*counter==0) {
		printf("��� ������� � ����������!!!\n");
		return 0;
	}

	cout << "---------------------------------------------------" << endl;
	cout << "|                 ������� ����������              |" << endl;
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����� ����� |  ��������  | ��� ������� | ������ |" << endl;
	cout << "|-------------------------------------------------|" << endl;

	for (int i = 0; i < *counter; i++) {
		fscanf(libr_f, "%s %s %d %c\n", book.surname, book.title, &book.year, &book.group);
		printf("|  %9s  | %10s |    %5d    |    %c   |\n",
			book.surname, book.title, book.year, book.group);
	}
	cout << "|-------------------------------------------------|" << endl;
	cout << "| ����������: � - �������������� ����������;      |" << endl;
	cout << "| � - ������� ����������; � - ���������� ������ - |" << endl;
	cout << "| ����                                            |" << endl;
	cout << "---------------------------------------------------" << endl;
	fclose(libr_f);
}