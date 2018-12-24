//Exercise1.6.2.cpp
//Basic C program that contains two print macro calls. 
//These macros must return the maximum value of the given arguments
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include "Defs.h"			//include file for Defs.h, which contains definitions for MAX2 and MAX3

int main()
{
	//initialize variables that are passed into the MAX2 and MAX3 macros
	double x, y, z;
	x = 3.12;
	y = 1005.3453;
	z = -1.1;

	//Output results from calls to MAX2 and MAX3
	printf("Maximum value of %.3f and %.3f is: %.3f\n", x, y, MAX2(x, y));
	printf("Maximum value of %.3f, %.3f, and %.3f is: %.3f\n", x, y, z, MAX3(x, y, z));

	return 0;
}