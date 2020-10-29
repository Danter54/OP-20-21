#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	double a;
	printf("Enter your value: ");
	scanf("%lf", &a);
	a *= a ;
	a *= a ;
	a *= a ;

	printf("Your answer: %.2lf \n", a);

}