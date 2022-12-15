#pragma once

#include <vector>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <cmath>

constexpr double get_max_rows()
{
	return std::sqrt(std::numeric_limits<std::size_t>::max());
}

template <class T>
class CMatrix
{
	std::vector<T> elements;
	unsigned long n;

	CMatrix(unsigned long n);
	void validate_n(unsigned long candidate);

public:
	CMatrix() {}
	void read_from_file(const std::string filename);
	void print_to_file(const std::string filename);
	template <class U>
	friend CMatrix<U> operator*(const CMatrix<U>& lhs, const CMatrix<U>& rhs);
};

template <class T>
CMatrix<T>::CMatrix(unsigned long n): n(n)
{
	if (n > get_max_rows()) {
		std::cerr << "Error: number of elements exceeds std::size_t (" << get_max_rows() << "), quitting," << std::endl;
		exit(EXIT_FAILURE);
	}
	elements.resize(n * n);
};

template <class T>
void CMatrix<T>::read_from_file(const std::string filename)
{
	std::ifstream inputStream(filename);
	if (!inputStream) {
		std::cerr << "Error: cannot open input file " << filename << ", quitting." << std::endl;
		exit(EXIT_FAILURE);
	}

	inputStream >> n;
	if (n > get_max_rows()) {
		std::cerr << "Error: number of elements exceeds std::size_t (" << get_max_rows() << "), quitting." << std::endl;
		inputStream.close();
		exit(EXIT_FAILURE);
	}
	elements.resize(n * n);
	for (auto i = 0UL; i < elements.size(); i++) {
		inputStream >> elements[i];
	}
	inputStream.close();
};

template <class T>
void CMatrix<T>::print_to_file(const std::string filename)
{
	std::ofstream outputStream(filename);
	if (!outputStream) {
		std::cerr << "Error: cannot open output file " << filename << ", quitting." << std::endl;
		exit(EXIT_FAILURE);
	}

	outputStream << n;
	for (auto i = 0UL; i < elements.size(); i++) {
		outputStream << " " << elements[i];
	}
	outputStream << std::endl;
	outputStream.close();
};

template <class T>
CMatrix<T> operator*(const CMatrix<T>& lhs, const CMatrix<T>& rhs)
{
	CMatrix<T> result(lhs.n);
	unsigned long cur_row, cur_col;
	for (auto i = 0UL; i < result.elements.size(); i++) {
		cur_row = i / result.n;
		cur_col = i % result.n;
		result.elements[i] = 0;
		for (auto j = 0UL; j < result.n; j++) {
			result.elements[i] += lhs.elements[cur_row * lhs.n + j] * rhs.elements[j * rhs.n + cur_col];
		}
	}
	return result;
};
