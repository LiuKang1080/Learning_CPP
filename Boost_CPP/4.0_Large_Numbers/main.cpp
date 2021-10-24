// Dealing with very large numbers using C++ Boost

/*
Dealing with very large numbers using C++ Boost:
	- For standard C++, the limits of numbers that we can use is 64bits, this means that the limit is 2^64, which is
		18,446,744,073,709,551,616.
	- For most cases we will be under this limit, but in certain industries, and certain problems require in dealing with much
		larger numbers.
	- There are 2 ways in dealing with this problem: 1) We construct our own data type, that dynamically allocates more memory
		when we're dealing with larger and larger numbers. OR 2) Use the Boost.MultiPrecision Library!

	- The multiprecision library provides integer, rational, floating point, and complex types that have more range and precision.
	- We will use cpp_int for dealing with very large integers.
	- cpp_int can hold an arbitrary amount of precision.
	- In order to use cpp_int we must first #include <boost/multiprecision/cpp_int.hpp>
		
		using namespace boost::multiprecision;

		cpp_int very_large_num = 1;

		for (unsigned i = 1; i <= 100; ++i) {
			very_large_num *= i;
		}
		
		std::cout << very_large_num << "\n";
		// this is 100! 100 factorial
		// this will print out:
		// 9332621544394415268169923885626670049071596826438162146859296389521759999322991560894146397615651828625
			3697920827223758251185210916864000000000000000000000000

Converting cpp_int into a string OR string to cpp_int:
	- We can use the previous chapters to convert back and forth between strings and cpp_ints. Look at 3.0_String_To_Numbers and
		3.1_Numbers_To_Strings.
	- We can use boost::lexical_cast<>() to convert to and from strings.
	- Look at the live example below:
*/


// C++ Includes:
#include <iostream>

// C++ Boost Includes:
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>


int main() {
	// large num example from C++ Boost Multi-Precision cpp_int
	// https://www.boost.org/doc/libs/1_72_0/libs/multiprecision/doc/html/boost_multiprecision/tut/ints/cpp_int.html

	using namespace boost::multiprecision;

	cpp_int num = 1;

	for (unsigned i = 1; i <= 50; ++i) {
		num *= i;
	}

	std::cout << num << "\n";
	std::cout << "\n";

	// convert this cpp_int into a std::string:
	const std::string string_num = boost::lexical_cast<std::string>(num);
	std::cout << string_num << "\n";

	/*
		- If we have a very large number in string format, and we want to convert it into a cpp_int, we can still use the
			boost::lexical_cast<>() to convert from string to cpp_int.

		- Ex) 
		
			#include <boost/multiprecision/cpp_int.hpp>
			#include <boost/lexical_cast.hpp>
			
			std::string large_num_string = // getting the very large number in string format from a source.
			cpp_int very_large_num = boost::lexical_cast<cpp_int>(large_num_string);

		- Look at the example below:
	*/

	// convert this string into a cpp_int and add 50 to it:
	std::cout << "\n";

	std::string large_string_num = "37107287533902102798797998220837590246510135740250";
	cpp_int large_num = boost::lexical_cast<cpp_int>(large_string_num);

	std::cout << large_num + 50 << "\n";
	
	return 0;
}
