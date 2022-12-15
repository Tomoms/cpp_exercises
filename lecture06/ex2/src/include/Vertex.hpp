#pragma once

#include <iostream>

class Vertex
{
private:
	double x, y;

public:
	Vertex() {};
	Vertex(double x, double y);
	double getX();
	double getY();
	double get_distance_to(const Vertex& other);
	friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex);
};
