// TestExceptionObjects.cpp
//
// Objective is to test setting up some exception handling capabilities - specifically, the bounds checking array
// in the array class.
// In this file, there will be try/catch code blocks to handle the array out of bounds exception
// by catching a generic ArrayException object, and letting polymorphism do its work
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)

#include "Circle.hpp"	//Header file that contains definition for object called Circle
using DevonKaberna::CAD::Circle;  //Using declaration for using a single class (Circle)

#include "Line.hpp"		//Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)

#include "Shape.hpp"	//Header file that contains definition for object called Shape
using DevonKaberna::CAD::Shape;  //Using declaration for using a single class (Shape)

#include "Array.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include <iostream>  // C++ style I/O

int main()
{
	Array array(3); // Initialize array object with size of 3

	// Let's try a round of testing using the try/catch block
	try
	{
		// Now let's add some Point objects to the array using SetElement
		array.SetElement(Point(10.0, 12.0), 0);
		array.SetElement(Point(1, 2), 3); //this should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Let's try another round of testing using the try/catch block
	try
	{
		array.SetElement(Point(2, 3), 1); // This should be fine
		cout << array.GetElement(1); // Should be fine too
		array.SetElement(Point(2, 3), -1); // This should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}
	
	// Let's try another round of testing using the try/catch block
	try
	{
		cout << array.GetElement(0); // Should be fine
		cout << array.GetElement(-1); // Should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Let's try another round of testing using the try/catch block
	// and let's test the array assignment operator
	try
	{
		array[0] = Point(100, 101); // Should be fine
		cout << array[0]; // Should be fine
		array[-1] = Point(200, 201); // Should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Let's try another round of testing using the try/catch block
	// and let's test the array assignment operator
	try
	{
		array[0] = Point(100, 101); // Should be fine
		cout << array[0]; // Should be fine
		array[-1] = Point(200, 201); // Should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Let's try another round of testing using the try/catch block
	// and let's test the const  Overloaded [] operator 
	try
	{
		const Array array_4(1);	// Let's setup a const Array that allocates for one static Point object
		cout << array_4[0] << endl;  // This should call the overloaded [] operator with CONST
		cout << array_4[1] << endl; // This should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	return 0;
}