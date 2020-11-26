#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
int main()
{
	system("cls");
	system("chcp 1251");
	int i = 0, j = 5;
	char str[4];
	bool arr[10];
	while(true){
		if (i == 5 && j == 10) {
			printf("Все места заняты!!!");
			break;
		}

		printf("Курите?\n");
		scanf("%s", str);

		if (strcmp(str, "Да") == 0) {
			if (i == 5) {
				printf("Места 1-5 заняты!\n");
				continue;
			}
			arr[i] = false;
			printf("Место %d, занято\n",i+1);
			i++;
		}else
		if (strcmp(str, "Нет") == 0) {
			if (j == 10) {
				printf("Места 6-10 заняты!\n");
				continue;
			}
			arr[j] = false;
			printf("Место %d, занято\n", j+1);
			j++;
		}
	}
	return 0;
}
