#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
int main()
{
	system("cls");
	system("chcp 1251");
	double x = 0, y = 0;
	printf("������� ���������� x � y: ");
	scanf("%lf %lf", &x, &y);
	printf("���� ���������� x=%0.2lf , y=%0.2lf \n",x,y);
	if ((x>=-1 && x<=1 && y<=1 && y>=0)||(x>=-1 && x<=0 && y<=0 && y>=-1)) {
		printf("����� �������� � �������� :) \n");
		system("pause");
		return main();
	}else
		printf("����� �� �������� � ��������! \n");
	system("pause");
	return main();
}