// TestNamespaces.cpp
//
// Objective is to test various types of namespaces including explicit namespace, using declaration, using directives, and alias namespaces
// 
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point
#include "Circle.hpp"	//Header file that contains definition for object called Circle

#include "Line.hpp"		//Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)

#include "Array.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

namespace DKC = DevonKaberna::CAD;  // Create an alias namespace DKC

#include <iostream>  // C++ style I/O

int main()
{

	// Create a point
	DevonKaberna::CAD::Point p1(10.0, -20.0);
	DevonKaberna::CAD::Point p2(5.0, 10.0);

	// Let's test negating coordinates
	DevonKaberna::CAD::Point p3 = -p1;
	cout << "Testing negating of " << p1 << " which is: " << p3 << endl;

	//Now let's test the overloaded assignment operator for class line
	DevonKaberna::CAD::Point p11(10.0, 11.0);
	DevonKaberna::CAD::Point p12(12.0, 13.0);
	DevonKaberna::CAD::Point p13(14.0, 15.0);
	DevonKaberna::CAD::Point p14(16.0, 17.0);

	// Let's instantiate l_1 and l_2 of type Line
	Line l_1(p11, p12);
	Line l_2(p13, p14);

	l_2 = l_1; //Deep copy assignment

	// Output the results
	// l_2 and l_1 should both display Point(10, 11) and Point(12, 13)
	cout << "Testing overloaded assignment operator for class line: " << endl;
	cout << l_1 << ", " << l_2;
	cout << "\n\n";

	//Now let's test the overloaded assignment operator for class circle
	// Note that DKC is an alias namespace
	DKC::Circle c_1(5.0, p11);
	DKC::Circle c_2(99.0, p12);

	c_2 = c_1;		//c_2 must make a deep copy of the c_1 members into current object c_1

	// Output the results
	// c_1 and c_2 should show the same values
	cout << "Testing overloaded assignment operator for class circle: " << endl;
	cout << c_1 << ", " << c_2;
	cout << "\n\n";

	// Create some Point objects on the stack
	DevonKaberna::CAD::Point pt;
	DevonKaberna::CAD::Point pt_2(100.0, 101.0);
	DevonKaberna::CAD::Point pt_3(900.0, 901.0);

	Array array(4); // Initialize array object with size of 4
	
	// Now let's add the Point objects to the array using SetElement
	array.SetElement(DevonKaberna::CAD::Point(10.0, 12.0), 0);
	array.SetElement(pt_2, 1);
	array.SetElement(pt_3, 2);

	// Let's test [] operator that writes
	array[3] = pt;

	// Let's output everything to double check
	for (int i = 0; i < array.Size(); i++)
	{
		std::cout << array[i] << endl;
	}
	return 0;
}