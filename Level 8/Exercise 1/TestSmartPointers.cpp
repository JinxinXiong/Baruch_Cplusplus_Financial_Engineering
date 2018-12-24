// TestSmartPointers.cpp
//
// Objective is to create a program that creates an array with shared pointers for shapes. Fill it with various shapes and print them. 
// Check if the shapes are automatically deleted when using shared ptr.
//
// Author: Devon Kaberna
//

#include "Array.hpp" //Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;

#include "Point.hpp" //Header file that contains definition for object called Point
using DevonKaberna::CAD::Point; 

#include "Shape.hpp"	//Header file that contains definition for object called Shape
using DevonKaberna::CAD::Shape;

#include "Circle.hpp" //Header file that contains definition for object called Circle
using DevonKaberna::CAD::Circle;

#include "Line.hpp" //Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;

#include "ArrayException.hpp" //Header file that contains definition for object called ArrayException

#include "boost/shared_ptr.hpp"  // Contains all functionality needed to created shared ptr via boost libraries

#include <iostream>  // C++ style I/O
using namespace std;

// Create an array of pointers to shape objects, and then create a line, circle, and point.
void doRegularPt()
{
		Array<Shape*> arr_sp(3);  // Array of shape pointers
		arr_sp[0] = new Line;
		arr_sp[1] = new Circle;
		arr_sp[2] = new Point;
}

int main()
{

	//************************************************************//
	// First, let's create an array of regular pointers to shape objects, and show that I
	// must delete them manually for them to destruct (even after the array is destructed)
	//************************************************************//
	
	doRegularPt();

	// Should be noted that none of the line, circle, nor point destructors were called, yet the array destructor was called
	// Thus we have a memory leak!

	//************************************************************//
	// Second, let's create an array of smart pointers to shape objects. 
	// Show that the shapes will automatically destruct once the Array destructs
	//************************************************************//

	cout << "Now testing with smart pointers......" << endl << endl << endl;

	// Typedef for a shared pointer to shape and
	// a typedef for an array with shapes stored as shared pointers.
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	try
	{
		ShapeArray shape_array(3); // Initialize variable to store array of smart pointers

		// Now let's put some smart pointers into the array
		shape_array[0] = ShapePtr(new Line());
		shape_array[1] = ShapePtr(new Circle());
		shape_array[2] = ShapePtr(new Point());

		// Now print them out
		for (int i = 0; i < 3; i++)
			shape_array[i]->Print();
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	//************************************************************//
	// At this point we should observe the exact number of constructor messages
	// equals number of destructor messages.  This proves that when the shared_ptr went out of scope
	// it takes care of deleting the shape pointers for us
	//************************************************************//

	return 0;
}