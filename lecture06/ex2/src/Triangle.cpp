#include <iostream>

#include "Triangle.hpp"

Triangle::Triangle(Vertex a, Vertex b, Vertex c): a{a}, b{b}, c{c}
{
}

void Triangle::print_vertices()
{
	std::cout << "Vertex a: " << a << "\n"
		<< "Vertex b: " << b << "\n"
		<< "Vertex c: " << c << std::endl;
}

double Triangle::calculate_perimeter()
{
	return a.get_distance_to(b) + a.get_distance_to(c) + b.get_distance_to(c);
}
