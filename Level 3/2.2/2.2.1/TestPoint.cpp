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

	//Prompt user for x and y coordinates
	cout << "Enter x coordinate:";
	cin >> x;

	cout << "Enter y coordinate:";
	cin >> y;

	// Create a point using default constructor
	Point p1;

	//now save x and y using Set member functions
	p1.SetX(x);
	p1.SetY(y);

	//Now print the description using the ToString() function
	cout << "Description of the point using ToString():" << p1.ToString() << endl;
	cout << "Description of the x-coordinate using GetX() function:" << p1.GetX() << endl;
	cout << "Description of the y-coordinate using GetY() function:" << p1.GetY() << endl;

	//now let's test creation of a point using no arguments
	Point p_5;
	cout << "Created point using no arguments: " << p_5.ToString() << endl;

	return 0;
}