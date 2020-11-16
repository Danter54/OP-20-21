#include <iostream>
#include <math.h>
#include <stdio.h>


int main()
{
	system("cls");
	system("chcp 1251");

	long n;
	double sum = 0, dbln=0, term=0;
	short k1=1;
	const double eps = 0.000001;

	for (n = 0; ;n++,k1=-k1) {
		dbln = n;
		term = k1 * (1 - (pow(dbln + 1, 2) / pow(dbln + 2, 2)));
				if (fabs(term) >= eps) {
			sum += term;
		}else break;

		if (n == 9) 
			printf("Сумма 10 членов ряда = %10.7lf\n",sum);
	}

	printf("Полная сумма ряда = %10.7lf\n", sum);
	return 0;
}