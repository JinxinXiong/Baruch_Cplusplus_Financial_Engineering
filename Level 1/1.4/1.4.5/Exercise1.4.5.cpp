// Exercise1.4.5.cpp
//Basic C program  that prints two columns on the screen with the temperature in degrees Celsius in the left column and degrees Fahrenheit in the right column.
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	double current_f = 0;  //current fahrenheit initialized

	printf("Celsius\t\tFahrenheit\n"); //print a header text

	//Start with 0 degrees Celsius and proceed until 19 degrees Celsius.
	//Take steps of 1 degree.
	for (int i=0; i<=19; i++) {
		current_f = (i * (((double)9) / 5)) + 32;  //calc current fahrenheit
		printf("%i\t%10.1f \n", i, current_f); //Print degrees Fahrenheit with 1 position after the comma.
	}
	return 0;
}