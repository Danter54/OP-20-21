#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	system("chcp 1251");
	system("cls");

	double x = 0;
	int n = 4;
	double a = 2.0, b = 40.5;
	double t1 = 0, t2 = 0;
	double ax = 0;

	printf("Введите значение переменной(x!=0) x=");
	scanf("%lf", &x);


	ax = double(n) - 2;	// Расчёт t1
	ax = ax * pow(x, n - 2);
	ax = -1.0 / ax;

	t1 = double(n) - 1;
	t1 = t1 * pow(x, n - 1);
	t1 = b / t1;

	t1 = t1 + ax;
	t1 = (1 / a) * t1;

	ax = x * (3.14 / 180);

	t2 = (2 * x / a * a) * sin(ax) - (x * x / a - 2 / pow(a, 3)) * cos(ax);  // Расчёт t2


	printf("Твой результат t1: %0.5lf\n", t1);  // Вывод данных
	printf("Твой результат t2: %0.5lf", t2);
}