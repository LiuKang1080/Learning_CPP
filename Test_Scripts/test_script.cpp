// Test Script

#include <iostream>
#include <string>


int main() {
    std::string str {"12345"};
    auto itr = str.begin();
    int num = 0;

    while (itr != str.end()) {
        std::cout << "itr is: " << *itr << " ";

        num = static_cast<int>(*itr) - 48;
        if (num == 3) {
            std::cout << "3 is printed.";
        }

        itr++;

        std::cout << "\n";
    }

    return 0;
}
