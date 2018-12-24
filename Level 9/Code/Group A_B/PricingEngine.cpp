// PricingEngine.cpp
//
// Implementation file for abstract class PricingEngine.
//
// Author: Devon Kaberna
//

#ifndef PRICING_ENGINE_CPP
#define PRICING_ENGINE_CPP

#include "PricingEngine.hpp"	// Header file that contains definition for object called PricingEngine

namespace DevonKaberna
{
	namespace Engine
	{
		PricingEngine::PricingEngine() {}  // Default constructor

		PricingEngine::PricingEngine(const PricingEngine& source) {}	// Copy constructor

		// Assignment operator
		PricingEngine& PricingEngine::operator = (const PricingEngine& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			return *this;
		}

		PricingEngine::~PricingEngine() {}	// Destructor
	}
}
#endif	// PRICING_ENGINE_CPP