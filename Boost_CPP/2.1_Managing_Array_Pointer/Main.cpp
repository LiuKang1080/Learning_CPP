// Managing Pointers to Arrays that do not leave Scope using C++ Boost

/*
	- We know the general code for managing pointers to a resource, but when we're dealing with arrays we need to call delete[]
		instead of calling the regualr delete. Otherwise will get a memory leak.

	- Ex)

		void may_throw_exception_1(char ch);
		void may_throw_exception_2(const char *buffer);

		void foo() {
			// we want to try and allocate 10MB, we cannot do that on the stack., we must allocate that memory onto the heap.
			char *buffer = new char[1024 * 1024 * 10];

			// If we have ceratin code following this that will throw an exception, what does it mean for the memory that is on
				the heap? How will we handle the exception? Will we just leave this function? When does delete[] get called?
				will delete[] ever get called?

			may_throw_exception_1(buffer[0]);
			may_throw_exception_2(buffer);

			delete[] buffer;
		}

	- We can use the Boost.SmartPointer library, this contains scoped_ptr<>, and the scoped_array<> classes.
	- We need to #include <boost/scoped_array.hpp>
	- Ex)

		void foo_fixed_1() {
			// allocate memory on the heap:
			boost::scoped_array<char> buffer(new char[1024 * 1024 * 10]);

			// some code that may throw an exception
			// but now the exception won't cause a memory leak

			may_throw_exception_1(buffer[0]);
			may_throw_exception_2(buffer.get());

			// the destructor of the variable buffer will call delete[]
		}

	- We can also use boost::movelib::unique_ptr<> class that exists in the Boost.Move Library
	- We just need to indicate that it is storing an array by providing [] at the end of the template parameter.
	- We need to #include <boost/move/make_unique.hpp>
	- Ex)

		void foo_fixed_2() {
			//allocate memory on the heap
			const boost::movelib::unique_ptr<char[]> buffer = boost::make_unique<char[]>(1024 * 1024 * 10)

			// now we have some code that will throw an excpetion
			may_throw_exception_1(buffer[0]);
			may_throw_exception_2(buffer.get());

			// the destructor of the variable buffer will automaticall call delete[]
		}

	- scoped_array<> works exactly like the scoped_ptr<> class, but calls delete[] in the destructor instead of the normal delete.
	- unique_ptr<T[]> does the same thing.
*/


// C++ Includes:
#include <iostream>

// C++ Boost Includes: 
#include <boost/scoped_array.hpp>
#include <boost/move/make_unique.hpp>


int main() {

	return 0;
}
