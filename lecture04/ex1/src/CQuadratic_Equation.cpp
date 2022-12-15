#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "CQuadratic_Equation.hpp"

CQuadratic_Equation::CQuadratic_Equation() : coeffs("coefficients"), roots {0, 0} {};

void CQuadratic_Equation::solve()
{
	auto delta{coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c};
	bool complex{delta < 0};
	double abs_delta_sqrt{std::sqrt(std::fabs(delta))};

	double re{(-coeffs.b) / (2.0f * coeffs.a)};
	double im{abs_delta_sqrt / (2 * coeffs.a)};

	if (complex) {
		roots[0] = {re, im};
		roots[1] = {re, -im};
	} else {
		roots[0] = {re + im};
		roots[1] = {re - im};
	}

	log();
}

void CQuadratic_Equation::print_solution()
{
	std::cout << "Roots are:\t" << roots[0].real() << " + i * " << roots[0].imag() << std::endl;
	std::cout << "and:\t\t" << roots[1].real() << " + i * " << roots[1].imag() << std::endl;
}

void CQuadratic_Equation::log()
{
	std::ofstream outputStream("history");
	if (outputStream) {
		outputStream << coeffs.a << " * x^2 + " << coeffs.b << " * x + "<< coeffs.c << " = 0" << std::endl;
	} else {
		std::cerr << "ERROR: the history file doesn't exist. Quitting." << std::endl;
		exit(EXIT_FAILURE);
	}
}
