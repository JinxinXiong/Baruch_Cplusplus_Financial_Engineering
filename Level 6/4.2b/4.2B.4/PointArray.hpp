// PointArray.hpp
//
// Header file for class PointArray, using template functionality in C++.
// Inherits from base class Array<Point>
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, and a function, GetLength, that returns total length between two points in an arrayy.
//
// Author: Devon Kaberna
//

#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.hpp"	// Header file that contains definition for object called Array
#include "Point.hpp"	// Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		class PointArray : public Array<Point>
		{
		private:
			// No member data for class PointArray

		public:
			// Constructors
			PointArray();  // Default constructor
			PointArray(const int& size_array);  // Overload constructor that initializes the array size and allocates number of elements specified by size argument
			PointArray(const PointArray& source);  // Copy constructor
			PointArray& operator = (const PointArray& source);  // Assignment operator
			virtual ~PointArray();  // Destructor

			double Length() const;  // Get total length between the points in the array
		};
	}
}
#endif // PointArray_HPP