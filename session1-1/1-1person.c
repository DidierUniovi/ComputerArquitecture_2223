#include <stdio.h>
#include <string.h>

struct _Person
{
	char name[30];
	int heightcm;
	double weightkg;
};

// This abreviates the type name
typedef struct _Person Person;
typedef Person* PPerson;

int main(int argc, char* argv[])
{
	Person Peter;

	// Javier is a pointer to a Person Struct
	PPerson pJavier;
	pJavier = &Peter;

	strcpy(Peter.name, "Peter");
	Peter.heightcm = 175;
	Peter.weightkg = 78.7;

	pJavier->weightkg = 83.2;

	printf("Peter's height: %d cm; Peter's weight: %.2f kg\n", 
		Peter.heightcm, Peter.weightkg);

	return 0;
}
