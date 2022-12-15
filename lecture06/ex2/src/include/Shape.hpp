#pragma once

#include "Vertex.hpp"

class Shape
{
public:
	virtual double calculate_perimeter() { return -1; };
	virtual void print_vertices() {};
	virtual ~Shape() {};
};
