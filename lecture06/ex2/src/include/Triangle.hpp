#pragma once

#include "Shape.hpp"

class Triangle : public Shape
{
private:
	Vertex a, b, c;

public:
	Triangle(Vertex a, Vertex b, Vertex c);
	~Triangle() {};
	void print_vertices() override;
	double calculate_perimeter() override;
};
