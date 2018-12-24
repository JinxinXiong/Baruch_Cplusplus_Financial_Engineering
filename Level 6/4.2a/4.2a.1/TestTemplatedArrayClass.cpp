// TestTemplatedArrayClass.cpp
//
// Objective is to test a templated array class that stores Point objects.
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)

//#include "Circle.hpp"	//Header file that contains definition for object called Circle
//using DevonKaberna::CAD::Circle;  //Using declaration for using a single class (Circle)
//
//#include "Line.hpp"		//Header file that contains definition for object called Line
//using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)
//
//#include "Shape.hpp"	//Header file that contains definition for object called Shape
//using DevonKaberna::CAD::Shape;  //Using declaration for using a single class (Shape)

#include "Array.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include "ArrayException.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include <iostream>  // C++ style I/O

int main()
{
	Array<Point> points(3);  // This time we will instantiate class Array with type Point

	// Let's try a round of testing using the try/catch block
	try
	{
		// Now let's add some Point objects to the array using SetElement
		points.SetElement(Point(10.0, 12.0), 0);
		for (int i = 0; i != 3; i++) cout << points[i] << endl;

		cout << (points[0] + points[1]) << endl;  // Let's do some basic addition and multiplcation operators
		cout << (points[0]*3) << endl;

		cout << points.GetElement(0); // Should be fine
		points[0]= Point(100, 101); // Should be fine
		cout << points[0]; // Should be fine

		// Now let's copy the array over and make sure copy constructor works
		Array<Point> points_1(points);  
		
		// Let's output everything to double check
		for (int i = 0; i < points_1.Size(); i++) cout << points_1[i] << endl;

		// Let's test [] operator that writes
		points_1[2] = Point(777, 888);

		// Let's output everything to double check
		for (int i = 0; i < points_1.Size(); i++) cout << points_1[i] << endl;

		const Array<Point> array_4(1);	// Let's setup a const Array that allocates for one static Point object
		//array_4[0] = Point(303, 404);  // Makes sense that I cannot assign, as array_4 is a CONST object. The [] function cannot change the state of the object and must also be CONST
		cout << array_4[0] << endl;  // This should call the overloaded [] operator with CONST

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