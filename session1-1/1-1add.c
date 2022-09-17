#include <stdio.h>

#define NUM_ELEMENTS 7

int add(int integersArray[], int length)
{
	int result = 0;

	for(int i = 0; i < length; i++){
		result = result + integersArray[i];
	}

	return result;
}


int main()
{
	int vector[NUM_ELEMENTS] = { 2, 5, -2, 9, 12, -4, 3 };
	int result;

	result = add(vector, NUM_ELEMENTS);
	printf("The addition is: %d\n", result);
	return 0;
}
