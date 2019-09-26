// comments in C++ start with //

/* 
Block comments in C++ are done just like in C  
*/

#include <iostream>
// # is the pre-processor directive. We have " " instead of < > for the include statements
// <iostream> is the standard library for input and output

int main() {

    // cout prints to the standard output stream (generally the command line or console)
    // << is the called the insertion operator
    std::cout << "Enter your favorite number between 1 and 100: ";

    // reading user input from the standard input stream. We use cin
    int number;
    std::cin >> number;

    std::cout << "You entered " << number << ". That's my favorite number as well!" << std::endl;

    return 0;
}

// Compiling, Linking, and Running C++ programs
// Compiling = converting the .cpp source file into an object file
// Linking = the linker combines multiple cpp source files, standard library files, and other .obj files before producing the .exe
