// Visitor.hpp
//
// Header file for class Visitor. Ensures type-safe access using Boost.Variant via overloaded () operators below, due to the requirement
// that the class must implement boost::static_visitor<T>.
// This class must overload operator() for every type used by the boost::variant variable it acts on.
// In our case, it must be able to act on every type of Shape (Line, Circle, and Point).
//
// Author: Devon Kaberna
//

#ifndef Visitor_HPP
#define Visitor_HPP

#include "Point.hpp" //Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;

#include "Circle.hpp" //Header file that contains definition for object called Circle
using DevonKaberna::CAD::Circle;

#include "Line.hpp" //Header file that contains definition for object called Line
using DevonKaberna::CAD::Line;

#include "boost/variant.hpp"  // Contains all functionality needed to create variants
using boost::variant;   // Using declaration, for readability purposes

namespace DevonKaberna
{
	namespace CAD
	{
		class Visitor : public boost::static_visitor<>
		{
		// Member data for class Visitor
		private:
			double m_dx;  // Delta for dx coordinate
			double m_dy;  // Delta for dy coordinate

		public:
			Visitor();  // Default constructor
			Visitor(double dx_value, double dy_value);  // Overload constructor that initializes with dx and dy value
			Visitor(const Visitor& source);	 // Copy constructor
			Visitor& operator = (const Visitor& source); // Assignment operator
			virtual ~Visitor();	// Destructor

			// Visit a Point
			// Overload operator() for Point
			void operator () (Point& p) const;

			// Visit a Line
			// Overload operator() for Line
			void operator () (Line& l) const;

			// Visit a Circle
			// Overload operator() for Circle
			void operator () (Circle& c) const;
		};
	}
}
#endif // Visitor_HPP