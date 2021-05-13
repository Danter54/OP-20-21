#include "Functions.h"
#include "Header_includer.h"

void Sum(int* array, int* sum, int count) {
	*sum = 0;
	for (int i = 0; i < count; i++) {
		if (*(array+i)>0) {
			*sum += *(array+i);
		}
	}
}

void Mult(int* array, int* mult, int count) {
	*mult = 1;
	for (int i = 0; i < count ; i++) {
		if (*(array+i)<0) {
			(*mult) *= (*(array+i));
		}
	}
}