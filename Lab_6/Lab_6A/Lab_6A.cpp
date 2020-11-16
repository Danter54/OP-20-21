#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctime>

int main()
{
	system("cls");
	system("chcp 1251");
	srand(time(NULL));

	int cnum =1 + rand()%100, ynum,i=1;
	printf("Угадай число которое я загадал\n");

	for (i;;i++) {

		printf("Введи свое число: ");
		scanf("%d",&ynum);

		if(ynum<cnum) {
			printf("Твоё число меньше моего\n");
		}

		else if (ynum > cnum) {
			printf("Твоё число больше моего\n");
		}

		else break;
	}

	printf("Ты угадал!!!\n");
	printf("Количество попыток: %d", i);
	return 0;
}