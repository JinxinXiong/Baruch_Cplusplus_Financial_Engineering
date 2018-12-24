//Exercise1.9.1.cpp
//C-program that reads the characters from the keyboard and shows them on screen 
//(the inputted characters should only be displayed when the user hits 'enter', line by line).
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int c; // The input characters

	// Print intro text
	printf("Start typing random characters. Press enter to display. Exit with a period (.)\n");

	//NOTE: having difficulty with ^A, so chose to use the period ascii character instead!!
	while ((c = getchar()) != '.') {
		putchar(c);  //output to screen whatever the user typed
	}

	printf("CTRL + A is a correct ending.\n");  //Now display this message following exit from while loop

	return 0;
}