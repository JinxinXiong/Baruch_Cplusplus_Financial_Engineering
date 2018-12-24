// AmericanOption.cpp
//
// Implementation file for class AmericanOption.  Derived from VanillaOption.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// Includes a virtual ToString function output, and a Print() function that prints AmericanOption information to the cout object.
// This class currently does not contain any real functionality at current point 
// An American option is a contract that can be exercised at any time prior to T.  Therefore it cannot be priced using an exact solution.
// As a future enhancement, this class might eventually be assocaited with a different pricing engine.
//
// Author: Devon Kaberna
//

#ifndef AMERICAN_OPTION_CPP
#define AMERICAN_OPTION_CPP

#include "AmericanOption.hpp"	// Header file that contains definition for object called AmericanOption

#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Instrument
	{
		AmericanOption::AmericanOption() : VanillaOption() {}  // Default constructor

		AmericanOption::AmericanOption(const OptionData& OD) : VanillaOption(OD) {}  // Overload constructor

		AmericanOption::AmericanOption(const OptionData& OD, const double& _b) : VanillaOption(OD, _b) {} //Overload constructor with Optiondata struct and cost of carry

		AmericanOption::AmericanOption(const AmericanOption& source) : VanillaOption(source) {}	// Copy constructor

		// Assignment operator
		AmericanOption& AmericanOption::operator = (const AmericanOption& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			VanillaOption::operator = (source);

			return *this;
		}

		AmericanOption::~AmericanOption() {}	// Destructor

		double AmericanOption::Price() const { return -1; }  // Method does not return meaningful data until such time that the class uses an appropraite pricing engine.
		double AmericanOption::Delta() const { return -1; } // Method does not return meaningful data until such time that the class uses an appropraite pricing engine.
		double AmericanOption::Gamma() const { return -1; } // Method does not return meaningful data until such time that the class uses an appropraite pricing engine.
	
		// Returns string description of the AmericanOption
		string AmericanOption::ToString() const
		{
			std::string s = VanillaOption::ToString();

			stringstream ss;
			ss << s << "AmericanOption" << endl;

			return ss.str();
		}

		// Overloaded Ostream << operator
		// os is passed in by reference, as is eo of type AmericanOption
		// Returns os by reference!
		ostream& operator << (ostream& os, const AmericanOption& a)
		{
			return os << "AmericanOption" << endl;
		}
	}
}
#endif	// AMERICAN_OPTION_CPP