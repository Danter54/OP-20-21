#include "Function.h"



void main() {
	setlocale(LC_ALL, "RU");

	int size_1 = 0, size_2 = 0;			// Инициализация переменных
	double average = 0;			
	int *array_2 ;

	printf("Введите размер массива: ");	// Узнаём размер массива
	scanf_s("%d",&size_1);

	int* array_1 = new int[size_1];		// Инициализация динамического массива

	printf("Выполняется инициализация массива...\n");
	array_filling(array_1,size_1);		// Заполнение массива

	printf("Основной массив: ");
	for (int i = 0; i < size_1; i++) {
		printf("%d ", *(array_1 + i)); 
	}									//Вывод основного массива


	printf("\nВыполнение основной функции...\n");


	array_2=function(array_1,size_1,&size_2,&average);

	printf("Среднее значение: %2.2f \n", average);

	printf("Вывод нового массива(меньше среднего): ");
	
	for (int i = 0; i < size_2;i++) {
		printf("%d ",*(array_2+i));
	}

	delete[]array_1;
	delete[]array_2;

}