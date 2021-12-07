// Print all numbers that are not completely divisible 3, 5, and 9


#include <iostream>
#include <vector>


void get_divisible_numbers(std::vector<int> &vec, const int limit) {
    /*
        Parameters: [std::vector<int>](vec) 
                    [const int](limit)
        
        Return:     [void]

        - limit is the upper limit of the number range.
        - Accept an empty vector, and fill the vector with all of the numbers that are not completely divisible by 3, 5, and 9.
        - Return the vector when complete
    */

    for (int i = 1; i <= limit; i++) {
        // Check to see if i is completely divisible by 3, 5, or 9. If it is then continue to the next number. If it is not, then
        // add that number to the vector.
        // No need to check to see if it's divisible by 9 since if it is divisible by 3, then it is also divisible by 9. 
        if ((i % 3 == 0) || (i % 5 == 0)) {
            continue;
        } else {
            vec.push_back(i);
        }
    }
}


void print_vector(const std::vector<int> &vec) {
    // print the contents of the vector. Print only 5 numbers in a single line.
    int counter = 1;

    for (auto i: vec) {
        if (counter == 6) {
            std::cout << "\n";
            counter = 1;
        }

        std::cout << i << ", ";
        counter++;
    }
}


int main() {
    // create empty vector
    std::vector<int> vec = {};
    int limit = 1'000;

    get_divisible_numbers(vec, limit);
    print_vector(vec);

    return 0;
}
