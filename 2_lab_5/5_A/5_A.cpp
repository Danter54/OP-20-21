#include "Functions.h"

using namespace std;

int main()
{
	system("chcp 1251");
	int N = 0, M = 0;

	cout << "Введите замеры матрицы (N M): ";
	scanf_s("%d %d",&N, &M);
	while (N <= 0 || M <= 0) {
		cout << "Неверно введённые размеры матрицы!!!" << endl;
		cout << "Введите ещё раз: ";
		scanf_s("%d %d", &N, &M);
	}

	int** matrix;
	int* min = new int[M];
	int* max = new int[N];
	int sum = 0;
	int mult = 1;

	int *p_array = nullptr;

	matrix = new int* [N];
	for (int i = 0; i < N; i++) {	//Инициализация массива
		matrix[i] = new int[M];
	}

	random_add(matrix, &N, &M);
	print(matrix, &N, &M);
	p_array = task(matrix,N,M, min, max, &sum, &mult);

	printf("Max: ");
	printf("%d",p_array[0]);
	printf("\n");

	printf("MIN:");
	printf("%d", p_array[1]);
	printf("\n");

	delete[] p_array;
	delete[]min;
	delete[]max;
	return 0;
}