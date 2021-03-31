// Smart Pointers in C++

/*
Smart Pointers:
    - Ultimately we want to write code that has NO "new" and "delete" keywords. All of the memory management should be handled by
        the C++ compiler.

Issues With Raw Pointers:
    - C++ provides felxibility with memory management:
        - Allocation
        - Deallocation
        - Lifetime management
    
    - With this felxibility comes potentially serious problems:
        - Unitialized (wild) pointers
        - Memory leaks
        - Dangaling pointers (pointing to a storage location that the pointer thinks is still valid, but has already been
            deallocated)
        - Not exception safe
    
    - Raw pointers bring ownership issues:
        - Who owns the pointer?
        - When should a pointer be deleted?

What Is A Smart Pointer?:
    - Smart pointers are objects, implemented as C++ template classes which we can instantiate.
    - Can only point to heap-allocated memory
    - They are automatically deleted when they are no longer needed.
    - Smart pointers adhear to RAII principles.

    - C++ smart pointers:
        - Unique Pointer (unique_ptr)
        - Shared Pointer (shared_ptr)
        - Weak Pointer (weak_ptr)
        
        - Auto Pointer (auto_ptr) (Deprecated - we will not be covering this)

    - We need to include the specific header file in order to use smart pointers

        #include <memory>

    - C++ smart pointers are defined by class templates
        - Wrapper around a raw pointer.
        - Provides overloaded operators:
            - dereference (*)
            - member selection (->)
            - pointer arithmetic is NOT supported (++, --, etc)
            - can have custom deleters

    - General Syntax:
        
        std::smart_pointer_type<some_class> ptr = ...;
        ptr->method();
        std::cout << (*ptr) << "\n";                        // dereference the pointer

    - pointer will automatically be destroyed when it is no longer needed.

RAII - Resource Acquisition Is Initialization:
    - Common idiom / patter in software development, based on container object lifetime
    - RAII objects are allocated on the stack.
    
    - Resource Acquisition:
        - Open a file
        - Allocate memory
        - Acquire a lock

    - Is Initialization:
        - The resource is acquired in a constructor.
        - The resource is acquired at object initialization time.

    - Resource Relinquishing:
        - Happens in the destructor
            - Cloasing a file
            - Deallocating memory
            - Releasing a lock
*/


#include <iostream>
#include <memory>
// need to include the memory header file in order to use the smart pointers


int main() {

    return 0;
}
