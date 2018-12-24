//Exercise1.3.4.cpp
//Basic C program that that uses the fact that 0 (zero) is interpreted as FALSE and non-zero is interpreted as TRUE.
//Uses the ?: operator to print if someone is married or not.
//
//Author: Devon Kaberna
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int married = 2; //variable used for testing ?: operator

	//output
	printf("Is this person married: %i \n",  married ? 1 : 0);

	return 0;
}

