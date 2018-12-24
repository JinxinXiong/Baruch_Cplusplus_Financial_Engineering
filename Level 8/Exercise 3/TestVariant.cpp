// TestVariant.cpp
//
// Objective is to create a program that works with Variants.   
// Prompts user to choose a shape. Chosen value will be created and then returned to user as a variant of type MyShapeType
// Following, will move the variant's coordinates by 10 and 20, respectively, by using apply_visitor().
//
// Author: Devon Kaberna
//

#include "Point.hpp" //Header file that contains definition for object called Point
using DevonKaberna::CAD::Point; 

#include "Circle.hpp" //Header file that contains definition for object called Circle
using DevonKaberna::CAD::Circle;

#include "Line.hpp" //Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;

#include "boost/variant.hpp"  // Contains all functionality needed to create variants
using boost::variant;   // Using declaration, for readability purposes

#include "Visitor.hpp"  // Contains all functionality needed to create Visitor object
using DevonKaberna::CAD::Visitor;  // Using declaration, for readability purposes

#include <iostream>  // C++ style I/O
using namespace std;

// Prompts user to choose a shape
// Chosen value will be created and then returned to user as a variant of type variant<Point, Line, Circle>
boost::variant<Point, Line, Circle> ReturnShape()
{
	boost::variant<Point, Line, Circle> myType;
	int shape_type = 0;  // To be used for input

	cout << "What shape type to create (1=Point, 2=Line, or 3=Circle): " << endl;  // Prompt user
	cin >> shape_type;  // Obtain input

	switch (shape_type)  // Determine which variant to return
	{
	case 1:
		myType = Point(11.1, 12.2);  // Create a Point and return it to function caller
		break;
	case 2:
		myType = Line(Point(5.5, 6.5), Point(7.5, 8.5));  // Create a Line and return it to function caller
		break;
	case 3:
		myType = Circle(1.1, Point(9.5, 10.5));  // Create a Circle and return it to function caller
		break;
	}

	return myType;  // Now return the variant
}

int main()
{
	// Create a typedef for a ShapeType variant that contains a Point, Line, or Circle
	typedef boost::variant<Point, Line, Circle> MyShapeType;
	MyShapeType test_variant = ReturnShape();  // Prompt user to choose a shape, returning the variant

	cout << "Variant chosen is: " << test_variant << endl << endl;  // Output result

	Line lnA;  // Try to get the value out of the variant using boost::get<T>()
	try
	{
		lnA = boost::get<Line>(test_variant);  // This will error at run-time if I didn't choose line in the ReturnShape() function above
	}
	catch (boost::bad_get& err) 
	{
		cout << "Error: " << err.what() << endl << endl;
	}

	// Pass in instantiation of Visitor object (Visitor.hpp) and the variant
	boost::apply_visitor(Visitor(10, 20), test_variant);  // Now let's move the variant's coordinates by 10 and 20, respectively, by using apply_visitor function

	cout << "Value after moving variant using delta x=10 and delta y=20 is: " << test_variant << endl;  // Output the result

	return 0;
}