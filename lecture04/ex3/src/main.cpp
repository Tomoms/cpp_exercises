#include <iostream>

template <class T, class U>
T sum(const T& arg1, const U& arg2)
{
	return arg1 + arg2;
};

template <class T, class... Ts>
T sum(const T& arg, const Ts&... args)
{
	return arg + sum(args...);
};

int main()
{
	std::cout << sum(1.0, 1.009, 1.0, 8) << std::endl;
	return 0;
}
