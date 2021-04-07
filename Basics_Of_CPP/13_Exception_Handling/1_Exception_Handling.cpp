// Exception Handling in C++

/*
Exception Handling:
    - Generally we want to use exception handling only when needed.
    - Only when it prevents our code from continuing to run.
    - Exception handling properly on very large programs is very difficult.

    - Ecxeption handling generally is dealing with extraordinary situations.
    - Indicates that an extraordinary situation has been detected or has already occurred.
    - The program can deal with the extraordinary situation in a suitable manner.
    - Generally we want to do exception handling on synchronus code NOT async code!

    - General causes for exceptions:
        - Insufficient resources
        - Missing resources
        - Invalid operations
        - Range violations
        - Underflows and overflows
        - Illegal data

    - Our code is considered Exception Safe when our code handles these exceptions.

    - Terminology:
        - Exception = An object or primitive type that signals that an error has occurred.
    
        - Throwing an Exception (Raising an Exception) = Your code detects that an error has occurred or will occurr. The place
            where the error occurred may not know how to handle the error. The code can throw an exception describing the error
            to another part of the program that knows how to handle the error.

        - Cathcing an Exception (Handle the Exception) = Code that handles the exception. It may or may not cause the program to
            terminate.

    - Exception Syntax and Keywords:
        - throw:
            - Throws an exception
            - Followed by an argument

        - try {code that may cause an exception}
            - You place the code that may throw an exception in a try block
            - If the code throws an exception the try block is exited
            - The thrown exception is handled by a catch handler
            - If no catch handler exists, then the program terminates

        - catch (Exception ex) {code to handle the exception}
            - Code that handles the exception
            - Can have multiple catch handlers
            - May or may not cause the program to terminate
            - Here Exception ex is the exception type 

Divide By Zero Example:

        double average {};
        average = sum / total;

    - What happens when total = 0? Crash? Overflow?
    - The division by 0 error result depends on the data type of the arguments.
    - int divide by 0 vs. float divide by 0 MAY provide different results in errors.

        if (total == 0) {
            // what to do?
        } else {
            average = sum / total;
        }

    - Now we implement the try / catch blocks

        double average {};
        try {                                           // try block
            if (total == 0) {
                throw 0;                                // throw the exception
            }

            average = sum / total;                      // won't execute if total == 0
        } catch (int &ex) {                             // exception handler
            std::cerr << "Can't divide by 0 \n";
        }

    - int &ex is a reference to the exception
    - In the try block we write the code that could potentially throw an exception.
    - The type of excpetion here is an int and we set it to 0.
    - The best practice is to throw objects NOT primitives.
    - What do we throw? We can throw anything: int, char, pointer, objects
    - We can also throw ANY integer in this example.

    - If no excpetion is thrown, then the catch will NOT execute.
    
    - If total == 0, then 0 is thrown, no further code in the try block executes
    - The divide by zero does NOT happen, and the catch block now executes.
    - The exception handler expects an exception object of the same data type of the one we threw.
    - When an exception is thrown, C++ is looking for the exception that is thrown, if we do not catch it, then the program
        terminates. We can deal with the exception if we catch the excpetion.
    
    - When we catch the best practice is to catch a reference!
    - The name of the variable of the catch can be anything naming it &ex is fine.
    - &ex will just be whatever we just threw. Here in this case it will be 0
    - If we throw an interger exception, and we hve a double catch block, then there is nothing to catch the int exception, our
        program will just terminate. We MUST catch the same data type in order to deal with it.

    - std::cerr is another output stream reserved for error messages, or error logging.
    - By default std::cerr is your console just like std::cout
*/


#include <iostream>


int main() {
    // divide by zero example:
    double average {};
    int sum = 5;
    int total = 0;

    try {
        if (total == 0) {
            throw 0;
        }

        average = sum / total;
    } catch (int &ex) {
        std::cerr << "Value of &ex: " << ex << "\n";
        std::cerr << "Cannot divide by 0 \n";
    }

    std::cout << "===== \n";
    std::cout << "Miles per gallon example \n";
    // ===================================================
    // miles per gallon example:
    
    int miles = 15;
    int gallons = 0;
    double miles_per_gallon {};

    // we're doing int division
    
    // miles_per_gallon = miles / gallons;
    // miles_per_gallon = static_cast<double>(miles) / gallons;
    // std::cout << "Result: " << miles_per_gallon << "\n";
    
    /*
        - The program crashes, or we get a crazy error number for int divide by int
        - Comment out line 129, and uncomment line 130:
        - We get the result inf
    
        - What happens if miles is -15?
        - We get -inf
    
        - What happens if miles is 0, and gallons is 0, with one or both being a double?
        - We get nan (not a number)
    
        - We can use regualr if statements to handle the error of 0 division ourselves

            if (gallons != 0) {
                miles_per_gallon = static_cast<double>(miles) / gallons;
                std::cout << "Result: " << miles_per_gallon << "\n";
            } else {
                std::cerr << "Cannot divide by 0 \n";
            }
    */

    // using the try catch block for mpg example
    try {
        if (gallons == 0) {
            throw 5;
        } else {
            miles_per_gallon = static_cast<double>(miles) / gallons;
            std::cout << "Result: " << miles_per_gallon << "\n"; 
        }
    } catch (int &ex) {
        std::cerr << "Value of &ex: " << ex << "\n";
        std::cerr << "Cannot divide by 0 \n";
    }

    return 0;
}
