#include <iostream> 

#define INT_WIDTH	(sizeof(int) * 8)

int main()
{
	int num;
	std::cin >> num;

	bool digits[INT_WIDTH] = {0};
	int mask{1};
	for (int i = INT_WIDTH - 1; i >= 0; i--) {
		digits[i] = num & mask;
		mask <<= 1;
	}

	std::cout << "Signed binary representation of " << num << ":" << std::endl;
	for (int i = 0; i < INT_WIDTH; i += 4) {
		std::cout << digits[i] << digits[i + 1] << digits[i + 2] << digits[i + 3] << " ";
	}
	std::cout << std::endl;

	return 0;
}
