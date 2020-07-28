// Pointer Arithmetic in C++

/*
Pointer Arithmetic:
    - Pointers can be used in: Assignment, Arithmetic, and Comparison expressions.
    - C++ allows pointer arithmetic. Generally pointer arithmetic only makes sense with raw arrays.

++ and -- Operators:
    - (++) increments a pointer to the next array element.
        p_int++;
    - (--) decrements a pointer to the previous array element.
        p_int--;

Addition and Subtraction Operators:
    - (+) increments a pointer by n * sizeof(type)

        p_int += n; OR p_int = p_int + n;

    - (-) decrements a pointer by n * sizeof(type)

        p_int -= n; OR p_int = p_int - n;

Subtracting 2 Pointers:
    - Subtracting 2 pointers determines the number of elements between the 2 pointers.
    - The 2 pointers must be of the same data type. 
    - If the 2 pointers are different data types then we will get a compiler error.

== and != Operators:
    - == determines if 2 pointers are pointing to the same location. This does NOT compare if the data values are the same.
*/


#include <iostream>


int main() {

    return 0;
}
