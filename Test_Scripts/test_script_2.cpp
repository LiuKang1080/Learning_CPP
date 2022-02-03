// Challenges in C++


/*
Pointers Challenge:
    - Create a function that uses pointers to move through an array of integers. Print both the memory address and the value
        of each element.
*/


#include <iostream>
#include <array>


void print_array(const std::array<int, 5> &arr) {
    // function only accepts an array size of 5.
    // create iterator starting at the beginning of the array:
    auto itr = arr.begin();

    while (itr != arr.end()) {
        std::cout << "Memory Address: " << &itr << ", Value at address: " << *itr << "\n";
        std::cout << "========== \n";
        itr++;
    }
}


int main() {
    // Normal example:
    // create array
    int arr1[] = {10, 20, 30, 40, 50};

    // create pointer to array
    int *ptr = {arr1};

    // for loop 
    for (auto i: arr1) {
        std::cout << "Memory Address: " << ptr << " Value of element: " << *ptr << '\n';
        std::cout << "=== \n";
        ptr++;
    }

    // Proper example using the STL:
    // Same challenge except we will use std::array using the print_array function.
    std::array<int, 5> arr2 = {11, 22, 33, 44, 55};
    print_array(arr2);

    return 0;
}
