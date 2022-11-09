#include <stdio.h>
#include <string.h>

int main()
{
	int  temp = 5;
	int *aux = NULL;
	*aux = 5;
	memcpy(aux, &temp, sizeof(int));
	printf("P: %ld\n", (long) aux);
}

