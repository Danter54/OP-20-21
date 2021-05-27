#include "Point.h"

Point::Point()
{
	x = y = 0;

}

Point::Point(int valueX, int valueY)
{
	x = valueX;
	y = valueY;
}

Point::Point(Point& copy)
{
	this->x = copy.x;
	this->y = copy.y;
}

void Point::Set()
{
	std::cout << "X->";
	std::cin >> x;

	std::cout << "Y->";
	std::cin >> y;
}

void Point::Sum_Mult(int* sum, int* mult)
{
	*sum = x + y;
	*mult = x * y;
}

void Point::Print(int *sum, int *mult)
{
	std::cout << "X-> " << x<<std::endl;
	std::cout << "Y-> " << y << std::endl;

	std::cout << "Sum -> " << *sum << std::endl;
	std::cout << "Mult -> " << *mult << std::endl;
}
