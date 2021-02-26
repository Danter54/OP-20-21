#include "Header.h"
int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	int num, count = 0;

	library book[N];

	for (;;) {
		cout << "Меню:\n";
		cout << "1 -> Ввод с экрана;\n";
		cout << "2 -> Ввод случайным образом;\n";
		cout << "3 -> Сортировка;\n";
		cout << "4 -> Вывод библиотеки;\n";
		cout << "0 -> Выход из программы;\n";

		cout << "Введите значение: ";
		cin >> num;
		switch (num)
		{
		case (1): count=Input(book); break;
		case (2): count=Rand_input(book); break;
		case (3): Sort(book,count); break;
		case (4): Output(book,count); break;
		case (0): return 0;
		default:cout<<"Вы ввели неверное значение!!!";
		}
	}
	return 0;
}