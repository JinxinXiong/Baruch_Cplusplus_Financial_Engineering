// ArrayException.hpp
//
// Header file for class ArrayException
// This class is an abstract base class that contains a pure virtual function - GetMessage().
// Also contains standard constructor, copy constructor, destructor, and assignment operator.
// They don't do anything at this point since there are no data members, but for best practice, I implemented them anyways.
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		class ArrayException
		{
		private:
			// No ArrayException data members at this point

		public:
			// Constructors
			ArrayException();  // Default constructor
			ArrayException(const ArrayException& source);	// Copy constructor

			ArrayException& operator = (const ArrayException& source);	// Assignment operator
			virtual ~ArrayException();	// Destructor

			virtual std::string GetMessage() const = 0;  // Abstract function GetMessage() must be implemented in derived classes
		};
	}
}
#endif // ArrayException_HPP