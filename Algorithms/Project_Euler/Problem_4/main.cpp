// Project Euler - Problem #4

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/


#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>


// palindrome check function
bool is_palindrome(const std::string &str) {
	/*
		- Checks to see if the given string is a palindrome

		parameters:	[std::string][str] = passed in by reference.
		return:		[bool] = true / false
	*/

	// take the string and add it to a deque using a for loop
	std::deque<char> dq;

	for (auto i: str) {
		dq.push_back(i);
	}

	// use a while loop to loop through the deque, check to see if the front and the back are the same. 
	char c1;
	char c2;

	while (dq.size() > 1) {
		c1 = dq.front();
		c2 = dq.back();

		// check to see if c1 and c2 are equal, return false if they're not!
		if (c1 != c2) {
			return false;
		}

		// pop front and back of the deque
		dq.pop_front();
		dq.pop_back();
	}

	// only the while loop will return false
	return true;
}

// result function
int result(int limit) {
	/*
		- Returns the largest integer in a vector. This vector contains plaindrome results.

		parameters:	[int][limit] = The upper limit.
		return:		[int][result] = This is the largest value within the 
	*/

	// test only the numbers between (limit - 100) and the limit.
	// No point in testing the product results between 0 - 900 since > 900 will have the largest results.
	int lower_limit = limit - 100;
	std::vector<int> vec;

	// check to see if the vector is empty. Loop if it is empty, on each iteration increase the size of the range by 100
	// stop looping if the vector is not empty.
	while (vec.empty()) {
		// loop through all multiples between the range and test to see if the result is a palindrome
		for (int x = lower_limit; x < limit; ++x) {
			for (int y = lower_limit; y < limit; ++y) {
				// convert the product result into a C++ style string
				int product = x * y;
				std::string num_string = std::to_string(product);

				// add the result into the vecotr id it's a palindrome
				if (is_palindrome(num_string)) {
					vec.push_back(product);
				}
			}
		}

		// increase the range by 100 by reducing the lower_limit by 100
		lower_limit -= 100;
	}

	// the vector will have duplicates since x * y will return the same result 2 times
	// we can use the std::max_element(), which is located in the <algorithm> header file
	// create an iterator so that we can use it to iterate through the vector container
	// std::distance() returns the location of where itr is pointing to (itr is pointing to the max_element).
	// this is the index of the max_element

	// we can also "dereference" the iterator. std::max_element will return the location where the largest integer is.
	// "dereference" the iterator to get the actual value of max_element.

	std::vector<int>::iterator itr;
	itr = std::max_element(vec.begin(), vec.end());
	
	/*int index = std::distance(vec.begin(), itr);*/
	/*int result = vec[index];*/

	// "dereference" the iterator
	int result = *itr;

	return result;
}


int main() {
	// Specific solution to the Project Euler problem number 4:
	int limit = 1000;
	std::cout << "The largest palindrome of 2 products up to the Limit: " << limit << " is: " << result(limit) << "\n";

	return 0;
}
