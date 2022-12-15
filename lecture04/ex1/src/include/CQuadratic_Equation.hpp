#pragma once

#include <complex>
#include "CCoeffs.hpp"

class CQuadratic_Equation {
public:
	CCoeffs<int> coeffs;
	std::complex<double> roots[2];

	CQuadratic_Equation();
	void solve();
	void print_solution();
	void log();
};
