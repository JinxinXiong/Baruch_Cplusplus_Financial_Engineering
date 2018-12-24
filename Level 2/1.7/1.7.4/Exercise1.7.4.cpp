//Exercise1.7.4.cpp
//Basic C program that has a function DayName()which can print the day of a given day-number. 
//
//Author: Devon Kaberna
//

//Need to use _CRT_SECURE_NO_WARNINGS to avoid compilation errors. Seems that scanf is now deprecated.
#define _CRT_SECURE_NO_WARNINGS

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//Function declaration 
//Purpose is to print the day of a given day-number
//num_day is a number (0-6) provided by user
//day is an array of day-names, i.e., Sunday, Monday, etc.
//returns the day-name based on num_day
char* DayName(int num_day, char* day[]);

int main()
{
	//Per homework notes, the day-name (1-7) should be written "hard-coded” into the program using an array of strings. 
	//I start the array at 0, rather than 1
	char day_0[10] = "Sunday";
	char day_1[10] = "Monday";
	char day_2[10] = "Tuesday";
	char day_3[10] = "Wednesday";
	char day_4[10] = "Thursday";
	char day_5[10] = "Friday";
	char day_6[10] = "Saturday";
	char* day[7] = {day_0, day_1, day_2, day_3, day_4, day_5, day_6};
	
	int num_day = 0;  //initialize variable used as input by user

	printf("Enter day-number for a given day. 0 starts with Sunday, up to 6 for Saturday:");  //Obtain input from user
	scanf("%d", &num_day);

	printf("Day %d is a %s\n", num_day, DayName(num_day, day));  //Now output the result,calling the  DayName function
	
	return 0;
}

//DayName() function 
//Purpose is to print the day of a given day-number
//num_day is a number (0-6) provided by user
//day is an array of day-names, i.e., Sunday, Monday, etc.
//returns the day-name based on num_day
char* DayName(int num_day, char* day[])
{
	return day[num_day];  //returns the day-name based on num_day
}