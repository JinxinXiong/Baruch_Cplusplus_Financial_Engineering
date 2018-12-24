// StaticVariableTest.cpp
//
// Objective is to test using static variables for array default size
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

#include "Array.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include "ArrayException.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include <iostream>  // C++ style I/O


int main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	intArray1.DefaultSize(15);
	
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;


	/*
	Following values are printed:
	0
	0
	0
	15
	15
	0
	*/

	/*
	In OOPS, static member variables are shared by all objects of the class...
	But in template-based programming in C++, a static member variable is created for EACH DIFFERENT TYPE
	of template class that is created.  Therefore, the default size for doubleArray will remain as 0.
	*/

	return 0;
}