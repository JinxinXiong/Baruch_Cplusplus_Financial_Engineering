// TestColonSyntax.cpp
//
// Objective is to test performance associated with using colon (:) syntax and associated member initializer list
// rather than member assignment  
//
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)

#include "Circle.hpp"	//Header file that contains definition for object called Circle
using DevonKaberna::CAD::Circle;  //Using declaration for using a single class (Circle)

#include "Line.hpp"		//Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)

#include "Array.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include <iostream>  // C++ style I/O

int main()
{
	//Line l; 
	/* 
	When Line class does NOT use : syntax
	-->Number of point constructor, destructor, and assignment calls = 8.
	When Line class does use : syntax
	-->Number of point constructor, destructor, and assignment calls = 4.

	Basically, there's a significant increase in performance between using member initializer list vs member assignment.
	Performance slows using member assignment because the member data must first initialized with default constructors, and then 
	reaassigned via assignment operator with actual values.  When using member initializer, the constructor (in my case an overload constructor)
	will be called once and the object will be constructed and initialized in one operation
	*/


	// Create a point
	Point p1(10.0, -20.0);
	Point p2(5.0, 10.0);

	//Now let's test the overloaded assignment operator for class line
	Point p3(10.0, 11.0);
	Point p4(12.0, 13.0);

	// Let's instantiate l_1 and l_2 of type Line
	Line l_1(p3, p4);
	Line l_2;

	l_2 = l_1; //Deep copy assignment

	//Now let's test the overloaded assignment operator for class circle
	Circle c_1(5.0, p1);
	Circle c_2(99.0, Point(88, 80));
	Circle c_3;


	return 0;
}