// OptionFactory.hpp
//
// Header file for class OptionFactory
//
// Author: Devon Kaberna
//

#ifndef OPTION_FACTORY_HPP
#define OPTION_FACTORY_HPP

#include "VanillaOption.hpp"  // Header file for base class vanilla option
using DevonKaberna::Instrument::VanillaOption;

#include "EuropeanOption.hpp"   // Header file for class vanilla european option
using DevonKaberna::Instrument::EuropeanOption;

#include "AmericanOption.hpp"    // Header file for class vanilla american option
using DevonKaberna::Instrument::AmericanOption;

#include "PerpetualAmericanOption.hpp"    // Header file for class vanilla perpetual american option
using DevonKaberna::Instrument::PerpetualAmericanOption;

#include <boost/shared_ptr.hpp>  // Boost shared pointer functionality

#include "OptionData.hpp"  // Header file for struct that contains all option parameters

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Factory
	{
		class OptionFactory
		{
		public:
			virtual boost::shared_ptr<VanillaOption> CreateOption(const OptionData& OD, const double& b) = 0;
		};

		class EuropeanOptionFactory : public OptionFactory
		{
		public:
			virtual boost::shared_ptr<VanillaOption> CreateOption(const OptionData& OD, const double& b)
			{
				return boost::shared_ptr<EuropeanOption>(new EuropeanOption(OD, b));
			}
		};

		class AmericanOptionFactory : public OptionFactory
		{
		public:
			virtual boost::shared_ptr<VanillaOption> CreateOption(const OptionData& OD, const double& b)
			{
				return boost::shared_ptr<AmericanOption>(new AmericanOption(OD, b));
			}
		};

		class PerpetualAmericanOptionFactory : public OptionFactory
		{
		public:
			virtual boost::shared_ptr<VanillaOption> CreateOption(const OptionData& OD, const double& b)
			{
				return boost::shared_ptr<PerpetualAmericanOption>(new PerpetualAmericanOption(OD, b));
			}
		};
	}
}

#endif // OPTION_FACTORY_HPP