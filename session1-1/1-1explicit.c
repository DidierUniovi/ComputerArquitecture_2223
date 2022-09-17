#include <stdio.h>

int main()
{
	int x = 1;  // 32 bits

	const char *p = (const char*)&x;

	// null char
	printf("%c\n", *p);

	if(*p){
		printf("Little endian\n");
	}
	else{
		printf("Big endian\n");
	}

	return 0;
}
