// Function Calls in C++

/*
Scope:
    - Scope determines when and where an identifier can be used.
    - C++ uses static lexical scoping.
    - 2 types of scopes: Local and Global scopes.

    Local or Block Scope: 
        - Identifiers are declared within { } blocks.
        - Function parameters have block scopes.
        - They are only visible within the { } block where it is declared.
        - Function local variables are only active while the function is executing. This is known as the lifetime of an 
            identifier.
        - Local variables are NOT preserved between function calls.
        - Within nested blocks inner blocks can "see", but outer blocks cannot "see" in.

    Static Local Variables:
        - Declared with static qualifier 

            static int value = 5;

        - Value is preserved between function calls
        - Only initialized the first time the function is called.

    Global Scope: 
        - Identifier declared outside of any function or class.
        - Visible to to all parts of the program after it has been declared.
        - Global CONSTANTS are okay, but the general best practice is to NOT use global variables.
            - We reduce dependencies. Allows for easier maintainability, and resuability.
            - Sometimes functions can change the value of the global variable, we manually need to keep track of the values and 
                detrermine if the change is intended or not. Don't use global variables! const global variables or constexpr are
                fine.
*/


#include <iostream>


int main() {

    return 0;
}
