// STL Vector | std::vector in C++

/*
std::vector
    - #include <vector>
    - We've been using vectors this entire time, we know the basics of vectors, but we'll go over some of their properties that
        we haven't seen before.
    
    - Dynamic Size:
        - Handled automatically
        - Can expand / contract as needed
        - Elements are stored in contigous memory as an array
    - Direct Element access (constant time) (O(1))
    - Rapid insertion / deletion at the back of the vector (constant time) (O(1))
    - Insertion / removal of elements at location (linear time) (O(n))
    - All iterators are available.
    - Iterators may become invalid, check the cppreference
    - Remember that when we add / remove elements from a vector we do not change the original data, the data is copied over into
        the container. Elements that are put into containers are COPIES!

Initialization / Assignment:

        std::vector<int> vec1 {1, 2, 3};
        std::vector<int> vec2 (10, 100);

    - In the second example, we're creating a vector that has 10 elements, each of those elements are 100.
    - Assignment after initilization:

        vec1 = {10, 20, 30};

Common Methods:
    - .front() method:
        - Access the first element in the vector

    - .back() method:
        - Access the last element in the vector

    - .push_back() method:
        - Adds an element to the back of the vector

    - .size() method:
        - Shows the size of the vector

    - .capacity() method:
        - Tells the current capacity of the vector, when the capacity is exceeded the vector will dynamically expand.
        - Generally we will not be using this method, but it can be useful in very niche cases.

    - .max_size() method:
        - Tells the maximum size a vector can be on your operating system. This is the maximum number of elements that a vector
            can hold. Generally this is a ver large number.
        - Running this on my machine gives: 2,305,843,009,213,693,951

Accessing Elements:
    - .at() method:
        - Access the element by the provided index. This method performs bounds checking.

    - Subscript Operator | [] method:
        - Manually access the element by the provided index. This method does NOT perform bounds checking.  

Insert Elements:
    - .push_back() method:
        - Adds an element to the back of the vector.

    - .pop_back() method:
        - Removes an element at the end of the vector.

    - .emplace_back() method:
        - Lets say that we have a Person class, this class has a name and an int representing the age. We also have a vector that
            holds Person objects. If we want to add a Person element into the vector we could do:

        vec1.push_back(Person {"Bob", 25});

        - Adds a Person element into the vector. What the .emplace_back() method does is it allows us to directly add in the
            details of the object into the vecotr. Directly add in the class object without having to tell the compiler that
            another Person object is being added into the vector:

        vec1.emplace_back("Alice", 20);

        - Added a new Person object at the end of the vector.
        - It will call the class constructor for us.
        - This is very efficient! Use emplace_back() when you can!

    - .empty() method:
        - Returns true if the vector is empty, returns false otherwise.

    - vec2.swap(vec1); method:
        - Swaps the elements of the 2 vectors.

    - std::sort(vec1.begin(), vec1.end()); method:
        - Sorts the vector in order.

    - .find() and .insert() methods:
        - General Syntax:
            - insert(location, what_to_insert);
        - We can use iterators to find elements, and insert elements in a location other than the end of the vector.

        std::vector<int> vec1 {1, 2, 3, 4, 5};
        std::vector<int> vec2 {10, 20, 30, 40, 50};

        auto it = std::find(vec1.begin(), vec1.end(), 3);
        - Find 3 in vec1, this will return a iterator "pointing" to the loaction where 3 is found

        vec1.insert(it, 10);
        - Add the element 10 into the location it, here it is "holding" the location of where 3 is, now we insert 10 into that
            location.

        it = std::find(vec1.begin(), vec1.end(), 4);
        - return a iterator that has the location where 4 is

        std::insert(it, vec2.begin(), vec2.end());
        // 1, 2, 10, 3, 10, 20, 30, 40, 50, 4, 5

Other Methods:
    - .shrink_to_fit() method:
        - When a vector increases in size generally it will double in size. If we have 50 elements, and we add the 51st element,
            the vector will grow and it will expand to have 100 elements. .shrink_to_fit() will reduce the size of the vector to
            be the smallest it can be while holding all of the elements.
        - Only available in C++11 and onward.

    - .reserve(n) method:
        - Reserves space for n number of elements in memory.
        - Generally we will not use this method, rather we will let the compiler handle the space, and once in a while we will
            call the .shrink_to_fit() method.

    - .clear() method:
        - Removes all of the elements in the vector

    - .erase() method:
        - removes the element at the provided location.
        - !!! LOOK AT THE EXAMPLE BELOW !!!
*/


#include <iostream>
#include <vector>


// print out the elements of a vector
void print_vector(const std::vector<int> &vec) {
    for (auto i: vec) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}


int main() {
    std::vector<int> vec1 {1, 2, 3};

    // show the maximum number of elements the vector can hold:
    std::cout << "Vector Max Size is: " << vec1.max_size() << "\n";

    // erase all even numbers in a vector
    std::vector<int> vec2 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // print the vector
    print_vector(vec2);
    auto it = vec2.begin();

    while (it != vec2.end()) {
        if (*it % 2 == 0) {
            vec2.erase(it);
        } else {
            ++it;
        }
    }

    /*
        - vec2.begin() returns an iterator that is pointing to the beginning of the vector.
        - the while loop: While it is not at the end of the vector keep looping.
        - if it (dereferenced) is completly divisible by 2, then erase that element. Pay attention that we're passing in it into
            the .erase() method. We are NOT dererencing it! We're passing in the "pointer" that is pointing to the location.
        - else increment forward.
        - We do NOT increment when we erase, or we will skip the next number everytime we erase, we want to check ALL of the
            numbers!
    */

    // print after the even numbers are gone
    print_vector(vec2);

    return 0;
}
