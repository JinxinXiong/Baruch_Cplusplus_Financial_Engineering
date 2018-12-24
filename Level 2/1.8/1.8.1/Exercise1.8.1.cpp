//Exercise1.8.1.cpp
//C-program that prints the contents of a struct called Article
//
//Author: Devon Kaberna
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//Header file that contains definition for a struct called Article
//Also contains function declaration for the function Print() 
#include "Article.hpp"    

int main()
{
	struct Article a = { 15, 25, "Test description" };  //contents of struct article initialized here
	struct Article* pt_a = &a; //create a pointer to article variable
	
	Print(pt_a); //call Print() function and pass in the pointer to article

	return 0;
}

//Purpose is to print the contents of article struct
//Function gets the address of the structure as a parameter
//Nothing returned from this function
void Print(struct Article* pt_a)
{
	//Output contents of the article struct
	printf("Article number is: %d\n", pt_a->Number);
	printf("Article quantity is: %d\n", pt_a->Qty);
	printf("Article description is: %s\n", pt_a->Description);
}