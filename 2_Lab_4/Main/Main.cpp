#include "Function.h"



void main() {
	setlocale(LC_ALL, "RU");

	int size_1 = 0, size_2 = 0;			// ������������� ����������
	double average = 0;			
	int *array_2 ;

	printf("������� ������ �������: ");	// ����� ������ �������
	scanf_s("%d",&size_1);

	int* array_1 = new int[size_1];		// ������������� ������������� �������

	printf("����������� ������������� �������...\n");
	array_filling(array_1,size_1);		// ���������� �������

	printf("�������� ������: ");
	for (int i = 0; i < size_1; i++) {
		printf("%d ", *(array_1 + i)); 
	}									//����� ��������� �������


	printf("\n���������� �������� �������...\n");


	array_2=function(array_1,size_1,&size_2,&average);

	printf("������� ��������: %2.2f \n", average);

	printf("����� ������ �������(������ ��������): ");
	
	for (int i = 0; i < size_2;i++) {
		printf("%d ",*(array_2+i));
	}

	delete[]array_1;
	delete[]array_2;

}