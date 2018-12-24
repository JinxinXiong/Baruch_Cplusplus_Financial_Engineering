// OptionParams.hpp
//
// Encapsulate option parameters.
//

#ifndef OPTION_DATA_HPP
#define OPTION_DATA_HPP

#include <boost/parameter.hpp>

namespace OptionParams
{
	BOOST_PARAMETER_KEYWORD(Tag, assetPrice)
		BOOST_PARAMETER_KEYWORD(Tag, strike)
		BOOST_PARAMETER_KEYWORD(Tag, expiration)
		BOOST_PARAMETER_KEYWORD(Tag, interestRate)
		BOOST_PARAMETER_KEYWORD(Tag, volatility)
		BOOST_PARAMETER_KEYWORD(Tag, dividend)
		BOOST_PARAMETER_KEYWORD(Tag, foreignFreeInterestRate)
		BOOST_PARAMETER_KEYWORD(Tag, optionType)
		BOOST_PARAMETER_KEYWORD(Tag, underlyingAssetType)
}

struct OptionData
{
	double S;	// underlying asset price
	double K;	// strike
	double T;  // expiry
	double r;  // interest
	double sig;  //vol
	double D;	// dividend
	double R;	// Foreign risk free interest rate
	int type;	// 1 == call, -1 == put
	int unam;	//TODO: Underlying asset; need to improve this
	

	explicit constexpr OptionData(double assetPrice, double strike, double expiration, double interestRate,
		double volatility, double dividend, double foreignFreeInterestRate,  int PC, int underlyingAssetType)
		: S(assetPrice), K(strike), T(expiration), r(interestRate), sig(volatility), D(dividend), R(foreignFreeInterestRate),  type(PC), unam(underlyingAssetType)
	{}

	template <typename ArgPack> OptionData(const ArgPack& args)
	{
		S = args[OptionParams::assetPrice];
		K = args[OptionParams::strike];
		T = args[OptionParams::expiration];
		r = args[OptionParams::interestRate];
		sig = args[OptionParams::volatility];
		D = args[OptionParams::dividend];
		R = args[OptionParams::foreignFreeInterestRate];
		type = args[OptionParams::optionType];
		unam = args[OptionParams::underlyingAssetType];
/*
		std::cout << "S " << S << "K " << K << ", T " << T << ",r " << r << std::endl;
		std::cout << "vol " << sig << ", div " << D << ", R " << R << ",type " << type << std::endl;*/
	}
};

#endif //OPTION_DATA_HPP