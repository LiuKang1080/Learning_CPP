// Map Containers in C++

/*
C++ Maps:
    - Also an associative container
        - A collection of stored objects that allow fast retrieval using a key.
        - The STL provides Sets and Maps.
        - Usually implemented as a balanced binary tree or hashsets.
        - Most operations are efficient.

    - There are 4 types of Maps:
        1) std::map
        2) std::unordered_map
        3) std::multi_map
        4_std::unordered_multimap

    - In order to use std::map we must first #include the <map> header file.
    - Similar to a dictionary.
    - Elements are stored as Key, Value pairs (std::pair)
    - Ordered by key.
    - NO duplicate elements (Keys are unique)
    - Direct element access using the key.
    - All iterators are available. Iterators become invalid when the corresponding element is deleted.

Map Initialization and Assignment:
    - General Syntax:
        std::map<key, value> map_name {initialization_data};

        std::map<std::string, std::string> m1 {
            {"Bob", "Hello"},
            {"Alice", "There"},
            {"Mark", "World"}
        };

Common Methods:
    - .size() method:
        - Shows the current size of the map

    - .max_size() method:
        - A very large number, shows the maximum number of elements a map can hold. Depends on the operating system.

    - No concept of a front and a back, therefore there are no front() and back() methods.
    
Inserting Elements Into a Map:

        std::pair<std::string, std::string> p1 {"Roger", "Ranger"};

        m1.insert(p1);

        OR 

        m1.insert(std::make_pair("James", "Engineer"));

    - There is another way to add elements into the map, using the subscript operator and the .at() method.

        m1["Frank"] = "Teacher";        // Insert
        m1["Frank"] = "Instructor";     // Update the value
        m1.at("Frank") = "Professor";   // Update the value using the .at() method

Erasing Elements From The Map:
    - We can use the .erase() method to remove an element from the map.
    - The argument we pass in is the Key, we do NOT pass in the Value

        m1.erase("Frank");

    - ex)

        if (m1.find("Bob") != m1.end()) {
            std::cout << "Bob is found in the map. \n";
        }

    - Using an iterator example:

        auto itr = m1.find("George");
        if (itr != m1.end()) {
            m1.erase(itr);
        }

        - If George is found in the map, we will remove that key, value pair.

    - .count() method:
        - Counts the number of times that key appears in the map. Since it's a regular map, it will either be 0 or a 1

        int num = m1.count("Bob");

    - .clear() method:
        - Removes all of the elements from the map.

    - .empty() method:
        - Returns a true / false depending on if the map is empty or not.

Multi-Map:

        #include <map>
        std::multi_map

    - Ordered by Key
    - Allows duplicate elements
    - All iterators are available

Unordered-Map:

        #include <unordered_map>
        std::unordered_map

    - Elements are unordered
    - No duplicates of elements allowed
    - No reverse iterators allowed

Unordered-Multimap:

        #include <unordered_map>
        std::unordered_multimap

    - Elements are unordered
    - Allows duplicates of elements
    - No reverse iterators are allowed
*/


#include <iostream>
#include <map>
#include <unordered_map>


int main() {

    return 0;
}

// Testing commit