// Converting Strings to Numbers using C++ Boost

/*
Converting Strings to Numbers in C++ Using Boost:
	- Converting strings to numbers in standard C++ is ineffient and very unfriendly.
	- let's take a look at an example:

		#include <sstream>

		void example() {
			std::istringstream iss("100");
			int i;

			iss >> i;

			// rest of the code
		}

	- There are several unnecessary operations that occured in the example above. Once this runs we don't need the temp variable
		iss, and it will only be alive until the end of the scope.
	- There is a library in Boost which will help us convert from strings to numbers, it is called Boost.LexicalCast
	- It contains 3 main functions:
		- boost::lexical_cast
		- boost::bad_lexical_cast
		- boost::conversion::try_lexical_convert

	- In order to use the lexical cast we must #include <boost/lexical_cast.hpp>
	- Ex)

		#include <boost/lexical_cast.hpp>

		void example2() {
			const int i = boost::lexical_cast<int>("100");
			// ...
		}

	- We can even use this for non-zero terminated strings:

		void example3() {
			char chars[] = {'x', '1', '0', '0', 'y'};
			const int i = boost::lexical_cast<int>(chars + 1, 3);
			// start at point, ending point for the contents in the parenthesis. Zero based index.

			assert(i == 100);
		}

	- boost::lexical_cast function accepts string as an input and converts it to the type specified in <>.
	- This will automatically check bounds for us.
	- boost::lexical_cast<>() also checks the syntax of the input and throws an exception if it's wrong.
	- Ex)

		#include <iostream>
		#include <boost/lexical_cast.hpp>

		void example4() {
			try {
				const int i = boost::lexical_cast<int>("This is not a number!");
				assert(false);	// must not reach this line!
			} catch (const boost::bad_lexical_cast &e) {}
		}

	- There is also the boost::conversion::try_lexical_convert function that reports errors by return code
	- Ex)

		#include <cassert>
		#include <boost/lexical_cast.hpp>

		void xample5() {
			int i = 0;
			const bool ok = boost::conversion::try_lexical_convert("Bad input", i);
			// take from the given input, attempt to convert and store the bool value of the attempt into the variable provided.

			assert(!ok);
		}

	- boost::lexical_cast just like all std::stringstream classes uses std::locale and can convert localized numbers.
	- The C++ standard has no lexical_cast, but C++17 has std::from_chars functions that could be used to create fast generic 
		conversions.
	- Those conversions do not use locales at all. std::from_chars functions were designed to not allocate memory, they do not
		throw exceptions, and have no atomic properties.
*/


// C++ Includes:
#include <iostream>

// C++ Boost Includes:
#include <boost/lexical_cast.hpp>


int main() {
	// example convert from string to int
	const long long int num = boost::lexical_cast<long long int>("8737540000");

	std::cout << num << "\n";

	return 0;
}
