#pragma once
#include <iostream>
class Complex
{
private:
	int r;
	int m;

public:
	void set();
	void add(int a, int b);
	void sum(Complex* other);
	void output();
};

