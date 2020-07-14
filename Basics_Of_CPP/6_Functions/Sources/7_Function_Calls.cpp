// Function Calls in C++

/*
Scope:
    - Scope determines when and where an identifier can be used.
    - C++ uses static lexical scoping.
    - 2 types of scopes: Local and Global scopes.

    Local or Block Scope: 
        - Identifiers are declared within { } blocks.
        - Function parameters have block scopes.
        - They are only visible within the { } block where it is declared.
        - Function local variables are only active while the function is executing. This is known as the lifetime of an 
            identifier.
        - Local variables are NOT preserved between function calls.
        - Within nested blocks inner blocks can "see", but outer blocks cannot "see" in.

    Static Local Variables:
        - Declared with static qualifier 

            static int value = 5;

        - Value is preserved between function calls
        - Only initialized the first time the function is called.

    Global Scope: 
        - Identifier declared outside of any function or class.
        - Visible to to all parts of the program after it has been declared.
        - Global CONSTANTS are okay, but the general best practice is to NOT use global variables.
            - We reduce dependencies. Allows for easier maintainability, and resuability.
            - Sometimes functions can change the value of the global variable, we manually need to keep track of the values and 
                detrermine if the change is intended or not. Don't use global variables! const global variables or constexpr are
                fine.

Function Calls:
    - Functions use the "Function Call Stack", an area in memory.
    - LIFO = Last In First Out
        - Analogous to a stack of books or pancakes
    - Push and Pop data 
        - Push = Put a data item onto the stack.
        - Pop = Remove a data item from the stack. (Remove from the top of the stack)
    
    - Stack Frame or Activation Record: 
        - Functions must return control to the function that called it.
        - Each time a function is called the compiler creates a new activation record and pushes it onto the stack.
        - When a function terminates the compiler pops the activation record and returns control to the function that called it.
        - Local variables and function parameters are allowed on the stack.
        - We cannot jump into the middle of the stack. We must start at the top of the stack and work or way down.

    - Stack Size:
        - The stack size is finite in terms of memory.
        - Stackoverflow: Too many function calls and activation records pushed onto the stack. Generally this is unrecoverable,
            and the program crashes and terminates.

    - Stack Memory Structure: From top to bottom
        - Heap
            - Pointers 
            - "Free Storage"
        - Stack 
            - Function calls
            - Function parameters 
        - Static / Global Variables
        - Code Area 
*/


#include <iostream>


// function definitions:
void static_variable() {
    static int num1 = 100;
    std::cout << num1 << "\n"; 
    num1 += 10;
    std::cout << num1 << "\n"; 
}


int main() {
    // static variable example:
    static_variable();
    static_variable();
    static_variable();
    // we see that the value of num1 is being preserved, it is not being reset to 100 each time the static_variable() function is
    // called.

    return 0;
}
