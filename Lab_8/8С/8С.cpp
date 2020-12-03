#define _CRT_SECURE_NO_WARNINGS
#define SIZE (15)
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "ru");
	char count[SIZE];
	int sum = 0, it = 0, rev = 0, num = 0, temp = 0;
	printf("Введите число: ");
	gets_s(count);
	num = atoi(count); //Конвертируем строку в int

	while (num!=0) {

	sum += num % 10;	//Сумматор чисел числа
	num /= 10;
}
	printf("Sum: %d\n", sum);
	num = atoi(count);

	while(num!=0) {
		num/= 10;		//Подсчёт количества цифр в числе
		it++;
	}

	printf("Quantity: %d\n", it);

	num = atoi(count);

	printf("Revert: ");
	while (num!=0) {
		temp = num % 10;	//Число наоборот
		num /= 10;
		printf("%d", temp);
	}
}