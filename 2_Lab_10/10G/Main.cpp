#include <iostream>
#include "TIMER.h"

int main() {
	setlocale(LC_ALL, "ru");

	TIMER obj1;
	obj1.Output();

	TIMER obj2(20);
	obj2.Output();

	TIMER obj3(20, 3);	// 1- �������� ������� 2- ������
	obj3.Output();

	TIMER obj4(obj3);	//������ ������������ �����������
	obj4.Output();

	return 0;
}