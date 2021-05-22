// Set Containers in C++

/*
Set Containers:
    - The set containers are associative containers:
        - A Collection of stored objects that allow fast retrieval using a key.
        - The STL provides Sets and Maps.
        - Usually implemented as a balanced binary tree or hashsets
        - Most operators are very efficient.

Sets:
    - There are 4 set types in C++:
        1) std::set
        2) std::unordered_set
        3) std::multi_set
        4) std::unordered_multiset

    - In order to use a set, we must first #include the <set> header file.
    - Sets are similar to a mathematical set.
    - Ordered by a key.
    - No duplicate items.
    - All iterators are available.
    - Iterators invalidate when corresponding element is deleted.
    
Set Initialization / Assignment:
    
        std::set<int> s1 {1, 2, 3, 4, 5};
        std::set<std::string> stooges {
            std::string {"Larry"},
            "Moe",
            std::string {"Curly"}
        };

        s1 = {2, 4, 6, 8, 10};

Common Methods:

        std::set<int> s1 {4, 1, 1, 3, 3, 2, 5};     // 1, 2, 3, 4, 5
    
    - NO duplicates! Duplicates are ignored. The program will still compile without any errors. The duplicates are simply ignored.
    - No concept of front() and back() methods.

    - .size():
        - Shows the current size of the set
        - s1.size();        // 5

    - .max_size():
        - The maximum number of elements that a set can contain. A very large numnber, generally depends on the operating system.

    - .insert():
        - adds the element provided in the argument into the set.
        - s1.insert(7);     // 1, 2, 3, 4, 5, 7

    - .emplace()
    
    - The set is automatically sorted.
    - There is NO direct element access. No subscript operator [], or the .at() operator

        Person p1 {"Larry", 18};
        Person p2 {"Moe", 25};

        std::set<Person> stooges;
        stooges.insert(p1);                     // adds p1 to the set
        
        auto result = stooges.insert(p2);       // adds p2 to the set

    - Uses the overloaded operator< for ordering of elements
    - Returns a std::pair<iterator, bool>
        - first argument = An iterator to the inserted element or to the duplicate in the set.
        - second argument = A boolean indicating success or failure.

    - .erase():
        - removes the element provided in the argument
        - s1.remove(3);     // removes the 3 | 1, 2, 4, 5, 7

    - .find():
        - creates an iterator "pointing" to the provided element in the argument

        auto itr = s1.find(5);      // creates an iterator pointing to the element 5
        if (itr != s1.end()) {
            s1.erase(itr);          // erase what the iterator is pointing to, it will erase 5
        }

    - The .find() method for sets is different compared to the .find() method found in the STL. This specific .find() has
        specific features related to dealing with sets. Use the .find() method found in the <set> header file.
    
    - .count():
        - Shows how many times an element appears in the set. This isn't really useful for a set itself since there cannot be any
            duplicate items, but is included in the <set> header file because std::multi_set is also included in this header file.
            .count() method is useful for multisets.

    - .clear()
        - Remove all of the elements.

    - .empty()
        - Returns a true / false depending on if the set is empty or not.

Multi Sets:
    - The multi_set feature is located in the same header file as regualr sets.
    - In order to use multi sets we must #include the <set> header file.

        #include <set>
        std::multi_set

    - Sorted by keys.
    - Allows duplicates of elements.
    - All iterators are available.

Unodered Set:
    
        #include <unordered_set>
        std::unordered_set

    - Elements are unordered.
    - NO duplicate elements.
    - Elements CANNOT be modified once they're in the unodered set.
        - Elements MUST be erased, and new elements inserted.
    - NO reverse iterators allowed!

Unordered Multiset:

        #include <unordered_set>
        std::unordered_multiset

    - Elements are unordered.
    - Allows duplicate items.
    - NO reverse iterators!
*/


#include <iostream>
#include <set>
#include <unordered_set>


int main() {

    return 0;
}
