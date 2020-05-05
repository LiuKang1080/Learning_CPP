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
    /*
        Vector challenge:
            1)
            - Create 2 empty vectors named Vector 1 and Vector 2.
            
            2)
            - Add 10 and 20 to vector 1 dynamically using the push_back() method
            - Display the elements in Vector 1 using the .at() method as well as the size() method

            3)
            - Add 100 and 200 to Vector 2 dynamically using the push_back() method
            - Display the elements in Vector 2 using the .at() method as well as the size() method

            4)
            - Declare an empty 2D vector called vector_2d
            - Add both vector 1 and vector 2 dynamically using the push_back() method
            - Display the elements in vector_2d using the .at() method

            5)
            - Change vector.at(0) to 1000
            - Display the elements in vector_2d again using the .at() method
            - Display the elements in vector 1 
    */

    // 1) Create the empty vectors:
    std::vector<int> vector_1;
    std::vector<int> vector_2;

    // 2) add elements to vector_1 and display the contents
    vector_1.push_back(10);
    vector_1.push_back(20);

    std::cout << "** Vector 1: \n";
    std::cout << vector_1.at(0) << "\n";
    std::cout << vector_1.at(1) << "\n";
    std::cout << "The size of Vector 1 is: " << vector_1.size() << " elements. \n";

    // 3) add elements to vector 2, and display the contents.
    vector_2.push_back(100);
    vector_2.push_back(200);

    std::cout << "** Vector 2: \n";
    std::cout << vector_2.at(0) << "\n";
    std::cout << vector_2.at(1) << "\n";
    std::cout << "The size of Vector 2 is: " << vector_2.size() << " elements. \n";

    // 4) create a 2d vector called vector_2d, and add both vector 1 and 2 into the 2d vector. Display the contents.
    std::vector<std::vector<int>> vector_2d;
    vector_2d.push_back(vector_1);
    vector_2d.push_back(vector_2);

    std::cout << "** 2D Vector: \n";
    std::cout << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << "\n";
    std::cout << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << "\n";

    // 5) change the first element of vector 1 from 10 to 1000 and print out the contents of 2d vector again
    vector_1.at(0) = 1000;

    std::cout << "** Changed 2D Vector: \n";
    std::cout << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << "\n";
    std::cout << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << "\n";

    // even though we changed the first element of vector 1, printing the 2d vector will results in the same as before.
    // when we add elements to vectors, we are making a copy of what we're inserting into the vector.
    
    // when we use ints, floats, or doubles for the vector we are making a copy of that vector, if we wanted to use the vector
        // itself we would need to use pointers to the vector  
        
    return 0;

}
