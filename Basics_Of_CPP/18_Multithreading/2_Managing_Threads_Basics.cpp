// Managins Threads in C++

/*
Managing Threads:
    - Every C++ program has at least 1 thread, which is the thread running main(), started by the C++ runtime.
    - The program can then launch other threads that have another function as an entry point.
    - Those threads can run concurrently with each other and with the initial thread running main().
    - The same way the initial thread exits when the program exits at return 0; line, the same thing occurs for the rest of the
        threads. The threads exit when the function return is called.

Launching a Thread:
    - In order ot use threads we must #include the <thread> header file.
    - We start by constructing a std::thread object.
    - The simplest form is a void function that takes in no parameters and pass that into the std::thread. This runs on its own
        thread and stops when the function return is called or when the function ends.
    - The starting point is ALWAYS a std::thread object.

        #include <thread>
        void do_work();
        std::thread my_thread(do_work);

    - We do not want to CALL the function when we pass it into std::thread, therefore no ().
    - std::thread works on ANY callable object. This means that we can also pass in instances of classes.

        class background_task {
        public:
            void operator() () const {
                do_something();
                do_somethig_else();
            }
        };

        background_task f;
        std::thread my_thread(f);

    - In this case, the supplied function object is copied into the storage belonging to the newly created thread of execution
        and invloked from there.
    - We need to pay close attention to HOW we're passing in functions into std::thread.
    - If we pass in a temporary rather than a named variable, then the syntax can be the same as a function declaration. The compiler
        will interprets is as such.

        std::thread my_thread(background_task());

    - This declares a function called my_thread, this function accepts 1 parameter (of the type: pointer to a function taking in no
        parameters anjd returning a background_task object), and this function will return an std::thread object! Rather than
        launching a new thread!
    - There are 2 ways to avoid this:

    1) Add an extra set of parenthesis:

        std::thread my_thread((background_task()));

    2) Use the uniform initialization syntax:

        std::thread my_thread { background_task() };

    - Lambda expressions also avoid this issue.

        std::thread my_thread ([] {
            do_something();
            do_something_else();
        })

Decide What To Do Next:
    - Once we've launched the thread, we then need to decide explicitly what do next.

    1) Whether to wait for the thread to run and finish, OR
    2) Leaving the thread to run on its own.

    1) Joining it, OR
    2) Detaching it

    - If we do not explicitly decide before the std::thread object is destroyed then the program will terminate.
    - We NEED to ensure that the thread is either joined() or detached(), EVEN in the presence of exceptions!
    - NOTE that we need to make this decision BEFORE std::thread is destroyed, the thread itself may have already finished long
        before we join with it or detach it.
    - If we do not want to wait for the thread to finish then we need to ensure that the data accessed by the thread is valid
        until the thread is finished with it.
    - One situation we need to pay attention to is when the thread function holds pointers or references to local variables and
        the thread hasn't finished when the function exits.

        struct func {
            int &i;
            func(int &i_) 
                : i(i_) {}

            void operator() () {
                for (int i = 0; i < 1000000; ++i) {
                    do_something(i);
                }
            }
        };

        void oops() {
            int some_local_state = 0;
            func my_func(int some_local_state);
            std::thread my_thread(my_func);
            my_thread.detach();
        }

    - Here do_something(i) potentially has access to dangling reference.
    - my_thread.detach() doesn't wait for the thread to finish.
    - When the end is reached in the funcion oops() the thread might still be running. What happens to the func object that has
        been instantiated? What happens to the thread?
    - In this case the new thread that is associated with my_thread wil probably still be running when oops() exits because we've
        explicitly decied NOT to wait for the thread to finish by calling detach(). do_something(i) might access an already
        destroyed variable.
    - One common way to handle this scenario is to make the thread function self contained, and copy the data into the thread rather
        than sharing the data.

    - In particular it is a BAD idea to create a thread within a function that has access to the local variables in that function!
        Unless we're absolutely sure that the thread is guarnteed to finish before the function exits. Alternativley we can ensure
        that the thread has completed execution before the function exits by joining with the thread!

Waiting For The Thread To Finish:
    - 
*/


#include <iostream>
#include <thread>


int main() {
    
    return 0;
}
