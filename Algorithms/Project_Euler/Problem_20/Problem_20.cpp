// Project Euler Problem #20

/*
n! means n x (n - 1) x ... x 3 x 2 x 1

For example, 10! = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/


#include "includes.h"
#include "function_library.h"


int main() {
	// Project Euler - Problem #20
	int base = 100;
	unsigned long long int result = compute_addition_string(compute_factorial(base));

	std::cout << "The sum of the digits of the number 100! is: ";
	std::cout << result << "\n";

	return 0;
}
