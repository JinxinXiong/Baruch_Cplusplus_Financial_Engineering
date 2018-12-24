// Article.hpp
//Defines a struct definition called Article and function declaration for function called Print()
//
//Author: Devon Kaberna
//

// Preprocessor directive

#ifndef Article_HPP
#define Article_HPP

//struct definition for Article
struct Article
{
	int Number;			//Article Number
	int Qty;			//Article Quantity
	char Description[20];	//Article Description max 20 characters
};

//Function declaration 
//Purpose is to print the contents of article struct
//Function gets the address of the structure as a parameter
//Nothing returned from this function
void Print(struct Article* pt_a);

#endif