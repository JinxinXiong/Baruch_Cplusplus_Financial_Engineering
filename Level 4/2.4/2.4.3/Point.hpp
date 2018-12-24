// Point.hpp
//
// Header file for Points in two dimensions, x and y. 
// Includes standard constructor, overload constructor, copy constructor, assignment operator overload, and destructor
// Includes getter and setter functions as well as a ToString() function.
// Also includes functions to calculate distance
// Includes operator overloads for negating coordinates, scaling, adding, comparing, assigning, and scale + assign
// Also includes a Ostream << overloaded operator
// Also includes overload constructor that accepts one double as an argument, and initializes both x and y values 
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
	Point();									// Default constructor

	// Overload constructor that accepts one double as an argument, and initializes both x and y value
	// Note that this constructor is declared as explicit - to prevent usage of constructors as implicit conversion operators
	explicit Point(double value);
	
	Point(double x_value, double y_value);		// Overload constructor that initializes with x and y value
	Point(const Point& p);						// Copy constructor
	Point& operator = (const Point& source);	// Assignment operator
	~Point();									//Destructor

	// Accessing functions
	double X() const;					// The x-coordinate
	double Y() const;					// The y-coordinate

	// Setter functions
	void X(double new_X);				// The x-coordinate
	void Y(double new_Y);				// The y-coordinate

	// Member operator overloading
	Point operator - () const;					// Negate the coordinates
	Point operator * (double factor) const;		// Scale the coordinates
	Point operator + (const Point& p) const;	// Add coordinates
	bool operator == (const Point& p) const;	// Equally compare operator
	Point& operator *= (double factor);			// Scale the coordinates & assign

	string ToString() const;					//Returns a string description of the point

	double Distance() const;					//Calculate distance to the origin(0,0)
	double Distance(const Point& pt) const;		//Calculate distance between two points
};

// Overloaded Ostream << operator
ostream& operator << (ostream& os, const Point& p);		// Send to ostream

#endif // Point_HPP