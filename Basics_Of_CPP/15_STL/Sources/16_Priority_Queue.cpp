// Priority Queue in C++

/*
Priority Queue:
    - Allows insertions and deletions of elements in order from the front of the container.
    - Elements are stored internally as a vector by defualt.
    - Elements are inserted in priority order (largest value will always be at the front)
    - No iterators are supported.
    - A Heap data structure is used for the priority queue. It is NOT the same as the the Heap / Free Store for dynamically
        allocated memory! They are not the same thing.
    
    - std::priority_queue
    - In order to use the prioirty queue, we must first #include the <queue> header file.

Common Methods:
    - .push() method:
        - Insert an element into the sorted order.
    
    - .pop() method:
        - Removes the top element (the largest element).

    - .top() method:
        - Access the top element.
        - Does not remove the element.

    - .empty() method:
        - Is the priority queue empty?
        - Return true or false depending on if the priority queue is empty or not.

    - .size() method:
        - Number of elements in the priority queue.

Initialization:
    
        std::priority_queue<int> pq;    // vector
        pq.push(10);
        pq.push(20);
        pq.push(5);

        std::cout << pq.top();          // 20 (largest number)
        pq.pop();                       // remove the largest number
        std::cout << pq.top();          // 10 is now the largest number

Display all of the elements in a Priority Queue:
    - Just like before with stack and the regular queue, our display function will need an priority queue passed in by VALUE!
        If we pass in a priority queue by reference then we will modifying the original priority queue. We need to pay attention
        to see how we are passing data into the function.

        template <typename T>
        void display(std::priority_queue<T> pq) {
            while (!pq.empty()) {
                T element = pq.top();               // set the largest element
                std::cout << element << " ";
                pq.pop();
            }
        }
*/


#include <iostream>
#include <queue>


// display function
template <typename T>
void display(std::priority_queue<T> pq) {
    while (!pq.empty()) {
        T element = pq.top();
        std::cout << element << " ";
        pq.pop();
    }

    std::cout << "\n";
}


int main() {
    // create an empty priority queue
    std::priority_queue<int> pq;

    // add elements into the priority queue
    for (auto i: {3, 7, 20, 50, 100, 10, 10, 30}) {     
        // priority queues can have duplicates
        pq.push(i);
    }

    // display the priority queue
    display(pq);

    return 0;
}
