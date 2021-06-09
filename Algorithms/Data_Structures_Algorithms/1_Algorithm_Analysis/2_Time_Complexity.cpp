// Time Complexity in Algorithm Analysis

/*
Time Complexity of an Algorithm:
Frequency Count Method:
    - We determine the number of steps per execution
    - We add up all of the statements, and then add up the total number of times this occurs
    - This is uaully done with for loops and while loops. Might happen with if / switch statements as well
    - We need to pay attention for nested loops, and nested if statements.
    
    - For time analysis each statement consumes 1 unit of time. We add up all of the statements, and then add that to the number
        of statements in the loop, and then multiply that to the number of times the loops runs. This final result gives us the total
        number of units of time the algorithm takes.

        int array_sum(const std::vector<int> &vec) {
            int total = 0;

            for (int i = 0; i < vec.size(); ++i) {
                total += vec.at(i);
            }

            return total;
        }

    - There are 2 statments that are not a part of the loop: total time units = 2
    - The loop has only 1 statement within it: total time units = 2 + (1 * )
    - The loop will run .size() + 1 number of times. Why + 1? Example size = 5, from 0 to 4, that's 5 loops, when i = 5 the loop
        will check to see if i < 5, this check takes 1 unit of time asd well, so it will be size() + 1

        total time units = 2 + (1 * (size() + 1))
*/


#include <iostream>


int main() {

    return 0;
}
