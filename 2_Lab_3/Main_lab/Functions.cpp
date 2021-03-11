#include "Functions.h"

void Rand_Num_Gen(int *a, int count) {

	srand(time(NULL));

	for (int i = 0; i < count; i++) {
		*(a+i) = rand()%2-2;
	}
}


int *Main_Function(int *a, int* b, int count, double* average, int*size_b) {

	for (int i = 0; i < count; i++) {
		*average += *(a + i);
	}
	*average /= count;

	for (int i = 0,j=0; i < count; i++) {
		if (*(a+i)<*average) {
			*(b + j) = *(a + i);
			(*size_b)++;
			j++;
		}
	}
	return 0;
}