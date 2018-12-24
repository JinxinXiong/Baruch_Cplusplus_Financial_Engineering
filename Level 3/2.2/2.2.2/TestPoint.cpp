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
	Point p1;

	//now save x and y using Set member functions
	p1.SetX(x);
	p1.SetY(y);

	//Prompt user for x and y coordinates for second point
	cout << "Enter x coordinate for second point:";
	cin >> x;
	cout << "Enter y coordinate for second point:";
	cin >> y;

	// Create a second point
	Point p2;

	//now save x and y using Set member functions
	p2.SetX(x);
	p2.SetY(y);

	//now print distance from origin
	cout << "Distance from origin for p1 is: " << p1.DistanceOrigin() << endl;
	cout << "Distance from origin for p2 is: " << p2.DistanceOrigin() << endl;

	//now print distance between p1 and p2
	cout << "Distance between p1 and p2 is: " << p1.Distance(p2) << endl;

	//now let's test creation of a point using no arguments
	Point p_5;
	cout << "Created point using no arguments: " << p_5.ToString() << endl;
	cout << "Distance of new point: " << p_5.DistanceOrigin() << endl;

	return 0;
}