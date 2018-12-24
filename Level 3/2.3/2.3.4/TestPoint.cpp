// TestPoint.cpp
//
// Simple examples of using Point class.
//
// Author: Devon Kaberna

#include "Point.hpp" //Header file that contains definition for object called Point

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{

	// Create a point using pre-defined numbers per exercise
	const Point p1(1.5, 3.9);
	
	//cp.X(0.3);  //this will throw a compiler error

	//now print x to console
	cout << p1.X() << endl;

	//now let's test creation of a point using no arguments
	Point p_5;
	cout << "Created point using no arguments: " << p_5.ToString() << endl;
	cout << "Distance of new point: " << p_5.Distance() << endl;

	return 0;
}