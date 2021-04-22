// Reading From a File in C++

/*
Reading from a text file:
    - Input files (fstream and ifstream). fstream and ifstream are commonly used for input files.
    
    1) #include <fstream>
    2) Declare an fstream or an ifstream object
    3) Connect it to a file on your file system (Opens it for reading)
    4) Read the data from the file via the stream
    5) Close the stream after we're done working with the file

2) Creating a stream object to read from a file:

        std::fstream in_file {"../myfile.txt", std::ios::in};

    - Opening the file for reading in binary:

        std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary};

    - Here the ../myfile.txt is the path for the specified file. ../ looks in the parent directory for that file.
    - std::ios::in opens the file in input mode (read only, does not write to the file)
    - | is the pipe operator / bitwise or operator
    - By defualt files are open in text mode, not binary. If we want to read a file in binary, we need to manually specifiy it.
    - The ifstream class is used for input stream files only. fstream can be used for reading and writing to and from files.

        std::ifstream in_file {"../myfile.txt", std::ios::in};

    - the std::ios::in is optional for ifstream, since it is the defualt.

        std::ifstream in_file {"../myfile.txt"};

    - We still must supply the binary made flag if we want to read the file in binary

        std::ifstream in_file {"../myfile.txt", std::ios::binary};

.open() Method:
    - Another common way to open a file:

        std::ifstream in_file;      // haven't provided the filename to associate with it
        std::string filename;
        std::cin >> filename;       // get the file name from the user

        in_file.open(filename);
        OR
        in_file.open(filename, std::ios::binary);

        - This is a common approach since we may not know the name of the file until run-time, so instead we ask for the user
            for the file name.

.isopen() Method:
    - Checking to see if the file opened successfully, we can use the .isopen() method.

        if (in_file.isopen()) {
            // read from the file
        } else {
            // file could not be loaded
            // does the file exist?
            // should the program terminate if the file cannot be opened?
            // generally this is program dependent on how we deal with this situation        }

    - We can test the stream object itself:

        if (in_file) {                  // just check the file itself to see if it is opened
            // read from the file
        } else {
            ...
        }

5) Closing The File:
    - Always close any files to flush out any unwritten data.
    - .close() method.

        in_file.close();

    - It is very important to close for output files. For reading and writing to files.
    - The best practice is to close the file regardless of that we're doing! If we open a file, we should close it when we're
        done working with it!

4) Reading From Files:
    - There are many ways to read from files.
    - We can use the extraction operator for formatted reads from files.
    - We use the extraction operator the same way we used it for cin.

        // File Contents
        [
            100
            123.45
            Bob
        ]

        int num {};
        double total {};
        std::string name {};

        in_file >> num;
        in_file >> total >> name;
        // we assume that in_file is created successfully

.getline() Method:
    - We can use the .getline() method to get 1 line at a time.

        [This is a line] File Contents

        std::string line {};
        std::getline {in_file, line};

        - in_file = The stream we're reading from
        - line = The stream we're reading it to

    - The entire line up to the new line character will be read in, and stored into the string variable named line.

Reading Line By Line Using a For Loop:

        std::ifstream in_file {"../myfile.txt"};    // open file
        std::string line {};

        if (!in_file) {                             // check to see if the file is open 
            std::cerr << "File Open Error \n";
            return 1;                               // exit the program (main)
        }

        while (!in_file.eof()) {                    // while not at the end of the file eof() method
            std::getline(in_file, line);
            std::cout << line << "\n";              // display the line 
        }

        // close the file when we're done working with it
        in_file.close();

Different Version of a While Loop:

        while (std::getline(in_file, line)) {       // read a line
            std::cout << line << "\n";
        }

        // close the file when we're done working with it
        in_file.close();

    - We can embed many of the string input statements into the while loop condition.
    - These statements return a reference to the stream object, they'll only return a true value if the read line was successful.
    - When we reach end of the file or some other error occurs, they will not return true and the while loop stops.

Reading A Text File 1 Character At A Time. .get() Method:
    
        std::ifstream in_file {"../myfile.txt"};    // open file
        char c;

        if (!in_file) {                             // check to see if the file is open 
            std::cerr << "File Open Error \n";
            return 1;                               // exit the program
        }

        while (in_file.get(c)) {                    // get a character
            std::cout << c;                         // display that character
        }

        // close the file when we're done using it
        in_file.close()

    - The .get() method is generally for unformatted files. Unformatted reads 1 character at a time, regardless of what that
        character is.
*/


#include <iostream>
#include <fstream>


int main() {

    return 0;
}
