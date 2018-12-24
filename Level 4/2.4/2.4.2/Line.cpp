// Line.cpp
//
// Implementation file for Line that is comprised of two points - start and end.
// Contains the getter and setter functions, as well as a ToString function to output decription of the line created.
// Also includes functions to calculate length
// Also includes a Ostream << overloaded operator
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point
#include "Line.hpp"		//Header file that contains definition for object called Line

#include <sstream>	//C++ stream buffering
#include <iostream> // C++ style I/O
using namespace std;

Line::Line() : m_startpoint(0, 0), m_endpoint(0, 0) // Default constructor
{
	//cout << "New Line created: " << ToString() << "\n";
}

Line::Line(const Point& start_point, const Point& end_point) : m_startpoint(start_point), m_endpoint(end_point) // Overload constructor that initialize with start- and end-point
{
	//cout << "Line created in constructor: " << ToString() << "\n";
}

Line::Line(const Line& l)	//Copy constructor
{
	m_startpoint = l.m_startpoint;
	m_endpoint = l.m_endpoint;

	//cout << "Line created in copy constructor: " << ToString() << "\n";
}

// Assignment operator
Line& Line::operator = (const Line& source)
{
	//check to make sure not assigning to myself
	if (this == &source)
		return *this;

	m_startpoint = source.m_startpoint;
	m_endpoint = source.m_endpoint;

	return *this;
}

Line::~Line()	// Destructor
{
	//cout << "Line destroyed: " << ToString() << "\n";;
}

// Getter member-function for m_start, which is the starting point
// Returns data member m_startpoint
Point Line::Start() const
{
	return m_startpoint;
}

// Setter member-function for m_startpoint
// Modifies object state of data member m_startpoint
void Line::Start(const Point& new_start_point)
{
	m_startpoint = new_start_point;
}

// Getter member-function for m_endpoint
// Returns data member m_endpoint
Point Line::End() const
{
	return m_endpoint;
}

// Setter member-function for m_endpoint
// Modifies object state of data member m_endpoint
void Line::End(const Point& new_end_point)
{
	m_endpoint = new_end_point;
}

// Returns string description of the point
string Line::ToString() const
{
	stringstream ss;
	ss << "Line Start Point: " << m_startpoint.ToString() << ", Line End Point: " << m_endpoint.ToString() << endl;

	return ss.str();
}

// Calculate length of the Line
// Function output is length of the line
double Line::Length() const
{
	return m_startpoint.Distance(m_endpoint);
}

// Overloaded Ostream << operator
// os is passed in by reference, as is l of type Line
// Returns os by reference!
ostream& operator << (ostream& os, const Line& l)
{
	os << l.ToString();
	return os;
}