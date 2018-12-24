// PerpetualAmericanOption.cpp
//
// Implementation file for class PerpetualAmericanOption.  Derived from class AmericanOption.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// This class is considered a separate entity than an American option
// because one distinction is that perpetual option price is the time - homogeneous price and is the same 
// as the normal price when the expiry price T tends to infinity.  Therefore the formulas for perpetual american options are embedded within this class.
// Delta and gamma functionality have not yet been fully developed and currently return a -1.
//
// Author: Devon Kaberna
//

#ifndef PERPETUAL_AMERICAN_OPTION_CPP
#define PERPETUAL_AMERICAN_OPTION_CPP

#include "PerpetualAmericanOption.hpp"	// Header file that contains definition for object called PerpetualAmericanOption

#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Instrument
	{
		PerpetualAmericanOption::PerpetualAmericanOption() : AmericanOption() {}  // Default constructor

		PerpetualAmericanOption::PerpetualAmericanOption(const OptionData& OD) : AmericanOption(OD) { } // Overload constructor with option data entered via end user

		PerpetualAmericanOption::PerpetualAmericanOption(const OptionData& OD, const double& _b) : AmericanOption(OD, _b) {} // Overload constructor - allows end user to override cost of carry parameter - b_
																															// Overridden b is passed down to base class

		PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) : AmericanOption(source) {}	// Copy constructor

		// Assignment operator
		PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			AmericanOption::operator = (source);

			//Copy state

			return *this;
		}

		PerpetualAmericanOption::~PerpetualAmericanOption() {} 	// Destructor

		double PerpetualAmericanOption::Price() const  // Return option price
		{
			if (IsCall())  // Call
				return this->CallPrice(this->option_vector_data());
			else
				return this->PutPrice(this->option_vector_data());
		}

		double PerpetualAmericanOption::Delta() const { return -1; }  // Get Delta - no current functionality.  For future enhancement.
		double PerpetualAmericanOption::Gamma() const { return -1; }  // Get Gamma - no current functionality.  For future enhancement.

		// Return call price to end user as type double
		// Passes in vector of option parameters.  Refer to comments in method for mapping of option param vector.
		double PerpetualAmericanOption::CallPrice(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			double sigma_sqr = pow(_Option_Params[4], 2);
			double h1 = 0.5 - ((_Option_Params[5]) / sigma_sqr);
			h1 += sqrt(pow(((_Option_Params[5]) / sigma_sqr - 0.5), 2) + 2.0 * _Option_Params[2] / sigma_sqr);
			double pric = (_Option_Params[1] / (h1 - 1.0))*pow(((h1 - 1.0) / h1)*(_Option_Params[0] / _Option_Params[1]), h1);

			return pric;
		}

		// Return put price to end user as type double
		// Passes in vector of option parameters.  Refer to comments in method for mapping of option param vector.
		double PerpetualAmericanOption::PutPrice(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			double sigma_sqr = pow(_Option_Params[4], 2);
			double h1 = 0.5 - ((_Option_Params[5]) / sigma_sqr);
			h1 -= sqrt(pow(((_Option_Params[5]) / sigma_sqr - 0.5), 2) + 2.0 * _Option_Params[2] / sigma_sqr);
			double pric = (_Option_Params[1] / (1.0 - h1))*pow(((h1 - 1.0) / h1)*(_Option_Params[0] / _Option_Params[1]), h1);

			return pric;
		}

		// Returns a vector of monotonically increasing range of underlying values of whatever parameter user chooses.
		// Used for end-user presentation purposes.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> PerpetualAmericanOption::MeshOptionParamVector(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object
			return m_mesh_.MeshVector();  // Call Mesher object and returns mesh array of doubles separated by a mesh size h.
		}

		// Returns a vector of option prices as a function of a monotonically increasing range of S values.
		// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> PerpetualAmericanOption::MeshPriceVector(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object

			if (IsCall())
				return this->CalculateVector(m_mesh_, &DevonKaberna::Instrument::PerpetualAmericanOption::CallPrice);  // Call CalculateVector function - passing CallPrice as a function pointer
			else
				return this->CalculateVector(m_mesh_, &DevonKaberna::Instrument::PerpetualAmericanOption::PutPrice);  // Call CalculateVector function - passing PutPrice as a function pointer
		}

		// Returns a "matrix" (i.e., vector of vectors) of option parameters. Used for end-user presentation purposes.
		vector<vector<double> > PerpetualAmericanOption::MeshOptionParamMatrix(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property); // Instantiate Mesher object
			return m_mesh_.MeshParamMatrix();  // Return matrix of option parameters
		}

		// Returns a vector of option prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
		// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> PerpetualAmericanOption::MeshPriceMatrix(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object

			if (IsCall())
				return this->CalculateMesh(m_mesh_, &DevonKaberna::Instrument::PerpetualAmericanOption::CallPrice);  // Call CalculateMesh function - passing CallPrice as a function pointer
			else
				return this->CalculateMesh(m_mesh_, &DevonKaberna::Instrument::PerpetualAmericanOption::PutPrice);  // Call CalculateMesh function - passing PutPrice as a function pointer
		}

		// Calculcates option price as a function of a monotonically increasing range of S values.
		// This function only caters to the "S" parameter. The method CalculateMesh() function is able to compute prices for ANY parameter.
		// Parameter S varies based on increment h.  All other parameters remain constant.
		// Mesher object passed in.  CallPrice/PutPrice passed in as a function pointer in argument vcm.
		vector<double> PerpetualAmericanOption::CalculateVector(const Mesher<double>& mesh, VectorCalcModel vcm) const
		{
			std::vector<double> _AssetPrices = mesh.MeshVector();  // Return mesh array of doubles separated by a mesh size h

			vector<double> _Option_Params(6);
			_Option_Params = mesh.OptionParamsVector();  //Return option parameters as a vector of double

			int size = mesh.MeshVector().size();  // Size is driven from user input of mesh size
			int start = 0;
			int j = 0;

			std::vector<double> result(size, start);  // Sets up the size of the vector

			for (vector<double>::const_iterator i = _AssetPrices.begin(); i != _AssetPrices.end(); ++i)  // STL iterator that iterates through each value of parameter S
			{
				//Parameter S varies based on increment h.  All other parameters remain constant.
				_Option_Params[0] = *i;  // For each S value in the mesh, override parameter S in the option param vector

				result[j] = std::invoke(vcm, this, _Option_Params);  // CallPrice or PutPrice function is passed in via function pointer; store price in result vector
				j++;
			}
			return result;  // Return vector of option prices
		}

		// Calculcates option price as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
		// Mesher object provides a "matrix" (i.e., vector of vectors) of option parameters to this function.
		// CallPrice/PutPrice passed in as a function pointer in argument vcm.
		vector<double> PerpetualAmericanOption::CalculateMesh(const Mesher<double>& mesh, MeshModel mm) const
		{
			std::size_t numberOfRows = mesh.MeshVector().size();  // Size is driven from user input of mesh size
			int start = 0;
			int row_arr = 0;

			vector<vector<double> > _OptionParamMatrix = mesh.MeshParamMatrix();  // Mesh object returns a "matrix" (i.e., vector of vectors) of option parameters

			std::vector<double> result(numberOfRows, start);  // Will store vector of option prices
			vector<vector<double> >::const_iterator vvi_iterator; // STL iterator that iterates through each row of the matrix - each row contains one complete set of option parameters in a vector (1xN)

			for (vvi_iterator = _OptionParamMatrix.begin(); vvi_iterator != _OptionParamMatrix.end(); ++vvi_iterator) // Loop through each row of option parameters (1xN)
			{
				result[row_arr] = std::invoke(mm, this, *vvi_iterator);  // CallPrice or PutPrice function is passed in via function pointer; store price in result vector (1xN)
				row_arr++;
			}
			return result;  // Return vector of option prices
		}

		// Returns string description of the PerpetualAmericanOption
		string PerpetualAmericanOption::ToString() const
		{
			std::string s = AmericanOption::ToString();

			stringstream ss;
			ss << s << "PerpetualAmericanOption" << endl;

			return ss.str();
		}

		// Overloaded Ostream << operator
		// os is passed in by reference, as is eo of type PerpetualAmericanOption
		// Returns os by reference!
		ostream& operator << (ostream& os, const PerpetualAmericanOption& a)
		{
			return os << "PerpetualAmericanOption" << endl;
		}
	}
}
#endif	// PERPETUAL_AMERICAN_OPTION_CPP