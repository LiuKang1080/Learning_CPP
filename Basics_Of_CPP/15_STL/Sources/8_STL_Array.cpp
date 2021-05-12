// STL Array | std::array in C++

/*
STL Array:
    - In order to use std::array we must #include the <array> header file
    - #include <array>
    
    - Fixed size, the size must be known at compile time.
    - std::array is an object type.
    - std::array provides direct element access.
    - It also provides access to the underlying raw array
    - We should use std::array instead of the raw arrays whenever possible.
    - ALL iterators are available, and do not invalidate.
    - If we have a fixed size of something, then we should condsonder this over other data structures. We should definitely
        consider std::array over the raw array.

std::array Initialization and Assignment:
    - General Syntax:

        std::array<data_type, size>;
    
    - ex)

        std::array<int, 5> arr1 { {1, 2, 3, 4, 5} };

    - The double {{}} is for C++11, we only need 1 pair of {} for C++14 and onward.
    - If we have more than 5 elements then we will get an error. If we have less than 5 elements then the rest of the elements
        will be initialized to 0.

        std::array<std::string, 3> stooges {
            std::string {"Larry"},
            "Moe",
            std::string {"Curly"}
        };

    - We can also reassign:

        arr1 = {2, 4, 6, 8, 10};

Common Methods for std::array
    - .size() method:
        - Available to all containers. Shows the size of the container
    
    - .at() method:
        - Shows the element at the index provided.
        - ex) arr1.at(2) // 3.
        - We can also manually index with []. arr1[2]   // 3
        - .at() method performs bounds checking, it will throw an error if it is out of bounds.
            - [] no bounds checking
            - .at() performs bounds checking

    - .front() method:
        - access the first element in the array.
    
    - .back() method:
        - access the last element in the array.
    
    - .empty() method:
        - returns true if the array is empty, false if the array is not empty
    
    - .max_size() method:
        - not really useful for arrays since we know the size of the array ourselves or if we use the .size()
            method. This method is rather more useful for other containers. Returns the maximum size of the container.
    
    - .fill() method:
        - ex) arr1.fill(10) fills all of the elements in the array with the data provided.
    
    - .swap() method:
        - ex) arr2.swap(arr1); Swaps the elements of the 2 arrays.
        
    - .data() method:
        - - We can access the raw array address 

        int *data = arr1.data();
        - Generally we don't want to deal with the raw array / raw pointers of the array, and we just want to use the methods 
            provided by the STL for the array. Sometimes other libraries will work with the raw array, in those cases this is
            where the .data() method comes in handy.

    - .sort() method:
        - sorts the array. 
        - ex) 
        
        std::sort(arr1.begin(), arr1.end()); 
        
    - .min_element:
        - returns an iterator to the minimum element

        std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
        - we can imagine that the iterator "pointer" is pointing to the min element

    - .max_element:
        - returns an iterator to the maximum element

        auto max_num = std::max_element(arr1.begin(), arr1.end());
        
        std::cout << *min_num << *max_num << "\n";

    - .adjacent_find() method:
        - Returns an iterator. Searches the container and returns the first occurrance of 2 adjacent values. These 2 values are
            compared with the == operator, we need to overload this operator if we wanted to use our data types.

        std::array<int, 5> arr1 {2, 1, 3, 3, 5};

        auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());

        if (adjacent != arr1.end()) {
            std::cout << "Adjacent number found with value: " << *adjacent << "\n";
        } else {
            std::cout << "No adjacent elements found \n";
        }

    - accumulate() method:
        - In order to use the accumulate() method we need to #include the <numeric> header file.
        - This will add up all of the elements and return the result.

        #include <numeric>

        int sum = std::accumulate(arr1.begin(), arr1.end(), 0);

        - The last argument for accumulate() is the starting number, here in this example we started from 0. If we want to start
            from 10, then it will start adding the elements of the array onto 10. 
        - The int data type MUST match! It must atch for the array, match for the int sum, and it must match as the last argument
            for the accumulate function.

    - .count() method:
        - Counts the number of times the data entry appears within the container.
        
        std::array<int, 10> arr1 {1, 2, 3, 1, 3, 3, 3, 3, 2, 3};
        int num_count = std::count(arr1.begin(), arr1.end(), 3);

    - The last argument is the data entry we provide to the .count() function that will count the number of times it will appear
        in the container.
*/


#include <iostream>
#include <array>


int main() {

    return 0;
}
