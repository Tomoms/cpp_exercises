#include <stdio.h> 

#define SIZE	10

void print_array(int array[static SIZE], int i)
{
	if (i == SIZE)
		return;

	printf("%d, ", array[i]);
	print_array(array, i + 1);
}

int main()
{
	int arr[SIZE];
	printf("Enter %d integers, one at the time:\n", SIZE);
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &arr[i]);
	}
	print_array(arr, 0);
	printf("\n");
	return 0;
}
