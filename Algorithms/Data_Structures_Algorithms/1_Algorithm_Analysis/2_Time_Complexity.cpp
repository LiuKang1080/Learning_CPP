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

    - The first statement = 1, the for loop is n + 1 number of times it runs, the statement inside the for loop runs n times, the
        last statement runs once, adding up all of the steps we get 2n + 3. This is our time function

    - f(n) = 2n + 3. This is the time complexity function.
    - O(n)

    - To finish this specific algorithm analysis we will look at the space complexity.
    - vec takes up n spaces, total takes 1 space, i takes 1 space, vec.size() in the for loop will also be computed; this will
        take up 1 space. The total space all of these variables take is n + 3. This space complexity function is s(n) = n + 3.

Nest For Loop Time Complexity Analysis:
    - We looked at a single for loop, we will now look at the time complexity and get the time function for nested for loops:
    - A function that adds 2 matricies: Matrix a and b are square matricies of dimensions n x n.

        std::vector add_matrix(std::vector &matrix_a, std::vector &matrix_b, n) {
            std::vector<int> matrix_c;
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    matrix_c.push_back(matrix_a[i][j] + matrix_b[i][j]);
                }
            }

            return matrix_c;
        }
        
    - the first for loop will take n+1 time units, whatever is there in the for loop will execute n times; There are 2 statements
        within the 1st for loop, the second for loop, and the statement within that for loop. we have n and then another n. The
        second for loop is of time complexity n+1, but that statement is done n times due to the first for loop, we multiply:
        n (n + 1) = n^2 + n

        so far we have: n + 1
                        n^2 + n

        The statement within the for loop will take n times, but since this statement is within the first for loop we will need to
        multiply it with n: n x n = n^2

        so far we have: n + 1
                        n^2 + n
                        n^2

        The total is =  2n^2 + 2n + (Other single statments that aren't in the loop = 2)
        
    - The time function is: f(n) = 2n^2 + 2n + 2
    - We take the highest degree since this is the biggest determining factor in how the function behaves:
        - O(n^2)

    - To finish the analysis, we will look at the Space Complexity:
    - matrix_a, matrix_b, matrix_c, n, i, j
    - all of the matricies are nxn square matricies: 3n^2
    - n, i, and j all consume 1 space unit: 3
    - Total space units / Space Complexity Function: s(n) = 3n^2 + 3
        - O(n^2)
*/


#include <iostream>


int main() {

    return 0;
}
