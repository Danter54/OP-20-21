#include "Area.h"
#include <iostream>

void Area::calculating(int x, int y)
{
	if (y==0) {
		y = x;
	}

	Area::res = y * x;
	std::cout << "Res -> " << res<<std::endl;
}
