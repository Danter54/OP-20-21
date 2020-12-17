#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
using namespace std;
#define N (45)
#define M (5)
double dur1[M]{ 0 };
double dur2[M]{ 0 };
double dur3[M]{ 0 };

int sampling(int mas[N]) {
	int tmp = 0;
	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i; j < N; j++) {
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


int random(int mas[N]) {
	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 201 - 100;
	}
	return mas[N];
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
	setlocale(LC_ALL, "ru");
	int mas[N]{ 0 };
	srand(time(0));

	cout << "*******************************" << endl;
	cout << "|     Расчётно-графическое    |" << endl;
	cout << "|           задание           |" << endl;
	cout << "|     Сортировка 'Вставкой'   |" << endl;
	cout << "******************************" << endl;


	for (int i = 0; i < M; i++) {
		cout << "===========================================" << endl;
		cout << "Ход №: " << i + 1 << endl;
		random(mas);
		cout << "Прежний массив: ";
		for (int q = 0; q < N; q++) {
			cout << mas[q] << " ";
		}
		cout << endl;

		auto start = chrono::high_resolution_clock::now();
		sampling(mas);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		dur1[i] = duration.count();
		cout << "Отсортированый массив: ";
		for (int q = 0; q < N; q++) {
			cout << mas[q] << " ";
		}
		cout << endl << endl;

		/*Сортировка массива(Упорядоченый)*/
		cout << "Массив до сортировки(упорядоченый): ";
		for (int q = 0; q < N; q++) {
			cout << mas[q] << " ";
		}
		cout << endl;

		start = chrono::high_resolution_clock::now();
		sampling(mas);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		dur2[i] = duration.count();

		cout << "Отсортированый масив: ";
		for (int q = 0; q < N; q++) {
			cout << mas[q] << " ";
		}
		cout << endl << endl;;

		revsort(mas); //Сортировка наоборот
		cout << "Прежний масив(Отсортированый наоборот): ";
		for (int q = 0; q < N; q++) {
			cout << mas[q] << " ";
		}
		cout << endl;

		start = chrono::high_resolution_clock::now();
		sampling(mas);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		dur3[i] = duration.count();
		cout << "Отсортированый масив: ";
		for (int q = 0; q < N; q++) {
			cout << mas[q] << " ";
		}
		cout << endl;

	}

	for (int q = 0; q < 54; q++) {
		cout << '+';
	}
	cout << endl;

	cout << "Время сортировки (Неотсортированого массива:)" << endl;
	for (int q = 0; q < M; q++)
	{
		cout << q + 1 << ". " << setprecision(2) << scientific << dur1[q] << " " << endl;
	}

	cout << "Время сортировки (Упорядоченого массива:)" << endl;
	for (int q = 0; q < M; q++)
	{
		cout << q + 1 << ". " << setprecision(2) << scientific << dur2[q] << " " << endl;
	}

	cout << "Время сортировки (Упорядоченого массива наоборот:)" << endl;
	for (int q = 0; q < M; q++)
	{
		cout << q + 1 << ". " << setprecision(2) << scientific << dur3[q] << " " << endl;;
		//cout << dur1[q]<<' ';
	}

	system("pause");
	return 0;
}