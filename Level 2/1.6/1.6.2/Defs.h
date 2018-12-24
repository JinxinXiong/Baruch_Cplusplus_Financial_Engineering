// Defs.h
// Provides a simple example of the use of two macros,  MAX2(x,y) and MAX3(x,y,z).
//These macros must return the maximum value of the given arguments. 
//Let the macro MAX3 make use of the macro MAX2.
//
//Author: Devon Kaberna
//

// Preprocessor directive
#ifndef Defs_H
#define Defs_H

#define MAX2(x,y) (((x)>(y))?(x):(y)) //definition for MAX2; Variable x and y gets their value in the function main()
#define MAX3(x,y,z) (((MAX2(x,y))>(z))?(MAX2(x,y)):(z)) //definition for MAX3; Variable x, y, and z gets their value in the function main()

#endif