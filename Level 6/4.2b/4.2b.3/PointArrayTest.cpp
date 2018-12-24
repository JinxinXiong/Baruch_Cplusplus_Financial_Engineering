// PointArrayTest.cpp
//
// Objective is to test adding Point objects into an array called PointArray, which is derived from Array with template argument set to Point.
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)
//
//#include "Circle.hpp"	//Header file that contains definition for object called Circle
//using DevonKaberna::CAD::Circle;  //Using declaration for using a single class (Circle)
//
//#include "Line.hpp"		//Header file that contains definition for object called Line
//using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)
//
//#include "Shape.hpp"	//Header file that contains definition for object called Shape
//using DevonKaberna::CAD::Shape;  //Using declaration for using a single class (Shape)

//#include "NumericArray.hpp"	//Header file that contains definition for object called NumericArray
//using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include "PointArray.hpp"	//Header file that contains definition for object called PointArray
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include "ArrayException.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include <iostream>  // C++ style I/O

int main()
{
	try
	{
		PointArray PointArray(3);  //Declare PointArray

		// Add some Points objects into the PointArray
		PointArray[0] = Point(40, 50);
		PointArray.SetElement(Point(11, 12), 1);
		PointArray.SetElement(Point(30, 40), 2); 
		
		// Output values to verify
		for (int i = 0; i != PointArray.Size(); i++) cout << PointArray[i] << endl;

		// Now output the total length between points in the array
		cout << PointArray.Length() << endl;
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