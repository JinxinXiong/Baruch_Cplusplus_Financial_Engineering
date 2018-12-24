//Exercise1.3.7.cpp
//Basic C program that efficiently multiplies a number by a factor 2 to the power n. 
//
//1 shift to the left is the same as multiplying by 2.
//2 shifts to the left are the same as multiplying by 4.
//3 shifts to the left are the same as multiplying by 8.
//Author: Devon Kaberna
//

//Need to use _CRT_SECURE_NO_WARNINGS to avoid compilation errors. Seems that scanf is now deprecated.
#define _CRT_SECURE_NO_WARNINGS

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	//input parameters entered by user
	int number = 0;
	int n = 0;

	//prompt user to enter number
	printf("Enter a number: ");
	scanf("%d", &number);

	//prompt user to enter n
	printf("Enter a number for n (i.e., 2 to the n): ");
	scanf("%d", &n);

	number = number << n;  //shift number based on n, which is same as multiplying by 2 to the power n

	//output result
	printf("The result is: %d \n", number);

	return 0;
}

