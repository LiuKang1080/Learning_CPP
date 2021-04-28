// Writing to a File in C++

/*
Writing to a file:
    - #include <fstream> We need to include this header file in order to read and write to files.
    
    - Output files (fstream and ofstream)
    - fstream and ofstream are the most commonly used classes for writing to a file.
    - Basic steps:
        1) #include <fstream>
        2) Declare an fstream ofstream object
        3) Connect it to a file on the file system (opens it up for writing)
        4) Write data to the file via the stream
        5) Close the file when we're done working with the file

    - By defualt if we write to a file that DOES NOT EXIST, then C++ will automatically create the file.
    - If the file does exist and we write to it, then the contents of the file will be removed / truncated UNLESS we state
        otherwise.
    - We can write to files in text or in binary mode. We can use any of the stream modes we've learned about.
    
    - When we're done working with the file, we MUST close the file, it is way more important that we do this for output files
        compared to input files, since it flushes any buffers that may not have been written out to the file yet.

    - Output Files:
        - Output files will be created if they do not exist
        - Output files will be overwritten (truncated) by defualt [unless we specify that we want to append to the file]
        - Can be opened so that new writes appends to the file
        - Can be opened in text mode or in binary mode

        std::fstream out_file {"../myfile.txt", std::ios::out};
        std::fstream out_file {"../myfile.txt", std::ios::out | std::ios::binary};

    - Here the | is the bit-wise or operator. The pipe character
    - By defualt files open in text mode.
    - The fstream class can open a file for reading AND writing at the same time.

ofstream:
    - The ofstream is for output ONLY.
    
        std::ofstream out_file {"../myfile.txt"};

    - Here std::ios::out is optional since in the ofstream it is present by defualt
    
    - Other file opening options:
        1) Truncate (discard changes) - This is the defualt when opening a file.

            std::ofstream out_file {"../myfile.txt", std::ios::trunc};

        2) Append on each write:

            std::ofstream out_file {"../myfile.txt", std::ios::app}; 

        3) Seek to the end of the stream when opening:
            - ate = at end
            - Set the initial position of the next write at the end of the file.

            std::ofstream out_file {"../myfile.txt", std::ios::ate};

Opening a File:
    - The .open() method:
    
        std::ofstream out_file;
    
    - We create the file object, but we do not provide the file name, since a majority of the time we do not know the file name
        until run-time 

        std::string file_name;
        std::cin >> file_name;      // ask the user for the file name at run-time

        out_file.open(file_name);

Check To See If The File Is Open:
    - We can use the .is_open() method to check to see if the file is open

        if (out_file.is_open()) {
            // write to the file
        } else {
            // if file open fails do we exit? close the program?
        }

    - Another way to check to see if the file is opened is to use the actual object itself!

        if (out_file) {         // just check with the object itself
            // write to the file
        } else {
            // what do we do when the file open fails?
        }

.close() Method:
    - To close a file we can use the .close() method.
    - ALWAYS close a file when we're done using it!

        out_file.close();

Writing to a File:
    - We can use the insertion operator ( << ) for formatted writes to files
    - Same way we used it with std::cout << 

        int num = 10;
        double total = 25.75;
        std::string name = "Bob";

        out_file    << "num: " << num << "\n" 
                    << "total: " << total << "\n"
                    << "name: " << name << "\n";

    - std::endl - Actually flushes out any unwritten bufferes to the file.

Example: Copying a text file to another file one line at a time:
    
        std::ifstream in_file {"../myfile.txt"};    // open the file
        std::ofstream out_file {"../copy.txt"};

        // check to see if the files are properly opened
        if (!in_file) {
            std::cerr << "File Open Error for Reading. \n";
            return 1;
        }

        if (!out_file) {
            std::cerr << "File Open Error for Writting. \n";
            return 1;
        }

        std::string line {};

        // read the contents of the file and copy them into the other file
        while (!in_file.eof()) {
            std::getline(in_file, line);        // read the data from the file
            out_file << line << "\n";           // write the data to the file
        }

        // close the files when we're done working with them!
        in_file.close();
        out_file.close();

Using Formatted Read and Writes to Files:
    - We can use the .get() and the .put() methods.

        char c;
        
        while (in_file.get(c)) {        // get the character
            out_file.put(c);            // write the character 
        } 

        // close the files
        in_file.close();
        out_file.close();
*/


#include <iostream>
#include <fstream>
#include <string>


int main() {
/*
Writing to Files Challenge:
    - A File called Original.txt contain Lorem Ipsum text.
    - Lorem Ipsum text is generated from the website: https://www.lipsum.com/
    - Each line contains a single sentence from the text.
    - Copy all of the text from the Original file to a file called Copy.txt
    - format the Copy.txt file so that each line starts with a line number, followed by the sentence text.
*/

    // create the input / output files objects
    std::ifstream in_file {"Original.txt"};
    std::ofstream out_file {"Copy.txt"};

    // test to see if file opening is successful
    if (!in_file.is_open()) {
        std::cerr << "Error Opening File: Original.txt \n";
        return 1;
    }

    if (!out_file.is_open()) {
        std::cerr << "Erro Opening File: Copy.txt \n";
        return 1;
    }

    // set up the variables. More efficient if we set up the variables AFTER we check to see if the file opening is successful.
    int line_number = 1;
    std::string line {};

    // perform data processing
    // read from the file and copy text over to the other file
    while (std::getline(in_file, line)) {
        out_file << line_number << ": " << line << "\n";
        ++line_number;
    }

    // close the files
    in_file.close();
    out_file.close();

    std::cout << line_number << " Lines were copied over to the new file. \n";
    std::cout << "Finished copying file. \n";

    return 0;
}
