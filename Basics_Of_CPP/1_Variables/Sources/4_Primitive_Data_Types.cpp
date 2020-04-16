// Primitive Data Types in C++

/*
    Built in Primitive Data Types:
        - Integer Types 
        - Floating Point Types
        - Character Types
        - Boolean Types

        - Size and Percision is often compiler and OS dependent
            #include <climits>

        - Type sizes:
            - 8 bit     = 2^8   = 256
            - 16 bit    = 2^16  = 65,536  
            - 32 bit    = 2^32  = 4,294,967,296
            - 64 bit    = 2^64  = 18,446,744,073,709,551,615

    Character Data Type:
        - Used to represent a single character 'A', '@'
        - char = exactly 1 byte = 8 bits
        - char16_t = at least 16 bits
        - char32_t = at least 32 bits
        - Single quotes for chars. Using double quotes represents it as a string.

    Integer Data Type:
        - Represents whole numbers.
        - signed and unsigned.
        - By default integers are signed.
        - unsigned are values that are zero and greater (only positive).
        - short, long, long long
        - C++14 and above: for large numbers we can do assignments like such: long int large_number = 9'999'999'999
            Makes it easier to read. The compiler will strip out the ' and compile as if it wasn't there.

    Floating Point Data Type:
        - Represents non-integer numbers: 5.00, 2.639, 3.14
        - signed and unsigned.
        - Represented by exponents. 
        - General syntax: 1.0e+100

            Type    |       Percision       |       Range
           float    |   7 decimal digits    |   10^-38 - 10^38
           double   |   15 decimal digits   |   10^-308 - 10^308
        long double |   19 decimal digits   |   10^-4932 - 10^4932

    Boolean Data Type:
        - Represents True and False.
        - 0 = false, 1 = true. (Any non-zero is evaluated to true)
        - Usually 8 bits.
        - true and false are reserved C++ keywords.

    sizeof() Operator:
        - Determines the size in bytes of a data type or a variable.
        ex) sizeof(int); sizeof(my_var); sizeof my_var;
        - The last style of syntax can only be done on variables.
        - The sizeof() operator gets its information from 2 header files:
            <climits> and <cfloats>
        - <climits> has defined constants for the size of data types
*/


#include <iostream>


int main() {
    // we will get an overflow if we only use a long int, we need to use a long long int
    // pay attention to compiler warnings in case overflows happen.
    long long int my_num = 9'999'999'999;
    std::cout << "Large Integer is: " << my_num << "\n";

    // very large numbers:
    long double large_number = 3.0e+120;
    std::cout << "Large Floating Point is: " << large_number << "\n";

    // sizeof() operator examples
    std::cout << "Char: " << sizeof(char) << " bytes \n";
    std::cout << "Int: " << sizeof(int) << " bytes \n";
    std::cout << "Float: " << sizeof(float) << " bytes \n";
    std::cout << "Double: " << sizeof(double) << " bytes \n";
    std::cout << "Long Long: " << sizeof(long long) << " bytes \n";
    std::cout << "Long Double: " << sizeof(long double) << " bytes \n";

    return 0;
}
