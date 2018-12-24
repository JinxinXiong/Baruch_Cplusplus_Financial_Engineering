// Macro.c
//Basic C program that contains two print macro calls. 
//The first prints the variable a, the second prints the variables a and b. 
//Printing happens by the use of the PRINT1 and PRINT2 macros that accept arguments. 
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include "Defs.h"			//include file for Defs.h

int main()
{
	PRINT1('A'); //Calls PRINT1, which is a macro defined in Defs.h
	PRINT2('B','C'); //Calls PRINT2, which is a macro defined in Defs.h

	return 0;
}
