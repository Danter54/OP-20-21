#include "Header.h"
int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	int num, count = 0;

	library book[N];

	for (;;) {
		cout << "����:\n";
		cout << "1 -> ���� � ������;\n";
		cout << "2 -> ���� ��������� �������;\n";
		cout << "3 -> ����������;\n";
		cout << "4 -> ����� ����������;\n";
		cout << "0 -> ����� �� ���������;\n";

		cout << "������� ��������: ";
		cin >> num;
		switch (num)
		{
		case (1): count=Input(book); break;
		case (2): count=Rand_input(book); break;
		case (3): Sort(book,count); break;
		case (4): Output(book,count); break;
		case (0): return 0;
		default:cout<<"�� ����� �������� ��������!!!";
		}
	}
	return 0;
}