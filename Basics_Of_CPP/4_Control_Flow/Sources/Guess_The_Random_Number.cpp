// Using while loop to find the random number.

/*
Random Number Generation:
    Random Int Number Generation:
        - general syntax for random number generation: (std::rand() % max_number) + min_number 
        
            int random_value = (std::rand() % 30) + 15;
    
        - this will generate a number between the minimum of 15 and the maximum of 30

    Random Float Number generation between 0 and 1:
        - generating random floats from 0 to 1:
        
        for (int i = 0; i < 10; i++) {
            std::cout << (float)std::rand() / RAND_MAX << " ";
        }

        - Take a look at the math, RAND_MAX / RAND_MAX gives us 1, anything lower for rand() will gives us a number below 1 and
            above 0.

    Random Float Between 2 Points:
        // set boundry values. ex) a random float number between 7.00 and 15.75: min = 7.00 max = 15.75
        float max;
        float min;

        // generate a random number
        float random = ((float) std::rand()) / (float) RAND_MAX;

        // get range between 2 numbers
        float range = max - min;

        std::cout << (random * range) + min << "\n";

    <random> Module:
        - The random module contains various random functions and distributions for both whole numbers and floating-point numbers

        #include <random>

        - Generate Random Int Numbers 
        
            std::random_device rd; // Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<int> dis(1, 10);
            // here we have a uniform distribution of ints between 1 and 10

            std::cout << "Generating random numbers between 1 and 10: " << "\n";
            for (int i = 1; i <= 10; i++) {
                std::cout << dis(gen) << "\n";
            }

        - Generate Random Floating-Point / Double Numbers Between a Range

            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_real_distribution<double> dis(1.00, 2.00);
            // random double number between 1.00 and 2.00

            for (int n = 0; n < 10; ++n) {
                std::cout << dis(gen) << "\n";
            }
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
// need to #include <cstdlib> for rand() for random number generation
#include <random>
// random module for std::uniform_int_distribution<> and std::uniform_real_distribution<>
#include <ctime>
// getting the current time for seed geenration


int main() {
    /*
    // generate random int number between 1 and 10
    std::random_device rd; //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dis(1, 10);
    // here we have a uniform distribution of ints between 1 and 10

    std::cout << "Generating random int numbers between 1 and 10: " << "\n";
    for (int i=1; i<=10; i++) {
        std::cout << dis(gen) << "\n";
    }
    */

    // std::cout << "=============== \n";

    /*
    // generate a random float / double between 2.25 and 7.75
    std::cout << std::fixed << std::setprecision(4);

    std::random_device rm;  
    std::mt19937 mt(rm()); 
    std::uniform_real_distribution<double> dist(2.2500, 7.7500);
    // random double number between 1.00 and 2.00

    std::cout << "Generating random doubles between 2.25 and 7.75";
    for (int i=1; i<=10; i++) {
        std::cout << dist(mt) << "\n";
    }
    */

    // Guess the random number
    // initialize random int number between 1 and 10
    std::random_device rd;
    std::mt19937 gen(static_cast<long unsigned int> (std::time(nullptr)));
    // current seed is noe based on time
    std::uniform_int_distribution<int> dis(1, 10);
    // here we have a uniform distribution of ints between 1 and 10
    int random_number = dis(gen);
    int guess {};

    // set up game:
    std::cout << "Random number has been selected between 1 and 10. Guess the number: ";
    std::cin >> guess;

    while (guess != random_number) {
        if (guess < random_number) {
            std::cout << "The random number is larger. Try again: ";
            std::cin >> guess;
        } else {
            std::cout << "The random number is smaller. Try again: ";
            std::cin >> guess;
        }
    }

    std::cout << "Congratulations, you guessed the number!";

    return 0;
}
