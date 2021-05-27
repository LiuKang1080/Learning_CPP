// Queue in C++

/*
Queue in C++:
    - The queue is a FIFO (First In First Out) data structure.
    - The queue is implmented as an adapter over other STL containers.
    - Implemented as a list or a deque.
    - Elements are pushed at the back, and popped from the front.
    - No iterators are supported.
    - We cannot add or remove elements from the middle of the queue, therefore iterators are not supported.
    - Think of queues as a waiting line. Elements enter on one end, and leave from the other end.

    - std::queue
    - In order to use the queue, we must first #include the <queue> header file.

Common Methods:
    - .push() method:
        - Add an element to the back of the queue.

    - .pop() method:
        - Remove an element from the front of the queue.

    - .front() method:
        - Access the element at the front of the queue.
        - Does not remove the element.
        
    - .back() method:
        - Access the element at the back of the queue.
        - Does not remove the element.

    - .empty() method:
        - Is the queue empty?
        - Returns a true / false depending on if the queue is empty or not.

    - .size() method:
        - Returns the number of elements in the queue.

Initialization:
    - Since the queue is an adapter class, we can choose what the underlying container will be. Our options are Lists and Deques.

        std::queue<int> q1;                     // deque (The STL will default to deques)
        std::queue<int, std::list<int>> q2;     // list
        std::queue<int, std::deque<int>> q3;    // deque

        q1.push(10);        // add 10 to the queue. 10 is the at the front and the back of the queue
            10
        
        q1.push(20);        // add 20 to the BACK of the queue, 10 is at the front
            20 10

        q1.push(30);        // add 30 to the back of the queue, 10 is still at the front
            30 20 10

        std::cout << q1.front();    // 10 
        std::cout << q1.back();     // 30

        q1.pop();       // remove 10
        q1.pop();       // remove 20

        std::cout << q1.size();     // 1 There is only 1 element (30)

Display All Elements in a Queue:
    - We can manually create a display function that displays all of the elements. The display function requires a queue to be
        passed in as an argument, it requires it to be passed in by VALUE! It needs to be passed in by value so that we make
        changes to the COPY. If it's passed in by reference, then we will be modifying the original queue! We need to pay 
        attention to how we're passing in data into functions.

        template <typename T>
        void display(std::queue<T> queue) {
            while (!queue.empty()) {
                T element = queue.front();
                std::cout << element << " ";
                queue.pop();
            }
        }
*/


#include <iostream>
#include <queue>


// display function
template <typename T>
void display(std::queue<T> queue) {
    while (!queue.empty()) {
        T element = queue.front();
        std::cout << element << " ";
        queue.pop();
    }

    std::cout << "\n";
}


int main() {
    // create an empty queue
    std::queue<int> q1;

    // use a for loop to add elements into the queue
    for (auto i: {10, 20, 30}) {
        q1.push(i);
    }

    // display all of the elements in the queue
    display(q1);

    // display the front, and the back
    std::cout << "Front: " << q1.front() << ", Back: " << q1.back();

    return 0;
}
