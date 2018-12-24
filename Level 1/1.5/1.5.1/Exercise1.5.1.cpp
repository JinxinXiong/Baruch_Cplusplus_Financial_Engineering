// Exercise1.5.1.cpp
//Basic C program that calls a function minus(). 
//This function receives two arguments and returns the difference(regular subtraction, not absolute).
//This difference should be printed on screen.
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//function declaration
//Simple subtraction function
//num1 and num2 are int inputs into function
//return difference of two input params
int minus(int num1, int num2);

int main()
{
	int result = 0; //result variable init
	int a = 10;  //first input variable
	int b = 2;  //second input variable

	//display output
	printf("%i minus %i equals: %i \n", a, b, minus(a, b));

	//reset variables and display output
	a = -8;
	b = -6;
	printf("%i minus %i equals: %i \n", a, b, minus(a, b));

	//reset variables and display output
	a = 8;
	b = -10;
	printf("%i minus %i equals: %i \n", a, b, minus(a, b));

	return 0;
}

//Function minus
//Returns difference of num1 and num2
int minus(int num1, int num2)
{
	return num1 - num2;
}