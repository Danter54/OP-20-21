#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int a, b, tmp;
	printf("Enter your first value: ");
	scanf("%d", &a);
	printf("Enter your secound value: ");
	scanf("%d", &b);

	tmp = a;  //First method
	a = b;
	b = tmp;
	printf("First method:\n");
	printf("1=%d \n", a);
	printf("2=%d \n", b);

	tmp = a; //Come back values
	a = b;
	b = tmp;

	a = a + b;//Secound method
	b = b - a;
	b = -b;
	a = a - b;
	printf("Secound method:\n");
	printf("1=%d \n", a);
	printf("2=%d \n", b);
}