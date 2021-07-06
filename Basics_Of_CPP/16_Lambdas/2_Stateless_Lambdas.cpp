// Stateless Lambdas in C++

/*
Stateless Lambdas:
    - A stateless lambda is a lambda that has an empty capture list. This means that the lambda captures no information about
        the environment, except for the info that was passed into the parameter list.

        int x = 10;
        [](int x) { std::cout << x; }(100);

    - NOTICE! the last (), Since the lambda is stateless it does NOT know anything about the outside environment! It does not
        know any information about int x = 10; The () at the end instantiates a function object with the argument passed in,
        this passes into the lambda, and 100 will be printed out.

Auto / "Templated" Lambdas:
    - In the working code below, that lambda only accepts ints in the vector, what abouit floats, doubles, chars? Rather than
        fully "templating" a lambda, we instead use the auto keyword. We let the compiler deduce the return types, and the
        parameter types for us.

        int num1 = 5;
        float num2 = 10.75;

        auto L = [](auto x){ std::cout << x; };

    - notice the 2 auto keywords for BOTH the parameter list (second auto), and the return type (first auto).

        std::vector<int> test_scores_1 {93, 88, 72, 68, 70};
        std::vector<int> test_scores_1 {93.25, 88.00, 72.50, 68.75, 70.48};

        auto bonus = [](auto &test_scores, int bonus_points) {
            for (auto &score: test_scores) {
                score += bonus_points;
            }
        };

        bonus(test_scores_1, 5);
        bonus(test_scores_2, 5);

    - Both statements are valid.
    - Remember that auto is NOT a type! It is an instruction telling the compiler to deduce the data type for us!

Passing Lambdas Into Functions:
    - #include <functional>     // for std::function
    
    - C++14:

        void foo(std::function<void(int)> L) {
            L(10);
        }

        - the void is the return type, int is the parameter type. The whole thing is the lamda expression.

    - C++14:

        - Passing a lambda expression as a function pointer

        void foo(void (*L)(int)) {
            L(10);
        }

        - void the return type, int is the parameter data type.

    - C++20:

        void foo(auto L) {
            L(10);
        }

        - The auto keyword deduces BOTH the return type, and the parameter type.

Return a Lambda From a Function:
    - We can also return lambdas from functions.

    - Method 1)
        
        std::function<void (int)> foo() {
            return [](int x) { std::cout << x; };
        }

    - Method 2)

        void (*foo()) (int) {
            return [](int x) { std::cout << x; };
        }

    - Method 3)

        auto foo() {
            return [](int x) { std::cout << x; };
        }

    - Use the 1st or the 3rd one! It is highly recommended that we use the 3rd method, for returning a lambda from a function.
    - We need to pay attention to what C++ version, and see if it support this feature.
    - The seocnd method is from old legacy code for backwards compatability.
    - How to use this?:

        auto L = foo();
        L(10);              // displays 10

    - Passing the entire lambda itself into the parameter list of a function:

        foo([](int x) { std::cout << x; };) {}

        OR 

        auto L = [](int x) { std::cout << x; };
        foo(L);

    - Why pass lambdas into functions?
    - We can take a look at predicate lambdas to see an example as to why we should pass in lambdas into a function.
    - Predicate = A C++ function that takes in any number of arguments. A predicate lambda supports this idea.
    - Predicate lambdas return a boolean value 

        void print_if(std::vector<int> nums, bool(*predicate)(int)) {
            for (int i: nums) {
                if (predicate(i)) {
                    std::cout << i;
                }
            }
        }

        int main() {
            std::vector<int> nums {1, 2, 3};

            print_if(nums, [](auto x) { return x % 2 == 0; });      // displays evens
            print_if(nums, [](auto x) { return x % 2 != 0; });      // displays odds
        }

    - bool(*predicate)(int) is the lambda to be passed in.
    - [](auto x) { return x % 2 != 0; } is the actual lambda argument.
    - If the lambda returns true and under that condition it will print in the if statement within the for loop.
*/


#include <iostream>
#include <vector>


int main() {
    std::vector<int> test_scores {90, 92, 94, 96, 98};

    // lambda
    auto bonus = [](std::vector<int> &test_scores, int bonus_points) {
        for (int &score: test_scores) {
            score += bonus_points;
        }
    };

    bonus(test_scores, 5);

    // print the contents of the vector after the lambda worked on it.
    for (int i=0; i<test_scores.size(); i++) {
        std::cout << test_scores[i] << " ";
    }

    return 0;
}
