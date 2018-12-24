//Exercise1.5.4.cpp
//Basic C program that prints a number digit by digit by using the putchar() function. 
//
//Author: Devon Kaberna
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O

//function declaration
//input is an integer which is then printed
void printnumber(int num);

int main()
{
	printnumber(-5000066);  //call printnumber function
	return 0;
}

//Purpose of method is to recursively print a number digit by digit
//input parameter is an integer that is printed
void printnumber(int i)
{
	//Handles negative numbers 
	if (i < 0) {
		i *= -1;
		putchar('-');
	}

	//Uses the modulo operator (%) to determine the digit to print.
	//Uses the division operator ( / ) to calculate the argument for the recursive call
	if ((i / 10) != 0) {
		printnumber((i / 10));  //recursive call to function
		putchar('0' + (i % 10));  //print output
	} else {
		putchar('0' + i);
	}

}