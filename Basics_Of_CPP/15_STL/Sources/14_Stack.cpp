// The C++ Stack

/*
Stack:
    - The stack is an adaptive container.
    - LIFO (Last In First Out) data structure.
    - Implemented as an adapter over other STL containers. It can be implemented as a vector, list, or a deque.
    - All operations on the stack occur on 1 of the ends of the stack (top).
    - No iterators are available.
    - Since we're only dealing with 1 end of the stack, it doesn't make sense to move through the rest of the stack, therefore
        no iterators.
    - Only containers that have the feature of front() and back() are implemented as a stack.
    
    - In order to use the stack, we must first #include the <stack> header file.
    - std::stack
    
Initialization of a Stack:
    - Since a stack is an adaptive class, we can choose what the underlying container will be.

        std::stack<int> s1;                 // deque (The STL will use a deque by defualt, if no container is provided as an argument)
        std::stack<int, std::vector<int>>;  // vector
        std::stack<int, std::list<int>>;    // list
        std::stack<int, std::deque<int>>;   // deque

Common Methods:
    - .push() method:
        - Insert an element at the top of the stack.

    - .pop() method:
        - Remove an element from the top of the stack.

    - .top() method:
        - Access the top element of the stack. Does NOT remove the element.
        - Returns a reference to the top element of the stack. We can modify it!

    - .empty() method:
        - Returns a true / false depending on if the stack is empty or not.

    - .size() method:
        - Returns the number of elements in the stack.

        std::stack<int> s1;
        s1.push(10);                // adds 10 to the stack

        s1.push(20);                // adds 20 to the stack
            20
            10

        s1.push(30);                // adds 30 to the stack
            30
            20
            10

        std::cout << s1.top();      // 30
        s1.pop();                   // remove 30 from the top of the stack
        s1.pop();                   // remove 20 from the top of the stack
        std::cout << s1.size();     // 1. Only 10 exists on the stack, only 1 element

Displaying all of the elements of a Stack:
    - Since a stack does not have any iterators we need to manually get each element, remove them from the stack after
        printing each element, and then moving onto the next element.
    - The stack that we pass in as an argument needs to be passed in by VALUE! Or else we will delete the original stack!
    - We need to pay attention to see if we actually need to pass in stacks by value or by reference!

        template<typename T>
        void display(std::stack<T> s) {
            while (!s.empty()) {                // while not empty
                T element = s.top();            // take the top element
                s.pop();                        // pop element
                std::cout << element << "\n";   
            }
        }
*/


#include <iostream>
#include <stack>


// displahy function
template <typename T>
void display(std::stack<T> stack) {
    while (!stack.empty()) {
        T element = stack.top();
        std::cout << element << " ";
        stack.pop();
    }
}


int main() {
    // create a stack with no elements
    std::stack<int> s1;

    // fill the stack with data
    for (auto i: {10, 20, 30, 40, 50}) {
        s1.push(i);
    }

    // call the display function to print out all of the elements
    display(s1);
    // remember that we're passing in s1 by VALUE, this will create a copy of the stack, and pass it into the function.
    // notice how the stack data is printed.

    return 0;
}
