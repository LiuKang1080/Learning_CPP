// Asymptotic Notation, Big O, Omega, and Theta

/*
Asymptotic Notation:
    - The theory behind asymptotic notation comes from the field of mathematics.
    - The notations that we will use represent the symbols / functions that we've used. Time complexity function and the space 
        complexity function.
    - We need a simple way to represent the time complexity functions.

    - Big O Notiation: This represents the upper bound of a function.
    - Big Omega Notation: This represents the lower bound of a function.
    - Theta Notiation: This represents the average bound of a function.

    - We can represent any time complexity / space complexity function as one of these notations.
    - Theta Notation is the most useful out of all three notations. Why do we need the other two if Theta is the "best" one?
        - We can use the other 2 notations if we cannot exactly specify the place of the function on the Standard Complexity 
            Graph. We can then use the upper bound.
        - The Standard Complexity Graph refers to the graph that plots all of the "standard" functions of n f(n):

            1 < log_n < sqrt(n) < n < n log_n < n^2 < n^3 < ... < 2^n < 3^n < ... < n! < n^n

        - Generally the time complexity of an algorithm will be one of the above functions.
        - If it is not one of those functions, then it may be a multiple of the above functions. If it is not a multiple of the
            above functions, then we might not be able to represent Theta. We then use Big O to represent the upper bound of the
            complexity function.

Ex)
    - Lets say we have a function f(n) = 2n + 2, This is the Theta function.
    - How do we represent Big O? We can say that Big O satisfies the condition if f(n) = O(g(n)) such that f(n) <= c * g(n).
        Where c is a constant.

    - This means that 2n + 2 <= _____. We can have whatever function we want as long as it satisfies that condition.
    - What is the lowest possible value we can have on the right side to satisfy that condition?
        - We can have 2n + 2 = 
        - set both sides to the same thing, and add n to each of the constants on the right side
        - 2n + 2 <= 2n + 2n
        - 2n + 2 <= 4n
        - This is the lowest possible function to meet this condition.

        - g(n) is on the right hand side. g(n) = 4n, the order is O(n)

    - What happens if we set g(n) = n^2? Yes, this also satisfies the condition, in fact ALL orders above n satisfy the
        condition. 
    - This is what Big O is. The upper bound is all of the possible functions above the order of n.

        - Big O = n < n log_n < n^2 < n^3 < ... < 2^n < 3^n < ... < n! < n^n    [Upper Bound]
        - Omega = 1 < log_n < sqrt(n) < n                                       [Lower Bound]

        - Notice that n is in BOTH the upper bound and the lower bound.
        - Therefore the function order of n itself becomes the average bound. This is Theta!

    - Why do we need to take into account ALL of the functions in the upper bound? We don't. We should try to take the closest
        function to Theta while still remaining as an upper bound, this is what Big O is! Even though mathematically it remains
        true for all high order functions above n, it is not useful, so we try to remain as close to Theta as possible while
        still remaining in the upper bound.
    - Omega Notation is the closest to Theta while still remaining in the lower bound!

    - These Notations are just a representation of a complexity function. DO NOT mix them the Best case scenario or the Worst 
        Case scenario! They are NOT the same! We can use any notion for the best or worst case. These ideas are NOT the same.

Ex)

        f(n) = n^2 log(n) + n

    - We set up the functions that are less than and greater than f(n):

        n^2 log(n) <= n^2 log(n) + n <= 2n^2 log(n) 

    - We see that Big O the upper bound, is n^2log(n), Omega which is the lower bound is also n^2log(n). Theta which is the average is also
        n^2log(n)
    - Where does n^2log(n) belong on the time complexity chart? We can see that the n^2 term is the most dominating term, this
        means that n^2log(n) is greater than n^2, but less than n^3.

Ex) 

        f(n) = n!

    - Here n factorial is defined as:

        n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1

    - We start by taking the upper and lower bounds by creating functions that are less than and greater than f(n)

        1x1x1 ... x1 <= 1x2x3x...xn <= nxnxnx...xn

    - the left side is a constant number that multiples by the same constant number, n times. The right side is n times n, n
        number of times. We can reduce these functions:

        1 <= n! <= n^n

    - Big O which is the upper bound is n^n. Omega, which is the lower bound is 1. What is the average in this case? Theta cannot
        be definied. For lower numbers of n it will be very low in the time complexity graph, but for larger numbers of n, it
        will be much higher on the time complexity graph.
    - The upper bound of f(n) = n! is n^n, and the lower bound is 1.
    - Since we cannot define Theta, looking at the upper bound or the lower bound depending on the algorithm analysis, will be
        more important.
    - If Theta is present and definied, then we generally use Theta. If Theta is not definied / present, then we must rely on the
        upper bound (Big O), or the lower bound (Omega).
    - When we're just presented with O(n^2), are we as close as we can be to g(n)? When we are only given Omega(n^2), are we the
        closest we can be to g(n)? Are the upper and lower bounds as close as they can be? This is why Theta is more important than
        the upper and lower bounds.
*/


#include <iostream>


int main() {

    return 0;
}
