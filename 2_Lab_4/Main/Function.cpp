#include "Function.h"

void array_filling(int* arr, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 10 - 5;
	}
}

void average_func(int* arr, int* newarr, int size, double *average, int* new_size) {

	int count = 0;

	for (int i = 0; i < size; i++) {
		*average += *(arr + i);
	}

	*average /= size;

	for (int i = 0; i < size; i++) {
		if ( *(arr+i) < (*average) ) {
			*(newarr + *new_size) = *(arr+i);
			(*new_size)++;
		}
	}

}





