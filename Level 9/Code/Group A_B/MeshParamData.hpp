// MeshParamData.hpp
//
// Encapsulate mesh parameters
//
// Author: Devon Kaberna
//

#ifndef MESH_PARAM_DATA_HPP
#define MESH_PARAM_DATA_HPP

#include <boost/parameter.hpp>

namespace MeshParams
{
	BOOST_PARAMETER_KEYWORD(Tag, sensitivityType)
		BOOST_PARAMETER_KEYWORD(Tag, property)
		BOOST_PARAMETER_KEYWORD(Tag, start)
		BOOST_PARAMETER_KEYWORD(Tag, end)
		BOOST_PARAMETER_KEYWORD(Tag, step)
}

struct MeshParamData
{
	 int _sensitivity_type;  // Price = 0, Delta = 1, Gamma = 2, Vega = 3, Theta = 4, Rho = 5, Coc = 6
	 int _property;  //S = 0, K = 1, T = 2, r = 3, sig = 4, b = 5
	 double _start;  // Mesh starting point
	 double _end;  // Mesh end point
	 double _step;   // Mesh increment


	explicit constexpr MeshParamData(int sensitivityType, int property, double start, double end,
		double step, double h_override)
		: _sensitivity_type(sensitivityType), _property(property), _start(start), _end(end), _step(step)
	{}

	template <typename ArgPack> MeshParamData(const ArgPack& args)
	{
		_sensitivity_type = args[MeshParams::sensitivityType];
		_property = args[MeshParams::property];
		_start = args[MeshParams::start];
		_end = args[MeshParams::end];
		_step = args[MeshParams::step];
	}
};
#endif //MESH_PARAM_DATA_HPP