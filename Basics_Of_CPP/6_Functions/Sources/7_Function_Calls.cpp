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

Inline Functions:
    - Function calls have some overhead since the function and its parameters get put onto the stack.
    - If we have a very simple function, sometimes the overhead of moving the function on the call stack might be more than just
        running the function.
    - We can suggest to the compiler to compile the functions 'inline'.
        - This avoids function call overhead
        - generates inline assembly code
        - faster
        - could create code bloat (do not abuse)
    - Generally inline functions are located in .h header files, since the definitions must be available to every source file
        that uses it.

    - General Syntax for inline functions:

        inline int add_numbers(int a, int b) {
            return a + b;
        }

        int main() {
            int result = 0;
            result = add_numbers(10, 20);

            return 0;
        }

Recursive Functions:
    - Function that calls itself, either directly or indirectly.
    - Recursive problem solving
        - Contains a base case
        - Divide the rest of the problem into sub-problems and do a recursive call.
    
    - Math: 
        - Factorials, Fibonacci, Fractals...
    - Searching & Sorting:
        - Binary Search, Searching Trees...

    - Recursion is a form of iteration. If recursion does not stop, we will have an infinite recursion.
    - Recusrion can be resource intensive (Call Stack).
    - Watch for StackOverflow Errors.
    - Base Cases terminates the recursion. They are needed!
    - Only use recursion when it makes sense.
    - Anything that can be done recursivly can be done iteratively.

    - Factorial Example:

        unsigned long long factorial(unsigned long long n) {
            if (n == 0) {                   // base case
                return 1;
            }

            return n * factorial(n-1);      // recursive case
        } 

        int main() {
            std::cout << factorial(10) << "\n";

            return 0;
        }
*/


#include <iostream>


/* Function Definitions: */
// static variable example:
void static_variable() {
    static int num1 = 100;
    std::cout << num1 << "\n"; 
    num1 += 10;
    std::cout << num1 << "\n"; 
}

// fibonacci function:
unsigned long long fib(unsigned long long n) {
    if (n <= 1) {
        return n;
    }

    return fib(n-1) + fib(n-2);
}


int main() {
    // static variable example:
    static_variable();
    static_variable();
    static_variable();
    // we see that the value of num1 is being preserved, it is not being reset to 100 each time the static_variable() function is
    // called.

    std::cout << "========== \n";

    // fibonacci example
    std::cout << fib(20) << "\n";

    return 0;
}
