#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>


using namespace std;
#define N (100)
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int m=0, n=0, k=0, l=0;
	int mas1[N][N]{}, mas2[N][N]{}, mas3[N][N]{};


	cout << "Введите размер 1 матрици:(не больше 100) ";
	cin >> m >> n;
	cout << "Введите размер 2 матрици:(не больше 100) ";
	cin >> k >> l;


	if (n!=k) {
		cout << "Неверно заданые размеры матриц!!!";
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas1[i][j] = rand()%4;
		}
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			mas2[i][j] = rand() %4;
		}
	}

	cout << "Arr1:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(6) <<mas1[i][j] ;
		}
		cout << endl;
	}

	cout << "Arr2:" << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << setw(6) << mas2[i][j];
		}
		cout << endl;

	}
	int temp = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			for (int b = 0; b < k; b++)
			{
				mas3[i][j] += (mas1[i][b] * mas2[b][j]);
			}
		}
	}
	cout << "Result:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << setw(6) << mas3[i][j];
		}
		cout << endl;
	}

	  
}