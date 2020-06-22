// Passing Arrays to Functions in C++

/*
Passing Arrays to Functions:
    - We can pass in arrays to functions by providing square brackets in the formal parameter description.

        void print_array(int numbers[]);

    - The array elements are NOT copied like single parameters that are passed in (pass by value).
    - Since the array name evaluates to the location of the array in memory, this address is copied
    - The function has no idea how many elements are in the array. It only knows the location of the 1st element
        (the name of the array).
    - We need to pass in the size of the array into the function.

        void print_array(int numbers[], size_t size);

        int main() {
            int number_array[] = {1, 2, 3};
            print_array(number_array);
            
            return 0;
        } 

        void print_array(int numbers[], size_t size) {
            for (size_t i=0; i<size; i++) {
                std::cout << numbers[i] << "\n";
            }
        }

    - Since we're passing in the location of the first element of the array, the function can modify the actual array.
    - We can tell the compiler that the function parameters are const so that the elements of the array do not get changed.
    - We use const to tell the function that the parameter passed in is read-only. 

        void print_array(const int numbers[], size_t size) {
            for (size_t i=0; i<size; i++) {
                std::cout << numbers[i] << "\n";
            }
        }

    - The const modifier prevents any attempts to modify the elements within the array that is passed into the function.
    - Generally we want a print function to only print and not modify any data.
*/


#include <iostream>


// function prototypes:
void print_array(const int array[], size_t size);
void zero_array(int array[], size_t size);


int main() {
    // changing all elements in an array to zero
    int array[] = {1, 2, 3, 4, 5}; 
    print_array(array, 5);
    zero_array(array, 5);
    print_array(array, 5);

    return 0;
}


// function definitions:
void print_array(const int array[], size_t size) {
    for (size_t i=0; i<size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";
}

void zero_array(int array[], size_t size) {
    for (size_t i=0; i<size; i++) {
        array[i] = 0;
    }
}
