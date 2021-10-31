// Passing Arguments Into C++ Threads

/*
Passing Arguments Into Threads:
    - Passing arguments into a callable or a function is simple as passing in additional arguments into the std::thread
        constructor.
    - By default the arguments are copied into the internal storage where they can be accessed by the newly created thread, and
        then passed into the function as rvalues as if they were temporaries.
    - Ex)

        void func(int i, const std::string &str);
        std::thread t(func, 5, "Hello");

    - This creates a new thread which calls func(5, "Hello").
    - Even though func takes in an std::string as a second parameter, the string literal is passed as a const char *, and is then
        converted into a std::string only in the context of the new thread.
    - For parameters that are passed in by reference, the std::thread constructor doesn't know what it is. It does not know the
        type of the arguments expected by the function and it just blindly copies the supplied values. We need to wrap the
        arguments that need to be referenced in std::ref().
    - Ex)

        void update_data_for_widget(widget_id w, widget_data &data);
        void oops(widget_id w) {
            widget_data data;
            std::thread t(update_data_for_widget, w, data);
            display_status();
            t.join();
            process_widget_data(data);
        }

    - Here we need to replace line 25 by wrapping the reference &data into std::ref(). The new line is now:

        std::thread t(update_data_for_widget, w, std::ref(data));

    - Now update_data_for_widget will be correctly passed a reference to data, rather than a temporary copy of data.
    - We need to #include the <functional> header file to use std::ref().
    - Look at the official documentation for std::ref. https://en.cppreference.com/w/cpp/utility/functional/ref
*/


#include <iostream>
#include <string>
#include <thread>
#include <functional>


void print_string(const std::string &str) {
    // pass in the string by reference, there is no copying here
    std::cout << "The String that was passed in is: " << str << "\n";
}


int main() {
    // create a string for testing:
    std::string my_string = "Hello Multi-threading World! This is a test!";

    // Create a new thread:
    // The second argument in std::thread will be passed INTO the function that is binded to the thread, this this case, we will
    // pass the argument my_string INTO the function print_string that accepts an std::string as its first argument.
    // Since the print_string function accepts the string by reference we must wrap the argument in std::ref().
    std::thread t(print_string, std::ref(my_string));
    // bind the thread into the main function, and wait for the thread to complete running.
    t.join();

    return 0;
}
