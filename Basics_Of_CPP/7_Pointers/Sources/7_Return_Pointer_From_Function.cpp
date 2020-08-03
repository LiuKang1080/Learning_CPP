// Returning Pointers From Functions in C++

/*
Returning Pointers From Functions:
    - Functions can also return pointers.
    - General Syntax:

        type *function_name(parameters);

    - We should return pointers when:
        1) Memory is dynamically allocated in the function
        2) Return pointers to data that was passed in 

    - NEVER return a pointer to a local function variable!
    - The function will return an address of whatever type we specified in the function declaration.

    ex)

        int *largest_int(int *p_int1, int *p_int2) {
            if (*p_int1 > *p_int2) {                    // we're not comparing the pointers themselves. we're comparing the
                return p_int1;                          // values that they point to
            } else {
                return p_int2;
            }
        }

        int main() {
            int a = 100;
            int b = 200;

            int *p_largest_num = nullptr;
            p_largest_num = largest_int(&a, &b);
            std::cout << *p_largest_num << "\n";

            return 0;
        }

    - Dynamically allocate memory inside the function, and then return the address from the function. ex)

        int *create_array(size_t size, int init_value=0) {
            int *p_new_storage = nullptr;

            p_new_storage = new int[size];      // pointer pointing to the data in the Heap, we do NOT want to lose this pointer
                                                            
            for (size_t i=0; i<size; ++i) {
                *(p_new_storage + 1) = init_value;
            }

            return p_new_storage;
        }

        int main() {
            int *p_array = nullptr;                     // will be allocated by the function
            p_array = create_array(100, 10);            // 100 elements in the array each having a value of 10

            // create array returns a pointer that is pointing to some address on the Heap
            // we return that address and store it into the p_array pointer
            // when the create_array() function is done running all local variables in that function will be deleted off of the
                stack 
            // we now have a pointer in main() that points to that address on the Heap
            // if we do not have a pointer that is pointing to that specific memory address, then we will have a memory leak

            ... use the array ...

            delete [] p_array;                          // free up the storage, notice how we free the storage in main.

            return 0;
        }

    - Never return a pointer to a local variable!

        int *dont_do_this() {
            int size {};
            ...
            return &size;
        }

        - size is a local variable, we're returning the address of a local variable in the function 
        - Once this function is done running it will go out of scope. 
        - Remember the stack, when this function is done the local variables on the stack will be deleted.
        - The pointer that we return will still be pointing to that address, since the function on the stack is now cleared the
            pointer will now be pointing to garbage data.
        - These types of bugs are extreamly difficult to find.

        int *dont_this_either() {
            int size {};
            int *p_int = &size;
            ...
            return p_int;
        }
*/


#include <iostream>


int main() {

    return 0;
}
