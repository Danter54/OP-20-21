#include"Function.h"


int main()
{
	setlocale(LC_ALL, "RU");

	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;

	int* arr = new int[size];

	Filling_array(arr, size);

	std::cout << "Наш массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << *(arr + i) << ' ';
	}
	std::cout << std::endl;
	int size_arr2=0;
	int* arr2 = Main_function(arr, size, &size_arr2);
	std::cout << "\nНаш новый массив: ";
	for (int i = 0; i < size_arr2; i++) {
		std::cout << *(arr2+i)<<' ';
	}

	std::cout << std::endl;
	delete[] arr, arr2;
	
	return 0;
}