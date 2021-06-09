// Test Script

#include <iostream>
#include <string>
#include <vector>


int array_sum(const std::vector<int> &vec) {
    int total = 0;

    for (int i = 0; i < vec.size(); ++i) {
        total += vec.at(i);
    }

    return total;
}


int main() {
    std::vector<int> my_vec {1, 2, 3, 4, 5};

    std::cout << array_sum(my_vec) << "\n";

    return 0;
}
