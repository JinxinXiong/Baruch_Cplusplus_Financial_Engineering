//Exercise1.4.3.cpp
//Basic C program that asks for text input from the keyboard. 
//The output of this program should be the amount of characters, the amount of words and the amount of newlines that have been typed. 
//Multiple consecutive spaces should not be counted as multiple words.
//This one uses switch-case statement
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include <ctype.h>          //This include file declares the narrow character (char) classification functionality.


int main()
{
	int c = 0; //characters entered by user
	int prev_char = 0; //previous character entered by user
	int count_chars = 0;  //count of characters
	int count_words = 0; //count of words
	int count_newlines = 0;  //count of newlines

	//prompt user to enter text
	printf("Enter some text at the prompt:");

	//reading of characters from the keyboard can be stopped when the shutdown-code ^D (CTRL + D) is entered
	//also put in ascii code for CTRL + Z
	while ((c = getchar()) != 4 && c != 26 && c != EOF) {
		switch (isspace(c)) {  //check if character is a space
		  case 0:  //in this case 0 indicates false from isspace()
			switch (isspace(prev_char) >=1) {  //check if previous character is a space, if so increment words counter
			  case 1: count_words++;
			    break;
			}
			switch (prev_char) {  
			  case 0: count_words++;
				break;
			}
		}
		//if ascii is 10 or 13 for new lines, increment count of newlines
		switch (c) {
		  case 10: count_newlines++;  
			break;
		  case 13: count_newlines++;
			break;
		  default: 
			switch (prev_char) {
			  case 0: count_newlines++;
				break;
			}
		}
		count_chars++;  //incement character counter
		prev_char = c;
	}

	//Display output
	printf("Amount of characters is: %d \n", count_chars);
	printf("Amount of words is: %d \n", count_words);
	printf("Amount of newlines is: %d \n", count_newlines);

	return 0;
}