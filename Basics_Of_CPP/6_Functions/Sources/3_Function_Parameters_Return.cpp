// Function Parameters and Return

/*
Function Parameters:
    - When we call a function we can pass in data into the function.
    - When the function is called, the data that is passed in are called arguments.
    - In the function definition they are called parameters.
    - The arguments and parameters must match in data type, the number of arguments / parameters, and the order.
    - The compiler will try to convert from one data type to another if it can for the arguments that are passed in to try and 
        match the parameters
    
        void say_hello(std::string name) {
            std::cout << "Hello " << name << "\n";
        }

        say_hello("Shiva");             // This is a C-Style string literal, the compiler will automatically convert this into a
                                            C++ string.

Pass By Value:
    - When we pass data into a function, it is passed by value.
    - Pass by value is when the compiler makes a copy of the data that is passed into the function.
    - Whatever changes we make to the parameter in the function does NOT affect the argument that was passed in.
    
    - Formal vs Actual Parameters:
        - Formal Parameters: The parameters defined in the function header.
        - Actual Parameters: The parameters used in the function call (the arguments). This is passed by value.

Return Statement:
    - If a function returns a value it must use the return keyword statement.
    - If a function does not return a value (void), then a return statement is optional.
    - A return statement can occur anywhere in the body of the function.
    - Return statement immediately exits the function.
    - We can have multiple return statements in a function, but generally we should avoid many return statments in a function.
    - The return value is the result of the function call.

Defualt Argument Values:
    - When a function is called, all arguments must be provided.
    - We can tell the compiler to use default values if the arguments aren't provided.
    - Default values can be in prototypes or definitions but NOT in both.
        - The best practice is to set the default values in the function prototypes.
        - Default values must appear at the tail end of the parameter list.
    - We can have multiple default values.
        - Default values must appear consecutively at the tail end of the parameter list.

    - ex) 

        double calc_cost(double base_cost=100.00, double tax_rate, double shipping=5.00);

        - This will result in a compiler error. We cannot provide a default to base_cost, not provide one for tax_rate, and then
            provide one for shipping. Once we start providing a defualt the rest of the parameters MUST contain default values.
            In this example tax_rate must have a default value. 
*/


#include <iostream>


int main() {

    return 0;
}
