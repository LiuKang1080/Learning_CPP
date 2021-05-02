// STL in C++

/*
STL (Standard Template Library):
    - The STL has 3 main components:
        1) Containers: Collections of objects or primitive types
            (Arrays, Vectors, Deques (pronounced "deck"), Stack, Set, Map ... etc)

        2) Algorithms: Functions for processing sequences of elements from containers
            (find, max, count, accumulate, sort ... etc)

        3) Iterators: Generate squences of elements from containers
            (forward, reverse, by value, by reference, constant ... etc)

    - The STL is a library of powerful, reusable, adapatable, generic classes and functions.
    - It is implemented by using C++ Templates.
    - It has implementations of common data structures and algorithms.
    - It has known time and size complexity for its algorithms.
    - Tried and tested. Consistent. Extendable. Fast, and Type safe.
    
    - Simple sort example:

        #include <vector>
        #include <algorithm>

        std::vector<int> v1 {1, 5, 3};

    - We want to sort all of the elements in this vector, we want to sort it by increasing value

        std::sort(v1,begin(), v1.end());

        // now we print the values of the vector
        for (auto element: v1) {
            std::cout << element << "\n";
        }

        // we get 1 3 5

    - We used the sort function from the STL
    - It can sort any STL container, not just vectors

    - Simple accumulate example:

        int sum {};

        sum = std::accumulate(v1.begin(), v1.end(), 0);
        std::cout << sum << "\n";

        // we will get the result 9 (1 + 3 + 5)

    - Here .begin() is the starting position, .end() is the ending position.
    - The final argument is the data type of the sum / accumulation. (If we want to sum ints we use 0, if we want to sum doubles
        then we will use 0.0)

1) Containers / Types of Containers:
    1) Sequence Containers:
        - Maintains the ordering of the elements
        - arrays, vectors, lists, forward_list, deque (pronounced "deck")

    2) Associative Containers:
        - Insert elements in a pre-definied order or no order at all.
        - set, multi-set, map, multi-map

    3) Container Adapters:
        - stack, queue, priority queue

2) The STL Algorithms:
    - There are about 60 algorithms in the STL.
    - There are both modifying and non-modifying algorithms (modifying the sequence the algorithm acts upon)

3) Types of Iterators:
    - Input Iterators: From the container to the program
    - Output Iterators: From the program to the container
    - Forward Iterators: Navigate one item at a time in one direction
    - Bi-Directional Iterators: Navigate one item at a time in both directions
    - Random Access Iterators: Directly access a container item
*/


#include <iostream>
#include <algorithm>


int main() {

    return 0;
}
