//Exercise1.3.8.cpp
//Basic C program that uses assignment-operators.
//Supposed to predict what will be printed on screen (provide a code file with comments stating the output for each line)
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int x = 2;
	int y;
	int z;

	x *= 3 + 2;
	printf("x=%d\n", x);
	/*
	x*=5
	x=10
	*/

	x *= y = z = 4;
	printf("x=%d\n", x);
	/*
	x=40
	*/

	x = y == z;
	printf("x=%d\n", x);
	/*
	x = 1
	*/

	return 0;
}

