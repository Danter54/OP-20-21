#include "Function.h"

int* One_as_two(int *array) {

	int count = 1;

	for (int i = 0; i < N;i++) {
		for (int j = 0; j <=i; j++) {
			*(array + (i - j) * N + j) = count++;
		}
	}

	for (int j = 1; j < N; j++) {
		for (int i = 0; i <= N - 1-j;i++) {
			*(array+ ((N - 1) - i) * N + (j + i) ) = count++;
		}
	}
	return array;
}

int** Two_as_two(int** array) {
	int count = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			*(*(array+(i-j))+j) = count++;
		}
	}

	for (int j = 1; j < N; j++) {
		for (int i = 0; i <= N - 1 - j; i++) {
			*(*(array+((N-1)-i))+(j+i))= count++;
		}
	}


	return array;
}