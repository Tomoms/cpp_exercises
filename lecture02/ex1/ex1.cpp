#include <iostream>
#include <cmath>

class CCoeffs {
public:
	double a, b, c;

	CCoeffs():a(0), b(0) {};

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

void solve_quadratic_equation(const CCoeffs& coeffs)
{
	double delta = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
	bool complex = delta < 0;
	double abs_delta_sqrt = std::sqrt(std::fabs(delta));

	double re = (-coeffs.b) / (2 * coeffs.a);
	double im = abs_delta_sqrt / (2 * coeffs.a);

	if (complex) {
		std::cout << "Roots are:\t" << re << " + i * " << im << std::endl;
		std::cout << "and:\t\t" << re << " - i * " << im << std::endl;
	} else {
		std::cout << "Roots are:\t" << re + im << std::endl;
		std::cout << "and:\t\t" << re - im << std::endl;
	}
}

int main()
{
	CCoeffs coeffs;
	coeffs.ask_for_input();
	coeffs.print();
	solve_quadratic_equation(coeffs);
	return 0;
}
