#include <iostream>
#include "Revers.h"

int main() {
	setlocale(LC_ALL,"RU");
	int x , y , z;
	std::cout <<"¬ведите 3 числа: " ;
	std::cin >> x >> y >> z;
	Revers obj;
	obj.Method1(&x, &y, &z);
	std::cout << x << ' ' << y << ' ' << z;
	std::cout << "\n************************************";

	std::cout << "\n¬ведите 3 числа: ";
	std::cin >> x >> y >> z;
	obj.Method2(x, y, z);
	std::cout << x << ' ' << y << ' ' << z;

	return 0;
}