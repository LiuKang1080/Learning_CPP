// nCr Recursion

/*
Combination Formula / Selection Formula:
    - Given a set of objects, in how many ways can we select those objects?
    - This formula is used to give us the number of ways we can select the subset of those objects.
    - Ex) Given 7 objects: a,b,c,d,e,f,g: in how many ways can I select a group of 3?
        - a,b,c
        - a,b,d
        - . . . 
        - a,c,b (This one will NOT work, changing the location / a permutation does not count towards the number of unique
            combinations)
        - nPr is the permutation formula.
    
    - The general formula is given as:

        nCr = n! / r! (n-r)!

    - The general formula in code is:
        - We already have the formula for recursion.
        
        int combination_formula(int n, int r) {
            int t1, t2, t3;

            t1 = fact(n);
            t2 = fact(r);
            t3 = fact(n - r);

            return t1 / (t2 * t3);
        }

    - What is the time complexity? What is the space complexity?
    - The fact() functions are O(n), so the total statement on line 29 will be constant since it is just multiplication and division.
    - The total is 3n --> O(n)

Combination Formula Using Recursion:
    - We can use Pascal's Triangle. The values of nCr can be obtained by performing addition recursively.
    - Any nCr value can be obtained by this general formula using pascal's triangle:

        nCr = [n-1Cr-1] + [n-1Cr]

    - Converting this into code we have:

        int combination_formula(int n, int r) {
            if (r == 0 || n == r) {
                // this is the base case
                return 1;
            } else {
                return combination_formula(n-1, r-1) + combination_formula(n-1, r);
            }
        }
*/


#include <iostream>


int main() {

    return 0;
}
