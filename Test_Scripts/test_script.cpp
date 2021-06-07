// Test Script

#include <iostream>
#include <string>


void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}


int main() {
    int x = 5;
    int y = 7;

    std::cout << "Before Swap: X: " << x << " Y: " << y << "\n";

    swap(x, y);

    std::cout << "After Swap: X: " << x << " Y: " << y << "\n";

    return 0;
}
