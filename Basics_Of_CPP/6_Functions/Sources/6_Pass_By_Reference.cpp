// Pass by reference in C++

/*
Pass By Reference
    - Sometimes we want to be able to change the data value of the parameters we pass into functions. In order to achieve this we
        can use pass by reference.
    - We need the address of the actual parameter. We can use reference parameters to tell the compiler to pass in a reference
        to the actual parameter.
    - The formal parameter will now be an alias for the actual parameter.
    - No copy of the data is made.

    - In a previous example we passed in a vector into a function that prints the contents of the vector. Before it was passed
        into the function with pass by value. This creates a copy of the vector, this takes up more time and memory. Passing
        by reference allows us to save the memory overhead while still allowing the same functionality.
    - We need to pay attention to how parameters are being passed in, and we need to decide on how to pass in parameters.
    
    - We can pass in parameters as pass by reference by adding the & (address of operator) in front of the varible.
    
    - Print vector contents example)

        void print_vector(std::vector<int> &v) {

        } 





*/


#include <iostream>


int main() {

    return 0;
}
