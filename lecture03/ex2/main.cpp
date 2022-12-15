#include "CComplex.hpp"
#include <iostream>

int main()
{
	CComplex a(CComplex::Polar(5, 3.14));
	std::cout << a - CComplex(CComplex::Cartesian(-5, 0));
	return 0;
}
