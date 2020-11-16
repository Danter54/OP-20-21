#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctime>

int main()
{
	setlocale(LC_ALL,"ru");
	srand(time(NULL));

	int n = 0, num1=0, num2=0, temp=0, answer=0;
	double mark = 0;
	printf("Введите количество примеров: ");
	scanf("%d",&n);
	printf("Тест начался:\n");

	for (int i = 0; i < n; i++) {
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		temp = num1 * num2;
		printf("%d * %d = ",num1,num2);
		scanf("%d",&answer);

		if (temp == answer) mark++;
	}

	printf("Количество правильных ответов: %0.0lf\n", mark);

	mark =(mark/n) * 12;

	if (mark < 1) {
		mark = 1;
	}

	printf("Твоя оценка = %0.0lf\n",mark);
}