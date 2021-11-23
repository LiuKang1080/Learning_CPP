// Exponents / Powers using Recursion

/*
Exponents / Powers with Recursion:
    - m^n = m multiplied by itself n number of times.
    - pow(m, n) = m*m*m*...*(n-1) number of times * m
    - pow(m, n) = pow(m, n-1) * m
    - When n is less than or equal to 0, it will return 1.
    - We can write a recursion function:

        int power(int m, int n) {
            if (n <= 0) {
                return 1;
            } else {
                return power(m, n-1);
            }
        }

    - What is the Time Complexity of this recursion function? It will be n + 1. Order of O(n).
    - What is the Space Complexity? It will be n, since there are n number of calls onto the stack. Order of O(n).
    - Is there a way to reduce the Time Complexity of this recursion function?
    - If the exponent is odd, we can remove 1 m, and compute the even exponent and then multiply back in the final m we removed at the beginning.
    - Ex) 2^9 = 2 * 2^8 ==> Here 2^8 = (2^2) ^ 4 = (2*2)^4 ==> 2^9 = 2 * (2^2)^4
    - We can change the recursion function to be:

        int power(int m, int n) {
            if (n <= 0) {
                return 1;
            } else if (n % 2 == 0) {
                // if the power is even we multiply m*m, and divide n by 2
                return power(m*m, n/2);
            } else {
                // exponent is odd, we need to add another mutiply of m
                return m * power(m*m, (n-1)/2);
            }
        }

    - Now what is the time complexity of the this new recursion function? What does the recursive stack trace look like?
    - How many multiplications does this recursion function call perform compared to the first one?
*/


#include <iostream>


int power(int m, int n) {
    if (n <= 0) {
        return 1;
    } else {
        return power(m, n-1) * m;
    }
}


int main() {
    int base = 2;
    int exponent = 9;
    
    std::cout << base << " raised to the " << exponent << " is: " << power(base, exponent) << "\n";

    return 0;
}
