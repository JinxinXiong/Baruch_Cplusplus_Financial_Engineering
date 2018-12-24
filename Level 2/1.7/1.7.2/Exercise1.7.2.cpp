//Exercise1.7.2.cpp
//Basic C program that determines the length of the string.
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

#define MAXLINE 30			//MAXLINE constant of 30

//Function declaration 
//Purpose is to determine the length of the string
//str is an array up to 30 chars + \0
//returns length of the string
int Length(char str[]);

int main()
{
	char string[MAXLINE + 1]; // Line of maximum 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	//exit upon Ctrl-z (often written as ^Z). 
	while ((c = getchar()) != EOF && i<MAXLINE && c!= 26)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

//Purpose is to determines the length of the string
//str is an array up to 30 chars + \0
//returns length of the string
int Length(char str[]) 
{
	int count = 0;  //variable used to keep track of length of string

	//increment the counter until reaching '\0'
	while (str[count] != '\0') {
		count++;
	}

	return count;
}