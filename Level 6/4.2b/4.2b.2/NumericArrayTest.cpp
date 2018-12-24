// NumericArrayTest.cpp
//
// Need to test a new class - NumericArray.cpp. Purpose of that class is to leave Array class as generic, and 
// add numerical functionality into the NumericArray class, which derives from Array.
//
// Author: Devon Kaberna
//

#include "Point.hpp"	//Header file that contains definition for object called Point
using DevonKaberna::CAD::Point;  //Using declaration for using a single class (Point)
//
//#include "Circle.hpp"	//Header file that contains definition for object called Circle
//using DevonKaberna::CAD::Circle;  //Using declaration for using a single class (Circle)
//
//#include "Line.hpp"		//Header file that contains definition for object called Line
//using DevonKaberna::CAD::Line;  //Using declaration for using a single class (Line)
//
//#include "Shape.hpp"	//Header file that contains definition for object called Shape
//using DevonKaberna::CAD::Shape;  //Using declaration for using a single class (Shape)

#include "NumericArray.hpp"	//Header file that contains definition for object called NumericArray
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include "ArrayException.hpp"	//Header file that contains definition for object called Array
using namespace DevonKaberna::Containers;  // Using directive for a complete namespace

#include <iostream>  // C++ style I/O

int main()
{
	// Declare some test variables
	NumericArray <double> doubleNumericArray1(5);
	NumericArray <double> doubleNumericArray2(5);
	try
	{
		// Let's initialize both numeric arrays with some test values
		for (int i = 0; i != doubleNumericArray1.Size(); i++) doubleNumericArray1[i] = (i * 2);
		for (int i = 0; i != doubleNumericArray2.Size(); i++) doubleNumericArray2[i] = (i * 3);
		
		// Now output and verify
		for (int i = 0; i != doubleNumericArray1.Size(); i++)
		{
			cout << doubleNumericArray1[i] << ", " << doubleNumericArray2[i] << endl;

		}

		// Declare sum variable
		NumericArray <double> doubleNumericArraySum(5);

		// Now let's sum them up
		doubleNumericArraySum = doubleNumericArray1 + doubleNumericArray2;

		// Verify and output
		for (int i = 0; i != doubleNumericArraySum.Size(); i++)
			cout << doubleNumericArraySum[i] << endl;

		// Now scale
		NumericArray <double> doubleNumericArrayScale(5);
		doubleNumericArrayScale = doubleNumericArraySum * 2;

		// Now let's verify
		for (int i = 0; i != doubleNumericArrayScale.Size(); i++)
			cout << doubleNumericArrayScale[i] << endl;

		// Now let's test dotproduct
		cout << "Dot Product equals: " << (doubleNumericArray1.DotProduct(doubleNumericArray2)) << endl;
		
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	return 0;
}