//Exercise1.9.2.cpp
//C-program that reads the characters from the keyboard and is written to a file.
//User provides name of the file
//
//Author: Devon Kaberna
//

//Need to use _CRT_SECURE_NO_WARNINGS to avoid compilation errors. Seems that scanf is now deprecated.
#define _CRT_SECURE_NO_WARNINGS

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	FILE* fp;  //setup file variable
	char filename[50] ="FileName.txt"; //Default name of file
	int c = 0; //The input characters

	printf("Input name of the file: "); 	//Print intro text and ask user to specify filename
	scanf("%s", filename);

	fp = fopen(filename, "w");  //now create a file

	//Prompt user to start typing
	printf("\nStart typing random characters. Press enter to display. Exit with a period (.)\n");

	//NOTE: having difficulty with ^A, so chose to use the period ascii character instead!!
	while ((c = getchar()) != '.') {
		fputc(c, fp);  //write whatever user typed into the file
	}
	printf("CTRL + A is a correct ending.\n");  //Now display this message following exit from while loop

	fclose(fp);  //Close the file
	return 0;
}