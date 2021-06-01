// Function Library / Function Definition for Project Euler Problem #8

/*
The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
*/


#include "includes.h"
#include "function_library.h"


// calculate the product in a given range function
unsigned long long int adjacent_digits_product(const int &range, const std::string &number) {
	/*
		- Given a very large number in string form, and a given range. Take the range and set up a lower bound and upper bound.
			Move through the entire string by 1 iteration at a time until the upper bound reaches the end of the string.
			Calculate the product of all the numbers within the range at that current iteration:

			ex) assume the string is 12345678910, and the range is 3, on the first iteration the product will be 1 x 2 x 3 = 6
			on the next iteration we will move the range upwards by 1, now the product will be 2 x 3 x 4 = 24.
			24 > 6. Find the largest product after we've moved the range all the way to the end of the string.

		Parameters: [int][range] = The upper limit of the range.
					[std::string][number] = The large number provided in string form.
		Return:		[unsigned long long int][result] = The specific Project Euler problem #8 has the range of 13, 9^13 = 
						2.5x10^12 so regualr ints will overflow. 
	*/

	// initialize variables
	unsigned long long int result = 0;
	unsigned long long int product = 0;
	// create temp variables that hold the type cast to int from the type of *itr
	int leading_cast = 0;
	int trailing_cast = 0;

	// first set up the leading iterator and the trailing iterator
	// the traling iterator starts at the very first character of the string
	auto trailing_itr = number.begin();

	// the leading iterator needs to start at the end of the range, here in this problem the range is 13, so the leading iterator
	// needs to start on the 13th character of the string
	auto leading_itr = number.begin();
	// use a for loop to move the leading iterator into the correct position
	for (int i = 1; i < range; ++i) {
		++leading_itr;
	}

	// use while loop to move the leading iterator upwards on each iteration until the end of the string
	while (leading_itr != number.end()) {
		/*
			- Calculate the product within the range.
			- static_cast<int>(*itr): when we dereference itr we will get a char, we can convert that char into a int. We need 
				to be careful! These chars are in ASCII, the number 0 in ASCII starts at 48 in integer form. If we want numbers from 0 to 10
				we need to subtract the result of the type cast by 48:

					int num = static_cast<int>(*itr) - 48;

			1) check to see if leading_itr is pointing to an alphanumneric character and not a newline (\n)
			2) set the first number into product, this is what trailing_itr is currently pointing to
			3) use a for loop to move trailing_itr upwards by 1 until it reaches leading_itr
			4) multiply the product by what trailing_itr is pointing to currently
			5) if either trailing_itr or leading_itr is pointing to 0, then continue to the next iteration
			6) once trailing_itr reaches leading_itr, store the product into result if the product is greater than the previous
				result.
			7) reset trailing_itr back to its original position
			8) move leading_itr and trailing_itr upwards by 1 in the next iteration of the while loop
			9) return the result when the entire while loop is done
		*/

		// check to see if both of the iterators are pointing to an alphanumeric character. We only want it to point to a alphanum character
		if ((!std::isalnum(*leading_itr)) && (!std::isalnum(*trailing_itr))) {
			++leading_itr;
			++trailing_itr;
			continue;
		}

		// cast the trailing and leading iterators to int
		leading_cast = static_cast<int>(*leading_itr) - 48;
		trailing_cast = static_cast<int>(*trailing_itr) - 48;

		// set what trailing_itr is pointing to into product. If it's pointing to 0 contiunue the next iteration
		if ((leading_cast != 0) && (trailing_cast != 0)) {
			// since trailing and leading itr are not equal to 0, we can add the current trailing number into the product
			product = trailing_cast;

			// use a for loop to go through the range up to the leading_itr
			for (int i = 1; i < range; ++i) {
				// check to see if trailing_cast is equal to 0
				if (trailing_cast != 0) {
					// increment trailing_itr
					++trailing_itr;

					// recast trailing_cast on each iteration
					trailing_cast = static_cast<int>(*trailing_itr) - 48;
					
					product *= trailing_cast;
					
				} else {
					// break if trailing_cast == 0
					break;
				}
			}
			// product *= leading_cast;

			// reset the trailing_itr back to its original position
			for (int i = 1; i < range; ++i) {
				// check to see if trailing_itr is at the beginning of the string or not. 
				// (we can't decrement the iterator when it's at the beginning)
				if (trailing_itr != number.begin() && (leading_itr != number.end())) {
					--trailing_itr;
				}
			}

			/*
				- Multiply the product by leading_itr
				- If trailing_cast finishes the entire for loop without encountering 0, that means the entire range is done.
				- We multiply the product with the final leading_cast
				- If trailing_cast does become zero and breaks out of the loop early, we can still multiply leading_cast to the
					product. We will rest the product back to 1 at the very end of this current loop so that the next iteration
					can start from the range again.
			*/

			/*std::cout << "finished the loop, product is: " << product << "\n";*/

			// check to see if the current product is greater than result, if it is then replace result with the current product
			if (product > result) {
				result = product;
			}

			// reset the product back to 1 so that the next iteration can start from the beginning of wherever trailing_itr is
			// pointing to
			product = 1;

			// increment leading and tailing iterators
			if (leading_itr != number.end()) {
				++leading_itr;
				++trailing_itr;
			} else {
				break;
			}

		} else { 
			// if the leading_itr is 0, then that means the entire product is equal to 0
			// we can need to increment both of the iterators, and then continue onto the next iteration of the loop
			if (leading_itr != number.end()) {
				++leading_itr;
				++trailing_itr;
			} else {
				break;
			}

		}
	}

	// when the whil loop finishes we will have the maximum product of the numbers within the provided range over the string
	// return the result

	return result;
}
