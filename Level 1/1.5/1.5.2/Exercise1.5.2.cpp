// Exercise1.5.2.cpp
//Basic C program that prints the factorials of a number.
//Example -- 6!(six factorial) is the same as 6 * 5 * 4 * 3 * 2 * 1
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//function declaration
//Simple recursive function
//integer is input into recursive function for factorial
//return number from recursive function call
int recursion(unsigned int num);

int main()
{
	int start_num = 6;  //use this as starting point for recursion
	
	printf("%i! is the same as ", start_num);  //print output
	recursion(start_num);  //call recursion function

	return 0;
}

//Simple recursive function
//integer is input into recursive function for factorial
//returns number from recursive function call and also prints each number in the factorial
int recursion(unsigned int i)
{
	if (i == 0) {
		printf("%i\n", i);
		return 1;
	} else if (i == 1) {
		printf("%i\n", i);
		return 1;
	} else {
		printf("%i * ", i);
		return recursion(i - 1);
	}
}