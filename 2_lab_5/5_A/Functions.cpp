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

int *task(int **matrix, int N, int M, int* min, int * max, int*sum, int *mult) {

	int* pointer = new int[2];


	for (int i = 0; i < N; i++ ) {
		*(max+i) = *(*(matrix + i) + 1);
		for (int j = 0; j < M; j++) {
			if (*(max + i)< *(*(matrix + i) + j)) {	//MAX
				*(max + i) = *(*(matrix + i) + j);
			 }
		}
	}

	for (int j = 0; j < M; j++) {
		*(min + j) = *(*(matrix + 1) + j);
		for (int i = 0; i < N; i++) {
			if ( *(min+j) > *(*(matrix+i)+j) ) {
				*(min+j)= *(*(matrix + i) + j);		//MIN
			}
		}
	}

	if (N == M) {
		for (int i = 0; i < N; i++) {
			*sum += *(*(matrix + i) + i);
		}
		printf("Sum %d\n", *sum);
		pointer[0] = *sum;

	}
	else printf("Не возможно посчитать сумму!!!\n");
	
	if (N == M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i+j==N-1) {
					*mult =(*mult) * (*(*(matrix + i) + j));
				}
			}
		}
		printf("Mult %d\n", *mult);
		pointer[1] = *sum;


	}
	else printf("Не возможно посчитать произведение!!!\n");

	return pointer;
}