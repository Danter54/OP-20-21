#include <iostream>
#include <ctime>
#include "windows.h"
#include <chrono>
using namespace std;
#define N (5)

int insert(int mas[N]) {
	for (int i = 1; i < N; i++) {
		int key = mas[i];
		int j = i - 1;
		while (j>=0 && mas[j]>key) {
			mas[j + 1] = mas[j];		//Сортировка массива вставкой
			mas[j] = key;
			j--;
		}
	}
	return mas[N];
}

int sampling(int mas[N]) {
	int tmp = 0;
	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i; j < N; j++ ) {
			if (mas[j] < mas[min]) {		//Сортировка миссива выбором
				min = j;
			}
		}

		if (i != min) {
			tmp = mas[i];
			mas[i] = mas[min];
			mas[min] = tmp;
		}
	}

	return mas[N];
}

int randgen(int mas1[N], int mas2[N]) {
	for (int i = 0; i < N; i++) {
		mas1[i] = rand() % 201 - 100;	//Задаём рандомные числа
	}
	for (int i = 0; i < N; i++) {
		mas2[i] = mas1[i];
	}
	return mas1[N],mas2[N];
}

int revsort(int mas[N]) {
	for (int i = 1; i < N; ++i)
	{
		for (int r = 0; r < N - i; r++)
		{
			if (mas[r] < mas[r + 1])
			{
				// Обмен местами
				int temp = mas[r];
				mas[r] = mas[r + 1];
				mas[r + 1] = temp;
			}
		}
	}
	return mas[N];
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int mas1[N]{};
	int mas2[N]{};

	cout << "*****************************" << endl;
	cout << "|   Розрахунково-графічне   |" << endl;
	cout << "|     графічне завдання     |" << endl;
	cout << "*****************************" << endl;

	randgen	(mas1, mas2);
	cout << "Количество єлементов: "<<N<<endl;
	cout << "=======================================================\n\n";
	cout << "Сортировка вставкой: \n\n";
	auto start = chrono::high_resolution_clock::now();
	insert(mas1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end-start;
	cout << "Время сортировки неупорядоченного массива: "<<duration.count()<<"s\n";

	start = chrono::high_resolution_clock::now();
	insert(mas1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время сортировки упорядоченого  массива: " << duration.count()<<"s\n";

	revsort(mas1);	//Обратно упорядоченный массив

	start = chrono::high_resolution_clock::now();
	insert(mas1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время сортировки обратно упорядоченого  массива: " << duration.count() << "s\n\n";

	cout << "=======================================================\n\n";

	cout << "Сортировка выбором: \n\n";

	start = chrono::high_resolution_clock::now();
	sampling(mas2);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время сортировки неупорядоченного массива: " << duration.count() << "s\n";

	start = chrono::high_resolution_clock::now();
	sampling(mas2);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время сортировки упорядоченого  массива: " << duration.count() << "s\n";

	revsort(mas2);	//Обратно упорядоченный массив

	start = chrono::high_resolution_clock::now();
	sampling(mas2);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время сортировки обратно упорядоченого  массива: " << duration.count() << "s\n\n";
	cout << "=======================================================\n\n";



	



	return 0;
}
