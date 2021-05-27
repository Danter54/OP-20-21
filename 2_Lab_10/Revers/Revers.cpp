#include "Revers.h"

void Revers::Method1(int* x, int* y, int* z) {

	min = x;
	max = y;

	if (*max < *min) {
		max = x;
		min = y;
	}
	if (*max < *z) {
		max = z;
	}
	else if (*min > * z) {
		min = z;
	}

	temp = *min;
	*min = *max;
	*max = temp;
}

void Revers::Method2(int& x, int& y, int& z)
{
	min = &x;
	max = &y;

	if (*max < *min) {
		max = &x;
		min = &y;
	}
	if (*max < z) {
		max = &z;
	}
	else if (*min > z) {
		min = &z;
	}

	temp = *min;
	*min = *max;
	*max = temp;
}

