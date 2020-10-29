#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdio.h>

int main() {
	double a, b, c, p, s;
	printf("Enter first side of triangle: ");
	scanf("%lf", &a);
	printf("Enter secound side of triangle: ");
	scanf("%lf",&b);
	printf("Enter third side of triangle: ");
	scanf("%lf",&c);

	p = (a + b + c) / 2;
	s = sqrt(p*(p-a)*(p-b)*(p-c));

	printf("The area of the triangle is: %lf \n", s);
}