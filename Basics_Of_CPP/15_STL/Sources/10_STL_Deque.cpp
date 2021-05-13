// Deque | std::deque | Double Ended Queue in C++

/*
Deque | std::deque | Double Ended Queue:
    - Pronounced "deck", NOT "de-q".
    - In order to use this container we must first #include the <deque> header file.
    - Deque provides dynamic sizes hold elements:
        - Handeled automatically,
        - Can expand and contract as needed.
        - Elements are NOT stored in contigous memory.
        
    - Direct access of elements (constant time) (O(1))
    - Rapid insertion and deletion of elements at the FRONT AND BACK (constant time) (O(1))
    - Insertion and deletion of elements in other locations (linear time) (O(n))
    
Initialization and Assignment:
    - We can initialize and assign deques just like vectors, the syntax is exactly the same

        std::deque<int> d1 {1, 2, 3, 4};
        std::deque<int> d2 (10, 100);       // 10 elements, all being 100

    - The memory structure for deques can be thought of as linked lists of elements that are seperated. If space is not
        available then it will store the new elements in another locationn and then link that location to the previous element

Common Methods:
    - Most of the methods are exactly the same as with vectors. Refer to the cppreference for the full list.
    - Deques are really good at adding / removing elements from the front AND the back of the data structure

        // add elements:
        d1.push_back();
        d1.push_front();

        // remove elements:
        d1.pop_back();
        d1.pop_front();

    - .size()
    - .max_size()
    - .front()
    - .back()
    - .emplace_back()
    - .emplace_front()

    - All of these methods behave the same as with vectors, and the syntax for using them is the exact same.
    - Generally if we need to add things to the end OR at the front of something, then we should use a deque. If we need to add
        elements to the middle of something, then something like a list is going to be better. We should choose the right data
        structure for the right job. We should not just use whatever we want, whenever we want!
*/


#include <iostream>
#include <deque>
#include <vector>


// deque print function
void print(const std::deque<int> &deque) {
    for (auto i: deque) {
        std::cout << i << " ";
    }
}


int main() {
    // given a vector of ints from 1 - 10, and an empty deque, add all of the even numbers to the end of the deque and all of the
    // odd numbers to the front of the deque
    std::vector<int> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d1;

    // range-based for loop
    for (const auto &element: vec1) {
        // check to see if it's even
        if (element % 2 == 0) {
            // if it's even add to the end of the deque
            d1.push_back(element);
        } else {
            // else the number is odd, add it to the front of the deque
            d1.push_front(element);
        }   
    }

    // print the deque:
    print(d1);

    return 0;
}
