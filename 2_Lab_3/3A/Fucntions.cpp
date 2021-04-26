#include "Functions.h"
#include <ctime>


void fill_array(int array[]) {
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 20 - 10;
	}
}

void relative_address(int array[], int* count, int* sum) {
	int* p_array=array;
	for (int i = 0; i < SIZE; i++) {
		if (*(p_array+i)<0) {
			*sum += *(p_array + i);
			(*count)++;
		}
	}
}

void absolute_address(int array[], int* count, int* sum) {
	int* p_array = array;
	for (int i = 0; i < SIZE; i++,p_array++) {
		if (*p_array<0) {
			*sum += *p_array;
			(*count)++;
		}
	}
}

void without_index(int array[], int* count, int* sum) {
	for (int* p_array = array; p_array<array+SIZE ; p_array++ ) {
		if (*p_array<0) {
			*sum += *p_array;
			(*count)++;
		}
	}
}

void array_of_pointer(int array[], int* count, int* sum) {
	int* p_array[SIZE];

	for (int i = 0; i < SIZE; i++) {
		p_array[i] = &array[i];
	}

	for  (int i=0 ;i<SIZE; i++){
		if (*p_array[i]<0) {
			*sum += *p_array[i];
			(*count)++;
		}
	}
}

void pointer_to_pointer(int array[], int* count, int* sum) {
	int *p1_array = array;
	int* p2_array = p1_array;
	for (int i = 0; i < SIZE; i++) {
		if (*(p2_array+i)<0) {
			*sum += *(p2_array+i);
			(*count)++;
		}
	}
}
