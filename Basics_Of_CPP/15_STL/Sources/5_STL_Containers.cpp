// STL Containers in C++

/*
STL Containers:
    - Data structure that can store object of almost any type.
        - Uses template based classes.
    
    - Each container has member functions
        - Some member functions are specific to the container
        - Others are available to all containers

    - Each container has an associated header file
        - #include<container_type>

Common Container Methods:
    - defualt constructor, overloaded constructor, copy & move constructor, destructor, copy & move assignment (operator=), size,
        empty, insert, and others...
    - We can also compare 2 containers with: < and <=, > and >=, == and !=, swap, erase, clear, begin and end, and others...

    - What types of elements can we store in a container?
        - A COPY of the element will be stored in the container
            - All primitives are OK

        - Elements should be:
            - Copyable and assignable (copy constructor / copy assignment)
            - Movable for efficiency (move constructor / move assignment)

        - Ordered associative containers must be able to compare elements
            - operator<, operator= must be overloaded

    - We must overload the constructors and other operators properly in order to use our objects within containers
    - The compiler can handle most of the work, but we need to make sure we're properly doing it.
*/


#include <iostream>


int main() {

    return 0;
}
