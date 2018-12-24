// TestTemplateMethodPattern.cpp
//
// Objective is to test the inner workings of the template method pattern.
// Print() has been added to the base class Shape.  This function is inherited in all derived classes, which in turn,
// will polymorphically (if that's even a word) call their own respective ToString() function.
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
	// Let's create some Shape* pointers and assign them to Line, Point, and Circle objects.
	Shape* shapes[4];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Circle;
	shapes[3] = new Point(3.4, 5.6);

	//shapes[4] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	for (int i = 0; i != 4; i++) shapes[i]->Print();  // Call the Print() function implemented in base class Shape
	for (int i = 0; i != 4; i++) delete shapes[i];  // Now delete all of the objects

	return 0;
}