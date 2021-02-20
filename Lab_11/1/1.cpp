#include <iostream>
#include <ctime>
#define I (10)
using namespace std;

 int Sum (int mas[],int N){
	 int sum = 0;
	 if (mas[N] > 0) sum = mas[N]; // Проверка елемента масива на положительность
	 if (N == 0) return sum; // Условие выхода
	 return sum + Sum(mas, N - 1); // Рекурсия
}

int main()
{
	setlocale(LC_ALL,"RU");
	srand(time (0));
	int mas[I]{};
	for (int i = 0; i < I; i++) {
		mas[i] = rand()%200-100;	//Рандомно заданые числа
	}
	cout << "Наш масив: ";
	for (int i = 0; i < I; i++) {
		cout << mas[i]<<" ";		//Выовод массива
	}
	cout << endl;


	cout <<"Сумма массива: "<< Sum(mas,I-1); // Вывод суммы
	return 0;
}