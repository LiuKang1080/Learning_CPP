// Arrays in C++

/*
    Arrays:
        - Collection of elements.
        - All elements are of the same data type. (compound data type / structure)
        - Each individual element of the array can be accessed directly.
    
    Characteristics of Arrays:
        - Fixed size.
        - Elements are all of the same data type.
        - Stored in contiguous memory.
        - 1st element is index 0
        - last element of the array is: array size - 1
        - There is no automatic Out of Bounds checking! We need to manually check if we're out of bounds!
        - If we tell the compiler to check an element that is out of bounds of an array, it will do so without giving us a
            warning. We need to pay attention to where the array starts and ends.
    
    Declaring Arrays:
        - General syntax: Data_Type Array_Name[Constant_Number_Of_Elements];

        int my_arr[5];      // array is not initialized

    Initializing Arrays:
        int test_scores[5] {100, 95, 88, 82, 96};   // manually initialize each element
        int my_arr[10] {0};                         // initialize all elements to 0
        int another_array[] {1, 2, 3, 4, 5};        // the compiler will automatically calculate the size of the array for us
        int high_score_per_level[10] {3, 5, 4};     // initialize the first 3 elements, the rest are initialized to 0

    Accessing Array Elements:
        - General syntax: Array_Name[Element_Index]     // called array subscripts
        std::cout << test_scores[2];                  // this prints out the 3rd element of the array
        
        - Changing an individual element of an array:
        test_scores[2] = 90;    // assignment statement  

    Printing The Array Itself:
        std::cout << test_scores;
        - this prints out something like 0x61fee4. This is the memory address where the array is located. C++ use these memory
            addresses to do the indexing and picking the individual elements.

    Multi-Dimensional Arrays:
        - General Syntax: Data_Type Array_Name[dim1_size][dim2_size];

        int movie_rating[3][4];     // [rows][columns], here the rows represent the reviewer, the columns are the movie 

        - initializing multi-dimensional arrays:

        int movie_rating[3][4] {
            {0, 4, 3, 5},
            {2, 3, 3, 5},
            {1, 4, 4, 5}
        };

        - Accessing multi-dimensional arrays are the same as accessing 1D arrays.
*/


#include <iostream>


int main() {

    return 0;
}
