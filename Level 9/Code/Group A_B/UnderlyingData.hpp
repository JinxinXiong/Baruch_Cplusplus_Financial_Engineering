// UnderlyingData.hpp
//
// Encapsulate option parameters.
//


#ifndef UNDERLYING_DATA_HPP
#define UNDERLYING_DATA_HPP

#include <boost/parameter.hpp>

namespace UnderlyingParams
{
	BOOST_PARAMETER_KEYWORD(Tag, CostOfCarry)
		
}

//
struct UnderlyingData
{
	double b; //cost of carry

	explicit constexpr UnderlyingData(double CostOfCarry) : b(CostOfCarry)
	{}

	template <typename ArgPack> UnderlyingData(const ArgPack& args)
	{
		b = args[UnderlyingParams::CostOfCarry];
	}
};


#endif //OPTION_DATA_HPP