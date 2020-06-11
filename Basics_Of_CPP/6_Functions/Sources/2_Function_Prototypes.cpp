// Function Prototypes in C++

/*
Function Prototypes:
    - The compiler must know about a function before it can be used.
    - Generally we can define functions before calling them in main(), this works well for small programs, but for large
        programs it is not practical. We cannot also use features like 2 functions that call each other.
    - In order to solve this problem we can use Function prototyping

    - Function Prototyping: Tells the compiler what it needs to know without a full function definition.
    - This is also called forward declarations.
    - Placed at the beginning of the program. 
    - Function Prototyping is generally used in header files (.h)

    - General Syntax:

        data_type function_name(parameter_data_type); 

    - Notice that it is not required to include the actual parameter variable
    - We use this to tell the compiler that this is how we will define a function later. This allows us to use features like 2 
        functions that call each other.
    - With function prototypes the compiler doesn't need to know what the function is, it only needs the header information.
    - We can have as many function prototypes as we need.
    - Only 1 function prototype per function.
    - The order of the function prototypes do not matter.

    - Void function prototype:

        #include <iostream>
        
        void say_hello();
            // this is defined as void, and having no parameters. When we actually define this function later we must follow 
            // these rules

        int main() {
            say_hello();                        // No errors
            say_hello(100);                     // Error since the say_hello prototype is stated as having no parameters 
            std::cout << say_hello() << "\n";   // Error due to no return value

        } 

        void say_hello() {
            std::cout << "Hello" << "\n";
        }
*/


#include <iostream>


int main() {
    
    return 0;
}
