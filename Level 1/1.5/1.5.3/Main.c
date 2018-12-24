// Main.c

//Exercise 3
//Basic C program that demonstrates usage of a header file
//
//Author: Devon Kaberna
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include "Print.h"          //include file for Print.h

int main()
{
	print(9);  //call print function and pass value of 9

	return 0;
}