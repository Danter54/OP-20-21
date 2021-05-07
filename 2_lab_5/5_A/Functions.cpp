#include "Functions.h"

void random_add(int** matrix, int *N, int *M) {
	srand(time(NULL));

	for (int i = 0; i < *N; i++) {
		for (int j = 0; j < *M; j++) {
			*(*(matrix + i) + j) = rand()%200-100;
		}
	}
}

void print(int** matrix, int* N, int* M) {
	for (int i = 0; i < *N; i++) {
		for (int j = 0; j < *M; j++) {
			std::cout<<std::setw(4) << *(*(matrix + i) + j)<<' ';
		}
		std::cout << std::endl;
	}
}

void task(int **matrix, int N, int M, int* min, int * max, int*sum, int *mult) {

	for (int i = 0; i < N; i++ ) {
		*(max+i) = *(*(matrix + i) + 1);
		for (int j = 0; j < M; j++) {
			if (*(max + i)< *(*(matrix + i) + j)) {
				*(max + i) = *(*(matrix + i) + j);
			 }
		}
	}

	std::cout << "MAX: ";
	for (int i = 0; i < N; i++) {
		std::cout << *(max + i) << ' ';
	}

}