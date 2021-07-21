// Function Library / Function Definitions

/*
n! means n x (n - 1) x ... x 3 x 2 x 1

For example, 10! = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

==========
	- Esentially this problem has already been solved in Project_Euler/Problem_16.
	- We will reuse the functions that we used to solve Problem_16.
*/


#include "includes.h"
#include "function_library.h"


template <typename T>
std::string stringstream_cast(const T &num) {
	/*
		Parameters: [const <template> T][& num] - Takes in a number and converts that number into a string.
		Return:		[std::string][] - We will return the string 100!

		- We will first compute 100! and then pass that result into this function, this will take that result and convert into a
			std::string.
	*/

	std::stringstream ss;
	ss << num;

	return ss.str();
}


std::string compute_factorial(int base) {
	/*
		Parameters:	[int][base] - The base number that we will use to start the factorial. For Project Euler problem 20 we will use 100
									as the base.
		Return:		[std::string][large_num] - We will return the string version of the result of the factorial of base. 
	*/

	using namespace boost::multiprecision;

	// initiate variables:
	cpp_int result = 1;
	std::string large_num;

	// use a for loop to calculate the factorial
	for (int i = 1; i <= base; ++i) {
		result *= i;
	}

	// conver the result into a string
	return stringstream_cast(result);
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
