#include <iostream>
#include <iomanip>
using namespace std;
#define N (50)

int mas3[N];

int transform(int mas[N], int size, int B , int C) {

	int mas2[N][N]{};
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < C; j++) {	//Переписывание матрицы
			mas2[i][j] = mas[C * i + j];
		}
	}

	cout << "Прежний массив: " << endl;

	for (int i = 0; i < B; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << setw(5) << mas2[i][j];
		}
		cout << endl;
	}

	cout << "Отзеркаленый массив: " << endl;
	
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < C / 2; j++) {
			int temp = 0;
			temp = mas2[i][j];
			mas2[i][j] = mas2[i][(C - 1) - j];	//Зеркальное отражение
			mas2[i][(C - 1) - j] = temp;
		}
		
	}

	for (int  i = 0; i < B; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout <<setw(5)<< mas2[i][j]; //Вывод зеркального отражения в массив
		}
		cout << endl;
	}


	
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < C; j++) {
			mas3[C*i+j] = mas2[i][j];
		}
	}

	return 0;


}

int main()
{
	setlocale(LC_ALL, "Ru");
	int n, mas[N]{},K=0,M=0;
	cout << "Введите количество элементов одномерного массива: ";
	cin >> n;
	cout << "Введите элементы массива: ";

	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}

	cout << "Введите количество строк и столбцов: ";
	cin >> K >> M;
	if (K*M>n) {
		cout <<"Неверно введённые параметры!!!" ;
		return 0;
	 }
	transform(mas,n,K,M);
	
	
	cout << "Одномерный массив: "<<endl;
	for (int i = 0; i < K*M; i++)
	{
		cout << setw(5) << mas3[i];
	}
	return 0;
}
