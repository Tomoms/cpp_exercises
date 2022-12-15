#pragma once

class CCoeffs {
public:
	double a, b, c;

	CCoeffs();
	CCoeffs(std::string filename);
	void print();
	void ask_for_input();
};
