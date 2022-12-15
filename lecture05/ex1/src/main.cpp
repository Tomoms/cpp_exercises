#include <iostream>
#include "CMatrix.hpp"

int main()
{
	CMatrix<int> A, B;

	A.read_from_file("A.txt");
	B.read_from_file("B.txt");
	auto C = A * B;
	C.print_to_file("C.txt");

	return 0;
}
