#include "Function.h"

void Filling_array (int *arr, int size) {

	srand(time(NULL));

	for (size_t i = 0; i < size; i++)
	{
		*(arr+i) = rand() % 2 - 2;
	}
}

void Main_function(int* arr, int size) {

	double average = 0;
	std::cout << "Ваш массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << *(arr+i)<<' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < size; i++) {
		average += *(arr+i);
	}
	average /= size;

	std::cout << "Среднее значение: " << average << std::endl;

	int size_b = 0;

	for (int i = 0; i < size;i++) {
		if (*(arr+i)<average) {
			size_b++;
		}
	}

	int* b = new int[size_b];

	for (int i = 0,j=0; i < size; i++) {
		if (*(arr + i) < average) {
			*(b+j) = *(arr+i);
			j++;
		}
	}

	std::cout << "Новый массив(елементы которого меньше среднего): ";
	for (int i = 0; i < size_b;i++) {
		std::cout << *(b+i)<<' ';
	}

	delete[] b;
}