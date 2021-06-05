// Function Library / Function Definitions


#include "includes.h"
#include "function_library.h"


// prime number check function
bool prime_check(const int &num) {
	/*
		- Checks to see if the provided number is a prime number

		Parameters:	[int][num] = The number passed in will be checked to see if it is a prime number
		Return:		[bool]
	*/

	int count = 0;

	// loop from 2 to num
	for (int i = 2; i < num; i++) {
		// check to see if num is completely divisible by the current iteration, if it is then that means it is not a prime
		// number. we break and move onto the next iteration.
		if ((num % i) == 0) {
			return false;
			break;
		} else {
			count += 1;
		}
	}

	// return true if count equals num - 2. We do num - 2 since our loop started with 2, and not 0.
	if (count == (num - 2)) {
		return true;
	} else {
		return false;
	}
}


// sum of primes up to a limit
unsigned long long int prime_sum(const int &limit) {
	/*
		- We already have a prime number check function from previous problems. We will use the prime_check() function to test
			if the current number is a prime number.
		- We will keep track of the size of the vector, when we have a prime number we will add it to the vector. We will continue
			to loop until the size of the vector is equal to the limit.
		- We will use std::accumulate() to sum all of the integers within the vector, return this result

		Parameters:	[int][limit] = The upper limit of the size of the vector
		Return:		[unsigned long long int][result]
	*/

	// initialize variables:
	/*std::vector<unsigned long long int> vec {};*/
	unsigned long long int result = 0;
	// start at 3, since 2 is the smallest prime we will add it at the end
	int num = 3;

	// use a while loop to keep looping 
	for (num; num < limit; num += 2) {
		// increment num by 2 since all even nuimbers are not prime numbers
		// check to see if the current iteration of num is a prime number by calling the prime_check() function.
		// if it is a prime number then add it to the vector vec
		// increment num by 1
		if (prime_check(num)) {
			// add num to the current result
			result += num;
		}
	}
	
	return result + 2;
}


// Look at Sieve of Eratosthenes, implement that methodology for faster run times!
// This current methodology takes over 2 minutes to run with this specific problem, reduce the times!
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
