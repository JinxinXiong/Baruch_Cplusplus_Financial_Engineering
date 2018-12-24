// PricingEngine.hpp
//
// Header file for abstract class PricingEngine. Although ExactSolutionBSEngine is the only derived class, eventually, the goal is for other pricing methods to derive from this class.
//
// Author: Devon Kaberna
//

#ifndef PRICING_ENGINE_HPP
#define PRICING_ENGINE_HPP

namespace DevonKaberna
{
	namespace Engine
	{
		class PricingEngine
		{
		private:
			// Member data for class PricingEngine
			
		public:
			// Constructors
			PricingEngine(); // Default constructor
			PricingEngine(const PricingEngine& source);	// Copy constructor
			PricingEngine& operator = (const PricingEngine& source); // Assignment operator
			virtual ~PricingEngine();	// Destructor
		};
	}
}
#endif // PRICING_ENGINE_HPP