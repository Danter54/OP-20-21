#include "Complex.h"

void Complex::set()
{
	std::cout << "R -> ";
	std::cin >> r;

	std::cout << "M -> ";
	std::cin >> m;
}

void Complex::add(int a, int b)
{
	this->r += a;
	this->m += b;
}

void Complex::sum(Complex* other)
{
	this->r += other->r;
	this->m += other->m;
}

void Complex::output()
{
	std::cout << "Z = " << r << " + " << m << 'i'<<std::endl;
}
