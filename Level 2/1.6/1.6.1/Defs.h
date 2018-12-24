// Defs.h
// Provides a simple example of the use of macros
//
//Author: Devon Kaberna
//

// Preprocessor directive
#ifndef Defs_H
#define Defs_H

#define PRINT1(a) printf("%c\n", a)  //definition for PRINT1; Variable a gets its value in the function main()
#define PRINT2(a, b) printf("%c, %c\n", a, b) //definition for PRINT2; Variable a and b gets their value in the function main()

#endif