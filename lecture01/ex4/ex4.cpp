#include <iostream>

#define SIZE	10

int main()
{
	int array[SIZE];
	std::cout << "Enter 10 integers:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cin >> array[i];
	}

	int tmp;
	for (int i = 1; i < SIZE; i++) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[i]) {
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}

	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
	return 0;
}
