#include <iostream>
#include <stdio.h>
#include <time.h>

#define size (100)
#define maxarr (100)
#define minarr (-100)
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int arr[size], sum = 0, tempsum = 0, mintemp_I = 0, maxtemp_I = 0;
	bool istrue;
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % ( maxarr - minarr + 1 ) - 100; //Об'явление массива
	}
	

	for (int i = 0; i < size; i++) {
		if (arr[i]>0) {
			istrue = true;
		}
	}
	if (istrue != true) {
		printf("Нет положительных чисел");	//Проверка есть ли в масиве положительные числа
		return 0;
	}

	printf("Массив:\n");
	for (int i = 0; i < size; i++) {		//Вывод массива на экран
		printf("%d ", arr[i]); 
	}

	for (int i = 0; i < size; i++) {

		if (arr[i]<0) { 

			if (tempsum < sum)
			{	tempsum = sum;
				maxtemp_I = i;
				for (i; i > 0; i--) {
					if (arr[i - 1] < 0) {
						mintemp_I = i; //Обратный поиск минимума
						break;
					} else continue;
				}
			}
			sum = 0;
		}

		else if (arr[i] >= 0)
		{
			sum += arr[i]; //Суммирование 
		}


	}

	printf("\nСумма наибольшей последовательности положительных чисел: %d\n", tempsum);
	printf("Ряд масива: ");
	for (mintemp_I; mintemp_I < maxtemp_I; mintemp_I++) {
		printf("%d ", arr[mintemp_I]);
	}


}