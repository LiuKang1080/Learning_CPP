/*
Lapis Lazuli
    - 60 Total stats to get (0 / 60).
    - The cost of the first stat to get is 10
    - Each point put into the stat increases the cost by 1. 

    -ex) 0/60 points cost 10 lapis, 1/60 = 11 lapis cost, 2/60 = 12 lapis cost

    - Find the total number of lapis required to max out the entire full stat
*/


#include <iostream>


int main() {
    int total_lapis = 0;
    int cost = 10;

    for (int i=1; i<=60; ++i) {
        std::cout << "Iteration #: " << i << ", Lapis cost this iteration: " << cost << "\n";
        total_lapis += cost;
        ++cost;
        
        std::cout << "Total Lapis cost: " << total_lapis << "\n";
        std::cout << "=== === \n";
    }

    return 0;
}
