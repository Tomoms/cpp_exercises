#include <iostream>

#include "Triangle.hpp"
#include "Polygon.hpp"

int main()
{
	Triangle t {
		Vertex{0, 0},
		Vertex{0, 2},
		Vertex{2, 0}
	};
	t.print_vertices();
	std::cout << t.calculate_perimeter() << std::endl;

	int nvert = 5;
	Vertex *vertices = new Vertex[nvert];
	vertices[0] = Vertex{0, 0};
	vertices[1] = Vertex{0, 3};
	vertices[2] = Vertex{2, 4.5};
	vertices[3] = Vertex{3, 1.5};
	vertices[4] = Vertex{2, 0};
	Polygon polygon{vertices, nvert};
	polygon.print_vertices();
	std::cout << polygon.calculate_perimeter() << std::endl;
	return 0;
}
