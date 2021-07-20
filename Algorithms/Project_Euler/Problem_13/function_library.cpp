// Function Library / Function Definitions

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

The one hundred 50-digit numbers are stored in the text file "100_numbers.txt".
*/


#include "includes.h"
#include "function_library.h"


void find_large_sum(const std::string file_name) {
	/*
		Parameters: [std::string][const file_name] - The name of the file that we will use to store the one hundred 50-digit long numbers.
		Return:		[void]

		- Read line by line from the file provided.
		- We will use the boost::multiprecision library, and use the data type cpp_int to store the large numbers. We will also use
			this data type to perform the addition, and store the result in this data type.
	*/

	// using the boost::multiprecision namespace
	using namespace boost::multiprecision;

	// initiate variables
	cpp_int result = 0;
	std::string num;
	std::ifstream file;

	// check to see if the file is open:
	file.open(file_name);
	if (!file) {
		std::cerr << "Error opening file. \n";
	}

	// use a while loop to iterate through the file, use the get line method to read in line by line.
	// construct a cpp_int on each iteration, add to the total result
	while (std::getline(file, num)) {
		// add the num to the result on each iteration
		result += cpp_int(num);
	}

	// print the total result
	std::cout << result << "\n";

	// close the file when we're done working with it!
	file.close();
}
