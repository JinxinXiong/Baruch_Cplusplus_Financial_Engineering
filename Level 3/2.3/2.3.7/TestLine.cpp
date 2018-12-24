// TestLine.cpp
//
// Simple examples of using using Line class, which also tests the point class.
// Point hpp utilizes inline functions.
// Normal inline for the getters and default inline for the setters
//
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point
#include "Line.hpp"		//Header file that contains definition for object called Line

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{
	//initialize local variables
	double x, y = 0.0;

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

	// Create a second point
	Point p2(x, y);

	//now create a line with both points
	//By the way the Line overload constructor is created, I would expect the point copy constructor to be called twice when testing
	Line l(p1, p2);

	//Now return a description of the line
	cout << l.ToString() << endl;

	//now print distance between p1 and p2
	cout << "Distance between p1 and p2 is: " << l.Length() << endl;

	//Now set the x and y setters of p1
	p1.X(69);
	p1.Y(99);

	//Display the output using getters
	cout << "p1.x is: " << p1.X() << endl;
	cout << "p1.y is: " << p1.Y() << endl;

	//Now create two more points and a new line, and experiment with getter methods
	Point p3(50, 50);
	Point p4(100, 100);
	Line line_5(p3, p4);  //Since I am calling the Line overload constructor I would expect the point copy constructor to be called twice when testing

	cout << "Line start is: " << line_5.Start().ToString() << endl;		//I would expect point p3 copy constructor to be called
	cout << "Line end is: " << line_5.End().ToString() << endl;			//I would expect point p4 copy constructor to be called

	//Print description of line
	cout << line_5.ToString();

	//now let's test creation of a point using no arguments
	Point p_5;
	cout << "Created point using no arguments: " << p_5.ToString() << endl;
	cout << "Distance of new point: " << p_5.Distance() << endl;

	//now let's test creation of a line using no arguments
	Line l_9;
	cout << "Created line using no arguments: " << l_9.ToString() << endl;
	cout << "Distance of new line: " << l_9.Length() << endl;

	return 0;
}