//Exercise1.3.3.cpp
//Instructed to predict what will be printed on screen, with comments 
//stating the output for each line.
//
//
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int x;

	x = -3 + 4 * 5 - 6;
	printf("x=%d\n", x);
	/*
	(-3) + 20 - 6 = 11
	Output will be: x= 11
	*/

	x = 3 + 4 % 5 - 6;
	printf("x=%d\n", x);
	/*
	(3 + 4) - 6 = 1
	Output will be: x = 1
	*/

	x = -3 * 4 % -6 / 5;
	printf("x=%d\n", x);
	/*
	(-12%-6) /5 = 0/5 = 0
	Output will be: x = 0
	*/

	x = (7 + 6) % 5 / 2;
	printf("x=%d\n", x);
	/*
	(13%5)/2 = 1.5
	Output will be: x = 1.5
	*/

	return 0;
}

