// Point.cpp
//
// Implementation file for Points in two dimensions - x and y.
// Contains the getter and setter functions, as well as a ToString function to output decription of the point created.
// Also includes functions to calculate distance
// Also includes a Ostream << overloaded operator
// Includes operator overloads for negating coordinates, scaling, adding, comparing, assigning, and scale + assign
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point

#include <sstream>	//C++ stream buffering
#include <cmath>	//Needed to implement distance functions

#include <iostream> // C++ style I/O
using namespace std;

Point::Point() : m_x(0), m_y(0) // Default constructor
{
	//cout << "New Point created\n";
}

Point::Point(double x_value, double y_value) : m_x(x_value), m_y(y_value)	// Overload constructor that initialize with x and y value
{
	//cout << "Point created in constructor:" <<  *this << "\n";
}

Point::Point(const Point& p)	//Copy constructor
{
	m_x = p.m_x;
	m_y = p.m_y;

	//cout << "Point created in copy constructor:" << *this << "\n";
}

// Assignment operator
Point& Point::operator = (const Point& source)
{
	//check to make sure not assigning to myself
	if (this == &source)
	{
		cout << "Preclude self-assignment check worked" << endl;
		return *this;
	}
	else
	{
		m_x = source.m_x;
		m_y = source.m_y;

		return *this;
	}
}

Point::~Point()	// Destructor
{
	//cout << "Point destroyed:" <<  *this << "\n";
}

// Getter member-function for x-coordinate
// Returns data member m_x
double Point::X() const
{
	return m_x;
}

// Setter member-function for x-coordinate
// Modifies object state of data member m_x
void Point::X(double new_X)
{
	m_x = new_X;
}

// Getter member-function for y-coordinate
// Returns data member m_y
double Point::Y() const
{
	return m_y;
}

// Setter member-function for y-coordinate
// Modifies object state of data member m_y
void Point::Y(double new_Y)
{
	m_y = new_Y;
}

// Negate the coordinates
Point Point::operator - () const					
{
	return Point(-m_x, -m_y);
}

// Scale the coordinates
Point Point::operator * (double factor) const		
{
	return Point(m_x * factor, m_y * factor);		// Anonymous object
}

// Add coordinates
Point Point::operator + (const Point& p) const		
{
	return Point(m_x + p.m_x, m_y + p.m_y);			// Anonymous object
}

// Equally compare operator
bool Point::operator == (const Point& p) const		
{
	return (m_x == p.m_x) && (m_y == p.m_y);
}

// Scale the coordinates & assign
Point& Point::operator *= (double factor)			
{
	m_x *= factor;
	m_y *= factor;

	return *this;
}

// Returns string description of the point
string Point::ToString() const
{
	stringstream ss;
	ss << "Point(" << m_x << ", " << m_y << ")";

	return ss.str();
}

//Calculate distance to the origin(0,0)
double Point::Distance() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

//Calculate distance between two points
//Point pt passes in x and y coordinates for first point
//Data members m_x and m_y are the second point's x and y coordinates
double Point::Distance(const Point& pt) const
{
	return sqrt(pow((m_x - pt.m_x), 2) + pow((m_y - pt.m_y), 2));
}

// Overloaded Ostream << operator
// os is passed in by reference, as is p of type Point
// Returns os by reference!
ostream& operator << (ostream& os, const Point& p)
{
	os << p.ToString();
	return os;
}