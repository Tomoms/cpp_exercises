#include <iostream>

#include "Parser.hpp"

int main(int argc, char **argv)
{
	Parser parser{argc, argv};
	parser.parse();
	std::cout << parser << std::endl;
	return 0;
}
