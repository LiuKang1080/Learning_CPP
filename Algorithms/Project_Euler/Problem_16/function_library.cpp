// Function Library / Function Definitions

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/


#include "includes.h"
#include "function_library.h"


template <typename T>
std::string stringstream_cast(const T &num) {
	/*
		Parameters: [const <template> T][& num] - Takes in a number and converts that number into a string.
		Return:		[std::string][] - We will return the string 2^1000.

		- We will first compute 2^1000 and then pass that result into this function, this will take that result and convert into a
			std::string.
	*/

	std::stringstream ss;
	ss << num;

	return ss.str();
}


std::string compute_large_num(const int base, const int exponent) {
	/*
		Parameters:	[const int][base] - The base. In Problem_16 the base is 2.
					[const int][exponent] - The exponent. In Problem_16 the exponent is 1000.

		Return:		[std::string][] 
	*/
	
	namespace mp = boost::multiprecision;

	// create variables:
	mp::cpp_int large_num = mp::pow(mp::cpp_int(base), exponent);

	// use the stringstream_cast function to convert this large number into a string
	std::string large_num_string = stringstream_cast(large_num);

	return large_num_string;
}


unsigned long long int compute_addition_string(const std::string &large_num) {
	/*
		Parameters:	[const std::string][& large_num] - The large number in string form.
		Return:		[unsigned long long int][result] - This is the addition of each of the individual numbers of the string.
	*/

	// initialize varaibles:
	unsigned long long int result = 0;

	/*
		- Use a for loop to iterate through the entire string.
		- We will use an iterator to move through the string, get each character, convert to an integer, and add it to the total
		- On the conversion to an int: the itr on derefence will be pointing to a char, we need to subtract '0' on each iteration to
			get the correct integer. Subtract 48.
	*/
	for (auto itr = large_num.begin(); itr != large_num.end(); itr++) {
		result += (*itr) - 48;
	}

	return result;
}
