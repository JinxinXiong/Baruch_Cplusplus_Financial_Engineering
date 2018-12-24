// TestShapeBaseClass.cpp
//
// Objective is to test the new shape base class, and whether inheritance really works.
// Now, Circle, Line, Point all inherit from class Shape. 
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
	// Let's test some inheritance functionality first

	// Let's start out by creating some point objects
	Point p_1(100, 101);
	Point p_2(200, 201);

	p_1 = p_2; // p_1 should have same members and m_ID as p_2
	cout << p_1.ID() << endl;  // Print ID of point p_1
	cout << p_2.ID() << endl;  // Print ID of point p_2
	// Indeed we see that m_ID are the same for both now

	// Let's create some circle objects 
	Circle c_1(5.0, p_1);
	Circle c_2(99.0, p_2);

	cout << c_1.ToString() << endl; // Print Circle
	cout << "Circle ID: " << c_1.ID() << endl; // ID of the Circle.

	c_2 = c_1;	// c_2 should have same members and m_ID as c_1
	cout << c_1.ID() << endl;
	cout << c_2.ID() << endl;
	// Indeed we see that m_ID are the same for both now

	// Now let's answer the questions embedded in the comments below
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.n
	cout << s.ToString() << endl; // Print shape.
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
	/*Answer to previous question is yes , the public member of the base class Shape, which is ID()
	becomes part of the public interface of the derived class, Point. In other words, the 
	Point class inherits the base functionality from Shape	
	*/
	
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?
	/*Answer to previous question is yes , the public member of the base class Shape, which is ID()
	becomes part of the public interface of the derived class, Line. In other words, the
	Line class inherits the base functionality from Shape
	*/

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?
	cout << sp->ToString() << endl; // What is printed?
	/*
	Yes, it is possible for the pointer of type shape to be given the address of a Point object.
	Reason is because Point IS A Shape.  But this cannot be reversed, meaning, Shape IS A Pointer - that won't work.
	It will call the ToString() function of the Shape class, but print the ID of the Point class.
	This is because the compiler doesn't really know what type of object the Shape* variable is actually pointing to.
	*/
	
	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
										   // the base class assignment in point?
	/*
	Answer to previous question is NO, ID is not copied if one does not call the base class assignment operator in point.  
	If you create an override function (i.e., same function as in base class with same signature) such as the assignment operator,
	the compiler will not automatically call the base class assignment operator.  You must explicitly call it from
	the derived class assignment operator member function
	*/

	return 0;
}