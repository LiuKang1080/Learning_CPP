// Returning an Array from a function

/*
Returning an Array from a function in standard C++:
	- We generally have statements like:

		char* vector_advance(char *val);

	- As a programmer we need to not only understand what this statement means / what it does, we also need to know this function
		behaves externally with C++. Does the return values need to be deallocated by the programmer? Does the function assume that
		the input parameter have a specified width for the val? 
	- This is fairly simple compare to more complex C++ code, but the programmer still needs to worry about a few things
	- What about statements like this:
		
		char (&vector_advance(char (*val)[4])) [4];

	- Here vector_advance is a function that accepts and returns an array of 4 elements.
	- This is really hard to read, and the syntax is very confusing to most people.
	- We can use the boost library to write functions like these more clearly.

boost::array
	- We can use the boost/array library to write clear functions:

		#include <boost/array.hpp>

		typedef boost::array<char, 4> array_4_elements;
		array_4_elements &vector_advance(array_4_elements &val);
	
	- Here boost::array<char, 4> is a wrapper around an array of 4 char elements.
	- This code is much more readable from the example above.

- Here is how it works:
	- boost::array is a fixed sized array.
	- The first template parameter is the element type, and the second one is the size of an array.
	- If we need to change the array size at run-time, then we should use:
		- std::vector
		- boost::container::small_vector
		- boost::container::stack_vector
		- boost::container::vector

	- The boost::array<> class has no handwritten constructors and all of its members are public.

Example:
	
		#include <algorithm>
		#include <boost/array.hpp>

		typedef boost::array<char, 4> array_4;

		array_4 &vector_advance(array_4 &val) {
			// C++ lambda function
			const auto inc = [](char &c) { ++c; };
			
			// boost::array has the standard functions that most containers have in C++ STL
			std::for_each(val.begin(), val.end(), inc);

			return val;
		}

		int main() {
			// we can initialize a boost::array just like a normal array in C++
			array_4 val = {0, 1, 2, 3};
		
			// the defualt constructor
			array_4 val_res;

			// val_res is assignable
			val_res = vector_advance(val);

			assert(val.size() == 4);
			assert(val[0] == 1);

			// val[4] will trigger an assert error because max index is 3

			assert(sizeof(val) == sizeof(char) * array_4::static_size);
		}

	- One of the advantages of boost::array is that it does not allocate dynamic memory, and provides exactly the same performance
		as usual C array.
	- People from the C++ standard committee liked this idea and is now incorporated into the C++11 standard.
	- This takes the form os std::array.
	- And has been extended even more / has better support for usage with conexpr with C++17.
*/


// Boost Includes:
#include <boost/array.hpp>

// C++ Includes:
#include <iostream>
