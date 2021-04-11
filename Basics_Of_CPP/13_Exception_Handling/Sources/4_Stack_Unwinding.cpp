// Stack Unwinding In C++

/*
Stack Unwinding:
    - If an exception is thrown but not caught in the current scope C++ tries to find a handler for the exception by unwinding
        the stack.

    - Function in which the exception was not caught terminates and is removed from the call stack.

    - If a try block was used, then the catch blocks are checked for a match.

    - If no try block was used or the catch handler doesn't match, stack unwinding occurrs again and continues.

    - If the stack is unwound back to main and no catch handler handles the exception then the program terminates.
*/


#include <iostream>


// function prototypes:
void func_a();
void func_b();
void func_c();

// function definitions:
void func_a() {
    std::cout << "Starting A \n";
    func_b();
    std::cout << "Ending A \n";
}

void func_b() {
    std::cout << "Starting B \n";
    
    try {
        func_c();
    } catch (int &ex) {
        std::cerr << "Exception caught in B \n";
    }
    
    std::cout << "Ending B \n";
}

void func_c() {
    std::cout << "Starting C \n";
    throw 0;
    std::cout << "Ending C \n";
}


int main() {
    std::cout << "Starting main \n";
    
    /*
        - Here we can see the function calls and see how stack unwinding works WITHOUT any exceptions thrown
        - When func_a gets called, it will call B, which will call C, then C will end, B will end, then finally A will end.
        - once all of the functions are done then main will end.

        - uncomment line 41 to see the full stack unwinding with an exception.

        - If we throw an exception in C, then C++ will look for the handler in C, if it's not found then C++ will go BACK to the
            caller who called C to look for the handler. B called C, and the handler is not there, C++ will look for the handler
            in the scope that called B. A called B, C++ looks to see if A handles the exception, it does not so C++ looks at main
            since main called A, we finally see that there is a handler in main, and the exception is resolved.

        - Notice during the function call stack unwinding that the last std::couts DO NOT get called! Once the exception is
            thrown C++ will NOT execute the following lines and will continue to unwind terminating all of the functions until
            a handler is found. The functions get removed off of the stack! We need to pay attnetion! If we have destructors for
            certain objects, they will NOT get called! We need to pay attention when stack unwinding happens!

        - If a handler is not found after the full stack unwinding, then C++ will just terminate the program.

        - Since func_c() is the issue here, and is the scope that throws the exception, we can solve this without having to
            unwind the entire stack by having a try-catch block in func_b().
        - With the exception caught in B, B finishes, A finishes, and finally main finishes. Notice how C does NOT finish!
    */

    try{
        func_a();
    } catch (int &ex) {
        std::cerr << "Error exception caught in main. \n";
    }

    std::cout << "Finishing main" << std::endl;

    return 0;
}
