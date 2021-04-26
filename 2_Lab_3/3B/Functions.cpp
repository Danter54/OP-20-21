#include "Functions.h"


void fill_array(int* array, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		*(array + i) = rand() % 10 - 5;
	}
}

void array_s(int* array, int size) {
	int less = 0, more = 0, zero = 0;
	for (int i = 0; i < size; i++) {
		if (*(array + i) < 0) {
			less++;
		}
		else if (*(array + i) == 0) {
			zero++;
		}

		else more++;
	}

	int* p_less = new int[less];
	int* p_zero = new int[zero];
	int* p_more = new int[more];

	for (int i = 0, j=0, k=0, l=0; i < size; i++) {
		if (*(array + i) < 0) {
			*(p_less + j) = *(array + i);
				j++;
		}
		else if (*(array + i) == 0) {
			*(p_zero + k) = *(array + i);
			k++;
		}
		else {
			*(p_more + l) = *(array + i);
			l++;
		}
	}

	for (int i = 0; i < zero; i++) {
		*(array + i) = *(p_zero + i);
	}
	for (int i = 0; i < less; i++) {
		*(array + i + zero) = *(p_less + i);
	}
	for (int i = 0; i < more; i++) {
		*(array + i + zero + less) = *(p_more + i);
	}

	delete[]p_less;
	delete[]p_zero;
	delete[]p_more;
	p_less = nullptr;
	p_more = nullptr;
	p_zero = nullptr;
}