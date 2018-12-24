// Point.cpp
// Implementation file for Points in two dimensions - x and y.
// Contains the getter and setter functions, as well as a ToString function to output decription of the point created.
//
// Author: Devon Kaberna


#include "Point.hpp"	//Header file that contains definition for object called Point

#include <sstream>		//C++ stream buffering
#include <iostream>		// C++ style I/O
using namespace std;

Point::Point() : m_x(0), m_y(0) // Default constructor
{
	cout << "New Point created: " << ToString() << "\n";
}

Point::~Point()	// Destructor
{
	
	cout << "Point destroyed:" << ToString() << "\n";
}

// Getter member-function for x-coordinate
// Returns data member m_x
double Point::GetX()
{
	return m_x;
}

// Setter member-function for x-coordinate
// Modifies object state of data member m_x
void Point::SetX(double new_X)
{ 
	m_x = new_X;
}

// Getter member-function for y-coordinate
// Returns data member m_y
double Point::GetY() 
{
	return m_y;
}

// Setter member-function for y-coordinate
// Modifies object state of data member m_y
void Point::SetY(double new_Y)
{ 
	m_y = new_Y;
}

// Returns string description of the point
string Point::ToString()
{
	stringstream ss;
	ss << "Point(" << m_x << ", " << m_y << ")\n";
	
	return ss.str();
}