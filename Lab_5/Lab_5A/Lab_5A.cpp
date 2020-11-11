#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int main()
{
	system("cls");
	system("chcp 1251");
	int a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0, D = 0;
	printf("Введите коэфициенты квадратного уравнения: ");
	scanf("%d %d %d", &a, &b, &c);
	D = b * b - 4 * a * c;

	if (D>0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		printf("x1= %0.3lf , x2= %0.3lf", x1, x2);
		return 0;
	}
	else if (D<0) {
		printf("Корней нет!");
		return 0;
	}
	else
		x1 = -b / (2.0 * a);
	printf("x= %0.3lf", x1);
	return 0;
}