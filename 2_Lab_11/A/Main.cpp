#include <iostream>
#include "Point.h"

int main() {
	system("chcp 1251");

	int sum=0, mult=0;

	Point obj1;
	printf("1. obj\n");

	std::cout << "Введите Х и У\n";
	obj1.Set();
	obj1.Sum_Mult(&sum,&mult);
	obj1.Print(&sum,&mult);
	std::cout << "====================================\n";
	printf("2. obj\n");

	Point obj2(23, 10);
	obj2.Sum_Mult(&sum, &mult);
	obj2.Print(&sum,&mult);
	std::cout << "====================================\n";

	Point obj3(obj2);
	printf("3. obj\n");
	
	obj3.Sum_Mult(&sum, &mult);
	obj3.Print(&sum, &mult);



	return 0;
}