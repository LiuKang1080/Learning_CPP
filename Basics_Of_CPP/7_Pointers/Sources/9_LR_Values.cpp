// L-Values and R-Values in C++

/*
L-Values:
    - Values that have names and are addressable.
    - Modifiable if they are not constants.

        int x = 100;                // x is an l-value
        x = 200;
        x = 1000 + 2000;

        std::string name = "Bob";   // name is an l-value
        name = "Alice";

        100 = x;                    // 100 is NOT an l-value, it is a literal

R-Values:
    - Non-addressable and non-assignable.
    - A value that is not an l-value. 
    - Anything that is not an l-value is considered an r-value.
    - On the right side of an assignment expression.
    - A temporary which is ingtended to be non-modifiable.
    - A literal.

        int x = 100;                // 100 is an r-value
        int max_num = max(5, 10);   // max(5, 10) is an r-value

    - R-values can be assigned to l-values explicitly.

        int x = 100;                // the r-value is assigned to the l-value x
        x = x + 100;                // r-value (x + 100) is assigned to the l-value x. (x + 100) evaluated is not addressable

L-Value References:
    - The references we've been using are l-value references, because we're referencing l-values.

        int x = 100;
        int &ref1 = x;              // ref1 is a reference to the l-value x 
        ref1 = 200;

        int &ref2 = 500;            // ERROR, 500 is an r-value 

    - The same applies to pass by reference in functions

        int square(int &n) {
            return n * n;
        }

        - the parameter &n is a reference.

        int num = 10;
        square(num);                // OK
        square(5);                  // ERROR - can't reference r-value 5 
*/


#include <iostream>


int main() {

    return 0;
}
