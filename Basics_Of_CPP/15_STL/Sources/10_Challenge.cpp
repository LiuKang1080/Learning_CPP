// Deque Challenge, Palindrome Challenge.

/*
A Palindrome is a string that reads the same forwards or backwards.
    - Examples are:
        - madam
        - bob
        - toot
        - radar

An entire phrase can be a palindrome:
    - A Toyota's a toyota
    - A Santa at NASA
    - A man, a plan, a cat, a ham, a yak, a hat, a canal-panama!

Challenge:
    - For this challenge we will only consider alpha characters and omit all other characters.
    - We will not consider spaces, and punctuation
    - A common method to solving this type of problem is to compare the string forward and backwards, if they are equal then
        that string is considered a palindrome.
    - We will use a deque for this challenge.

    - Create a function called is_palindrome().
    - it accepts a const std::string reference.
    - Convert the entire string to alpha characters only, upper or lower case.
    - compare the string to the reverse sequence to determine if the the string is a palindrome.
    - Return true if the string is a plaindrome, else return false.

    - is_palindrome("A Santa At NASA")      // returns true
    - is_palindrome("Hello")                // returns false
*/


#include <iostream>
#include <cctype>
#include <string>
#include <deque>


// palindrome function
bool is_palindrome(const std::string &str) {
    /*
        - We will use a deque
        - Accessing the front and the back of the deque is efficient
        - We will access the front and the back of the deque, and compare to see if the character is the same
        - if the characters are the same, then we will remove those characters, and then check the next pair
        - if at any point the characters are not the same, then we will stop looping, and return false
    */
    std::deque<char> dq;

    // loop through the string
    for (auto i: str) {
        // take only the characters of the string and add them into the deque
        if (std::isalpha(i)) {
            dq.push_back(std::toupper(i));
        }
    }

    // now that our string in the deque is only alpha characters in upper case, we can now compare
    // create c1 and c2 variables
    char c1;
    char c2;

    // while there is more that 1 character we compare the front and the back of the deque
    // if they're the same, we remove the front and back characters
    while (dq.size() > 1) {
        c1 = dq.front();
        c2 = dq.back();
        
        // check to see if c1 and c2 are equal
        if (c1 != c2) {
            return false;
        }

        // pop front and back
        dq.pop_front();
        dq.pop_back();
    }

    // only the loop will return false
    return true;
}


int main() {
    // palindrome test
    std::string s1 = "A Santa at NASA";
    std::string s2 = "Hello";

    // set std::boolalpha so that we print out true / false instead of 1 / 0
    std::cout << std::boolalpha;
    std::cout << "s1 is a plaindrome? " << is_palindrome(s1) << "\n";
    std::cout << "s2 is a plaindrome? " << is_palindrome(s2) << "\n";

    return 0;
}
