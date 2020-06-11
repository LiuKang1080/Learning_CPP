// Functions in C++

/*
Functions:
    - Allows the modularization of a program.
    - Execution of a C++ program always begins with the main() function.
    - Functions have 4 main parts:
        1) Name: Name of the function. Follows the same rules as variables in terms of naming conventions. Should be meaningful
            names.
        2) Parameter List: The variables passed into the function. Their types must be specified.
        3) Return Type: The data type that is returned from the function. Functions can also return nothing.
        4) Body: The statements that are executed when the function is called. Statements are enclosed in braces (required).

    - General Syntax:

        return_type function_name(parameters) {
            statement(s);
            return_data;
        }

    - If we are not returning anything from the function, then we need to use the void keyword.
    - Functions can take multiple parameters each seperated by commas:

        void print_full_name(std::string first_name, std::string last_name) {
            std::cout << first_name << " " << last_name;

            // return; OR the return is not required because of void 
        }

    - When we call functions the arguments must be provided in order as the parameters.

    - Defining functions:

        void say_hello() {
            std::cout << "Hello" << "\n";
        }

    - Now we can call the function:

        int main() {
            say_hello();
            return 0;
        }

    - Functions can call other functions. The compiler must know the function details BEFORE it is called.

    ex)
        int main() {
            say_hello();
            return 0;
        }

        void say_hello() {
            std::cout << "Hello" << "\n";
        }

        - This will result in an ERROR since the compiler sees say_hello() but does not know how it is defined. It is called 
            before it is defined. 

    - General programming practice: Define functions before using them.
    - Function Prototyping will solve this issue. 
*/


#include <iostream>
#include <cmath>


int main() {
    std::cout << std::sin(180);
    // this is in radians

    return 0;
}
