// Pointers and Structs in C

/*
Pointer Basics:
    - Pointer is a variable that stores the ADDRESS of a variable. The value of the pointer is the memory address.
    - General Syntax for defining a pointer:

        data_type *pointer_name;

    - If we don't know what to initialize the pointer to, then we should initilize it to NULL.
    - If we need to explicitly need to use the NULL pointer definition we need to #include the <stddef.h> header file.

        int *ptr = NULL;

    - The NULL pointer is NOT the same as the Null Terminator ('\0').
    - If we already have a variable that we can initialize the pointer to, then we can use the address of operator ( & ):

        int num = 10;
        int *ptr = &num;

    - To access the value a pointer is pointing to we need to dereference the pointer.

        int result = 0;
        result = *ptr + 5;          // dereference the pointer (get 10), and add 5
        printf("%i", result);

    - !!! NEVER DEREFERENCE A NULL POINTER !!!
    - Always check a pointer for NULL before dereferencing it!

        if (!ptr_value) {
            // code block;
        }

        OR 

        if (ptr_value == NULL) {
            // code block;
        }

Pointers to Arrays:
    - Arrays in C and C++ ARE pointers under the hood.
    - When we define a pointer to an array, we do NOT designate the pointer as a "pointer to an array".
    - There is no such thing as: array *ptr_array = NULL;
    - If we want to assign a pointer to an array we just do:

        int values[100];            // an array with 100 spaces
        int *array_ptr = values;

    - The pointer will automatically point to the first element of the array.
    - We do not need to use the address of operator ( & ) 
    - We can manually do the pointer assignment ourselves, or we can let the compiler do this for us:

        int *array_ptr = &values;

        OR

        int *array_ptr = values;

Pointer Arithmetic:
    - Since pointers automatically point to the first element of an array, we can use the increment (++), and the decrement (--)
        operators to navigate through the array with the pointer.
    - We can use the general expression to access the values of the array:

        *(array_ptr + i);

    - Ex) 

        *(array_ptr + 10);

        - Take array_ptr add 10 to it, which means move to index 10, and then dereference the pointer to get the value.

Dynamic Memory Allocation in C:
    - malloc() is the function we use to dynamically allocate memory on the Heap.
    - The general syntax for allocating memeory is:

        int *num_ptr = malloc(25 * sizeof(int));

    - Allocate 25 spaces of ints, however large int is, and then point to that memory on the heap with the pointer.
    - We should always check to see if the memory we allocated actually went through, we can use an if statement to do that:

        int *num_ptr = malloc(25000000 * sizeof(int));
        if (!num_ptr) {
            // code to deal with memory allocation failure;
        }

Releasing Memory in C:
    - We should ALWAYS free / release the memory after we're done using it. We can do this by using the free() function.

        free(num_ptr);
        num_ptr = NULL;
    
    - After we're done freeing the memory, we should ALWAYS set the pointer to NULL.

Pointers to Structs in C:
    - We can also use pointer to point to structs, and use pointers to access members of a struct.

        struct Ractangle {
            int length;
            int width;
        };

        int main() {
            Rectangle r1 = {10, 5};     // set the lenght to 10, set the width to 5
            Rectangle *ptr = &r1;       // set a pointer to r1
            
            r1.length = 15;             // we can use the . operator to access the members of the struct

            // We need to access the member of the struct, and then dereference the pointer to get to the value if we use a pointer

            (*ptr).length = 7;          // we NEED to use (*ptr) becasue the ( . ) dot operator has higher precedence.
            // access the member of the struct, AND THEN dereference the pointer.

            // We can also use the arrow operator (->) to access the member of the struct and then dereference the pointer:
            ptr->length = 20;

            printf("Length is: %i \n", r1.length);  // should print out 20

            return 0;
        }

Dynamically Allocate Struct onto Heap in C:
    - Directly initialize the pointer to a struct on the heap:

        struct Rectangle *ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    - We need to type cast the malloc() function because it returns a void pointer. We type cast it to (struct Rectangle *)

Dynamically Allocate Struct onto Heap in C++:
    - Allocating memory in C++ is easier than it is in C. We use the new keyword to allocate memory on the heap.

        Rectangle *ptr = new Rectangle;         // assuming that a struct called Rectangle already exists
*/


#include <stdio.h>
#include <stdlib.h>


struct Rectangle {
    int length;
    int width;
};


int main() {
    struct Rectangle r1 = {10, 5};     // set the lenght to 10, set the width to 5
    struct Rectangle *ptr = &r1;       // set a pointer to r1
            
    r1.length = 15;             // we can use the . operator to access the members of the struct

    // We need to access the member of the struct, and then dereference the pointer to get to the value if we use a pointer

    (*ptr).length = 7;          // we NEED to use (*ptr) becasue the ( . ) dot operator has higher precedence.
    // access the member of the struct, AND THEN dereference the pointer.

    // We can also use the arrow operator (->) to access the member of the struct and then dereference the pointer:
    ptr->length = 20;

    printf("Stack Rectangle Length: %i \n", r1.length);  // should print out 20

    // ==========
    // dynamically allocate a struct into the heap
    struct Rectangle *heap_ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    // access the members of the struct using the -> arrow operator
    heap_ptr->length = 50;
    heap_ptr->width = 25;

    printf("Heap Rectangle Length: %i \n", heap_ptr->length);
    printf("Heap Rectangle Width: %i \n", heap_ptr->width);

    // free the memory after we're done using it:
    free(heap_ptr);
    heap_ptr = NULL;

    return 0;
}
