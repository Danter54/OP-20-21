#include"Header_includer.h"
#include "Functions.h"
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	system("chcp 1251");

	int* array=nullptr;
	int N = 0;
	int parametr=0;

	printf("������� ������ �������: ");
	scanf_s("%d", &N);

	array = (int*) malloc( N * sizeof(int) );
	printf("������: ");
	for (int i = 0; i < N; i++) {
		*(array + i) = rand()%20-10;
		printf("%d ", *(array+i));
	}
	printf("\n");

	void (*choice)(int* array, int* sum, int count) = Sum;
	choice(array,&parametr,N);

	if (parametr != 0) {
		printf("�����: %d\n",parametr);
	}
	else printf("��� ������������� ���������!!!\n");

	choice = Mult;
	choice(array, &parametr, N);

	if (parametr != 1) {
		printf("������������: %d\n", parametr);
	}
	else printf("��� ������������� ���������!!!\n");

	free(array);
}