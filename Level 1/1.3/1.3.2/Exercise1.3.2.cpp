//Exercise1.3.2.cpp
//Basic C program that calculates the surface of a triangle with one 90 degree angle.
//
//Author: Devon Kaberna
//

//Need to use _CRT_SECURE_NO_WARNINGS to avoid compilation errors. Seems that scanf is now deprecated.
#define _CRT_SECURE_NO_WARNINGS

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int base, height; //input parameters entered by user
	base = 0;
	height = 0;

	printf("Enter the base: ");  //prompt user to enter base
	scanf("%i", &base);

	printf("Enter the height: ");  //prompt user to enter height
	scanf("%i", &height);
	
	printf("Surface area is: %f \n", ((.5*height) * base));  //output with calculation

	return 0;
}