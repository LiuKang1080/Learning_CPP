// Multithreading in C++ Using Boost

/*
Multithreading in C++ Using Boost:
	- Multiple threads exists within a single process, threads may share process resources and have their own resources.
	- The Boost.Thread library provides unifaction across operating systems. This is NOT a header-only library, we must link against
		the libboost_thread and libboost_system libraries.
	- Ex) Create and fill a big file in a thread

		#include <cstddef> // for std::size_t

		bool is_first_run();

		// function that runs for a long time
		void fill_file(char fill_char, std::size_t size, const char *file_name);

		// called in thread that draws a UI
		void example_without_threads() {
			if (is_first_run()) {
				// this will execute for a long time
				fill_file(0, 8 * 1024 * 1024, "save_file.txt";
			}
		}

	- Starting a thread isn't that easy in C++

		#include <boost/thread.hpp>

		// call the thread that draws the UI
		void thread_example() {
			if (is_first_run()) {
				boost::thread(boost::bind(&fill_file, 0, 8 * 1024 * 1024, "save_file.txt")).detach();
			}
		}

	- The boost::thread variable accepts a functional object that can be called without parameters, we provide it using
		boost::bind.
	- This creates a new thread. The functional object is copied into the new execution thread and runs there, the return is
		ignored.
	- We then call detach() on that thread. The thread execution is detached from the boost::thread variable, and continues its
		execution. 
	- Just like in the C++ standard, we can also call join() to wait for the thread to finish and bind it back to the main thread.
	
		void joining_threads() {
			if (is_first_run()) {
				boost::thread t1(boost::bind(&fill_file, 0, 8 * 1024 * 1024, "save_file.txt"));

				// do some other work
				// wait for the thread to finish
				t1.join();
			}
		}

	- After the thread is joined the variable holds a "not-a-thread" state and the destructor does not call std::terminate
	- Remembher that we MUST call either join() or detach() before the destrcutor is called, or else the program will crash and
		terminate.

	- Another wrapper that the boost library contains is the boost::scoped_thread<T>, where T can be:
		- boost::interrupt_and_join_if_joinable
		- boost::join_if_joinble
		- boost::detach

	- Ex)
		
		#include <boost/thread/scoped_thread.hpp>

		void some_func();

		void RAII_example() {
			boost::scoped_thread<boost::join_if_joinable> t1(boost::thread(&some_func));

			// here t1 will be joined at scope exit.
		}
*/


// C++ Includes:
#include <iostream>

// C++ Boost Includes:
#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>


int main() {

	return 0;
}
