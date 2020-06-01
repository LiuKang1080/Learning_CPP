// C Style Chars and Strings in C++

/*
#include <cctype>
    - C Style Char: 
        - #include <cctype>: includes functions for testing characters, and converting character case.
        - The testing functions evaluate to booleans, these functions accept a char as an argument.  
            - Contains functions like: isalpha(), isdigit(), islower(), isupper(), isprint(), ispunct(), isspace()
            - Char conversion functions: tolower(), toupper()
    
#include <cstring>
    - C Style Strings:
        - String = sequence of characters. Contiguous in memory.
        - Implemented as an array of characters.
        - Terminated by the NULL character ('\0') (null character with a value of zero). 
            - Referred to as zero or Null terminated strings.

    - Declaring variables:
        char my_string[] = "Hello";     // 6 spaces in memory are reserved.
        my_string[5] = 'y';             // this results in a problem. The string no longer has a NULL terminator.

        - We will not get a compiler error or a warning since we're accessing within bounds of the string. 
        - We cannot increase the size of the string array on the fly.    
        - We need to create a large enough array to contain the string and as many null characters as we need

        char my_string[10] = "Hello"; 
        char my_string[5] = 'y';

        - We can now manually set the NULL Terminator at the end, ocne we're done changing the characters.

        - Initializing a string without providing values
        char my_string[10];
            
        - Now setting values:
        my_string = "Hello";            // This will result in an error. Where is the NULL Terminator?

        - Instead we need to use the strcpy function to set strings into initialized variables without any values
        strcpy(my_string, "Hello"); 

    - <cstring> header file:
        - All of the functions within the <cstring> header file assumes that all of the strings they're working with have a 
            NULL Terminator at the end.
        - They must contain a NULL Terminator or we will get errors.
        - Functions like strlen(), strcat() automatically adds the NULL Terminator at the end of the array for us.
        - If we are working on string on our own without these functions, then we need to pay attention to the NULL Terminator.

    - strlen() and the size_t data type:
        - The strlength returns a number showing the size of the array. The specific data type it returns depends on the OS
            it could return an unsigned int, or an unsigned long...
*/


#include <iostream>
#include <cctype>
// include this for C Style chars. Contains char conversion, and testing functions.
#include <cstring>
// include this for C style strings. Contains copying, concatenating, comparison, and searching string functions


int main() {
    char full_name[] {};
    std::cout << "Enter your full name: ";
    std::cin.getline(full_name, 50);
    // we use std::cin.getline() to get the entire line including spaces. 50 is the maximum number of characters to extract

    std::cout << full_name;
    
    return 0;
}
