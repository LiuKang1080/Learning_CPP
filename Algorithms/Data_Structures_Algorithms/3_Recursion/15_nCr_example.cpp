// nCr example in C++

/*
- Take factorial function, and the nCr function from the notes, in 15_nCr_Recursion.cpp
- The factorial function is recursive, but the nCr function is not.
*/


#include <iostream>


// factorial function
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return factorial(n-1) * n;
    }
}

// nCr function
int nCr(int n, int r) {
    int numerator;
    int denominator;

    numerator = factorial(n);
    denominator = factorial(r) * factorial(n-r);

    return numerator / denominator;
}


int main() {
    std::cout << nCr(5, 2) << "\n";

    // std::cout << nCr(5, 1) << "\n";
    // std::cout << nCr(5, 2) << "\n";
    // std::cout << nCr(5, 3) << "\n";
    // std::cout << nCr(4, 2) << "\n";

    return 0;
}
