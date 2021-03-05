#include "Functions.h"

int main()
	{
	setlocale(LC_ALL,"ru");

	int mas[N],mas2[N], count;
	std::cout << "Введите количество элементов в массиве (не больше 100): ";
	std::cin >> count;

	if (count>100 || count<0) {
		std::cout << "Вы ввели неверное значение!!!";
		return 0;
	}
	else if (count == 0) {
		std::cout << "Вы не хотите заполнять массив!";
		return 0;
	}

	Rand_Num_Gen(mas,count);
	Main_Function(mas, mas2, count);

	return 0;
}