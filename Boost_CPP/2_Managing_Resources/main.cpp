// Mangaging Resources Using The Boost Library

/*
The Boost library has many resources that allows us to extend the standard of C++ allowing us to:
	- Manage local pointers to classes that do not leave scope.
	- Reference counting of pointers to classes that is used across many different pointers.
	- Pointers to arrays that do not leave scope.
	- Storing function objects into variables.
	- Passing function pointers into a variable.
	- Passing C++ Lambda functions into variables.
	- Containers that hold pointers.

We will start with Managing Local Pointers to classes that do no leave Scope:
	- Sometimes we need to dynamically allocate memory and construct classes in that new memory.
	
		bool func1() {
			func_class *ptr = new func_class("Data");

			const bool something_happened = some_function_1(*p);

			if (something_happened) {
				delete ptr;
				return false;
			}

			some_function_2(p);

			delete p;
			return true;
		}

	- At first, this code looks correct, but what happens if some_function_1 or some_function_2 throws an exception?
		In that case then ptr will not be deleted. Let's try and put those functions into a try - catch block

		bool func2() {
			func_class *p = new func_class("Data");

			try {
				const bool something_else_happened = some_function(*p);

				if (something_else_happened) {
					delete p;
					return false;
				}
			} catch (...) {
				delete p;
				throw;
			}

			delete p;
			return true;
		}

	- The code is now correct, but it is hard to read.
	- We can use the Boost.SmartPtr library. It contains the boost::scoped_ptr class that will help us.

		#include <boost/scoped_ptr.hpp>

		bool func3() {
			const boost::scoped_ptr<func_class> ptr (new func_class("Data"));

			const bool something_else_happened = some_function(*p);

			if (something_else_happened) {
				return false;
			}

			some_function2(ptr.get());
			return true;
		}

	- Now there is no chance that the resource leak will occur and the code is much cleaner.
	- boost::scoped_ptr<T> are typical RAII classes. When an exception is thrown or when a variable goes out scope, the stack is
		unwound and the destructor is called.












*/


#include <iostream>


int main() {

	return 0;
}
