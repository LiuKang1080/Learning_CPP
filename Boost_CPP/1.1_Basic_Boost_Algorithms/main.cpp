// Basic Boost Algorithms

/*
Basic Boost Algorithms:
	- C++11 and C++14 have new algorithms from the <algorithm> header file.
	- If we are on a compiler that is before the C++11 compiler, then we need to manually write the functions ourselves.

Example:
	- A function that converts input into hexadecimal

		#include <iostream>
		#include <iterator>
		#include <string>

		#include <boost/algorithm/hex.cpp>

		void to_hex() {
			const std::string test_string = "Hello World";

			boost::algorithm::hex(test_string.begin(), test_string.end(), std::ostream_iterator<char>(std::cout));
		}

	- Boost Arrays and Containers that have .begin() and .end() functions satisfy the range concept, we can shorten the example
		above:

		void to_hex() {
			const std::string test_string = "Hello World";

			boost::algorithm::hex(test_string, std::ostream_iterator<char>(std::cout));
		}

	- We can shorten it, without need to use the .being() and .end() functions.
	- The Boost.Algorithm library is a very important library, and is frequently updated when the new iteration of C++ is
		released.
	- Here is the official link to the Algorithms library: http://boost.org/libs/algorithm
*/


#include <iostream>
#include <boost/array.hpp>


int main() {

	return 0;
}
