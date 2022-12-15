#include <iostream>
#include "CCoeffs.hpp"

CCoeffs::CCoeffs():a(0), b(0) {}

void CCoeffs::print()
{
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}

void CCoeffs::ask_for_input()
{
	std::cout << "Enter a, b and c:" << std::endl;
	std::cin >> a >> b >> c;
}
