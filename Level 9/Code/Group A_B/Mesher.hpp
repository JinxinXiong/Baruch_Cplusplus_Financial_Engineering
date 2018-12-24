// Mesher.hpp
//
// Header file for class Mesher. 
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// Purpose of this class is to 1.) provide a mesh vector for a monotonically increasing range of underlying values of S, for example 10, 11, 12, …, 50;
// and 2.) return a matrix (vector of vectors) of option parameters based on whatever parameter user chooses (i.e., S, K, r, etc.)
//
// Author: Devon Kaberna
//

#ifndef MESHER_HPP
#define MESHER_HPP

#include <vector>  // Vector container

#include "OptionData.hpp"  // Header file for struct that contains all option parameters
#include "MeshParamData.hpp"  // Encapsulate option parameters 

namespace DevonKaberna
{
	namespace Utilities
	{
		template <typename T>
		class Mesher
		{
		private:
			// Member data for class mesher
			std::vector<T> m_option_params_;  // Vector of option parameters used in this mesher
			T m_start_;  // Mesh starting point
			T m_end_;   // Mesh end point
			T m_step_;  // Mesh increment (i.e., h)
			int m_property_;  // Option parameter (i.e., S, K, r, etc.  These are all stored in OptionData struct

			void Init(const std::vector<T>& _option_params, const T& _m_start, const T& _m_end, const T& _m_step, const int& _m_property);  // Initialize
			void Copy(const Mesher<T>& source);  // Copy member data

		public:
			//Constructors
			Mesher();  // Default constructor
			Mesher(const std::vector<T>& _option_params, const T& _m_start, const T& _m_end, const T& _m_step, const int& _m_property);  // Overload constructor with mesh settings
			Mesher(const Mesher<T>& source);	 // Copy constructor
			Mesher<T>& operator = (const Mesher<T>& source); // Assignment operator
			virtual ~Mesher();	// Destructor

			std::vector<T> MeshVector() const;  // Returns a mesh array of T separated by a mesh size h
			std::vector<std::vector<T> > MeshParamMatrix() const;  // Returns a "matrix" (i.e., vector of vectors) of option parameters

			//Accessing functions
			T Start() const;  // Mesh starting point
			T End() const;  // Mesh end point
			T Step() const;  // Mesh increment
			int Property() const;  // Option parameter (i.e., S, K, etc.)
			std::vector<T> OptionParamsVector() const;  // Vector of option parameters

			// Modifier functions
			void Start(const T& _start);  // Mesh starting point
			void End(const T& _end);   // Mesh end point
			void Step(const T& _step);   // Mesh increment
			void Property(const int& _property);   // Option parameter (i.e., S, K, etc.)
			void OptionParamsVector(const std::vector<T>& _option_params);  // Vector of option parameters
		};
	}
}
#ifndef MESHER_CPP
#include "Mesher.cpp"
#endif // MESHER_CPP

#endif // MESHER_HPP