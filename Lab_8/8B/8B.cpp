#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctime>
#define N (10)


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int const SIZE = 10;
	int arr[20]{};
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 201 - 100;	//Инициализация массива
	}

	printf("Текущий массив:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}

	int Temp[100]{}, n, pos;
	printf("\nКоличество элементов (Не больше 100): ");	//Ввод массива который вставляется
	scanf("%d", &n);
	if (n > 100 || n <= 0) {
		printf("Неверно введеное значение!");
		return 0;
	}

	printf("Введите элементы которые нужно вставить: ");

	for (int j = 0; j < n; j++)
		scanf("%d", &Temp[j]);
	printf("Введите позицию в которую хотите вставить элементы: ");
	scanf("%d", &pos);
	if (pos<=0 ||pos>SIZE) {
		printf("Неверно введенная позиция!");
		return 0;
	}

	printf("Массив с добавлеными элементами: \n");

	for (int i = 0, j = 0; i < SIZE + n; i++) {
		if (i >= pos - 1 && i < pos + n - 1) {
			printf("%d ", Temp[j]);
			j++;
		}
		else if (i >= pos + n - 1) {
			printf("%d ", arr[i - n]);
		}
		else
			printf("%d ", arr[i]);
	}

	printf("\nПребыдущий массив: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nС какой позиции вы хотите удалить элементы: ");
	scanf("%d",&pos);
	if (pos<=0 ||pos>10) {
		printf("Не верно ведённая позиция!!!");
		return 0;
	}
	printf("Сколько элементов вы хотите удалить: ");
	scanf("%d",&n);
	int mas[10]{};
	if (n + pos < 0 || n + pos> SIZE+1) {
		printf("Неверно ведённые количество элементов!!!");
		return 0;
	}

	if (pos==1 &&n==10) {
		printf("Вы удалили весь массив!!!");
		return 0;
	}

	for (int i = 0; i < SIZE-n; i++)
	{
		if (i>=pos-1 && i<pos+n-1) {
			mas[i]=arr[i + n];
		}
		else if (i >= pos + n - 1) {
			mas[i]=arr[i+n];
		}
		else mas[i]=arr[i];
	}

	printf("Текущий массив: \n");
	for (int i = 0; i < SIZE - n; i++) {
		printf("%d ", mas[i]);
	}
}