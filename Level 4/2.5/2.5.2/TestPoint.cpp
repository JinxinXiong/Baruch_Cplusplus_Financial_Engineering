// TestPoint.cpp
//
// Objective is to test creating an array of pointers of Point objects
//
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{
	int array_size = 3;  // initialize my array size

	Point** pp = new Point*[array_size];  // An array of Point pointers with 3 elements on the heap

	// Check what new returns to see if its NULL
	if (pp == nullptr)
		cout << "Error: memory could not be allocated";
	else
	{
		for (int i = 0; i < array_size; i++)
		{
			pp[i] = new Point(10 + i, 20 + i);  // Create for each element in the array a point on the heap, and use other constructors other than default constructor
		}										// Note that I use 10 + i (as an example) just to make sure that each Point object is unique in construction 

		// Iterate the array the print each point in the array
		for (int i = 0; i < array_size; i++)
		{
			cout << *pp[i] << endl;
		}

		// Iterate the array again and delete each point in the array
		for (int i = 0; i < array_size; i++)
		{
			delete pp[i];
		}

		delete[] pp; // now delete the array itself
	}

	return 0;
}