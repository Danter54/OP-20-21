#include <iostream>
#include "Complex.h"

int main() {
	system("chcp 1251");

	Complex first;
	printf("������� ������������ (r) � ������ (m) �����: \n");
	first.set();
	first.output();

	first.add(3,5);
	first.output();

	Complex secound;
	secound.set();
	secound.sum(&first);
	secound.output();

	return 0;
}