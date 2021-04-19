// Interger Stream Manipulation in C++

/*
Formatting Integer Types:
    - Defualt when displaying integers is dec (base 10).
    
    - noshowbase = prefix used to show hexadecimal or octal
    - nouppercase = when displaying a prefix and hex values it will be lowercase
    - noshowpos = no "+" sign is displayed for positive numbers

    - Once again, these manipulators will stay active affecting ALL further output to the stream.

Setting different bases:

        int num = 255;
        std::cout << std::dec << num;       // displays 255
        std::cout << std::hex << num;       // displays ff (lower case is defualt)
        std::cout << std::dec << num;       // displays 377

    - 255 and 377 out of context it is impossible to tell the difference if 1 is a dec or an oct. We can use the showbase
        manipulation to tell the difference. This will display a prefix in front of the number.

        std::cout << std::showbase;
        std::cout << std::dec << num;       // displays 255
        std::cout << std::hex << num;       // displays 0xff (0x prefix for hexadecimal)
        std::cout << std::oct << num;       // displays 0377 (0 prefix for octal)

    - showbase applies to ALL further int outputs, it persists until we change it, or the program ends.
    - We can go back to defualt with:
        
        std::cout << std::noshowbase;

Displaying Hex Values in Upper Case:
    - we can use the showbase in combination with uppercase to format hex values:

        std::cout << std::showbase << std::uppercase;
        std::cout << std::hex << num;       // displays 0XFF (notice the x and f are both capitalized)               

Show Positive Sign Manipulator:
    - Displays the "+" sign for positive integers.

        int num1 = 255;
        int num2 = -255;

        std::cout << num1;          // displays 255
        std::cout << num2;          // displays -255
    
        std::cout << std::showpos;
        std::cout << num1;          // displays +255 (notice the + sign compared to before)
        std::cout << num2;          // displays -255

    - Certain applications work with the + sign in front of the numbers, those are the cases when we use this feature.
    - We can use noshowops to go back to normal output.

        std::cout << std::noshowpos;

    - We can reference the https://en.cppreference.com/w/ to look up the setf() and reset() methods for integer stream
        manipulation. Don't need to memorize the actual lines of code.
*/


#include <iostream>
#include <iomanip>


int main() {

    int num {255};

    std::cout << std::showbase;
    std::cout << std::dec << num << "\n";
    std::cout << std::hex << num << "\n";
    std::cout << std::oct << num << "\n";
    
    return 0;
}
