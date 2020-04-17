// Constants in C++

/*
    Constants in C++
        - Like C++ variables. They have names, occupy storage, usually typed.
        - Their value CANNOT change once they're declared.
    
    Types of constants in C++:
        - Literal Constants
        - Declared Constants (using the const keyword)
        - Constant Expressions (constexpr keyword)
        - Enumerated Constants (enum keyword)
        - Defined Constants (#define)

    Literal Constants:
        - This is the most obvious type of constant.
        ex) x = 12;

        - Integer literal constants
            12      = integer
            12U     = unsigned integer
            12L     = long integer
            12LL    = long long integer

        - Character literal constants
            \n      = new line
            \r      = return 
            \t      = tab
            \b      = backspace
            \'      = single quotes
            \"      = double quotes
            \\      = backslash

        - Declared Constants 
            - Done by using the const keyword
            ex) const double pi = 3.1415926

            - Trying to change the value of the const variable will result in a compiler error

        - Definied Constants 
            - Done by using the #define declaration
            - DO NOT use the defined constants in modern C++
            - The preprocessor does not check for data types, or understand C++ code.
*/


#include <iostream>
// Header file for C style printing and formatting
// #include <cstdio>


int main() {

    // Frank's Carpet Cleaning Service Challenge:
    
    // initialize variables
    int small_rooms = 0;
    int large_rooms = 0;

    const double price_per_small_room = 25.00;
    const double price_per_large_room = 35.00;
    const double sales_tax = 0.06;
    // deal expires in 30 days:
    const int estimate_expiration = 30;

    // input data from the user
    std::cout << "Hello welcome to Frank's Cleaning Service! \n";
    
    std::cout << "How many small rooms do you need cleaned? ";
    std::cin >> small_rooms;
    std::cout << "\n";

    std::cout << "How many large rooms do you need cleaned? ";  
    std::cin >> large_rooms;
    std::cout << "\n";

    // print the summary and the total costs
    std::cout << "=== Estimate for carpet cleaning service: ===\n";
    std::cout << "Number of small rooms: " << small_rooms << "\n";
    std::cout << "Number of large rooms: " << large_rooms << "\n";
    std::cout << "Price per small room: " << price_per_small_room << "\n";
    std::cout << "Price per large room: " << price_per_large_room << "\n";
    
    // We can use C style printing and formatting in C++. We need to include the <cstdio> header file.
    // printf("Price per large room is: %0.2f \n", price_per_large_room);

    double total_room_cost = (price_per_small_room * small_rooms) + (price_per_large_room * large_rooms);

    std::cout << "Cost: " << total_room_cost << "$ \n";
    std::cout << "Tax: " << total_room_cost * sales_tax << "$ \n";
    std::cout << "============ \n";

    std::cout << "Total Estimate: " << total_room_cost + (total_room_cost * sales_tax) << "$\n";
    std::cout << "This estimate is valid for " << estimate_expiration << " days" << std::endl;

    return 0;
}
