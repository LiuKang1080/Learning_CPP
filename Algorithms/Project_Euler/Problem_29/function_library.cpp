// Function Library / Function Definitions

/*
Consider all integer combinations of ab for 2 <= a <= 5 and 2 <= b <= 5:

2^2 = 4, 2^3 = 8, 2^4 = 16, 2^5 = 32
3^2 = 9, 3^3 = 27, 3^4 = 81, 3^5 = 243
4^2 = 16, 4^3 = 64, 4^4 = 256, 4^5 = 1024
5^2 = 25, 5^3 = 125, 5^4 = 625, 5^5 = 3125

If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

How many distinct terms are in the sequence generated by ab for 2 <= a <= 100 and 2 <= b <= 100?
*/


#include "includes.h"
#include "function_library.h"


int power_sequence() {
	/*
		Parameters: [None]
		Return:		[unordered_sequence.size()] - This is the number distinct terms within the unordered set
	*/

	namespace mp = boost::multiprecision;

	// create variables:
	mp::cpp_int num = 0;
	std::unordered_set<mp::cpp_int> unordered_sequence {};

	// use a nested for loop, both starting at 2 and ending at 100
	for (int i = 2; i <= 100; ++i) {
		for (int j = 2; j <= 100; ++j) {
			/*
				- Use the power function from the boost library to hold very large numbers.
				- We must construct one of the numbers into a mp::cpp_int! There is no defualt conversion from a regular int in C++ to a 
					boost multiprecision cpp_int.
				- Defualt function call for mp::pow is mp::pow(base, exponent);
			*/
			
			num = mp::pow(mp::cpp_int(i), j);

			// add the number into the unordered set, since this is a set, all elements within will be unique
			// automatically skips duplicates!
			unordered_sequence.insert(num);
		}
	}

	// find the size of the unordered set, and return it
	return unordered_sequence.size();
}
