#include "Functions.h"

using namespace std;

int main()
{
	system("chcp 1251");
	int N = 0, M = 0;

	cout << "������� ������ ������� (N M): ";
	scanf_s("%d %d",&N, &M);
	while (N <= 0 || M <= 0) {
		cout << "������� �������� ������� �������!!!" << endl;
		cout << "������� ��� ���: ";
		scanf_s("%d %d", &N, &M);
	}

	int** matrix;
	int* min = new int[N];
	int* max = new int[M];
	int sum = 0;
	int mult = 0;

	matrix = new int* [N];
	for (int i = 0; i < N; i++) {	//������������� �������
		matrix[i] = new int[M];
	}

	random_add(matrix, &N, &M);
	print(matrix, &N, &M);
	task(matrix,N,M, min, max, &sum, &mult);
	return 0;
}