// Smart Pointers: Unique Pointers in C++

/*
Unique Pointer | std::unique_ptr:
    - Simple smart pointer, very efficient.
    - Drop in replacement for raw pointers in many cases.
    - Unique pointers are located in the <memory> header file
    - #include <memory>

    - General Syntax:

        unique_ptr<T>

    - Points to an object of type T on the heap.
    - It is unique. There can only be 1 unique pointer pointing to the same object on the heap.
    - Owns what it is pointing to.
    - Cannot be copied (copy constructors are not available. We will get a compiler error if we try to copy the unique pointer)
    - CAN be moved (great for STL objects like the vector)
    - When the pointer goes out of scope whatever it points to is automatically destroyed.
    
        std::unique_ptr<int> p1 {new int {100}};

        - A unique pointer pointing to an int 

        std::cout << *p1 << "\n";       // 100

        - the syntax for using the pointer is the same as using a raw pointer
        - we can use the standard dereference operator

        *p1 = 200;
        std::cout << p1 << "\n";        // 200

        - whenever p1 goes out scope it will automatically be deleted.

.get() Method:
    - returns the pointer value to the managed object 

        std::cout << p1.get() << "\n";      // 0x123456

.reset() Method:
    - Sets the pointer to nullptr and the memory it points to will be released.

        p1.reset();

Pointer Checks:
    - We can also check to see if a pointer is initialized:

        if (p1) {
            std::cout << *p1 << "\n";       // we will get an error since we just NULL'd out the pointer on line 41
        }

Pointers To User Defined Objects:
    - We can also point to user defined objects

        std::unique_ptr<Account> p1 {new Account {"Bob"}};
        std::cout << *p1 << "\n";

        p1->deposit(1000);
        p1->withdraw(100);

    - The pointer is automatically deleted when p1 goes out scope and the storage on the heap is freed.

Unique Pointer - Vectors and Move:
    
    std::vector<std::unique_ptr<int>> vec;
    // a vector that stores unique pointers that all point to ints

    std::unique_ptr<int> ptr {new int {100}};
    // a unique pointer pointing to an int 

    vec.push_back{ptr};     // ERROR - Copy NOT allowed for unique pointers

    - We're trying to push ptr onto vec, this results in a copy of vec first, then the additional ptr attachment. This is not
        allowed! No copies!

    vec.push_back(std::move(ptr));

    - In this case ptr gives up the ownership of the pointer and it's moved to the vector. The vec now owns the pointer and ptr
        will be set to nullptr. When vec goes out of scope it will deallocate all of the elements and the storage on the heap
        will be freed.

A Better Way To Initialize Pointers | std::make_unique<>():
    - C++14 and onward
    
        std::unique_ptr<int> p1 = std::make_unique<int> (100);
    
    - The make_unique function returns a unique pointer for the specified type, and allows us to pass in initialization values
        into the constructor

        std::unique_ptr<Account> p2 = std::make_unique<Account> ("Alice", 1000);

        auto p3 = std::make_unique<Player> ("Hero", 100, 100);

        - The compiler decides what type p3 will be based on what make_unique returns.
*/


#include <iostream>
#include <memory>


int main() {
    // create a unique pointer
    std::unique_ptr<int> p1 = std::make_unique<int> (100);
    std::cout << "Printing out just p1, this is the address value: " << p1.get() << "\n";
    std::cout << "Printing out the value that p1 is pointing to: " << *p1 << "\n";

    // NULL out the pointer for good habits
    p1.reset();
    // when p1 automaticallt goes out of scope it will automatically free up the space, but we can manually clean up the pointer
    // when we're done using it

    return 0;
}
