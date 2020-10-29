#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int sec, min, days, year, time;
	sec = 60;
	min = 60;
	days = 24;
	year = sec * min * days * 365;
	
	printf("Enter your year: ");
	scanf("%d", &time);
	time = time * year;
	printf("Your time in sec: %d \n", time);
	printf("Integer overflow!!! \n"); //Переполнение данных
	printf("Using new type of data \n");

	double s, m, d, y, t;
	s = 60;
	m = 60;
	d = 24;
	y = sec * min * days * 365;
	
	printf("Enter your year: ");
	scanf("%lf", &t);

	t = t * y;
	printf("Your time in sec: %0.0lf" , t);
}