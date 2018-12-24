// TestCircle.cpp
//
// Simple examples of using using Circle class, which also tests the point class.
//
// Author: Devon Kaberna

#include "Point.hpp"	//Header file that contains definition for object called Point
#include "Line.hpp"		//Header file that contains definition for object called Line
#include "Circle.hpp"	//Header file that contains definition for object called Circle

#include <iostream>  // C++ style I/O
using namespace std;
	
int main()
{
	//initialize local variables
	double x, y, radius = 0.0;

	//Prompt user for the radius
	cout << "Enter the radius:";
	cin >> radius;

	//Prompt user for x and y coordinates for centre point
	cout << "Enter x coordinate for point:";
	cin >> x;
	cout << "Enter y coordinate for point:";
	cin >> y;

	// Create a point
	Point p1(x, y);

	//Now create a circle passing in radius and p1 as arguments
	//I would expect point copy constructor get called by way of how I used the ':' syntax in the Circle overload constructor
	Circle c1(radius, p1);

	//Now return a description of the circle
	cout << c1.ToString() << endl;

	//Now print the diameter
	cout << "Circle diameter : " << c1.Diameter() << endl;

	//Now print the area
	cout << "Circle area : " << c1.Area() << endl;

	//Now print the circumference
	cout << "Circle circumference : " << c1.Circumference() << endl;

	//Now's lets test some of the getter and setter functionality of radius
	c1.Radius(19);
	//Now print the radius
	cout << "Circle radius : " << c1.Radius() << endl;

	//Now's lets test some of the getter and setter functionality of centrepoint
	Point p_20(100, 101);

	Circle c_20;  //this should call circle default constructor, which in turn, will call point default constructor
	c_20.CentrePoint(p_20);  //this should call the point copy constructor and pass values of 100 and 101
	
	//Now print the radius which should be 0
	cout << "Circle radius : " << c_20.Radius() << endl;
	//Now print the centre point; this will result in a point copy constructor call
	cout << "Circle centrepoint : " << c_20.CentrePoint().ToString() << endl;
	//Now print the centre point x point; this will result in a point copy constructor call
	cout << "Circle centrepoint X member: " << c_20.CentrePoint().X() << endl;

	//now let's create a new circle using default
	Circle c23;  //this should call circle default constructor, which in turn, will call point default constructor
	
	//Now return a description of the circle
	cout << "Circle description: " << c23.ToString() << endl;

	return 0;
}