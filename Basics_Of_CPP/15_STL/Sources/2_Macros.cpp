// Generic Programming With Macros in C++

/*
Generic Programming With Macros:
    - Generic Programming = Code that works with a verity of types as arguments as long as those argument types meet the specific
        syntactic and semantic requirements. - Bjarne Stroustrup
    - There are 3 types of Generic Programming:
        1) Macros **beware** (beware using macros espeically with arguments)
        2) Function Templates
        3) Class Templates

Macros:
    - All macros start with a #
    - All # statements are pre-processor directives
    - There is no type information (The pre-processor does NOT know C++)
    - The pre-processor performs simple substitution

        #define MAX_SIZE 100
        #define PI 3.1415

    - There is no ; at the end of the line.
    - If there is a ; then it will be substituted in where ever MAX_SIZE is, and we don't want that
    
        if (num > MAX_SIZE) {
            std::cout << "Big \n";
        }

        double area = PI * r * r;
        std::cout << area;

    - The pre-processor goes through the code and removes all of the # statements, and it replaces it with the values where those
        names appear.
    - Then the processed file is sent to the C++ compiler.
    - The better way to do this with constants (const). Constants are typed, and are known to the compiler.

Why Macros?
    
        int max(int a, int b) {
            return (a > b)? a:b;
        }

        int x = 100;
        int y = 200;
        std::cout << max(x, y);     // displays 200

    - What about a max() function for ints, floats, doubles, chars? We could end up writing many max() functions. The code is the
        same for all of them, but the data type is different.
    - We can make this generic by defining this function with a macros:

        #define MAX(a, b) ((a > b)? a:b)

        std::cout << MAX(10, 20);       // 20
        std::cout << MAX(2.5, 7.5);     // 7.5
        std::cout << MAX('a', 's');     // s

    - Remember that the pre-processor is simply performing a substitution. It does NOT know any C++!
    
    - We need to be careful with macros!

        #define SQUARE(a) a*a

        result = SQUARE(5);             // expect 25
        result = 5*5;                   // get 25

        result = 100 / SQUARE(5);       // expect 4
        result = 100 / 5*5;             // get 100!

    - We do not the result we were looking for. This is just simple substitution!
    - We need to define the macros better

        #define SQUARE(a) ((a) * (a))

        result = 100 / SQUARE(5);       // expect 25
        result = 100 / ((5) * (5));     // get 25

    - We actually do not want to do this, since the compiler does not do this, we should not do this either, this is all handled
        by the pre-processor. We should let the compiler handle ALL C++ stuff, NOT the pre-processor!
    - DO NOT use macros with arguments in your C++ code!
    
    - The better way to do this is Templates!
*/


#include <iostream>


int main() {

    return 0;
}
