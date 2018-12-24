//Exercise1.7.1.cpp
//Basic C program that must exchange the value of two variables via a functin called Swap(). 
//For example: if i=123 and j=456, then i=456 and j=123 after Swap has been called
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//Function declaration 
//Purpose is to exchange the value of the two variables, x and y
//x and y are integers used for the exchange process
//Nothing is returned, because the function does its work via pointers
void Swap(int* x, int* y);

int main()
{
	//initialize variables passed into the Swap function
	int x = 123;
	int y = 456;

	//print values of x and y prior to function call
	printf("Value of x originally was %d.\n", x);
	printf("Value of y originally was %d.\n", y);

	//call function Swap, and pass in x and y via pointers
	//function should switch the values of  the variables
	Swap(&x, &y);
	
	//show output of variables x and y
	printf("Value of x after calling Swap() is now %d.\n", x);
	printf("Value of y after calling Swap() is now %d.\n", y);

	return 0;
}

//Purpose is to exchange the value of the two variables, x and y
//x and y are integers used for the exchange process
//Nothing is returned, because the function does its work via pointers
void Swap(int* x, int* y)
{
	//variables used for temporary storage purposes
	int temp_x = 0, temp_y = 0;  
	
	//now exchange the values
	temp_x = (int)(*y);
	temp_y = (int)(*x);

	//assign the exchanged values back to x and y via a pointer
	(*x) = temp_x;
	(*y) = temp_y;
}