//Exercise1.7.3.cpp
//Instructed to predict what will be printed on the screen
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialize array
int a[] = { 0, 1, 2, 3, 4 };

/*Here's the output
01234
01234

01234
024

43210
43210
43210
*/

int main()
{
	int i;
	int* p;

	for (i = 0; i <= 4; i++) PRD(a[i]); // 1
	NL;

	for (p = &a[0]; p <= &a[4]; p++) PRD(*p); // 2
	NL;
	NL;

	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); // 3
	NL;

	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4
	NL;
	NL;

	for (p = a + 4; p >= a; p--) PRD(*p); // 5
	NL;

	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); // 6
	NL;

	for (p = a + 4; p >= a; p--) PRD(a[p - a]); // 7
	NL;

	return 0;
}