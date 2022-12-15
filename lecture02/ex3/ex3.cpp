#include <iostream> 

#define SIZE	10

void print_array(int array[SIZE], int i)
{
	if (i == SIZE)
		return;

	std::cout << array[i] << ", ";
	print_array(array, i + 1);
}

int main()
{
	int arr[SIZE];
	std::cout << "Enter " << SIZE << " integers:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cin >> arr[i];
	}
	print_array(arr, 0);
	std::cout << std::endl;
	return 0;
}
