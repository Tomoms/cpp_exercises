#pragma once

#include <iostream>
#include <fstream>

template <class T>
class CCoeffs {
public:
	T a, b, c;

	CCoeffs(): a(), b(), c() {};

	CCoeffs(std::string filename)
	{
		if constexpr(std::is_same_v<int, T>){
			std::cout<<"Reading ints..."<<std::endl;
		}
		if constexpr(std::is_same_v<double, T>){
			std::cout<<"Reading doubles..."<<std::endl;
		}
		std::ifstream inputStream(filename);
		if (inputStream) {
			inputStream >> a >> b >> c;
			inputStream.close();
		} else {
			std::cerr << "ERROR: the coefficients file doesn't exist. Quitting." << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	void print()
	{
		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	}

	void ask_for_input()
	{
		std::cout << "Enter a, b and c:" << std::endl;
		std::cin >> a >> b >> c;
	}
};
