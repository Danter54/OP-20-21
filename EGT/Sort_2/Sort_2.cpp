#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
#define N (45)
#define M (20)
using namespace std;

int random(int mas[N]) {
	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 201 - 100;
	}
	return mas[N];
}

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

int main() {
	setlocale(LC_ALL, "Ru");
	double dur1[M]{0};
	double dur2[M]{0};
	double dur3[M]{0};

	int mas1[N]{0};
	int mas2[N]{ 0 };
	int mas3[N]{0};

	int mas[N]{0};

	random(mas1);
	for (int i = 0; i < N; i++) {
		mas2[i] = mas1[i];
		mas3[i] = mas1[i];
	}

	sampling(mas2);
	revsort(mas3);

	cout << "****************************"<<endl;
	cout << "|  Розрахунково- графічне  |" << endl;
	cout << "|         завдання         |" << endl;
	cout << "****************************" << endl;

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {
			mas[j] = mas1[j];
		}

		auto start = chrono::high_resolution_clock::now();
		sampling(mas);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		dur1[i] = duration.count();

		for (int j = 0; j < N; j++) {
			mas[j] = mas2[j];
		}

		 start = chrono::high_resolution_clock::now();
		sampling(mas);
		 end = chrono::high_resolution_clock::now();
		duration = end - start;
		dur2[i] = duration.count();

		for (int j = 0; j < N; j++) {
			mas[j] = mas3[j];
		}

		 start = chrono::high_resolution_clock::now();
		sampling(mas);
		 end = chrono::high_resolution_clock::now();
		duration = end - start;
		dur3[i] = duration.count();
	}

	cout << endl;
	cout << "Время выполнения сортировки: "<<endl;
	for (int i = 0; i < M; i++) {
		cout <<setprecision(2)<< scientific<< dur1[i]<<' ';
	}

	int min_i = 0, max_i = 0;
	double max_dur = dur1[0], min_dur = dur1[0];
	double sum = 0;

	for (int i = 0; i < M; i++) {
		if (dur1[i]<min_dur) {
			min_dur = dur1[i];
			min_i = i;
		}
		if (dur1[i]>max_dur) {
			max_dur = dur1[i];
			max_i = i;
		}
	}
	double L = M;
	for (int i = 0; i < M; i++) {
		if (i==max_i||i==min_i) {
			continue;
		}
		else sum += dur1[i];
	}
	cout << endl;
	cout << "Среднее время сортировки неупорядоченого массива= " << setprecision(2) << scientific << sum /(L-2.0)<<endl;

	cout << endl;
	cout << "Время выполнения сортировки: " << endl;
	for (int i = 0; i < M; i++) {
		cout << setprecision(2) << scientific << dur2[i] << ' ';
	}
	sum = 0; min_i = 0; max_i = 0;
	min_dur = dur2[0];	max_dur = dur2[0];


	for (int i = 0; i < M; i++) {
		if (dur2[i] < min_dur) {
			min_dur = dur1[i];
			min_i = i;
		}
		if (dur2[i] > max_dur) {
			max_dur = dur2[i];
			max_i = i;
		}
	}
	for (int i = 0; i < M; i++) {
		if (i == max_i || i == min_i) {
			continue;
		}
		else sum += dur2[i];
	}
	cout << endl;
	cout << "Среднее время сортировки упорядоченного массива = " << setprecision(2) << scientific << sum / (L - 2.0)<<endl;

	cout << endl;
	cout << "Время выполнения сортировки: " << endl;
	for (int i = 0; i < M; i++) {
		cout << setprecision(2) << scientific << dur3[i] << ' ';
	}
	sum = 0; min_i = 0; max_i = 0;
	min_dur = dur3[0];	max_dur = dur3[0];


	for (int i = 0; i < M; i++) {
		if (dur3[i] < min_dur) {
			min_dur = dur3[i];
			min_i = i;
		}
		if (dur2[i] > max_dur) {
			max_dur = dur3[i];
			max_i = i;
		}
	}
	for (int i = 0; i < M; i++) {
		if (i == max_i || i == min_i) {
			continue;
		}
		else sum += dur3[i];
	}
	cout << endl;
	cout << "Среднее время сортировки упорядоченного массива(наоборот) = " << setprecision(2) << scientific << sum / (L - 2.0);

	return 0;
}