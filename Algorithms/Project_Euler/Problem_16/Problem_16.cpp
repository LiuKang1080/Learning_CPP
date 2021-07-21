// Project Euler Problem #16

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/


#include "includes.h"
#include "function_library.h"


int main() {
	// Project Euler - Problem #16
	int base = 2;
	int exponent = 1000;
	unsigned long long int result = compute_addition_string(compute_large_num(base, exponent));

	std::cout << "The sum of the digits of the number 2^1000 is: ";
	std::cout << result << "\n";
	
	return 0;
}
