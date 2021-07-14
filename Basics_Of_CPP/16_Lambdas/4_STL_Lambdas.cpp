// C++ Lambdas in the STL

/*
Lambdas in the C++ STL:
    - The most frequent place that we will use lmabdas is in combination of lambdas, and the functions that are present in the
        algorithms in the STL.
    - Some of the algorithms in the STL has a general structure that is as follows:
        algorithm(starting_point, ending_point, lambda_expression)

        - Here the starting point, and the ending point is generally taken in as an iterator for that specific container.
        
Ex)
    - Simple for_each algorithm with lambdas
    
        std::vector<int> vec1 {10, 20, 30, 40, 50};

        std::for_each(vec1.begin(), vec1.end(), [](int num) {
            num += 5;
            std::cout << num;
        }; );

    - Here the last argument takes in a lambda expression. The lambda is a stateless lambda, and takes in 1 argument (num).
        It adds 5 to each number, and prints the current num.

Ex) 
    - Bonus points on a test example:
    - given a list of numbers increment all of them by the bonus points

        std::vector<int> test_scores {95, 93, 82, 76, 86};
        int bonus_points = 5;

    - We can use the std::transform() algorithm:

        std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), [bonus_points](int score) {
            return score += bonus_points;
        }; );

        // display the contents of the vector:
        for (int score: test_scores) {
            std::cout << score << " ";
        }

    - test_scores.begin() : we start the iterator here for this container
    - test.scores.end() : we stop the iterator here
    - test_scores.begin() : we starting writing back to the container starting at this location
    - The last argument is the lambda. This is a stateful lambda that captures by value, and also takes in an argument. The argument is the whatever the
        iterator is on that current iteration.

Ex)
    - Predicate lambda example. Remove even numbers from a vector:

        std::vector<int> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        vec1.erase(std::remove_if(vec1.begin(), vec1.end(), [](int num) {
            return num % 2 == 0;
        };, vec1.end()));        

        // if it is completely divisible by 2, then it's even, remove it.

        // print the contents of the vector:
        for (int num: vec1) {
            std::cout << num << " ";
        }
*/


#include <iostream>


int main() {

    return 0;
}
