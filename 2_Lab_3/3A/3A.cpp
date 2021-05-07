#include "Functions.h"

int main()
{
	system("chcp 1251");
	int array[SIZE];
	int choice, count = 0, sum = 0;

	fill_array(array);

	std::cout << "Ваш массив: ";
	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Выберите метод адресации: \n";
	std::cout << "0-выход из программы;\n";

	std::cout << "1-относительный адрес;\n";
	std::cout << "2-через абсолютный адрес;\n";
	std::cout << "3-не использовать индексацию;\n";
	std::cout << "4-через массив указателей;\n";
	std::cout << "5-через указатель на указатель;\n";
	std::cout << "6-через параметр указатели функции;\n";

	std::cout << "Ваш выбор: ";
	std::cin >> choice;

		switch (choice) {

			case 0: { std::cout << "Выход из программы!!!";
			return 0;
			}

			case 1: { relative_address(array, &count, &sum);
				printf("Количество: %d\n", count);
				std::cout << "Сумма:" << sum;
				return 0;};

			case 2: { absolute_address(array, &count, &sum);
			printf("Количество: %d\n", count);
			std::cout << "Сумма:" << sum;
			return 0;};

			case 3: {without_index(array, &count, &sum);
			printf("Количество: %d\n", count);
			std::cout << "Сумма:" << sum;
			return 0;};

			case 4: {array_of_pointer(array, &count, &sum);
			printf("Количество: %d\n", count);
			std::cout << "Сумма:" << sum;
			return 0;};

			case 5: {pointer_to_pointer(array, & count, & sum);
				printf("Количество: %d\n", count);
				std::cout << "Сумма:" << sum;
				return 0; };

			case 6:f_par(array,&count, &sum);
				printf("Количество: %d\n", count);
				std::cout << "Сумма:" << sum;
				break;
			default: {
				printf("Неверно введёное значение!!!");
				return 1; }
		}

}
