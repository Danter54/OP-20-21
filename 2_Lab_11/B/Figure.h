#pragma once
#include <iostream>
class Figure
{
private:
	double squere;
	const double PI = 3.14;
public:

	Figure();
	Figure(int a, int h = 0);

	void Print();
};

