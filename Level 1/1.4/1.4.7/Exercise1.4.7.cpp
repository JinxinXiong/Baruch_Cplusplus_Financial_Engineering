// Exercise1.4.7.cpp

//Basic C program that that counts how many times number 3 has been typed. 
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int c = 0; //characters entered by user
	int count_num_3 = 0;  //count variables when user enters 3

	printf("Enter some numbers at the prompt:"); //prompt user to start entering numbers

	//reading of characters from the keyboard can be stopped when the shutdown-code ^D (CTRL + D) is entered
	//also put in ascii code for CTRL + Z
	while ((c = getchar()) != 4 && c != 26 && c != EOF) {
		switch (c) {
			case 51:
				count_num_3++;
				break;
		}
	}

	//Output results
	if (count_num_3 > 0) {
		switch (count_num_3) {  //determine how many times user enters 3
			case 1:
				printf("Number three appears one time.\n");
				break;
			case 2:
				printf("Number three appears two times.\n");
				break;
			default:
				printf("Number three appears more than two times.\n");
				break;
		}
	} else {
		printf("Number three does not appear at all.\n");
	}

	return 0;
}