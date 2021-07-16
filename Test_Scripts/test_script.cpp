// Test Script


#include <iostream>
#include <vector>


std::vector<int> create_vector(int num) {
    std::vector<int> vec1 {};

    for (int i = 1; i <= num; i++) {
        vec1.push_back(i);
    }

    return vec1;
}

void print_vector(const std::vector<int> &vec1) {
    for (auto i: vec1) {
        std::cout << i << " ";
    }
}


int main() {
    // vector tests:
    print_vector(create_vector(15));    

    return 0;
}
