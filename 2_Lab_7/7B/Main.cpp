#include <iostream>
#include "Functions.h"

int main(int argc, char* argv[]) {
	system("chcp 1251");

	int size = 0;
	printf("¬ведите размер массива: ");
	scanf_s("%d", &size);

	int* array1 = new int[size];

	Init_arr(array1, size);
	printf("Array 1: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(array1 + i));
	}
	printf("\n");
	Write_in_file(array1, size);
	delete[] array1;
	int *array2 = new int[size];

	Write_array_from_file(array2,size);

	printf("Array 2: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(array2 + i));
	}
	int sum = 0;
	sum = Sum_div2(array2, size);
	printf("\n");
	printf("Sum of div 2: %d", sum);

	delete[] array2;

	return 0;
}