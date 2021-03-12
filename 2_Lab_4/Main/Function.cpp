#include "Function.h"

void array_filling(int* arr, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 10 - 5;
	}
}

int *function(int *array_1, int size_1, int *size_2, double *average) {


	for (int i = 0; i < size_1; i++)
	{
		*average += *(array_1+i);
	}


	*average /= size_1;

	for (int i = 0; i < size_1; i++) {
		if (*(array_1+i)<(*average)) {
			(*size_2)++;
		}
	}

	int* array_2 = new int[*size_2];

	for (int i = 0, j=0; i < size_1; i++) {
		if (*(array_1+i)<(*average)) {
			*(array_2 + j) = *(array_1+i);
			j++;
		}
	}

	return array_2;
}




