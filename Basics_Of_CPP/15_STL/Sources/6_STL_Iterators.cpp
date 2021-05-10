// STL Iterators in C++

/*
STL Iterators:
    - Allows abstracting an arbitrary container as a sequence of elements. It does not matter what the container actually is.
    - They are objects that work like pointers by design.
    - Most container classes can be traversed with iterators.

Declaring Iterators:
    - Iterators must be declared based on the container type they will iterate over.

        container_type::iterator_type iterator_name;

    - ex) 

        std::vector<int>::iterator it1;
        std::list<std::string>::iterator it2;
        std::map<std::string, std::string>::iterator it3;
        std::set<char>::iterator it4;

    - it1 is an iterator that iterates over a vector of integers. It can ONLY iterate over a vector of itegers!
    - We must be very specific when declaring an iterator.

.begin() and .end() methods for iterators:
    - The .begin() and .end() methods

        std::vector<int> vec1 {1, 2, 3};

        |   1   |   2   |   3   |       |

    - vec1.begin() will point to the FIRST element
    - vec1.end() will point to the location AFTER the last element!
    - .end() is NOT the last element! It is AFTER the last element! This is consistent throughout the STL.

    - Almost all container objects have .begin() and .end() methods, they return an iterator object that's pointing to the first
        element, or 1 past the last element in the container.

Initializing Iterators:
    
        std::vector<int> vec1 {1, 2, 3};
        std::vector<int>::iterator it = vec1.begin();

        OR

        auto it = vec1.begin();         // let the compiler determine the data type of the variable named it

    - Using the iterator, this will feel like using a pointer.
    - ++it, it++, *it, it->, ... etc

    - When we increment an iterator, we're asking it to point to the next element in the container.
    - How it works is determined by the container we're using.

Using an Iterator:
    
        std::vector<int> vec1 {1, 2, 3};
        std::vector<int>::iterator it = vec1.begin();

        while (it != vec1.end()) {
            std::cout << *it << "\n";
            ++it;
        }

        // 1 2 3

    - Why not use a range-based for loop? We could. We will see that the range-based for loop is converted into an iterator based
        for loop behind the scenes.
    
    - Not all containers support random access like vectors do, so a range-based for loop might not work. However an iterator may
        still be able to traverse the container. This is syntax more than anything.
    
        for (auto it=vec1.begin(); it!=vec1.end(); it++) {
            std::cout << *it << "\n";
        }

        // 1 2 3

    - Here in the for loop, the beginning is: auto it = vec1.begin(), the ending condition is: it != vec1.end(), and the
        increment is it++

    - This is how a range-based for loop works behind the scenes.

Using an Iterator / std::set example:
    
        std::set<char> suits {'C', 'H', 'S', 'D'};
        auto it = suits.begin();                        // let the compiler determine the data types
        
        while (it != suits.end()) {
            std::cout << *it << "\n";
            ++it;
        }

Reverse Iterator:
    - Works in reverse.
    - Last element is the first, and the first element is the last.
    - ++ moves backwards, and -- moves forwards. (!!! Pay Attention !!!)

        std::vector<int> vec1 {1, 2, 3};
        std::vector<int>::reverse_iterator rev_it = vec1.begin();

        while (it != vec1.end()) {
            std::cout << *it << "\n";
            ++it;
        }

        // 3 2 1

Other Iterators:
    - Normal iterators
        .begin() | .end()

    - const_iterator
        .cbegin() | .cend()

    - reverse_iterator
        .rbegin() | .rend()

    - const_reverse_iterator
        .crbegin() | .crend()
*/


#include <iostream>


int main() {

    return 0;
}
