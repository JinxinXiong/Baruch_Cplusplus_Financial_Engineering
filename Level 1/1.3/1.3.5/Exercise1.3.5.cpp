//Exercise1.3.5.cpp
//Basic C program that clearly shows the difference between --i and i--.
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	//Demonstrates ++i
	for (int i = 0; i < 10;) {
		printf("This is an example of a prefix increment: i=%i \n", ++i);
	}

	//Demonstrates i++
	for (int j = 0; j < 10;) {
		printf("This is an example of a suffix increment: j=%i \n", j++);
	}
	
	return 0;
}

