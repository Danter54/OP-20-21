#include <iostream>
#include "TIMER.h"

int main() {
	setlocale(LC_ALL, "ru");

	TIMER obj1;
	obj1.Output();

	TIMER obj2(20);
	obj2.Output();

	TIMER obj3(20, 3);	// 1- параметр секунды 2- минуты
	obj3.Output();

	TIMER obj4(obj3);	//Работа конструктора копирования
	obj4.Output();

	return 0;
}