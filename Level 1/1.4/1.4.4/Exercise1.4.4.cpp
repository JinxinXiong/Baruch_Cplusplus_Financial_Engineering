// Exercise1.4.4.cpp
//Basic C program that that prints two columns on the screen with the temperature in degrees Fahrenheit and the equivalent temperature in degrees Celsius.
//
//Author: Devon Kaberna
//

//Need to use _CRT_SECURE_NO_WARNINGS to avoid compilation errors. Seems that scanf is now deprecated.
#define _CRT_SECURE_NO_WARNINGS

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	//input variables
	int degree_step = 20;  //degree step initialized
	int start_f = 0; //start fahrenheit
	int end_f = 0;  //ending fahrenheit
	int current_f = 0;  //current fahrenheit
	double celsius = 0.0; //celsius variable initialized

	printf("Enter the start temp in Fahrenheit: ");  //prompt user to enter start temp in fahrenheit
	scanf("%i", &start_f);

	printf("Enter the end temp in Fahrenheit: ");  //prompt user to enter end temp in fahrenheit
	scanf("%i", &end_f);

	printf("Enter the step size: ");  //prompt user to enter degree step 
	scanf("%i", &degree_step);

	//The left column shows the temperature in Fahrenheit. The right column shows the temperature in Celsius.
	printf("Fahrenheit\tCelsius\n");

	while (start_f <= end_f) {  //loop until start fahrenheit is same or greater than end fahrenheit
		celsius = (((double)5) / 9) * (current_f - 32); //calc celcius
		printf("%i\t%10.1f \n", current_f, celsius);  //print current fahrenheit and celsius
		
		current_f += degree_step; //update fahrenheit temp
		start_f += degree_step;  //update starting fahrenheit temp
	}
	return 0;
}