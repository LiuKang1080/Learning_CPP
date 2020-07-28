// The const modifier with pointers in C++

/*
The const modifier with pointers:
    - There are 3 ways to qualify pointers:
        1) Pointers to constants
        2) Constant pointers
        3) Constant pointers to constants

1) Pointers to Constants:
    - The data pointed to by the pointer is constant and cannot change.
    - The pointer itself can change and point somehwere else.

        int high_score = 100;
        int low_score = 20;

        const int *p_score = &high_score;

        *p_score = 200;         // ERROR
        p_score = &low_score    // OK

2) Constant Pointers:
    - The data pointed to by the pointer can change.
    - The pointer itself cannot change, it cannot point to somewhere else.
    - The address / value of the pointer cannot change.

        int *const p_score = &high_score;

        p_score = &low_score;   // ERROR
    
    - The const modifier MUST come after the * for it to be a constant pointer!
    - int const *p_score is still read as a pointer pointing to a constant int!
        - const int and int const ARE THE SAME THING!

3) Constant Pointer to Constant:
    - The data pointed to by the pointer cannot change.
    - The pointer itself change, it cannot change and point somewhere else.

        const int *const p_score = &high_score;
*/


#include <iostream>


int main() {

    int high_score = 100;
    int low_score = 20;

    int *const p_score = &high_score;
    // p_score = &low_score;    

    return 0;
}
