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
	//initialize local variables
	double x, y = 0;

	//Prompt user for x and y coordinates for first point
	cout << "Enter x coordinate for first point:";
	cin >> x;
	cout << "Enter y coordinate for first point:";
	cin >> y;

	// Create a point
	Point p1(x, y);

	//Prompt user for x and y coordinates for second point
	cout << "Enter x coordinate for second point:";
	cin >> x;
	cout << "Enter y coordinate for second point:";
	cin >> y;

	// Create a point
	Point p2(x, y);

	//Prompt user for x and y coordinates for third point
	cout << "Enter x coordinate for third point:";
	cin >> x;
	cout << "Enter y coordinate for third point:";
	cin >> y;

	// Create a point using overloaded constructor that accepts x and y coordinates
	Point p3(x, y);

	//now print distance between p1 and p2
	cout << "Distance between p1 and p2 is: " << p1.Distance(p2) << endl;

	//now let's test creation of a point using no arguments
	Point p_5;
	cout << "Created point using no arguments: " << p_5.ToString() << endl;
	cout << "Distance of new point: " << p_5.Distance() << endl;

	return 0;
}