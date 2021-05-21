// Project Euler - Problem #3

/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

/*
NOTES:
	- We need to pay attention to the data types we're using!
	- This problem deal with a very large number: 600,851,475,143
	- 600 billion WILL overflow normal int data types:
		- int = will hold ~ 2 billion
		- unsigned int = will hold ~ 4 billion
		- long long int = will hold ~ *(2^63) - 1
	- We need to use long long ints in order to deal with the large numbers!
	- If we do not pay attention to the data types and just use regular ints, we will get negative results, which do not make sense.
*/


#include <iostream>
#include <vector>


// largest prime factor function
int largest_prime(long long int num) {
	/*
		- Finds the largest prime factor of a given number
		parameters:
		[long long int][num] = The maximum value within the list of the prime numbers
	*/
	long long int i = 2;
	int value = 0;
	std::vector<int> vec1{};

	while (i * i <= num) {
		/*
			- The largest prime number of num CANNOT be greater than the square root of num.
			- (largest prime number)^2 <= num.
		*/

		while (num > 1) {
			/*
				- num will be broken down by each prime divisor, this loop will continue until the divisor cannot be broken down any further.
			*/

			while (num % i == 0) {
				// append all of the prime numbers to the vector vec1
				vec1.push_back(i);
				num = num / i;
			}

			i += 1;
		}
	}

	// Return the maximum value within the prime numbers vector
	// The last element will generally be the largest prime number 
	// If the final element is not the largest prime number, we can sort the vector in order and the last element will be the largest

	return vec1.back();
}


int main() {
	// specific solution for the Project Euler problem number 3
	long long int num = 600851475143;
	std::cout << "The largest prime factor of the number " << num << " is: ";
	std::cout << largest_prime(num) << "\n";

	return 0;
}
