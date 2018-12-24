// Print.c
//Basic C program that prints a number
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//Purpose of function is to print value of integer passed as an argument
//input is an integer
//no return value
void print(int i)
{
	printf("%i multipled by 2 is: %i\n", i, (i*2));  //output result
}