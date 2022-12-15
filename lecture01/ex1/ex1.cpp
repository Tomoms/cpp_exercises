#include <iostream>
#include <cmath>

struct CCoeffs {
	double a, b, c;
};

int main()
{
	CCoeffs coeffs;
	std::cin >> coeffs.a >> coeffs.b >> coeffs.c;
	double delta = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
	bool imaginary{0};
	double delta_sqrt[2];

	if (delta >= 0) {
		delta_sqrt[0] = std::sqrt(delta);
		delta_sqrt[1] = -delta_sqrt[0];
	} else {
		imaginary = 1;
		delta_sqrt[0] = std::sqrt(-delta);
		delta_sqrt[1] = -delta_sqrt[0];
	}

	double re[2];
	double im[2];

	re[0] = (-coeffs.b) / (2 * coeffs.a);
	re[1] = re[0];
	if (imaginary) {
		im[0] = delta_sqrt[0] / (2 * coeffs.a);
		im[1] = delta_sqrt[1] / (2 * coeffs.a);
	} else {
		re[0] += delta_sqrt[0] / (2 * coeffs.a);
		re[1] += delta_sqrt[1] / (2 * coeffs.a);
	}

	std::cout << "Roots are ";
	std::cout << re[0];
	if (imaginary) {
		std::cout << " + i * " << im[0];
	}
	std::cout << " and ";
	std::cout << re[1];
	if (imaginary) {
		std::cout << " + i * " << im[1];
	}

	std::cout << std::endl;
	return 0;
}
