// Project Euler Problem #7

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/


#include "includes.h"
#include "function_library.h"


/*
	- Timer class code is from Learncpp website chapter 11.18 - "Timing Your Code"
	- https://www.learncpp.com/cpp-tutorial/timing-your-code/
*/
class Timer {
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	std::chrono::time_point<clock_t> m_beg;

public:
	Timer()
		:m_beg(clock_t::now()) {

		// Timer constructor
	}

	void reset() {
		m_beg = clock_t::now();
	}

	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


int main() {
	// Specific solution to Project Euler Problem number 7
	const int limit = 10001;
	
	std::cout << "The 10,001st prime number is: \n";

	Timer t;
	std::cout << prime_num_term(limit) << "\n";
	std::cout << "Time elapsed: " << t.elapsed() << "\n";

	return 0;
}

/*
NOTES:
	- The average time elapsed over the course of 3 runs in Release Mode in VS is: 1.45 seconds
	- The average time elapsed over the course of 3 runs in Debug Mode in VS is: 1.75 seconds
*/
