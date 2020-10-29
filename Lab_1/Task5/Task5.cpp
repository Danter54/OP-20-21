#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	double a;
	printf("Enter your number: ");
	scanf("%lf", &a);
	a += 5;
	printf("My value: %0.1lf \n", a);
	printf("Sorry but you lose \n");

}