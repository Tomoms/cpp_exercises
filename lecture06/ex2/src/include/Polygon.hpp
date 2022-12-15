#include "Shape.hpp"

class Polygon : Shape
{
private:
	const Vertex * const vertices;
	const int nvert;

public:
	Polygon(const Vertex * const vertices, const int nvert);
	~Polygon();
	double calculate_perimeter() override;
	void print_vertices() override;
};
