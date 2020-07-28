// Relationship of Pointers and Arrays in C++

/*
Pointers and Arrays:
    - The value of the array's name is the address of the 1st element in the array.
    - If the pointer pointing to the 1st element of the array, then the pointer and the array name can be (almost) used 
        interchangeably.
    
        int scores[] = {100, 90, 80};
        std::cout << scores << "\n";            // address of the 1st element
        std::cout << *scores << "\n";           // 100.

    - We can directly dereference the array itself. This gives us the value of the first element.
    
        int *p_scores = {scores};

    - Since the pointer is behaving like the 1st index of the array, we can index the pointer itself, just like an array.

        std::cout << p_scores[0] << "\n";       // 100
        std::cout << p_scores[1] << "\n";       // 90
        std::cout << p_scores[2] << "\n";       // 80

    - C++ does not have true arrays, the array is the address of the 1st element.
    - Since pointers behave very similar to arrays we can directly add numerical values to index them.

        std::cout << p_scores << "\n";          // address of the 1st element, 0x61ff10 
        std::cout << (p_scores + 1) << "\n";    // address of the 2nd element, 0x61ff14
        std::cout << (p_scores + 2) << "\n";    // address of the 3rd element, 0x61ff18

    - Adding numerical values to the pointers directly increments the addresses of the pointers in increments of the pointer data
        type. In this case 4 bytes will be incremented for every 1.
    - Pointers don't hold ints / doubles / ... they hold the addresses of those data types.
    - Pointer Arithmetic
    - We can derference them to get the value 

        std::cout << *(p_scores + 1) << "\n";   // 90
        std::cout << *(p_scores + 2) << "\n";   // 80
*/


#include <iostream>


int main() {
    // create array with ints
    int scores[] = {100, 90, 80};
    std::cout << scores << "\n";
    // dereferencing an array itself
    std::cout << *scores << "\n";

    // create a pointer pointing to the array
    int *p_scores = {scores};
    std::cout << p_scores << "\n";
    std::cout << *p_scores << "\n";

    return 0;
}
