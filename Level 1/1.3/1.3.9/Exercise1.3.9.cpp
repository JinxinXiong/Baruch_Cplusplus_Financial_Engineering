//Exercise1.3.9.cpp
//Instructed to predict what the following program prints on screen(provide a code file with comments stating the output for each line).
//Author: Devon Kaberna
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int x = 1;
	int y = 1;
	int z = 1;

	x += y += x;
	/*
	y = 2
	x = 3
	*/
	printf("%d\n\n", (x<y) ? y : x);
	//Output is: 3


	printf("%d\n", (x<y) ? x++ : y++);
	//Output is: 2; y is incremented after value of 2 is printed
	
	printf("%d\n", x);
	//Output is: 3

	printf("%d\n", y);
	//Output is: 3

	return 0;
}



