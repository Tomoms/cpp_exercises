#include <cmath>

#include "Vertex.hpp"

Vertex::Vertex(double x, double y): x{x}, y{y}
{
}

double Vertex::getX()
{
	return x;
}

double Vertex::getY()
{
	return y;
}

double Vertex::get_distance_to(const Vertex& other)
{
	double deltaX = other.x - x;
	double deltaY = other.y - y;
	return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

std::ostream& operator<<(std::ostream& os, const Vertex& vertex)
{
	os << "(" << vertex.x << "," << vertex.y << ")";
	return os;
}
