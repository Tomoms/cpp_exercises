#include "Polygon.hpp"

Polygon::Polygon(const Vertex * const vertices, const int nvert): vertices{vertices}, nvert{nvert}
{
}

Polygon::~Polygon()
{
	delete[] vertices;
}

double Polygon::calculate_perimeter()
{
	double perimeter = 0;
	Vertex cur;
	for (int i = 0; i < nvert - 1; i++) {
		cur = vertices[i];
		perimeter += cur.get_distance_to(vertices[i+1]);
	}
	return perimeter;
}

void Polygon::print_vertices()
{
	for (int i = 0; i < nvert; i++) {
		std::cout << "Vertex 1: " << vertices[i] << "\n";
	}
	std::cout << std::endl;
}
