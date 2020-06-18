// Function Overloading in C++

/*
Function Overloading:
    - We can have functions that have a different parameter list while having the same name.
    - Function Overloading is using the same name for various forms of that same function.
    - A type of polymorphism: We can have the same function name that works with different data types to execute similar behavior.
    - The compiler must be able to tell the functions apart based on the parameter list and arguments supplied.
    
        // function prototypes
        int add_numbers(int a, int b);
        double add_numbers(double a, double b);

        // main 
        std::cout << add_numbers(2, 3);             // the int, int version of add_numbers is called
        std::cout << add_numbers(10.00, 20.00)      // the double, double version of add_numbers is called

        // function definitions
        int add_numbers(int a, int b) {
            return a + b;
        }

        double add_numbers(double a, double b) {
            return a + b;
        }

    - Return type of overloaded functions: The return type is NOT considered when we return data from overloaded functions.

        // function prototypes 
        int get_value();
        double get_value();

        // main
        std::cout << get_value();                   // which get_value function was called? The compiler will give us an error.

Data Type Promotion in Overloaded Functions:
    - Data types can be promoted to higher value data types.

        print(100);                                 // prints the value using the int version
        print('A');                                 // character is always promoted to int, it should print 65 the ASCII version
        
        print(120.0);                               // calls the double version of the print function
        print(120.0F);                              // the float gets promoted to a double 

        print("C-Style Strings");                   // C style strings are promoted to C++ strings

Defualt Values With Overloaded Functions:
    - We need to pay attention to when we use default values with overloaded functions.

        print(int a=100);
        print(double a=100.00)

    - These 2 function prototypes both have default values and they are overloaded functions. When print() is called which
        version of the function will be called? The compiler will not guess which version we are trying to call, instead it will
        result in an error.
    - Either we only have 1 defualt value version of the overloaded function, or we have none. We need to pay attention to the
        defualt values.
*/


#include <iostream>


int main() {

    return 0;
}
