// Comments in C++ start with //

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

/*
Compiling, Linking, and Running C++ programs
Compiling = converting the .cpp source file into an object file
Linking = the linker combines multiple cpp source files, standard library files, and other .obj files before 
producing the .exe

Syntax Errors:
    - all statements must end with ; not following the stntax convention for C++ will give compiler errors.

Semantic Errors:
int main() return --> "name"; Here we have told the compiler that the function main is returning an int, but we're actually 
returning a string, this results in an error. ("Hello World / 125") a string divided by an integer.

Logical Errors:
if statements and for loops, these errors are the hardest since it is possible that the compiler will throw no warning, but the 
program itself will not behave properly. Human made errors. TEST YOUR CODE!

Compiler Warnings: The compiler has recognized that there are some issues with the code, but it is still able to properly compile.
ex)  int miles_driven;
    std::cout << miles_driven; 
    warning: 'miles_driven' is used uninitialized...
DO NOT IGNORE COMPILER WARNINGS. Do not treat them as soft errors, it could lead to logical, semanic problems, and generally are 
not standard for coding conventions. Generally we want zero warnings.

Linker Errors: The linker is having trouble linking all of the object files together to create an executable. Usually there is a 
library or object file missing.

Run Time Errors: Errors occurs when the program is running. Divide by zero, file not found, out of memory. This will case the program
to hard crash. Exception handling will help deal with runtime errors.

Basic Structure of a C++ program:
    - C++ has 93 keywords, these keywords are reserved, we cannot use them like we can as variables. ex) int, return, true, class ...
    - #include, main, std, cout, and cin are NOT reserved keywords

    - preprocessor derectives start with a # this sends commands to the preprocessor. Processes these statements before the compiler sees them.
    - the preprocessor first strips all the comments from the source file and substitutes them with a single space. #include is the most common
    - preprocessor directive, it will replace that line with the contents of the file that it is refering to (recursively processed). # does not 
    - understand C++ code.

    - << Stream Insertion Operator - Insert whatever is on the right hand side into the stream (generally it will be the standard output / terminal)
    - >> Extraction Operator - Takes data from the standard stream (generally will be the terminal) and stores the data into whatever is on the right
        hand side of it (generally stored into variables).
    - :: Scope Resolution Operator

Preprocessor and the preprocessor derective:  
    - Starts with the # character. Sends commands to the preprocessor.
    - The preprocessor strips all comments within the source file, and replaces the comments with a single space.
    - Comments NEVER make it to the compiler.
    - Looks for other preprocessor derectives and executes them. 
    - Generally the #include is the most used preprocessor.
    - #include replaces the line with the contents of the file that its referring to. It also recursively checks the contents of the files for #include and 
      processes the contents into those files.
    - Preprocessor derectives do NOT understand C++ syntax.

main() function 
    - Every C++ program must contain exactly 1 main() function 
    - This is the starting point of the program
    - main() must be lowercase
    

    int main() {
        code_block;
        return 0;
    }
        - main() does not except anything from the operating system.



    int main(int argc, char *argv[]) {
        code_block;
        return 0;
    }
        - Here main() expects data / information from the operating system.
        - argc stands for argument count
        - argv stands for argument vector. Contains string arguments


    both are valid main() function structure. 
*/
