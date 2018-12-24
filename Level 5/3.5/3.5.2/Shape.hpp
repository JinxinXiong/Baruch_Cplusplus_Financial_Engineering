// Shape.hpp
//
// Header file for Shape.  Shape is comprised of an ID.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor
// Includes getter function for retrieving the id of the shape.
// Also includes a virtual function ToString() that returns the id of the Shape as a string	
//
// Author: Devon Kaberna

#ifndef Shape_HPP
#define Shape_HPP

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace CAD
	{
		class Shape
		{
		private:
			//member data for class shape that contains the ID
			int m_id;	// The ID

		public:
			// Constructors
			Shape();	// Default constructor
			Shape(const Shape& source);	// Copy constructor that copies the id member
			
			Shape& operator = (const Shape& source);	// Assignment operator that copies the id member
			~Shape();	// Destructor

			// Accessing function for ID			
			int ID() const;	// Retrieves the id of the shape

			virtual string ToString() const;	//Returns the id of the Shape as a string
		};
	}
}
#endif // Shape_HPP