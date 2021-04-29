// String Streams in C++

/*
String Streams:
    - Allows us to read and write from strings in memory as much as we would read and write to files.
    - This is very powerful.
    - This is very useful for data validation.
    
Using String Streams:
    1) #include <sstream>
    2) Declare a stringstream, istringstream (read from string stream), or an ostringstream (write to string stream) object.
    3) Connect the string stream object to an std::string
    4) Read/Write data to/from the string stream using formatted I/O

Reading From a String Stream:
    - example:

        #include <sstream>

        int num {};
        double total {};
        std::string name {};
        std::string info {"Bob", 100, 1234.56};

        // read the data INTO the string stream
        std::istringstream iss {info};

        // set the data values to the proper variables using the string stream
        iss >> name >> num >> total;
        // notice the order is the same as it is in info

    - We are reading from a string stream

Writing to a String Stream:
    - example:

        int num = 100;
        double total = 1234.56;
        std::string name = "Bob";

        std::ostringstream oss {};

        // write the data into the oss string stream object
        oss << name << " " << num << " " << total;

        // display the contents of the string stream object
        std::cout << oss.str() << "\n";

    - The string stream has its own internal buffer, and we can display that entire string by calling the .str() method.

Basic Data Validation With String Streams:
    
        int value {};
        std::string input {};

        std::cout << "Enter an Integer: \n";
        std::cin >> input;

        std::stringstream ss {input};

        if (ss >> value) {
            std::cout << "An integer was entered \n";
        } else {
            std::cout << "An integer was NOT entered \n";
        }

    - We have a string named input, we read the user's input into that string. We don't read into an integer, we first read it
        into a string. We will then try to convert that string into an int if possible.
        
    - We create a srtring object ( ss ) and we connect it to the input string the user entered. We then try to extract an integer
        from ss and store it into the variable value. We can do this by using the extraction operator, if it is successful then
        we will have a valid int stored into value. If it is NOT successful, then we know that the user did not enter a valid int.
*/


#include <iostream>
#include <string>
#include <sstream>


int main() {

    return 0;
}
