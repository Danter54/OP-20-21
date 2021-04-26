#include <iostream>
#include "Functions.h"

using namespace std;
int main() {

	system("chcp 1251");
	
	int choice, count = 0;
	while (true) {

		
		std::cout << "\nЧто вы хотите сделать?\n";
		std::cout << "1. Ввод с экрана и запись в файл\n"
			<< "2. Ввод случайным образом и запись в файл\n"
			<< "3. Добавить запись в начало файла\n"
			<< "4. Добавить запись в конец файла\n"
			<< "5. Печать одной записи из файла по номеру\n"
			<< "6. Печать всех записей из файла\n"
			<< "7. Выход из программы\n";
		std::cout << "\nВаш выбор: ";
		cin >> choice;
		if (choice==1) {
			add_book(&count);
		}
		else if (choice == 2) {
			rand_add_book(&count);
		}
		else if (choice == 3) {
			beg_add(&count);
		}
		else if (choice == 4) {
			end_add(&count);
		}
		else if (choice == 5) {
			print_one(&count);
		}
		else if (choice == 6) {
			printf_all(&count);
		}
		else if (choice == 7) {
			cout << "\nВыход из программы!!!";
			break;
		}

	}
	return 0;
}