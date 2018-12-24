// TestPoint.cpp
//
// Objective is to test dynamically creating point objects on the free store, and also test creating an array of points on the free store
//
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{
	// Create some Point objects on the heap and then std::cout them just to verify they were created

	Point* pt = new Point;  // Using default constructor					
	if (pt == nullptr)  // Check what new returns to see if its NULL
		cout << "Error: memory could not be allocated";
	else
		cout << *pt << endl;

	Point* pt_1 = new Point(10.0, 12.0);  // Using overload constructor 
	if (pt_1 == nullptr)  // Check what new returns to see if its NULL
		cout << "Error: memory could not be allocated";
	else
		cout << *pt_1 << endl;

	Point* pt_2 = new Point(15.0, 16.0);  // Using overload constructor 
	if (pt_2 == nullptr)  // Check what new returns to see if its NULL
		cout << "Error: memory could not be allocated";
	else
		cout << *pt_2 << endl;

	Point* pt_3 = new Point(*pt_1);  // Using copy constructor 
	if (pt_3 == nullptr)  // Check what new returns to see if its NULL
		cout << "Error: memory could not be allocated";
	else
		cout << *pt_3 << endl;

	// Let's calculate distance and pass to std::cout
	cout << "Distance is: " << (*pt_1).Distance(*pt) << endl;
	cout << "Distance is: " << (*pt_2).Distance(*pt_3) << endl;

	// Now let's delete all of them
	delete pt;
	delete pt_1;
	delete pt_2;
	delete pt_3;

	// Next let's create an array points
	// First ask user to provide array size
	int size_array = 0;
	cout << "Enter size of array: ";
	cin >> size_array;

	// Now, per homework instructions, let's try create an array on the stack using the entered size
	//Point* pp[size_array];  //Can't compile this, because arrays on stack must have size set at compile time!!

	Point* pp; // Now let's create an array of points
	pp = new Point[size_array];  // Note: we can only use default constructor when creating an array of points on the heap using keyword new
	
	if (pp == nullptr)  // Check what new returns to see if its NULL
		cout << "Error: memory could not be allocated";
	else
	{
		// Just for the heck of it, let's std::cout the entire array just to confirm the array and the correct array size
		for (int i = 0; i < size_array; i++)
		{
			cout << pp[i] << endl;
		}

		delete[] pp; // Now delete the array
	}
	return 0;
}