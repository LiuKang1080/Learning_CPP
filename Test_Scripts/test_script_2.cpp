// Challenges in C++


/*
Pointers Challenge:
    - Create a function that uses pointers to move through an array of integers. Print both the memory address and the value
        of each element.
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Component {
private:
    std::string label;
    std::string description;
    std::string category_restriction;

public:
    // Compnent constructor:
    Component(std::string label, std::string description, std::string category_restriction, std::string file_path) 
        : label{label}, description{description}, category_restriction{category_restriction} {

        // generate the file with the path and the data
        std::ofstream out_file {file_path};

        // check to see if the file is properly opened
        if (!out_file.is_open()) {
            std::cout << "Error Opening File! \n";
        } else {
            std::cout << "File opened! \n";
        }

        // write the data to the file:
        /*
            - The strucutre of the file will have label, description, and then category_restriction in that order with newlines 
                in between.
        */
        out_file << label << "\n";
        out_file << description << "\n";
        out_file << category_restriction;
    
        // close file when we're done with it
        out_file.close();
    }

    // destructor
    ~Component(){}
};


int main() {
    Component comp1("Sword", "Very Sharp", "No Restrictions", "component.txt");

    return 0;
}
