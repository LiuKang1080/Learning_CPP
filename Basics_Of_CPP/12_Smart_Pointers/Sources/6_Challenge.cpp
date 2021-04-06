// Smart Pointers Challenge

/*
Smart Pointer Challenge
    - Implement the 3 Function Prototypes.
    - The code should contain NO "new" and "delete" calls.
    
    1) Create a function named make() that creates and returns a unique pointer to a vector of shared pointers to Test objects
    
    2) create a function named fill() that expects a vector of shared pointers to Test objects and a int representing the number
        of Test objects to create dynamically and add to the vector.

    3) Create a function named display() that expects a vector to shared pointers to Test objects and displays the data in each
        Test object.

    4) The main() should look like this:

        int main() {
            std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
            vec_ptr = make();
            std::cout << "How many data points do you want to enter? : ";
            int num;
            std::cin >> num;
            fill(*vec_ptr, num);
            display(*vec_ptr);

            return 0;
        }
*/


#include <iostream>
#include <memory>
#include <vector>


// Test class
class Test {
private:
    int data;

public:
    // no args constructor
    Test(): data {0} {
        std::cout << "\t Test constructor. Data: " << data << "\n";
    }

    // data args constructor
    Test(int data): data {data} {
        std::cout << "\t Test constrcutor. Data: " << data << "\n";
    }
    
    // destructor
    ~Test() {
        std::cout << "\t Test destructor called. Data: " << data << "\n";
    }

    int get_data() const {
        return data;
    }
};

// Function Prototypes:
auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

// Function Implementations:
// make() fucntion - makes the unique pointer
auto make() {
    // this function just makes the unique pointer on the heap, that's all this function does!
    // return the unique pointer
    // start with make_unique
    // what are we making unique? we're making a unique pointer to a vector, that has shared pointers to Test objects
    
    // for the return, we can tell the compiler to figure out the return data types. We can set the return data type in the
    // function header as auto
    // ask the compiler to figure it out itself what the return data type is.
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

// fill() function
void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    // the fill() functions expects the vector 
    // fill() also reads in the interger from the user for each iteration
    // we need a temp variable
    int temp;

    // loop num times
    for (int i=1; i<=num; ++i) {
        std::cout << "Enter the Data Point [" << i << "]: ";
        std::cin >> temp;

        // now create the shared pointer and enter the data into the Test object
        // std::shared_ptr<Test> ptr = std::make_shared<Test> (temp);

        // we have a vector of shared pointers, we just created the shared pointer, now we need to add in the shared pointer
        // into the vector
        // vec.push_back(ptr);

        // rather than doing it in 2 lines (lines 91 and 95) we can just do it 1
        vec.push_back(std::make_shared<Test>(temp));
    }
}

// display() function
void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "\n Displaying the vector data \n";
    std::cout << " ===== \n";

    // use a simple ranged based for loop to iterate through the vector and display the elements
    for (const auto &ptr: vec) {
        std::cout << ptr->get_data() << "\n";
    }

    std::cout << " ===== \n";
}


int main () {
    /*
        - vec_ptr is on the stack
        - vec_ptr is a unique pointer pointing to the heap. It is pointing to an vector object. The vector elements are
            shared pointers. The shared pointers are pointing to Test objects.
    */

    // vector call on the stack, nothing is on the heap, we need to implement the functions for the objects to be on the heap.
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    
    // make function returns a unique pointer that is pointing to a vector that contains shared pointers as its elements.
    // the shared pointers are managing Test objects on the heap. 
    vec_ptr = make();

    // ask the user how many data points they want to enter
    std::cout << "How many data points do you want to enter? : ";

    int num;
    std::cin >> num;

    // dereference vec_ptr, vec_ptr is a unique pointer
    // the fill function loops as many times as the user wanted (num), in each iteration it will ask the user 
    // "what number you want to enter? : "
    // for each one of those integers the user entered, we will create a shared pointer to a Test object and set the data to what
    // the user entered.
    fill(*vec_ptr, num);

    // dereference the vec_ptr, and iterating through the vector of shared pointers, and displaying the data that the test
    // objects hold.
    display(*vec_ptr);

    return 0;
}
