// Sum of Natural Numbers with Recursion

/*
Sum of the first natural N numbers using Recursion:
    - sum(n) = 1 + 2 + 3 + ... + (n-1) + n
    - Here all of 1 + 2 + 3 + ... is just sum(n) = sum(n-1) + n
    - Therefore our recursion equation is sum(n) = sum(n-1) + n
    - We need to have a base case like we do with ALL recursion problems, sum(0), when n = 0, the sum is equal to 0.
    - We can convert this equation into code, like the following:

        int sum(int n) {
            if (n == 0) {
                return 0;
            } else {
                return sum(n-1) + n;
            }
        }

    - There is also a general formula for the sum of natrual numbers to n.
    - (n(n+1)) / 2
    - This doesn't require a function, it's more efficent, since it does not take a function call onto the stack.
    - Therefore we can simplify the entire function into this:

        int sum(int n) {
            return (n * (n + 1)) / 2
        }

    - This doesn't require recursion. It is faster and more efficent.
    - The Time Complexity of this version is O(1), it is constant time complexity.
    
    - Like before we can convert all recursion code into loop code and vice-versa:

        int sum(int n) {
            int total = 0;

            for (int i = 0; i <= n; i++) {
                total += total + i;
            }

            return total;
        }

    - The Time Complexity of the above is O(n). The Space Complexity is O(1), constant space complexity with only 3 variables
        created on the stack.
*/


#include <iostream>


int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return sum(n-1) + n;
    }
}


int main() {
    int number = 5;

    std::cout << "The sum of all natural numbers up to and including " << number << " is: " << sum(number) << "\n";

    return 0;
}
