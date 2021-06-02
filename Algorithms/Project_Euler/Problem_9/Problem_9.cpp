// Project Euler Problem #9

/*
Special Pythagorean Triplet: A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2

There exists exactly one Pythagorean Triplet for which a + b + c = 1000.
Find the product of a*b*c.
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
	// Specific solution to Project Euler Problem number 9:

	// brute force method:
	std::cout << "Brute Force Method: \n";
	std::cout << "The product of a, b, and c for the pythaogrean triplet is: ";
	Timer t;
	std::cout << brute_force_method() << "\n";
	std::cout << "Time elapsed: " << t.elapsed() << "\n";

	std::cout << "\n";
	// pythagorean triplet:
	std::cout << "Pythagorean Triplet: \n";
	std::cout << "The product of a, b, and c for the pythaogrean triplet is: ";
	t.reset();
	std::cout << pythagorean_triplet() << "\n";
	std::cout << "Time elapsed: " << t.elapsed() << "\n";

	return 0;
}

/*
NOTES:
In Release Mode for Visual Studio:
	- brute_force_method() takes an average over 3 runs: 0.13 seconds.
	- pythagorean_triplet() takes an average over 3 runs: 0.0004 seconds.

	- (unoptimized) Python takes an average over 3 runs ~3 minutes.
	- (optimized) Python takes an average over 3 runs ~ 0.4 seconds.
*/
