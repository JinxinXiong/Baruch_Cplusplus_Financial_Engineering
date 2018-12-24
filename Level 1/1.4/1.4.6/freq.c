// freq.c
//
// Exercise 6
//Basic C program that that counts how many times each of the numbers 0-4 have been typed. 
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int c = 0;  //characters entered by user

	//count variables when user enters 0-4, as well as any other character
	int count_num_0 = 0;
	int count_num_1 = 0;
	int count_num_2 = 0;
	int count_num_3 = 0;
	int count_num_4 = 0;
	int count_num_other = 0;

	printf("Enter some numbers at the prompt:");  //prompt user to start entering numbers

	//reading of characters from the keyboard can be stopped when the shutdown-code ^D (CTRL + D) is entered
	//also put in ascii code for CTRL + Z
	while ((c = getchar()) != 4 && c != 26 && c != EOF) {
		switch (c) {
			case 48: 
				count_num_0++;
				break;
			case 49: 
				count_num_1++;
				break;
			case 50: 
				count_num_2++;
				break;
			case 51: 
				count_num_3++;
				break;
			case 52: 
				count_num_4++;
				break;
			default:count_num_other++;
		}
	}

	//Output results
	printf("Count of number 0 is: %d \n", count_num_0);
	printf("Count of number 1 is: %d \n", count_num_1);
	printf("Count of number 2 is: %d \n", count_num_2);
	printf("Count of number 3 is: %d \n", count_num_3);
	printf("Count of number 4 is: %d \n", count_num_4);
	printf("Count of all other characters: %d \n", count_num_other);

	return 0;
}