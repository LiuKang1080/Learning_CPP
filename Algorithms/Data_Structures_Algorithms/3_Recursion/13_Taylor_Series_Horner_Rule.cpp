// Taylor Series Expansion with horner's Rule

/*
Taylor Series Expansion with Horner's Rule:
    - How many multiplication terms do we need to do with the regular Taylor Series Expansion of e^x?
    - We need to do n(n + 1) number of multiplications.
    - This is on the order of O(n^2).
    - How do we reduce the number of multiplications?
    - We can use Horner's Rule to remove the common factor from the expansion, and then continue to remove the common factor on
        each term
    - Ex) With 4 terms:

        1 + x/1 + x^2/1*2 + x^3/1*2*3 + x^4/1*2*3*4

        - factor out x/1 the common term x/1

        1 + x/1 [1 + x/2 + x^2/2*3 + x^3/2*3*4]

        - factor out the common term x/2

        1 + x/1 [1 + x/2 [1 + x/3 + x^2/3*4] ]

        - factor out the common term x/3

        1 + x/1 [1 + x/2 [1 + x/3 [1 + x/4] ] ]

    - Now the number of multiplications done is on the order of O(n).
    - This is now linear order.
    - What is the common pattern for this version of the Taylor Series?
    - At calling time we need to figure out the x/n and then add by 1. All of the processing is done at calling time.
    - We can easily turn this into a loop:

        double taylor_series(double x, double n) {
            double result = 1;

            for (; n > 0; n--) {
                result = 1 + (result * (x/n));
            }

            return result;
        }

    - Now with recursion we need to perform the computation at calling time.
    - We also need to use static variables:

        double taylor_series(double x, double n) {
            static double result = 1;

            // base case for recursion
            if (n <= 0) {
                return result;
            } else {
                result = 1 + (result * (x/n));
                
                return taylor_series(x, n-1);
            }
        }
*/


#include <iostream>


double taylor_series(double x, double n) {
    static double result = 1;

    // base case for recursion
    if (n <= 0) {
        return result;
    } else {
        result = 1 + (result * (x/n));     
        return taylor_series(x, n-1);
    }
}


int main() {
    double exponent = 1;
    double num_terms = 10;

    std::cout << "Taylor Series Expansion, using Horner's Rule \nof ";
    std::cout << "e raised to the " << exponent << " power, for " << num_terms << " terms is: " << taylor_series(exponent, num_terms);
    std::cout << "\n";

    return 0;
}
