#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:

	Point();
	Point(int valueX, int valueY);
	Point(Point &copy);

	void Set();
	void Sum_Mult(int* sum, int *mult);
	void Print(int* sum, int* mult);

};

