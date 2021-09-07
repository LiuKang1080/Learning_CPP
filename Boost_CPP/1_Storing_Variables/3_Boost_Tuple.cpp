// Combining Multiple Values Into One

/*
Combining Multiple Values:
	- In the C++ standard we have std::pair and std::tuple (C++17) that combines different variables of different data types.
	- Boost also offers a similar container, but includes for triple, quads, and even more bigger collections of different
		data types.
	- We will use the Boost/Tuple module:

		#include <iostream>
		#include <string>
		
		#include <boost/tuple/tuple.hpp>

		// basic tuple:
		boost::tuple<int, std::string> a_pair (100, "Hello");
		boost::tuple<int, double, int, double> quad_tuple (10, 3.14, 72, 2.71)

	- It is very easy to get a specific value from the tuple:
	- We can use the get<>() function. It takes the general form:
		
		boost::get<n>(item_to_get_from)

	- Here n is a 0 based index of a required value.
	- Here is an example using the get<>() function:

		void example() {
			// get the items from a_pair
			const int var1 = boost::get<0>(a_pair);
			const std::string var2 = boost::get<1>(a_pair);

			// get items from quad_tuple
			const double var3 = boost::get<3>(quad_tuple);
		}

	- The boost::get<>() function has several overloaded functionsm, and is commonly used throught the entire boost library.

Creating boost::tuple:
	- We can use boost to create a tuple. We might need to use the boost specific version when we cannot use the std::tuple
		version.
	- Example, when we use boost::multiprecision::cpp_int along with standard data types, the regular std::make_tuple() function
		will not work since there is no overloaded function for cpp_int for the tuple, therefore we must use the boost version.
	- General Syntax:
		
		#include <boost/tuple/tuple.hpp>
		#include <boost/tuple/tuple_comparison.hpp>
		// We can use the comparison header file to compare the elements within the boost::tuple directly!

		void example_2() {
			std::set<boost::tuple<int, double, int>> s1;
			s1.insert(boost::make_tuple(1, 1.0, 10));
			s1.insert(boost::make_tuple(2, 10.0, 10));
			s1.insert(boost::make_tuple(3, 100.0, 10));

			// requires C++11 and onwards:
			const auto v1 = boost::make_tuple(0, 25.5, 37);

			assert (37 == boost::get<2>(v1));
			// We can use if-else / switch statements, this syntax makes it easier while giving us the power to use
			// boost data types
		}
*/


#include <boost/tuple/tuple.hpp>
