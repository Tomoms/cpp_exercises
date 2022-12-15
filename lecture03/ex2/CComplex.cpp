#include <cmath>
#include <iostream>
#include <ostream>
#include "CComplex.hpp"

CComplex operator+(const CComplex& rhs, const CComplex& lhs)
{
	return CComplex(CComplex::Cartesian(
		rhs.cartesian.x + lhs.cartesian.x,
		rhs.cartesian.y + lhs.cartesian.y
	));
}

CComplex operator-(const CComplex& rhs, const CComplex& lhs)
{
	return CComplex(CComplex::Cartesian(
		rhs.cartesian.x - lhs.cartesian.x,
		rhs.cartesian.y - lhs.cartesian.y
	));
}

CComplex operator*(const CComplex& rhs, const CComplex& lhs)
{
	return CComplex(CComplex::Polar(
		rhs.polar.magnitude * lhs.polar.magnitude,
		rhs.polar.phase + lhs.polar.phase
	));
}

CComplex operator/(const CComplex& rhs, const CComplex& lhs)
{
	return CComplex(CComplex::Polar(
		rhs.polar.magnitude / lhs.polar.magnitude,
		rhs.polar.phase - lhs.polar.phase
	));
}

std::ostream& operator<<(std::ostream& os, const CComplex& number)
{
	os << number.cartesian.x;
	if (number.cartesian.y >= 0) {
		os << " + ";
	} else {
		os << " - ";
	}
	os << "i * " << std::fabs(number.cartesian.y) << std::endl;
	return os;
}

CComplex::CComplex(const Cartesian& cartesian): cartesian(cartesian), polar(0, 0)
{
	cartesianToPolar();
}

CComplex::CComplex(const Polar& polar): cartesian(0, 0), polar(polar)
{
	polarToCartesian();
}

void CComplex::cartesianToPolar()
{
	double magnitude = std::sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y);
	double phase = std::acos(cartesian.x / magnitude);
	polar = CComplex::Polar(magnitude, phase);
}

void CComplex::polarToCartesian()
{
	double x = polar.magnitude * std::cos(polar.phase);
	double y = polar.magnitude * std::sin(polar.phase);
	cartesian = CComplex::Cartesian(x, y);
}
