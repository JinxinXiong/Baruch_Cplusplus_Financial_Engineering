// TestPoint.cpp
//
// Objective is to test constructors as conversion operator
// The Point class has an additional constructor that accepts one double as an argument, and initializes both x and y values 
//
// Author: Devon Kaberna


#include "Point.hpp"	//Header file that contains definition for object called Point
#include "Line.hpp"		//Header file that contains definition for object called Line
#include "Circle.hpp"	//Header file that contains definition for object called Circle

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{
	// Note: this code will compile and run
	// Turns out the 1.0 in the if statement is implicitly converted to a Point object, therefore being equal
	//Point p(1.0, 1.0);
	//if (p == 1.0) cout << "Equal!" << endl;
	//else cout << "Not equal" << endl;

	// To get around implicit conversion, we need to use the explicit keyword when declaring the overload constructor
	// We now need to cast 1.0 as a Point object, otherwise compiler will error
	Point p(1.0, 1.0);
	if (p == (Point) 1.0) cout << "Equal!" << endl;
	else cout << "Not equal" << endl; 

	return 0;
}