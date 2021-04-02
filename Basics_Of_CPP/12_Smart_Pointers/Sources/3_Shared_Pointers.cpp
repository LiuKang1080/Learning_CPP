// Shared Pointers in C++

/*
Shared Pointers:
    - Shared pointers are located in the <memory> header file
    - #include <memory>
    - shared_ptr : A smart pointer that provides shared ownership of heap objects.
    - shared_ptr<T>: 
        - Points to an object type T.
        - It is NOT unique so there can many shared pointers pointing to the same object on the heap.
        - Establishes shared ownership relationship.
        - CAN be assigned and copied.
        - CAN be moved.
        - Does NOT support managing arrays by defualt.
        - When the use_count goes to zero the managed object on the heap is destroyed.
            - We can use a reference counter as the number of shared pointers grows, the reference number grows. When the
                reference counter is zero, then we know that we have zero shared pointers pointing to that address. The last
                pointer that was pointing to that location cleans up that storage and deletes it before the shared pointer is
                deleted.

        std::shared_ptr<int> p1 = {new int {100}};
        std::cout << *p1 << "\n";
        *p1 = 200;
        std::cout << *p1 << "\n"; 

    - When p1 goes out of scope the data on the heap it is pointing to will be automatically destroyed. (As long as there are no
        other shared pointers pointing to it.) 
    - We do NOT need to manually call delete.
    
use_count() Method:
    - The use_count() method shows the number of shared pointer objects managing the heap object.
    
        std::shared_ptr<int> p1 {new int {100}};
        std::cout << p1.use_count() << "\n";        // 1
        
        std::shared_ptr<int> p2 {p1};               // shared ownership
        std::cout << p1.use_count() << "\n";        // 2

        p1.reset()                                  // dereference the use_count by 1, p1 is now NULLed out
        std::cout << p1.use_count() << "\n";        // 0
        std::cout << p2.use_count() << "\n";        // 1

    - Shared pointers allows us to point to user defined objects.

        std::shared_ptr<Account> p1 {new Account {"Ben"}};
        std::cout << *p1 << "\n";

        p1->deposit(1000);
        p1->withdraw(500);

    - We can use the same syntax for member access just like we did with raw pointers.
    - p1 is automatically deleted when it goes out of scope.

Shared Pointers - Vectors, Copy, and Move:
    - Unlike unique pointers, shared pointers CAN be copied and assigned.

        std::vector<std::shared_ptr<int>> vec1;
        std::shared_ptr<int> ptr {new int {100}};

        vec1.push_back(ptr);                        // this is OK, copy is allowed

        std::cout << ptr.use_count() << "\n";       // 2 (referenced from ptr, and the shared pointer in the vector)

std::make_shared<T>() - Make Shared Function:
    - Introduced in C++11
    
        std::shared_ptr<int> p1 = std::make_shared<int> (100);  // use count = 1
        std::shared_ptr<int> p2 {p1};                           // use count = 2
        std::shared_ptr<int> p3;                    
        // p3 IS initialized! It is NULL! All smart pointers are always initialized. It is impossible to have wild pointers with
        // smart pointers

        p3 = p1;                                                // use count = 3

        std::cout << p1.use_count() << "\n";
        std::cout << p2.use_count() << "\n";
        std::cout << p3.use_count() << "\n";

    - Use std::make_shared! It is more efficient!
    - The last pointer that references the heap, cleans up the heap. In this case p3 was the last shared pointer to reference
        that address on the heap, it is last pointer resposible for that address when p1 and p2 go out of scope. It will be last
        one to clean up that location on the heap.
*/


#include <iostream>
#include <memory>
#include <vector>


int main() {

    return 0;
}
