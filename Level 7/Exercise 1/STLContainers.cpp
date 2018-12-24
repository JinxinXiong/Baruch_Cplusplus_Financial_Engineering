// STLContainers.cpp
//
// Objective is to test creating containers of lists, vector and maps.
//
// Author: Devon Kaberna
//

#include <map>				// Map containers
#include <list>				// List containers
#include <vector>			// Vector containers

#include <iostream>  // C++ style I/O

int main()
{
	// Let's create a list of doubles
	std::list<double> l;

	// Add data from the back
	l.push_back(3);
	l.push_back(4);

	// Now add to front
	l.push_front(1);
	l.push_front(2);

	std::cout << "Creating list." << std::endl << std::endl;

	// Use front() and back() functions to access data at the beginning and end of the list, respectively
	std::cout << "Front of list: " << l.front() << std::endl;
	std::cout << "Back of list: " << l.back() << std::endl;

	std::cout << std::endl << std::endl << "Creating first vector." << std::endl << std::endl;

	// Declare a vector of doubles
	std::vector<double> v;
	v.reserve(20);   // Reserve space for 20 elements
					 // Interesting to note that when using reserve, push_back() works, but direct assign such as v[0] = 10 does not!

	// Let's check size/capacity before adding elements
	std::cout << "Size : " << v.size() << std::endl;
	std::cout << "Max size : " << v.max_size() << std::endl;
	std::cout << "Capacity : " << v.capacity() << std::endl;

	//	v[0] = 101; // This throws exception!  This is because no elements yet exist in the vector!
	// Now add elements
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v[0] = 101; // Overwrite element
	
	// Use index operator to access some elements and output values
	std::cout << "Element 0: " << v[0] << std::endl;
	std::cout << "Element 1: " << v[1] << std::endl;
	std::cout << "Element 2: " << v[2] << std::endl;
	//std::cout << "Element 3: " << v[3] << std::endl;  // This throws exception - no element exists here.
	std::cout << "Size : " << v.size() << std::endl;
	std::cout << "Max size : " << v.max_size() << std::endl;
	std::cout << "Capacity : " << v.capacity() << std::endl;

	v.clear(); // Clear out the vector

	std::cout << std::endl << std::endl << "Creating second vector." << std::endl << std::endl;

	std::vector<double> v1(8);  // Declare vector v1 with 8 elements

	// Let's check size before writing to elements
	std::cout << "Size : " << v1.size() << std::endl;
	std::cout << "Max size : " << v1.max_size() << std::endl;
	std::cout << "Capacity : " << v1.capacity() << std::endl;

	v1[0] = 20;	// Write access to elements
	v1[1] = 21;
	v1[2] = 22;

	// Use index operator to access some elements and output values
	std::cout << "Element 0: " << v1[0] << std::endl;
	std::cout << "Element 1: " << v1[1] << std::endl;
	std::cout << "Element 2: " << v1[2] << std::endl;
	std::cout << "Element 3: " << v1[3] << std::endl;
	std::cout << "Element 4: " << v1[4] << std::endl;
	std::cout << "Element 5: " << v1[5] << std::endl;
	std::cout << "Element 6: " << v1[6] << std::endl;
	std::cout << "Element 7: " << v1[7] << std::endl;

	// Let's check size before calling push_back function
	std::cout << "Size : " << v1.size() << std::endl;
	std::cout << "Max size : " << v1.max_size() << std::endl;
	std::cout << "Capacity : " << v1.capacity() << std::endl;

	std::cout << std::endl << std::endl << "Now make vector grow" << std::endl << std::endl;
	v1.push_back(23); // Make vector grow

	// Use index operator to access some elements and output values
	std::cout << "Element 0: " << v1[0] << std::endl;
	std::cout << "Element 1: " << v1[1] << std::endl;
	std::cout << "Element 2: " << v1[2] << std::endl;
	std::cout << "Element 3: " << v1[3] << std::endl;
	std::cout << "Element 4: " << v1[4] << std::endl;
	std::cout << "Element 5: " << v1[5] << std::endl;
	std::cout << "Element 6: " << v1[6] << std::endl;
	std::cout << "Element 7: " << v1[7] << std::endl;
	std::cout << "Element 8: " << v1[8] << std::endl;
	std::cout << "Size : " << v1.size() << std::endl;
	std::cout << "Max size : " << v1.max_size() << std::endl;
	std::cout << "Capacity : " << v1.capacity() << std::endl;

	v1.clear();  // Clear out the vector

	std::cout << std::endl << std::endl << "Creating map." << std::endl << std::endl;

	std::map<std::string, double> map;  // Create a map that maps strings to doubles

	// Wasn't sure of homework requirements, and if I could try other options for filling the map besides the [] operator
	// In any case these also work
	//map.insert({ "abc", 31.21 });  // Via initializer list
	//map.insert(std::map<std::string, double>::value_type("def", 34.56)); // via value_type
	//map.insert(std::pair<std::string, double>("ghi", 39.12)); // via pair<>
	//map.insert(std::make_pair("jkl", 37.23)); // via make_pair()
	
	// Fill map and access elements using [] operator
	map["abc"] = 31.21;
	map["def"] = 34.56;
	map["ghi"] = 39.12;
	map["jkl"] = 37.23; 

	// Now output
	std::cout << map["abc"] << std::endl;
	std::cout << map["def"] << std::endl;
	std::cout << map["ghi"] << std::endl;
	std::cout << map["jkl"] << std::endl;
	std::cout << "Map size: " << map.size() << std::endl;

	return 0;
}