// Point.cpp
//
// Implementation file for Points in two dimensions - x and y.
// Contains the getter and setter functions.
// Contains ToString function to output a string description of the point
// Also includes functions to calculate distance
// Namespace of DevonKaberna::CAD implemented below
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point

#include <sstream>	//C++ stream buffering
#include <cmath>	//Needed to implement distance functions
#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace CAD
	{
		Point::Point(): Shape(), m_x(0), m_y(0) // Default constructor
		{
			//std::cout << "New Point created\n";
		}

		Point::Point(double x_value, double y_value) : Shape(), m_x(x_value), m_y(y_value)	// Overload constructor that initialize with x and y value
		{
			//std::cout << "Point overload constructor:" << *this << "\n";
		}

		Point::Point(const Point& source): Shape(source), m_x(source.m_x), m_y(source.m_y)	//Copy constructor
		{

			//std::cout << "Point copy constructor: " << *this << "\n";
		}

		// Assignment operator
		Point& Point::operator = (const Point& source)
		{
			//check to make sure not assigning to myself
			if (this == &source) return *this;
				
			//std::cout << "Point assignment operator before base call: " << *this << "\n";
			// Call base class assignment
			Shape::operator = (source);
			
			// Copy state
			m_x = source.m_x;
			m_y = source.m_y;

			//std::cout << "Point assignment operator after base call: " << *this << "\n";

			return *this;
		}

		Point::~Point()	// Destructor
		{
			//std::cout << "Point destroyed:" << *this << "\n";
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

		// Returns string description of the point
		string Point::ToString() const
		{
			stringstream ss;
			ss << "Point(" << m_x << ", " << m_y << ")";

			return ss.str();
		}

		// Overloaded Ostream << operator
		// os is passed in by reference, as is p of type Point
		// Returns os by reference!
		ostream& operator << (ostream& os, const Point& p)
		{
			os << "Point(" << p.m_x << ", " << p.m_y << ")";
			return os;
		}
	}
}