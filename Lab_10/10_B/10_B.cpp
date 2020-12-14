#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
#define N (100)

int add(int mas[N][N], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mas[i][j] = rand()%21-10+1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<<setw(5) << mas[i][j];
		}
		cout << endl;
	}
	return mas[0][0];
}

int count(int mas[N][N], int n, int m, int k) {
	int count = 0;
	for (int j = 0; j < m; j++) {
		if (mas[k-1][j]>0) {
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int n, m, mas[N][N]{}, k;

	cout << "Введите размер массива(не больше 100*100): ";
	cin >> n >> m;
	if (n > 100 || m > 100 || n <= 0 || m <= 0 ) {
		cout << "Неверно заданые размеры массива!!!";	//Проверка заданых размеров массива
			return 0;
	}
	add(mas,n,m);
	cout << "Введите строку в которой нужно посчитать количество положительных элементов: ";
	cin >> k;
	if (k>n || k<=0) {
		cout << "Неверно заданная строка!!!";	//Проверка строки
		return 0;
	}

	cout<<"Количество положительных элементов в вашей "<<k<<" строке: "<<count(mas,n,m,k);
	cout <<"\n\nКоличество положительных элементов в каждой строке: \n";
	for (k = 1; k < n+1; k++) {
		cout <<"Количество положительных элементов в "<< k << " строке: "<< count(mas,n,m,k) ;
		cout << endl;
	}

	return 0;
}