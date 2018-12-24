// Point.hpp
//
// Header file for Points in two dimensions, x and y. 
// Includes standard constructor and destructor.
// Also includes getter and setter functions as well as a ToString() function.
//
// Author: Devon Kaberna


#ifndef Point_HPP
#define Point_HPP

#include <sstream>							//C++ stream buffering
#include <iostream>							// C++ style I/O
using namespace std;

class Point
{
private:
	double m_x;								// X coordinate data member
	double m_y;								// Y coordinate data member

public:
	// Constructors
	Point();								// Default constructor
	
	~Point();								//Destructor

	// Getter functions for x- and y-coordinates
	double GetX();					// The x-coordinate
	double GetY();					// The y-coordinate

	// Setter functions for x- and y-coordinates
	void SetX(double new_X);				// The x-coordinate
	void SetY(double new_Y);				// The y-coordinate

	string ToString();						//Returns a string description of the point
};

#endif // Point_HPP