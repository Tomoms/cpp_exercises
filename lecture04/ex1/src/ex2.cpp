#include "CQuadratic_Equation.hpp"

int main()
{
	CQuadratic_Equation eq;
	eq.coeffs.print();
	eq.solve();
	eq.print_solution();
	return 0;
}
