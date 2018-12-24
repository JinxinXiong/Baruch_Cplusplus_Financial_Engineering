// Visitor.cpp
//
// Implementation file for class Visitor. Ensures type-safe access using Boost.Variant via overloaded () operators below, due to the requirement
// that the class must implement boost::static_visitor<T>.
// This class must overload operator() for every type used by the boost::variant variable it acts on.
// In our case, it must be able to act on every type of Shape (Line, Circle, and Point).
//
// Author: Devon Kaberna
//

#include "Visitor.hpp"  //Header file that contains definition for object called Visitor

namespace DevonKaberna
{
	namespace CAD
	{
		Visitor::Visitor() : m_dx(0), m_dy(0) {}  // Default constructor
		
		Visitor::Visitor(double dx_value, double dy_value) : m_dx(dx_value), m_dy(dy_value) {}  // Overload constructor that initializes with dx and dy value
		
		Visitor::Visitor(const Visitor& source) :  m_dx(source.m_dx), m_dy(source.m_dy) {}  // Copy constructor

		Visitor& Visitor::operator = (const Visitor& source)  // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Copy state
			m_dx = source.m_dx;
			m_dy = source.m_dy;

			return *this;
		}

		Visitor::~Visitor() {}	// Destructor

		// Visit a point
		// Overload operator() for Point
		// Change coordinates of the reference point object by member data points m_dx and m_dy
		void Visitor::operator () (Point& p) const
		{
			p.X(p.X() + m_dx);
			p.Y(p.Y() + m_dy);
		}

		// Visit a Line
		// Overload operator() for Line
		// Change coordinates of the reference Line's Point objects - Start and End - by member data points m_dx and m_dy
		// Accomplish this by using operator() (Point& p) using references
		void Visitor::operator () (Line& l) const
		{
			// Obtain line's start and end points and assign to reference variables of type Point
			Point& pStart = l.Start();
			Point& pEnd = l.End();

			(*this)(pStart); // Call this object's operator() (Point &p), and pass in start point as a reference
			l.Start(pStart);  // Now directly modify (i.e., visit) line's start point, passing in visited start point via reference

			(*this)(pEnd);  // Call this object's operator() (Point &p), and pass in end point as a reference
			l.End(pEnd);  // Now directly modify (i.e., visit) line's end point, passing in visited end point via reference
		}

		// Visit a Circle
		// Overload operator() for Circle
		// Change coordinates of the reference Circle's Point object - CentrePoint - by member data points m_dx and m_dy
		// Accomplish this by using operator() (Point& p) using references
		void Visitor::operator () (Circle& c) const
		{
			Point& pCentrePoint = c.CentrePoint();  // Obtain circle's CentrePoint and assign to a reference variable of type Point
			(*this)(pCentrePoint);  // Call this object's operator() (Point &p), and pass in CentrePoint point as a reference
			c.CentrePoint(pCentrePoint); // Now directly modify(i.e., visit) circle's CentrePoint, passing in visited CentrePoint via reference
		}
	}
}