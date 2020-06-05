// C++ style strings

/*
#include <string>
    - Contains the std::string class.  
    - C++ strings are contiguous in memory.
    - C++ strings are dynamic (C style strings are fixed in size).
    - Works with the standard input / output streams.
    - String header file contains several useful methods for working with strings.
    - The regular operators can be used.
    - C++ strings can easily be converted into C style string if we need to.
    - C++ strings are safer compared to C style strings.

Declaring / Initializing Strings:
    - Initialization:
        std::string s1;                     // initialize empty string
        std::string s2 = "Hello";           
        std::string s3 = s2;                // both say hello, but s2 and s3 occupy different memory addresses

    - Assignment:
        std::string s1 = "C++ Rocks!";
        std::string s2 = "Hello";
        s2 = s1;                            // No need to do strcpy(), we can just use the assignment operator

    - Concatentation:
        std::string s1 = "C++";
        std::string s2 = "is powerful";
        std::string sentence;
        sentence = s1 + " " + s2 + " language.";

        However we cannot do:
        sentence = "C++ " + "is powerful "; // This is illegal. Will not compile due to the fact that we have 2 C style string 
            literals. We cannot concatenate C style string literals.

    - Accessing Strings:
        - Like with vectors we can access C++ strings with indexing and the .at() method.
    
        std::string s1 = "Hello";
        std::cout << s1[0];                 // prints H 
        std::cout << s1.at(3);              // prints l
        - The .at() method has out of bounds checking, it will throw and exception if it goes out of bounds.

    - for loops with strings:
        for (char c: s1) {                  // the data type of the ranged based for loop is a char 
            std::cout << c;
        }

        for (int c: s1) {
            std::cout << c;                 // Rather than displaying the the character value, it will display the integer value
                                                that represents the char. These are the ASCII codes of those characters.
        }

        Manual for looping with strings:
        std::string s1 = "Apple";
        for (size_t i=0; i<s1.length(); i++) {
            std::cout << s1.at(i) << "\n";
        } 

        - The data type of i is size_t, this is the proper way to do it.

    - Comparing Strings:
        - ==, !=, <, <=, >, >=
        - Compared character by character lexically (capital letters come first then lower case).
        - We can compare:
            1) 2 std::string objects
            2) std::string object and C style literal
            3) std::string object and C style variable

    - Substrings:
        - substr() function - extracts a substring from a std::string
        - General syntax: object.substr(start_index, length);

        std::string s1 = "This is a test";
        std::cout << s1.substr(0, 4);       // This
        std::cout << s1.substr(10, 4);      // test

        - The substring does not change the original string, it only returns a sub section of it. (slicing in python)

        - find() function - Returns the index of a substring in a std::string 
        - General syntax: object.find(search_string);

        std::cout << s1.find("This")        // 0 this returns the index where the match is first found
        std::cout << s1.find("is", 4)       // find "is" and start the search at index 4. This returns 5
        std::cout << s1.find("XYZ");        // string::npos = no position information. We can use this during if statements

        - Removing characters with erase() and clear()
        erase():
            - Removes a substring of characters from a std::string
            - General syntax: object.erase(start_index, length);

            std::cout << s1.erase(0, 5);    // returns "is a test"
            std::cout << s1.erase(5, 4);    // returns "is a"
        
        clear():
            - std::cout << s1.clear()       // returns an empty string

    - .length() Method:
        std::string s1 = "Hello";
        std::cout << s1.length();           // 5

        s1 += " Bob";

        std::cout << s1;                    // "Hello Bob"
        std::cout << s1.length();           // 9 - the space is included as part of the length.

    - Input and std::cin.getline();
        - We can use .getline() if we want to capture the entire line in the I/O stream including spaces. Normally spaces will 
            act as cut off points.
*/


#include <iostream>
#include <string>


int main() {
    std::string s1 = "Hello";
    s1 += " Bob";
    std::cout << s1.length() << "\n";
    std::cout << s1;

    std::cout << "\n";
    std::string secret_message {};
    std::cout << "Enter your message: ";
    std::getline(std::cin, secret_message);
    std::cout << "The secret message: "<< secret_message << " is: " << secret_message.length() << " characters long.";

    return 0;
}
