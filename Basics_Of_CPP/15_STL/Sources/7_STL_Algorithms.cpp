// STL Algorithms in C++

/*
STL Algorithms:
    - STL Algorithms work on a sequence of container elements provided to them by an iterator.
    - STL has many common and useful algorithms.
    - Look at the cppreference website for all of the algorithms.
    - Many algorithms require extra information in order to do their work:
        - Functors (Function Objects)
        - Function Pointers
        - Lambda Expressions (C++11)

    - In order to use the algorithms we must include the <algorithm> header file.
    - #include <algorithm>
    
    - Different containers support different types of iterators.
        - This determines the types of algorithms supported.

    - ALL STL algorithms expect iterators as thier arguments!
        - This determines the sequence obtained from the container.

Iterator Invalidation:
    - Iterators point to container elements.
    - It's possible iterators become invalid during data processing.
    - Suppose we are iterating over an vector with 10 elements, and then we clear() the vector while we're iterating, what
        happens to the iterator?
    - We will get undefinied behaviour, the iterator is pointing to invalid locations.

    - The cppreference / documentation has information on how iterators become invalid for all of the containers.

find Algorithm:
    - The find algorithm tires to locate the first accurrence of an element in a container.
    - This has lots of variations.
    - Returns an iterator pointing to the located element or end()

        std::vector<int> vec1 {10, 20, 30, 40, 50};
        auto loc = std::find(vec1.begin(), vec1.end(), 40);

        if (loc != vec1.end()) {
            std::cout << *loc << "\n";
        }

    - loc is a iterator object that is returned. It will return the value itself if it is found within the container, else it
        will return a 0 if the element is not within the container.

    - find needs to be able to compare objects. operator== is used and MUST be provided by the class.

for_each Algorithm:
    - Applies a function to each of the element in the itrerator. What function does it apply? It applies the function that we
        tell it to apply.
    - The Function must be provided to the algorithm as 1 of 3 options:
        1) Functor (Function Object)
        2) Function Pointer
        3) Lambda Expression - This is the best wayy to provide a function for an algorithm

ex) Square Each Element Example
1) Using a Functor:
    
        struct Square_Functor {
            void operator() (int x) {           // overload the () operator
                std::cout << x * x << " ";
            }
        };

        Square_Functor square;                  // Function object

        std::vector<int> vec1 {1, 2, 3, 4};

        std::for_each(vec1.begin(), vec1.end(), square);
        // 1 4 9 16

    - NOTE that the original container elements are NOT modified!
    - square is a instance of the data type struct Square_Function

2) Using a Function Pointer

        void square(int x) {                // regular function
            std::cout << x * x << " ";
        }

        std::for_each(vec1.begin(), vec1.end(), square);

    - Here the square parameter on line 81 is the name of a regular function 
    - What's being passed into the for_each function is a pointer to the square function, which is the address of the function
        square itself.
    - We only put the name of the function, NOT the (), we do NOT want to actually call the function!

3) Using a Lambda Expression:

        std::for_each(vec1.begin(), vec1.end(),
            [](int x) {std::cout << x * x << " ";});        // This is the lambda expression

    - (int x) is the parameter list.
    - {std::cout << x * x << " ";} is the function body.
*/


#include <iostream>
#include <algorithm>


int main() {

    return 0;
}
