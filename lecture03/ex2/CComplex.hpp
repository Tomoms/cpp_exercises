#pragma once

#include <ostream>

class CComplex
{
public:
	struct Cartesian {
		double x, y;

		inline Cartesian(float x, float y): x(x), y(y) {}
	};

	struct Polar {
		double magnitude, phase;

		inline Polar(float magnitude, float phase): magnitude(magnitude), phase(phase) {}
	};

	CComplex(const Cartesian& cartesian);
	CComplex(const Polar& polar);

private:
	Cartesian cartesian;
	Polar polar;

	void cartesianToPolar();
	void polarToCartesian();
	friend CComplex operator+(const CComplex& rhs, const CComplex& lhs);
	friend CComplex operator-(const CComplex& rhs, const CComplex& lhs);
	friend CComplex operator*(const CComplex& rhs, const CComplex& lhs);
	friend CComplex operator/(const CComplex& rhs, const CComplex& lhs);
	friend std::ostream& operator<<(std::ostream& os, const CComplex& number);
};
