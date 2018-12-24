// Point.hpp
//
// Header file for Points in two dimensions, x and y. 
// Includes standard constructor and destructor.
// Includes getter and setter functions as well as a ToString() function.
// Also includes functions to calculate distance
//
// This HPP file makes use of inline functions.  Normal inline for the getters and default inline for the setters
//
// Author: Devon Kaberna


#ifndef Point_HPP
#define Point_HPP

#include <sstream> //C++ stream buffering
#include <iostream> // C++ style I/O
using namespace std;

class Point
{
private:
	double m_x;	// X coordinate data member
	double m_y;	// Y coordinate data member

public:
	// Constructors
	Point();								// Default constructor
	Point(double x_value, double y_value);	// Overload constructor that initializes with x and y value
	Point(const Point& p);					// Copy constructor
	
	~Point();								//Destructor

	// Getter functions for x- and y-coordinates
	double X() const;							// The x-coordinate
	double Y() const;							// The y-coordinate

	// Setter functions for x- and y-coordinates
	// Using default inline function
	void X(double new_X) { m_x = new_X; }		// The x-coordinate
	void Y(double new_Y) { m_y = new_Y; }		// The y-coordinate

	string ToString() const;					//Returns a string description of the point

	double Distance() const;					//Calculate distance to the origin(0,0)
	double Distance(const Point& pt) const;		//Calculate distance between two points
};

// Implementation of the normal inline function for the getter functions for x- and y-coordinates
inline double Point::X() const { return m_x; }	// The x-coordinate
inline double Point::Y() const { return m_y; }	// The y-coordinate

#endif // Point_HPP