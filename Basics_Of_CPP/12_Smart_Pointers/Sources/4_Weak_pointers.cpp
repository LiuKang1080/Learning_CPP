// Weak Pointers In C++

/*
Weak Pointers:
    - weak_ptr<T>
    - Weak Pointers are located in the <memory> header file.
    - #include <memory>
    - Provides a non-owning "weak" reference.
    - Points to an object of type T on the heap.
    - Does NOT participate in owning relationship.
    - ALWAYS created from a shared pointer (shared_ptr).
    - Does NOT increment or decrement the reference use_count
    - Used to prevent strong reference cycles which could prevent objects from being deleted.

    - Strong circular references / cyclic references 
        - A refers to B
        - B refers to A
        - Shared strong ownership prevents heap deallocation
        - When A and B both go out of scope they will be gone from the stack, but the data that they were pointing to on the
            heap will still exist. We will get a memory leak since we lose the pointers to that data location, and that memory
            region is now inaccessable.

    - The Solution:
        - Make one of the pointers in the circular references / cyclic references a non-owning or "weak" pointer.
        - Now the heap storage deallocation can occur properly.
        - We will not leak any memory this way.
*/


#include <iostream>
#include <memory>


// create classes that have circular references
// class B forward declaration - we will implement the class later
class B;

// class A
class A {
private:
    std::shared_ptr<B> b_ptr;

public:
    void set_B(std::shared_ptr<B> &b) {
        std::cout << "set_B method in Class A is called \n";
        b_ptr = b;
    }

    // constructor
    A() {
        std::cout << "A Constructor called in class A \n";
    }

    // destructor
    ~A() {
        std::cout << "A Destructor called in class A\n";
    }
};

// implementation of class B
class B {
private:
    // std::shared_ptr<A> a_ptr;
    // a strong circular reference
    // we need to make this a weak_ptr in order to break the strong circular reference

    // make this a weak pointer in order to fix the memory leak issue.
    // making it a weak pointer will not affect the reference count
    std::weak_ptr<A> a_ptr;

public:
    void set_A(std::shared_ptr<A> &a) {
        std::cout << "set_A method in Class B is called \n";
        a_ptr = a;
    }

    // constructor
    B() {
        std::cout << "B Constructor called in class B \n";
    }

    // destructor
    ~B() {
        std::cout << "B Destructor called in class B \n";
    }
};


int main() {
    // create A and B shared pointers
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    // here we're creating 2 shared pointers: pointer a points to an "A" object on the heap
    // pointer b is pointing to an "B" object on the heap 

    // now create the circular reference
    a->set_B(b);
    b->set_A(a);
    
    /*
        - The data that is in the memory address IS a pointer
        - The "A" object is pointing to the B object
        - The "B" object is pointing to the A object
        - When this is done BOTH A and B will have a reference count of 1
        - When A OR B tries to go out of scope it will still have a reference count of 1
            RATHER instead of A or B getting destroyed, a and b GET destoryed!
        - We lose the shared pointers a and b, but the data in the memory addresses / the objects A and B are still existing in
            the memory!
        - The objects are still in memory and we have no way to get to them since the pointers are now gone
        
        - If we actually run the program, we notice that the destructors NEVER got called!
            since the destructors never got called the objects are still in memory!

        - We need to change one of the shared pointers into a weak pointer in roder to fix this memory leak
            look at line 69. Once we've made it a weak pointer, the memory leak is no longer an issue, and BOTH of the class' 
            destructors are called!

        - This is a common use case for the weak_ptr. This happens more often that you think!
            Pay attention to see where the shared pointers are pointing to and determine if there is a circular reference. If 
            there is a cyclical reference, we need to make sure that one of the shared pointers is a weak pointer to resolve
            the cyclical reference and prevent memory leaks.
    */

    return 0;
}
