// Variables, Primitive Types, and Constants in C++

/* 
    - Variables in C++:
        - Abstraction for data in memory locations. Allows us to use names and words that programmers understand rather than 
            memory addesses.
        - Variables have a Data Type and a Value.
        - Variables MUST be declared BEFORE they can be used. C++ is a Statically Typed language (The data type of variables 
            cannot change once declared. The value of the varaible can change but the data type must be the same.)

        - Declaring variables:
            - General syntax:
                VaraibleType VariableName;
            
            ex) 
                int age;
                double rate;
                string name;
            
            - Naming rules:
                - CAN: contain letters, numbers, and underscores 
                - CANNOT: start with a number, use C++ keywords, redeclare a variable in the same scope, use spaces in between
                    variables' name

            - Naming guidelines:
                - Be consistant with naming conventions
                    myVariable vs. my_variable
                - Avoid beginning names with underscores
                - Use meaningful names (not too short, not too long) 
                - NEVER use variables before initializing them
                - Declare variables close to when you need them in your code.

        - Initializing Variables:
            int age;        // uninitialized
            int age = 20;   // C - like initialization 
            int age (20);   // constructor initialization
            int age {20};   // C++11 list initialization syntax

    - Global variables
        - Global variables are automatically initialized to 0 if we do not manually initialize them.
        - Can be accessed from any part of the program, can be changed by any part of the program.
        - Generally it is not good practice to use global variables. Only use them if you need to! 
*/


#include <iostream>


int main() {

    // Allow user to enter the lengh and width of a room, calculate the area of the room
    // initialize variables
    int room_length = 0;
    int room_width = 0;

    std::cout << "Enter the length of the room: ";
    std::cin >> room_length;

    std::cout << "Enter the width of the room: ";
    std::cin >> room_width;

    std::cout << "The area of the room is: " << room_length * room_width << " square feet" << std::endl; 

    return 0;
}
