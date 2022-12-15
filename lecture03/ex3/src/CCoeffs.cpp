#include <iostream>
#include <fstream>
#include <cstdlib>
#include "CCoeffs.hpp"

CCoeffs::CCoeffs():a(0), b(0), c(0) {}

CCoeffs::CCoeffs(std::string filename)
{
	std::ifstream inputStream(filename);
	if (inputStream) {
		inputStream >> a >> b >> c;
		inputStream.close();
	} else {
		std::cerr << "ERROR: the coefficients file doesn't exist. Quitting." << std::endl;
		exit(EXIT_FAILURE);
	}
}

void CCoeffs::print()
{
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}

void CCoeffs::ask_for_input()
{
	std::cout << "Enter a, b and c:" << std::endl;
	std::cin >> a >> b >> c;
}
