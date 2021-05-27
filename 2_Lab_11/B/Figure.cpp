#include "Figure.h"

Figure::Figure()
{
	squere = 0;
}

Figure::Figure(int a, int h)
{
	if (h==0) {
		squere = PI * a * a;
	}
	else {
		squere = (a * h) / 2;
	}
}

void Figure::Print()
{
	std::cout << "Squere: " << squere<<std::endl;
}
