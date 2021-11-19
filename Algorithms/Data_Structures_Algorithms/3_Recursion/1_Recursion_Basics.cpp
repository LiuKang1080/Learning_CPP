// Recursion Basics

/*
Recursion Basics:
    - A function that calls itself is what is known as recursion.
    - There must always be a base condition which will terminate the function call, or else we will have an infinite call stack
        that will never stop calling the function, this will result in a stack overflow.
    - Recursion Example:

        void func(int n) {
            if (n > 0) {
                std::cout << "Number is: " << n << "\n";
                
                // call the function again making it recursive
                func(n - 1);
            }
        }

        int main() {
            int x = 3;
            func(x);

            return 0;
        }

    - Following the steps on how the function calls work is what is known as tracing.
    - We follow what gets passed into the function, what the function does, and then we follow any calls INTO the next
        function call.
    - A full trace of a recursive function call will look like a tree. We can also look at how the functions get placed into the
        stack, and also look at how it unwinds (Stack Unwinding).
    - We need to pay attention to HOW the stack unwinds! If we need to we can draw out the Recusion Tracing Trees.
    - The output of the previous example is: 3, 2, 1
    - What will be the output of:

        void func(int n) {
            if (n > 0) {
                // call the function again making it recursive
                func(n - 1);
                
                std::cout << "Number is: " << n << "\n";
            }
        }

        int main() {
            int x = 3;
            func(x);

            return 0;
        }

    - Pay attention to how the stack unwinds!
    
    - There are 2 main phases of recursion: 1) The Calling phase, and 2) the Returning phase.
    - Generally statements BEFORE the recursive call will execute at CALLING time, and statements that come AFTER the recursive
        call will execute at RETURNING time.
    
    - Stack Unwinding and how the stack works: Objects (Functions) get placed onto the stack when they are called. The stack
        behaves as FIFO (First In, Last Out). Think of it as a stack of pancakes. The 1st pancake enters the stack first, then the
        second pancake enters the stack, then finally the last pancake enters the stack. Now we eat the 3rd pancake FIRST, the 3rd
        pancake gets popped off the stack, then the 2nd pancake gets popped off the stack, then finally the first pancake gets
        popped off the stack (First In, Last Out).
*/


#include <iostream>


int main() {

    return 0;
}
