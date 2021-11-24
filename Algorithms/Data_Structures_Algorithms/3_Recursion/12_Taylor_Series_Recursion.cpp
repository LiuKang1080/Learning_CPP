// Taylor Series using Recursion

/*
Taylor Series Expansion of e^x:
    - The Taylor Series Expansion of e^x is definied as:

        e^x = 1 + x/1 + (x^2)/(2!) + (x^3)/(3!) + (x^4)/(4!) + n terms 

    - The more number of terms we have the more precise e^x will be.
    - There are 3 recursion sections:
        1) the summation (ignoring 1)
        2) the factorials (denominator)
        3) the powers of x (numerator)

    - We've found the recursion functions of factorials, powers, and summations from the previous examples.
    
        - sum(n) = sum(n-1) + n
        - fact(n) = fact(n-1) * n
        - pow(x, n) = pow(x, n-1) * x
    
    - We combine all 3 of the recursion functions into 1 function to get the Taylor Series approximation.
    - For sum(n), the addition of values is done at returning time. For fact(n) the multiplication is done at returning time.
        For pow(x, n) is also done at returning time.
    - Since we can only return 1 thing from a function, we need to use static variables. We will have 2 static variables 
        p (power), and f (factorial). The next terms p will be multiplied by x, and f will be multiplied by the next number in
        the term.

        double taylor_series(int x, int n) {
            static double power = 1;
            static double factorial = 1;
            double result;

            if (n <= 0) {
                return 1;
            } else {
                result = taylor_series(x, n-1);
                power *= x;
                factorial *= n;

                // we take the result of the previous function call and multiply it by (power/factorial)
                return (result + (power / factorial));
            }
        }
*/


#include <iostream>


double taylor_series(int x, int n) {
    static double power = 1;
    static double factorial = 1;
    double result;

    if (n <= 0) {
        return 1;
    } else {
        result = taylor_series(x, n-1);
        power *= x;
        factorial *= n;

        // we take the result of the previous function call and multiply it by (power/factorial)
        return (result + (power / factorial));
    }
}


int main() {
    double exponent = 1;
    double num_terms = 10;

    std::cout << "Taylor Series of ";
    std::cout << "e raised to the " << exponent << " for " << num_terms << " terms is: " << taylor_series(exponent, num_terms);
    std::cout << "\n";

    return 0;
}
