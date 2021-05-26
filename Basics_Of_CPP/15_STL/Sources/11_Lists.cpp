// Lists in C++

/*
C++ Lists:
    - Sequence containers.
    - Non-contigous in memory.
    - No direct access to elements with .at() or [] for element access.
    - Very efficient for inserting / removing elements once an element is found.

    - std::list
    - In order to use C++ lists, we need to #include the <list> header file.

    - Dynamic Size, changes size dynamically
    - The list is bi-directional (doubly - linked)
    - direct element is NOT provided
    - Rapid insertion / deletion of elements anywhere in the container (constant time) (O(1))
    - All iterators are available.
    - Iterators become invalid when the corresponding element is deleted.

        std::list<int> lst {1, 2, 3};

    - There are 3 elements, each of those those elements are doubly linked to the previous and next element
    - There is some overhead involved in maintaining these links within the list.
    - When we remove an element from the list, we need to re-link the list back together. The same thing occurs when we add an
        element.
    - It's most efficent when working with elements in the list that are NOT at the ends of the list.
    - If we're adding / removing elements at the beginning or the end of the list, then we should NOT be using a list, instead
        we should be using a deque!
    - We also need to take into consideration if we want the feature of element access? If we need to add / remove without
        needing the feature of direct element access, then the list data type is the best!
    
List Initialization:
    
        std::list<int> lst {1, 2, 3, 4, 5};
        std::list<int> lst1 (10, 100);          // 10 elements, each being 100

        std::list<std::string> stooges {
            std::string {"larry"},
            "moe",
            std::string {"curly"}
        };

        lst = {2, 4, 6, 8, 10};

Common Methods for Lists:
    - .size():
        - Shows the current size of the list
    
    - .max_size():
        - Shows the maximum size a list can be. Depends on the operating system.

    - .front():
        - The 1st element in the list.

    - .back():
        - The last element in the list.

    - Lists do NOT allow direct element access, no [] (subscript operator) or the .at() operator method.
    
    - .push_back() / .push_front():
        - Add an element to the back or the front of the list.

    - .pop_back() / .pop_front():
        - Remove an element at the front or back of the list.

    - .emplace_back() / .emplace_front():
        - Add user created / class objects' data directly into the list.

Iterators:
    - We can use iterators to iterate through the list container:

        std::list<int> lst {1, 2, 3, 4, 5};
        auto itr = std::find(lst.begin(), lst.end(), 3);    // create an iterator looking for the number 3 in the list

    - lst.insert(itr, 10);      // 1, 2, 10, 3, 4, 5 
        - The iterator is pointing to 3, we use this function to insert the number 10 at that location. It pushes the rest of the
            elements towards the right, and we add the number provided at the location of 3.

    - lst.erase(itr);       // erases the 3     1, 2, 10, 4, 5
        - The iterator will become invalid! itr was poiting to 3, now 3 is gone, where is itr pointing to now?

    - lst.resize(2);        // 1, 2     all elements after the 2nd element will be gone

    - lst.resize(5);        // 1, 2, 0, 0, 0    resizing upwards will set all of the defualt initialization of 0s

Traversing the List:
    - Since lists are bi-directional we can move in both directions from an element using the increment and the decrement operator
        ++, --

        std::list<int> lst {1, 2, 3, 4, 5};
        auto itr = std::find(lst.begin(), lst.end(), 3);    // itr points to the element 3

        std::cout << *itr;      // 3
        itr++;
        
        std::cout << *itr;      // 4
        itr--;
        itr--;

        std::cout << *itr;      // 2

Forward Lists in C++
    - Added in C++11
    - std::forward_list, if we want to use this we need to first #import the <forward_list> header file.
    - Dynamic Size: 
        - List of elements
        - List is uni-directional (singly-linked)
        - Less overhead than a standard std::list

    - Direct element is NOT provided
    - Rapid insertion / deletion of elements anywhere in the container. (Constant time) (O(1))
    - Reverse Iterators are NOT provided!
    - Iterator becomes invalid when the corresponding element is deleted!

Forward List Methods:
    - There are NO back() methods, NO reverses!
    
    - .max_size():
        - Shows the maximum size a forward_list can be. Depends on the operating system
    - .front():
        - 1st element
    
    - There is NO:
        - .size() method
        - .back() method

    - front() methods:
        - .push_front():
            - Add an element to the beginning of the forward list
        - .pop_front():
            - Remove an element at the front of the forward list
        - .emplace_front():
            - Add a class object directly into the forward list

    - Since the forward list is a singly linked list, it makes sense to insert elements into the list AFTER an iterator 
        reference.
    - Forward list supports methods named after this
    - ex)

        std::forward_list<int> lst {1, 2, 3, 4, 5};
        auto itr = std::find(lst.begin(), lst.end(), 3);        // an iterator finding the number 3

        lst.insert_after(itr, 10);
        // 1, 2, 3, 10, 4, 5

    - The first argument is what is adding to the list
    - the second argument is what data to actually add into the list

        lst.emplace_after(100);
        // 1, 2, 3, 100, 10, 4, 5

        lst.erase_after(itr);
        // erase the 100, remember the itr is pointing to the number 3
        // 1, 2, 3, 10, 4, 5

        lst.resize(2);
        // 1, 2

        lst.resize(5);
        // 1, 2, 0, 0, 0

    - re-sizing upwards will defualt initialize with 0s
*/


#include <iostream>
#include <list>
#include <forward_list>


int main() {

    return 0;
}
