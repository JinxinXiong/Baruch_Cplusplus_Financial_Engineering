// Wrapper.hpp
// 
// Purpose is to provide a different interface than the class it wraps.  I built this more for experimentation than anything.
//
// Author: Devon Kaberna
//

#ifndef WRAPPER_HPP
#define WRAPPER_HPP

namespace DevonKaberna
{
	namespace Utilities
	{
		// T represents class.  *g is a function pointer to class T
		template <typename T, double (T::*g)(const double&) const>

			// Init is passed in as a const double &
			// Had I needed another argument, I would simply add onto this with another specialization
			double Wrapper(const T& root_func, const double& init)
		{
			return (root_func.*g)(init);  // Call class T with *g as a function pointer
		}
	}
}

#endif // WRAPPER_HPP