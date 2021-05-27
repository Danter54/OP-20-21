#include <iostream>
#include "Figure.h"

int main() {

	std::cout << "Squere of circle: \n";
	Figure circle(2);
	circle.Print();

	std::cout << "Squere of triangle: \n";

	Figure triangle(5,2);
	triangle.Print();

	return 0;
}