// Vectors in C++

/*
    Vectors:
        - A Container in the C++ STL (Standard Template Library)
        - An array that grows and shrinks its size at execution time.
        - Provides similar syntax to arrays.
        - Provides bounds checking
        - Has functions in the STL like: sort, reverse, find, and more.

    Declaring Vectors:
        #include <vector>

        std::vector<data_type> vector_name;

        - Declaring vectors with a size
        std::vector<int> test_scores(30);   // Tells the compiler that we want a vector of 30 ints. Automatically initializes 
            all values to 0;

        std::vector<int> test_scores {100, 95, 98, 90, 80};     // The first 5 elements are initialized, the rest are set to 0

        srd::vector<double> hi_temps(365, 80.0);    // A vector with 365 spaces, all initialized to 80.0

    Accessing Elements in a vector:
        - 2 ways to access elements in a vector
            1) Array syntax: vector_name[element_index];
            2) Vector syntax: vector_name.at(element_index);

            ex) test_scores.at(1);  // gives the 2nd element of the test_scores vector

    Changing Elements in a Vector:
        - test_scores.at(0) = 92;   // assignment statement

    Changing the Size of the Vector:
        - Growing the vector size: We can use the .push_back() method
        vector_name.push_back(element);
        
        - Adds an element to the END of the vector.
        - Vector will automatically allocate the required space in memory.
        - Out of Bounds checking. C++ Vectors will give us exceptions and error messages if we go out of bounds.

    2D Vectors:
        - General Syntax:
        std::vector<std::vector<int>> movie_rating {
            {1, 2, 3, 4},
            {1, 2, 2, 4},
            {1, 3, 5, 5}
        };

        - Accessing elements in a 2D vector:
            1) Array Syntax: std::cout << movie_ratings[0][2]; 
            2) Vector Syntax: std::cout << movie_ratings.at(0).at(2);
*/


#include <iostream>
#include <vector>
// we need to include the <vector> header file to use vectors and their functions.


int main() {

    return 0;
}
