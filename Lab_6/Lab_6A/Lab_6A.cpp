#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctime>

int main()
{
	system("cls");
	system("chcp 1251");
	srand(time(NULL));

	int cnum =1 + rand()%100, ynum,i=1;
	printf("������ ����� ������� � �������\n");

	for (i;;i++) {

		printf("����� ���� �����: ");
		scanf("%d",&ynum);

		if(ynum<cnum) {
			printf("��� ����� ������ �����\n");
		}

		else if (ynum > cnum) {
			printf("��� ����� ������ �����\n");
		}

		else break;
	}

	printf("�� ������!!!\n");
	printf("���������� �������: %d", i);
	return 0;
}