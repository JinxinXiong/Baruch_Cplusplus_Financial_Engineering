//Exercise1.3.6.cpp
//Basic C program that shifts any number two places to the right. Input should be an integer
//
//Author: Devon Kaberna
//

//Need to use _CRT_SECURE_NO_WARNINGS to avoid compilation errors. Seems that scanf is now deprecated??
#define _CRT_SECURE_NO_WARNINGS

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int num = 0;  //input used for shifting

	//prompt user to enter number and capture it
	printf("Enter a number: ");
	scanf("%d", &num);

	//shift number two places to right
	num = num >> 2;

	//Output should be the shifted result
	printf("The number shifted two places to the right is: %d \n", num);

	//output an indication of whether a logical or arithmetic shift is performed 
	//(if a 1 or 0 is shifted in at the left side) for the inputted number
	if (num < 0) {
		printf("Input number was negative; arithmetic shift; 1 shifted in at left side.\n");
	} else {
		printf("Input number was positive; logical shift; 0 shifted in at left side.\n");
	}

	return 0;
}

