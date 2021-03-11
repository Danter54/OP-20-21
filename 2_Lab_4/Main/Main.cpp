#include "Function.h"



void main() {
	setlocale(LC_ALL,"RU");

	int size = 0;
	double average = 0;
	int size_of_new_array = 0;

	printf("Введите размер массива: ");
	scanf_s("%d", &size);

	int* array = new int[size];
	int* new_array = new int[size];

	array_filling(array,size);

	printf("Наш массив: ");

	for (int i = 0; i < size; i++) {
		printf("%d ",*(array+i));
	}
	printf("\n");
	average_func(array, new_array, size, &average, &size_of_new_array);

	printf("Average: %1.2lf\n",average);

	printf("Новый массив: ");

	for (int i = 0; i < size_of_new_array; i++) {
		printf("%d ",*(new_array+i));
	}


	delete [] array;
	delete [] new_array;
}