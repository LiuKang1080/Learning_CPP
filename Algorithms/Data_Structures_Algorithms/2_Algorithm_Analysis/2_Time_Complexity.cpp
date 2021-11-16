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

Nested For Loop Time Complexity Analysis:
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

Time Complexity Analysis of Different For Loop Conditions:
Ex)
    - we've looked at the general for loop with the loop termination condition being i<n, what about other complex termination
        statements?

        int p = 0;
        
        for (int i = 1; p <= n; ++i) {
            p = p + i;
        }

    - Here the loop termination condition is now dependent on p <= n, instead of i.
    - How do we analyze the time complexity?

    - Write what the values will be on each iteration:
        - Initial condition:    i=1, p=1
        - 1st iteration:        i=2, p=3
        - 2nd iteration:        i=3, p=5

    - i will execute k times, it does NOT execute n times, the value of p will reach <= n BEFORE it runs n times.
    - The loop only stops when p>n.
    - what is the structure of p?

        - p = k(k + 1) / 2

    - The loop stops when k(k + 1) / 2 > n
    - We can look at the highest order in order to look at the time complexity function.
    - k^2 > n ==> k > sqrt(n) This is the time complexity function. It is of the order O(sqrt(n))

Ex)

        for (int i = 1; i < n; i = i * 2) {
            statement;
        }

        - initial condition     i=1
        - 1st iteration         i=1*2       = 2
        - 2nd iteration         i=2*2       = 2^2
        - 3rd iteration         i=2^2 *2    = 2^3

    - The pattern is 2^k times.
    - We know that this loop terminates when i>n. What is i? i is 2^k
    - So we can assume that when 2^k > n is our condition
    - We need to isolate k by itself

    - k = log_2(n) This is our time complexity function. O(log(n))

Time Complexity Analysis Summary:
    - Source: 1.5.2 Time Complexity Example #2 (https://www.youtube.com/watch?v=9SgLBjXqwd4)

        - for (int i = 0; i < n; i++)       ==> O(n)
        - for (int i = 0; i < n; i = i + 2) ==> n/2 ==> O(n)
        - for (int i = n; i > 1; i--)       ==> O(n)
        - for (int i = 1; i < n; i = i * 2) ==> O(log_2(n))
        - for (int i = 1; i < n; i = i * 3) ==> O(log_3(n))
        - for (int i = n; i > 1; i = i / 2) ==> O(log_2(n))

Time Complexity Analysis of While Loops:
    - While loops differ from for loops since it is solely based on the condition

        while (condition == true) {
            statement;
        }

    - This loop will run as long as condition is equal to true, we need to look at how the condition changes, and see how many
        steps it takes in order to stop.
    - In order to get the Time Complexity function, we need to manually see how many times the loop will run

Ex)

        int i = 0;

        while (i < n) {
            statement;
            i++;
        }

    - We can assume here in this example that n = 10
    - statement and i++ each take n units of time
    - while (i < n) takes n + 1 units of time
    - int i = 0 take 1 unit of time
    - f(n) = 3n + 2, O(n)

    - In for loops, we have 2n + 1 as our total units of time. In Time Complexity Analysis we're not interested in the exact
        detail, we're interested in the highest order since that is the biggest determining factor.

Ex)

        int a = 1;

        while (a < b) {
            statement;
            a = a * 2;
        }

    - In the first iteration a = 1, then 2, then 4, then 8. The pattern here is 2^k
    - The loop will terminate when a >= b, since a = 2^k, so then 2^k >= b ==> 2^k = b. We now find k
    - k = log_2(b). The Order is O(log_2(n))

Ex)

        int i = 1;
        int k = 1;

        while (k < n) {
            statement;
            k = k + i;
            i++;
        }

    - Here in this example, k is being incremented by i, while i increments by 1 on each iteration.
    - what is the pattern for i and k?
    - how many times does this run? We don't know, let's say that it runs m times.
    - what is the pattern for i? it runs m times.
    - what is the pattern for k? first iteration 1+1, then 2+2, then 2+2+3, then 2+2+3+4
        The pattern for k is m (m + 1) / 2

    - We can assume that the loop stops when k >= n. We know what k is, we substitute in k.
        We only need to take the highest order, in k it will be m^2. Now we can equate it to n. m^2 = n
        m = sqrt(n)
    - The time complexity function for this is O(sqrt(n))

Time Compelxity Analysis of if statements
    - If the condition is met it will execute once. The minimum order is O(1).
    - If the if statement contains for loops or while loops within it, then we need to do further analysis.
    - The Loops within the if statement needs to be analyzed, and added onto to the if-else statement time complexity.

Summary of general Time Complexity:
    - 1 < log_n < sqrt(n) < n < n log_n < n^2 < n^3 < ... < 2^n < 3^n < ... < n! < n^n
*/


#include <iostream>


int main() {

    return 0;
}
