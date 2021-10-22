// Convert Numbers into Strings Using C++ Boost

/*
Converting Numbers Into Strings using C++ Boost:
	- We will continue using Boost.LexicalCast, but this time we will be converting numbers to strings.
	- We will specifically use boost::lexical_cast to perform this conversion.
	- In order to use boost::lexical_cast we must first #include boost/lexical_cast.hpp
	- Ex) Convert the number 100 into a string using boost::lexical_cast

		#include <iostream>
		#include <cassert>
		#include <boost/lexical_cast.hpp>

		void example1() {
			const std::string num_string = boost::lexical_cast<std::string>(100);
			assert(num_string == "100");
		}

	- The boost::lexical_cast<>() function can also accept numbers as input and convert them into a string type specified as the
		templated parameter <>. This is like the previous example in 3.0_String_To_Numbers
	- In most cases boost::lexical_cast is faster than the std::stringstream and printf functions.
*/


// C++ Includes:
#include <iostream>

// C++ Boost Includes:
#include <boost/lexical_cast.hpp>


int main() {
	// Number to String lexical cast example
	const std::string num_string = boost::lexical_cast<std::string>(5465135135357777777);
	std::cout << "The number is: " << num_string << "\n";

	return 0;
}
