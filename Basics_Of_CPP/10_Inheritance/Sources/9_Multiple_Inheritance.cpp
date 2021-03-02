// Multiple Inheritance in C++

/*
Multiple Inheritance:
    - When a Derived class inherits from 2 or more Base classes at the same time.
    - The Base class may belong to unrelated class hierarchies.

    - ex)
                            Person 

                Employee                Student

        Faculty    Admin    Staff

          Deparment Chair
    
    - A Department Chair 
        - "is-a" Faculty and
        - "is-a" Administrator

    - C++ Syntax for multiple inheritance:
    
    class Department_Chair: public Faculty, public Administrator {
        ...
    };

    - With multiple inheritance:
        - There are some interesting use cases
        - Easily misused
        - Can be very complex

    - Remember the Diamond problem!
        - How does the inheritance work?
        - B and C inherit from A
        - D inherits from both B and C 
        - How / What does D inherit from A, B, and C?
*/


#include <iostream>


int main() {

    return 0;
}
