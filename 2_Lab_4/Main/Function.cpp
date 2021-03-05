#include "Function.h"

void Filling_array (int *arr, int size) {

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		*(arr+i) = rand() % 2 - 2;
	}
}

int *Main_function(int *arr, int size, int *size2) {

	double average = 0;
	int count = 0;
	
	

	for (int i = 0; i < size; i++) {
		average += *(arr+i);
	}

	average = average / size;

	std::cout << "Среднее значение: " << average;

	for (int i = 0; i < size; i++) {
		if (*(arr+i)<average) {
			count++;
		}
	}

	int *array = new int[count];
	*size2 = count;

	for (int i = 0, j=0; i < size; i++) {
		if (*(arr+i)<average) {
			*(array + j) = *(arr+i);
			j++;
		}
	}

	return array;
}