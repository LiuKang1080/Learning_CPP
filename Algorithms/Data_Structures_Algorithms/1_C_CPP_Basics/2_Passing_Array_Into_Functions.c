// Passing Arrays Into Functions in C and C++

/*
Passing in Arrays Into Functions in C and C++:
    - Takke for example, we want to pass in an array into a function that prints the contents of the array:

        void print_array(int a[], int array_size) {
            // print the contents of the array
            for (int i = 0; i < array_size; i++) {
                printf("%i", a[i]);
            }
        }

        int main() {
            int a[5] = {2, 4, 6, 8, 10};

            print_array(a, 5);
        }

    - The method in which the array is passed into the function is Pass By Address.
    - Arrays CANNOT be passed by value at all in C or C++.
    - Arrays can only be passed by address. The address of the 1st element is given into the parameter of the function. Behind
        the scenes a pointer is pointing to the array from the parameter of the function.

    - With the definition of the function, we can also use a pointer as the parameter, we can also do:

        void print_array(int *a, int array_size) 

Returning An Array From a Function:
    - We can also return arrays from functions:

        int [] arr_rtrn(int array_size) {
            int *ptr = NULL;
            ptr = (int *)malloc(array_size * sizeof(int));

            return ptr;
        }

        int main() {
            int *my_ptr = NULL;
            my_ptr = arr_rtrn(5);
            
            // we declare a pointer, and use that pointer to catch the return of the array on the heap.
            // We need to be careful NOT to lose this pointer before we free the memory on the heap, or else we will lose access
                to that region of memory and we will get a memory leak.

            return 0;
        }

    - Since an array IS a pointer we can change the syntax to be:

        int * arr_rtrn(int array_size)

    - We should be explicit. If we have [], that means we will return an array, if we have the general *, that means we will
        return a pointer, and it might not be an array. We should always be explicit and leave no chances for misinterpretation.
    - Certain compilers will not allow just [], in those cases we must use the pointer for the return type *
*/


#include <stdio.h>
#include <stdlib.h>


void print_array(int a[], int array_size) {
    // print the contents of the array
    for (int i = 0; i < array_size; i++) {
        printf("%i \n", a[i]);
    }
}


int main() {
    int a[5] = {2, 4, 6, 8, 10};
    print_array(a, 5);
    
    return 0;
}
