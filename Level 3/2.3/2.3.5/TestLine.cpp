// TestLine.cpp
//
// Simple examples of using using Line class, which also tests the point class.
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

	//Now create another line and make sure the getter and setter methods work
	Line line_1;		//since I am creating object line_1 with no arguments, I would expect two point objects created with (0,0) since default constructor being called
	line_1.Start(p1);	//now pass in p1 using line's setter function - Start()
	line_1.End(p2);		//now pass in p2 using line's setter function - Start()

	//now print distance between p1 and p2
	cout << "Distance between p1 and p2 is: " << line_1.Length() << endl;
	//Print description of line
	cout << line_1.ToString();

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