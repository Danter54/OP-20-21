#include <iostream>
#include "Functions.h"
#include <time.h>

int main()
{
	system("chcp 1251");
	srand(time(NULL));
	int* array = nullptr;
	int N = 0;
	printf("Введите размер массива: ");
	scanf_s("%d", &N);

	array = (int*)malloc(N * sizeof(int));
	printf("Массив: ");
	for (int i = 0; i < N; i++) {
		*(array + i) = rand() % 20 - 10;
		printf("%d ", *(array + i));
	}
	void (*univerasal)(int* array, int N);

	int choice = 0;

	printf("\n");
	printf("Выберите метод сортировки\n");
	printf("1-Пузырьком\n");
	printf("2-Вставками\n");
	printf("3-Гнома\n");
	printf("4-Выбором\n");
	printf("Ваш выбор: ");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1: Sort(array,N,Buble);
		//univerasal(array,N);
		break;
	case 2: 
		Sort(array, N, Insert);
		break;
	case 3: 
		Sort(array, N, Gnom);
		break;
	case 4: 
		Sort(array, N, Selection);
		break;
	default:std::cout << "Неверное значение!\n";
		break;
	}

	printf("Отсортированый массив: ");
	for (int i = 0; i < N; i++) {
		printf("%d ", *(array + i));
	}

	free(array);

}