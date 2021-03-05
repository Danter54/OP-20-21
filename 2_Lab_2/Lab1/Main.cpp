#include "Functions.h"
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
		case (1): count= PRINT_TYPE1; break;
		case (2): count= PRINT_TYPE2; break;
		case (3): Sort(book,count); break;
		case (4): Output(book,count); break;
		case (0): return 0;
		default:cout<<"Вы ввели неверное значение!!!\n";
		}
	}
	return 0;
}