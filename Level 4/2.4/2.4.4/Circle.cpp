// Circle.cpp
//
// Implementation file for Circle.  Circle is comprised of a radius, and a centre point. 
// Includes standard constructor and destructor.
// Includes getter and setter functions for radius and centre point.
// Also includes functions to calculate diameter, area, and circumference.
// Also includes a Ostream << overloaded operator
//
// Author: Devon Kaberna


#ifndef _USE_MATH_DEFINES	//This block of code is needed for M_PI constant
#define _USE_MATH_DEFINES
#include <cmath>			//Libary cmath is used to implement circle functions
#endif // _USE_MATH_DEFINES


#include "Point.hpp"	//Header file that contains definition for object called Point
#include "Line.hpp"		//Header file that contains definition for object called Line
#include "Circle.hpp"	//Header file that contains definition for object called Circle

#include <sstream>	//C++ stream buffering

#include <iostream> // C++ style I/O
using namespace std;

Circle::Circle()	 // Default constructor
{
	//Initialize centerpointe and radius data members
	m_centre_point = Point(0, 0);
	m_radius = 0.0;
	//cout << "New Circle created:\n";
}

Circle::Circle(const double& start_radius, const Point& start_cp) : m_radius(start_radius), m_centre_point(start_cp) // Overload constructor that initializes the radius and centrepoint
{
	//cout << "Circle created in constructor.\n";
}

Circle::Circle(const Circle& c)	//Copy constructor
{
	m_radius = c.m_radius;
	m_centre_point = c.m_centre_point;

	//cout << "Circle created in copy constructor.\n";
}

// Assignment operator
Circle& Circle::operator = (const Circle& source)
{
	//check to make sure not assigning to myself
	if (this == &source)
		return *this;

	m_radius = source.m_radius;
	m_centre_point = source.m_centre_point;

	return *this;
}

Circle::~Circle()	// Destructor
{
	//cout << "Circle destroyed:\n";
}

// Getter member-function for radius
// Returns data member m_radius
double Circle::Radius() const
{
	return m_radius;
}

// Setter member-function for radius
// Modifies object state of data member m_radius
void Circle::Radius(const double& start_radius)
{
	m_radius = start_radius;
}

// Getter member-function for CentrePoint
// Returns data member m_centre_point
Point Circle::CentrePoint() const
{
	return m_centre_point;
}

// Setter member-function for CentrePoint
// Modifies object state of data member m_centre_point
void Circle::CentrePoint(const Point& start_cp)
{
	m_centre_point = start_cp;
}

//Calculate diameter of circle
double Circle::Diameter() const
{
	return 2 * m_radius;
}

//Calculate area of circle
double Circle::Area() const
{ 
	return M_PI * pow(m_radius, 2);
}

//Calculate circumference of circle
double Circle::Circumference() const
{
	return M_PI * m_radius * 2;
}

// Overloaded Ostream << operator
// os is passed in by reference, as is c of type Circle
// Returns os by reference!
ostream& operator << (ostream& os, const Circle& c)
{
	os << "Circle radius: " << c.m_radius << ", Centre Pointe: " << c.m_centre_point;
	return os;
}