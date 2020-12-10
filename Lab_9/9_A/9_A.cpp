#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define N (5)
int main()
{
	int mas[N][N]{};
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mas[i][j] = rand() % 201 - 100;
		}
	}

	cout << "Current Array: \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(5) << mas[i][j];
		}
		cout << endl;

	}
	int Maxmas[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Maxmas[i][j] = mas[i][j];
		}
	}
	int temp = 0,j_max=0;
	cout << "Max array" << endl;
	for (int i = 0; i < N; i++)
	{
		temp = Maxmas[i][0];
		j_max = 0;
		for (int j = 1; j < N; j++)
		{
			if (Maxmas[i][j]>temp) {
				temp = Maxmas[i][j];
				j_max = j;
			}
		}
		temp = Maxmas[i][0];
		Maxmas[i][0] = Maxmas[i][j_max];
		Maxmas[i][j_max] = temp;
		for (int j = 0; j < N; j++) {
			cout <<setw(5)<< Maxmas[i][j];
		}
		cout << endl;

	}
	int I_min = 0;
	for (int j = 0; j < N; j++)
	{
		temp = mas[0][j];
		I_min = 0;
		for (int i = 0; i < N; i++) {
			if (mas[i][j]<temp) {
				temp = mas[i][j];
				I_min = i;
			}
		}
		if (I_min==N-1) {
			continue;
		}
		else {
			temp = mas[N - 1][j];
			mas[N - 1][j] = mas[I_min][j];
			mas[I_min][j] = temp;
		}
		
	}
	cout << "Min array:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(5) << mas[i][j];
		}
		cout << endl;
	}
}