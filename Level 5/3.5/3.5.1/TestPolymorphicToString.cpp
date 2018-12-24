// TestPolymorphicToString.cpp
//
// Objective is to test the new shape base class, and whether inheritance really works.
// Now, Circle, Line, Point all inherit from class Shape. 
// Also, changed function ToString() in base class Shape to be virtual.
//
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)

#include "Circle.hpp"	//Header file that contains definition for object called Circle
using DevonKaberna::CAD::Circle;  //Using declaration for using a single class (Circle)

#include "Line.hpp"		//Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)

#include "Shape.hpp"	//Header file that contains definition for object called Shape
using DevonKaberna::CAD::Shape;  //Using declaration for using a single class (Shape)

#include <iostream>  // C++ style I/O

int main()
{

	// Let's create some objects to work with
	Shape s; // Create shape.
	Point p(10, 20); // Create point.

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; 
	cout << sp->ToString() << endl; 
	/*
	Unlike in 3.4.2, sp now calls the ToString() function of the Point object - not the Shape base class
	This is because ToString() in base class Shape has been declared virtual.  So the Shape* variable now knows
	what type of object it is when assigned the address of the point object.
	*/
	cout << sp->ID() << endl;  // Prints the m_ID of the point object
	cout << p.ID() << endl; // Prints the m_ID of the point object also 
	cout << p.ToString() << endl; // Print pointer object

	return 0;
}