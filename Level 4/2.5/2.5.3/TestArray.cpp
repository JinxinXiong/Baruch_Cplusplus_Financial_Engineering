// TestArray.cpp
//
// Objective is to test creating an array object that manages memory on behalf of the user.
// This Array class will allocate a default number of static Point elements for you, or allow you to designate the size.
// You can then store Point objects in this array, set them manually yourself, and retrieve manually yourself.
// You can also copy one array to another, as well as assign arrays to one another.
// 
// Author: Devon Kaberna

#include "Point.hpp"		//Header file that contains definition for object called Point
#include "Array.hpp"		//Header file that contains definition for object called Array

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{
	// Create some Point objects on the stack
	Point pt;
	Point pt_2(100.0, 101.0);
	Point pt_3(900.0, 901.0);

	Array array(4); // Initialize array object with size of 4
	
	// Now let's add the Point objects to the array using SetElement
	array.SetElement(Point(10.0, 12.0), 0);
	array.SetElement(pt_2, 1);
	array.SetElement(pt_3, 2);

	// Let's test [] operator that writes
	array[3] = pt;

	// Let's output everything to double check
	for (int i = 0; i < array.Size(); i++)
	{
		cout << array[i] << endl;
	}

	// Now let's copy the array over and make sure copy constructor works
	Array array_1(array);

	// Let's output everything to double check
	for (int i = 0; i < array.Size(); i++)
	{
		cout << array[i] << endl;
	}

	// Let's output element 0 and make sure GetElement() works
	cout << array.GetElement(0) << endl;  // Should return Point(10, 12)

	Array array_2(2); // Let's setup another array with size of 2 and add two Point objects
	array_2[0] = Point(69, 99);
	array_2[1] = Point(29, 39);

	// Let's output everything and make sure GetElement() works
	for (int i = 0; i < array_2.Size(); i++)
	{
		cout << array_2.GetElement(i) << endl;
	}

	// Now let's assign array_2 to array and make sure assignment overload operator worked
	// Since array_2 size is only 2 versus array's original size of 4, make sure it worked
	array = array_2;

	cout << "Array size is: " << array.Size() << endl; //Let's output size and make sure it's 2

	for (int i = 0; i < array.Size(); i++)
	{
		cout << array.GetElement(i) << endl;
	}

	// Testing array out of bounds functionality in function 
	// Should return Point (69, 99)
	cout << array.GetElement(4) << endl;

	// Testing array out of bounds functionality in [] overload operator
	// Should return Point (69, 99)
	cout << array[10] << endl;

	// Now let's test creating array using default constructor, which is 10
	Array array_3;
	cout << "Array size is: " << array_3.Size() << endl; //Let's output size and make sure it's 10

	// Let's add an element to it
	Point pt_4(505, 605);
	array_3.SetElement(pt_4, 0);

	// Now let's output everything
	for (int i = 0; i < array_3.Size(); i++)
	{
		cout << array_3.GetElement(i) << endl;
	}

	const Array array_4(1);	// Let's setup a const Array that allocates for one static Point object
	//array_4[0] = Point(1, 2);	 // Makes sense that I cannot assign, as array_4 is a CONST object. The [] function cannot change the state of the object and must also be CONST
	cout << array_4[0] << endl;  // This should call the overloaded [] operator with CONST

	Array array_5;
	array_5 = array_5;  // This is self-assignment; We want to make sure = operator precludes self-assignment.  Output from that function should indicate this.

	Array array_6 = array_5;   // Calls copy constructor, same as "Array array_6(array_5);

	return 0;
}