#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define N (10)
int main()
{
	int mas[N][N]{};
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mas[i][j] = rand()%201-100;
		}
	}
	int I_Max = 0, J_Max = 0, I_Min = 0, J_Min = 0;
	cout << "Current Array: \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout<<setw(5)<<mas[i][j];
		}
		cout << endl;

	}
	cout << endl;
	int MaxTemp=0;
	cout << "Max array: \n";
	for (int i = 0, j=0; i < N; i++)
	{
		MaxTemp = mas[i][j];
		for (int j = 1; j < N; j++)
		{

			if (mas[i][j] > MaxTemp) {
				I_Max = i;
				J_Max = j;
				MaxTemp = mas[i][j];
			}
		}
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				cout <<setw(5) <<mas[I_Max][J_Max];
			}
			else if (j == J_Max) {
				cout<< setw(5) << mas[i][0];
			}
			else cout<<setw(5) << mas[i][j];
		}
		cout << endl;
		
	}

	int MinTemp = 0;

	cout << "Min Array\n";
	for (int i = 0, j=0; i < N; i++) {
		MinTemp = mas[i][j];
		for (int j = 1; j < N; j++)
		{
			if (mas[i][j]<MinTemp) {
				I_Min = i;
				J_Min = j;
				MinTemp = mas[i][j];
			}

		}


		for (int j = 0; j < N; j++) {
			if (j == J_Min) {
				cout << setw(5) << mas[i][N - 1];
			}
			else if (j == N - 1) {
				cout << setw(5) << mas[I_Min][J_Min];
			}
			else cout << setw(5) << mas[i][j];
		}
		cout << endl;



	}
}