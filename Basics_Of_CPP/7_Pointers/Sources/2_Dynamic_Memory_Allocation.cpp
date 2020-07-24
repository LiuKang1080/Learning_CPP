// Dynamic Memory Allocation in C++

/*
Dynamic Memory Allocation:
    - Allocates storage on the Heap at runtime.
    - We can allocate storage for a variable at run time, or arrays.
        - For Arrays before we had to provide the size of the array, and that was fixed. Vectors grow and shrink dynamically.
    - We can use pointers to access newly allocated memory on the Heap storage.
    - ALL memory that is allocated dynamically via a pointer comes from the Heap.
    
new:
    - We can use the 'new' keyword to allocate storage.
    
        int *p_int = nullptr;
        p_int = new int;                // allocate an int on the Heap
                                        // create a new storage at runtime, and store that address in p_int
        std::cout << p_int << "\n";
        std::cout << *p_int << "\n";    // garbage data will be displayed 

        *p_int = 25;                    // dereference the pointer and assign it the value of 25 at the address
        std::cout << *p_int << "\n";    // 25 

    - The storage is on the Heap, and contains garbage data until we initalize it.
    - The allocated storage does not have a name. The only way to get to that storage is through the pointer.
    - If we lose the pointer (going out of scope / reassignment of the pointer) then we lost the only way to get back to that
        storage (memory leaks).

    - Once we're done using that storage, we must deallocate that storage so it can be used by the rest of the program.

delete:
    - We can use the 'delete' keyword to deallocate storage.

        int *p_int = nullptr;
        p_int = new int;            // allocate storage for an int on the Heap 
        .
        .
        .
        delete p_int;               // frees the allocated storage

    - Using delete: We need to make sure that the address that we use delete on is an address that was created on the heap
        with new.

new[]:
    - Create multiple spaces of data on the Heap at once

        int *p_array = nullptr;
        int size {};                // uninitialized array 

        std::cout << "How big is the array? : " << "\n";
        std::cin >> size;

        p_array = new int[size];    // allocate the array on the Heap

    - This will attempt to allocate that many integers on the Heap contigously in memory. If the storage is successful, the the
        address of the 1st integer is stored in p_array.

delete[]:
    - Deleting contigous array in memory, we can use the [] after the 'delete' keyword.

        delete [] p_array;          // deletes the entire array in memory

    - The brackets MUST be empty!
    - DO NOT include anything inside the brackets.
*/


#include <iostream>


int main() {

    return 0;
}
