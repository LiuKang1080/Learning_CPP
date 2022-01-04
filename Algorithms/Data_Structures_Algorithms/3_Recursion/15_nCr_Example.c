// nCr Example in C


/*
- We need a factorial function, and the regualr nCr function from the notes in the previous code.
- The factorial function is recursive, but the nCr function is not recursive.
*/


#include <stdio.h>


// Factorial Function
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return factorial(n-1) * n;
    }
}

// nCr Function
int nCr(int n, int r) {
    int numerator;
    int denominator;

    numerator = factorial(n);
    denominator = factorial(r) * factorial(n-r);

    return numerator / denominator;
}


int main() {
    printf("%i \n", nCr(5,2));
    // (5, 1) = 5
    // (5, 2) = 10
    // (5, 3) = 10
    // (4, 2) = 6

    return 0;
}
