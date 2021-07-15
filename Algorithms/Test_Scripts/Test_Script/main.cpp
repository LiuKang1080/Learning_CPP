// Test Script

#include <iostream>
#include <string>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp>


int main() {
    using namespace boost::multiprecision;

    // create variable to store very large number from the boost::multipercision library
    cpp_int num = 1;

    // use for loop to get the result of 100!
    for (unsigned int i = 1; i <= 100; i++) {
        num *= i;
    }

    std::cout << num << "\n";

    return 0;
}
