// Other Methods Of Reading From a File in C++

/*
.getline() Method:
    - Reads the whole line until a new line character is reached. This might be more useful compared to reading one character
        at a time with the extraction operator ( >> )
    
        std::string line;
        std::ifstream in_file;
        in_file.open("../poem.txt");

        if (!in_file) {
            std::cerr << "File Open Error \n";
        }

        while (std::getline(in_file, line)) {
            std::cout << line << "\n";
        }

        // always close the file when we're done working with it
        in_file.close();

    - std::getline() method has 2 versions: 1) getline() that works with char pointers or C-style strings, and 2) C++ style strings.
        We will be using the C++ style string version. We can just directly read from the file using the data type std::string

    - std::getline(stream_source, data_to_be_placed_into): There are 2 arguments that getline() requires. 1) The source of the
        stream, in this case it is the file [in_file], and 2) Where the data will be strored, in this case it is the variable
        called [line]

Reading a File (Unformatted) (1 Character At a Time):
    - We can use the .get() method to read in 1 character at a time. With the .get() method we don't have to worry about new-
        line, end of file, unique characters, or other program related issues. This gives us a little bit more flexibility.

        std::ifstream in_file;
        in_file.open("../poem.txt");
        char c;

        if (!in_file) {
            std::cerr << "File Open Error \n";
            return 1;
        }

        while (in_file.get(c)) {
            std:cout << c;
        }

        // always close the file when we're done working with it
        in_file.close();

    - Here for .get() requires 1 argument, it is looking for a place to store that data, here in this case we will store the
        data into a varibale called [c].
*/


#include <iostream>
#include <fstream>


int main() {

    return 0;
}
