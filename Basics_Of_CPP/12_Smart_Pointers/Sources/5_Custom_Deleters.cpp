// Custom Deleters With Smart Pointers In C++

/*
Custom Deleters:
    - Sometimes when we destroy a smart pointer we need to do more than just destroy the object on the heap.
    - These are special cases.
    - C++ smart pointers allow you to provide custom deleters.
    - There are lots of way to achieve this, we will be focusing on 2:
        - Custom Deleters - Functions
        - Custom Deleters - Lambdas

Custom Deleters - Functions:
    
        void my_deleter(some_class *raw_pointer) {
            // custom deleter code
            delete raw_pointer;
        }

        std::shared_ptr<some_class> ptr {new some_class{}, my_deleter};

    - declare ptr as a shared pointer pointing to some_class.
    - In the initializer list we're creating the managed object using new, but we're also passing in the name of the custom
        deleter function.
    
    - Test Class example:

        void my_deleter(Test *ptr) {
            std::cout << "custom deleter called \n";
            delete ptr;
        }

        std::shared_ptr<My_Class> ptr {new My_Class{}, my_deleter};

    - ptr IS the pointer that the shared smart pointer is managing.
    - This also works for unique pointers.

    - Pay attention to the function that is passed in!
        - We're passing in JUST the name of the function into the initializer.
        - We do NOT have any parenthesis!
        - We're NOT calling the function in the initializer!

Custom Deleters - Lambda:
    - Lambdas are anonymous functions

        std::shared_ptr<Test> ptr (new Test{100}, [] (Test *ptr) {
            std::cout << "Using the custom delete in the Lambda function \n";
            delete ptr;
        });

    - Lambdas are declared right in line where we want to use them.
    - We do not need to make a seperate function which we will call later, instead the function code executes right there 
        in-line.

Small Smart Pointers Summary:
    - Try to use unique pointers the most. TZhey're simple, efficient, and the most "drop-in" type of smart pointers.
    - This is the highest recommended / standard programming practice to use unique pointers
    - If we only have a single pointer to manage (even with vectors) use a unique pointer
    - If we have multiple pointers pointing to the same object, or very complex data structures, then we should use shared
        pointers.
    - If we have circular references (pay attention to the shared pointers), then we need to use weak pointers to prevent the
        circular references, and prevent memory leaks.
*/


#include <iostream>
#include <memory>


int main() {

    return 0;
}
