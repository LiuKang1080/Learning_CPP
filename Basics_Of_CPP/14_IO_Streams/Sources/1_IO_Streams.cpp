// File, I/O, and Streams in C++

/*
File, I/O, and Streams:
    - C++ uses streams as an interface between the program and input and output devices.
    - Independent of the actual device. (From a programmer's perspective, we do not need to worry about what device is connected)
    - Sequence of bytes (This is what a stream is)
    - Input stream provides data to the program.
    - Output stream recieves data from the program.

Common Header Files:
    - These header files allows us to work with files, streams, ans other I/O without having to make these features ourselves.

    - <iostream> = Provides definitions for formatted input and output from and to streams (we've been using this the entire time!)
    
    - <fstream> = Provides definitions for formatted input and output from and to file streams.

    - <iomanip> = Provides definitions for manipulators used to format stream I/O

Commonly Used Stream Classes:
    - ios = Provides basic support for formatted and unformatted I/O operations. Serves as a base class for most other classes
        related to I/O.

    - ifstream = Provides high level input operations on file based streams.

    - ofstream = Provides high level output operations on file based streams.

    - fstream = Provides for high level I/O operations on file based streams. Derived from ofstream and ifstream.

    - stringstream = Provides for high level I/O operations on memory based strings. Derived from istringstream and ostringstream.

Global Stream Objects:
    - cin = Standard input stream - by defualt "connected" to the standard input device (keyboard). Instance of istream.

    - cout = Standard output stream - by defualt "connected" to the standard output device (console). Instance of ostream.

    - cerr = Standard error stream - by default "connected" to the standard to the standard error device (console). Instance of
        ostream (unbuffered).

    - clog = Standard logging stream - by defualt "connected" to the standard log device (console). Instance of ostream 
        (unbuffered).

    - Global objects are initialized BEFORE main() is executed.
    - The best practice is to use cerr for error messages, and clog for logging messages.

Stream Manipulators:
    - In order to use the manipulators we must include <iomanip>

        #include <iomanip>

    - Streams have useful member functions to control formatting.
    - Can be used on input and output streams.
    - The time of effect on the stream varies (Setting for the entire program, setting for an object's life, setting applied instantly).
    - Can be used as member functions or as manipulato.

        std::cout.width(10);            // member function
    
    - calling the width() method on the cout object.

        std::cout << std::setw(10);     // manipulator

Common Stream Manipulators:
    - Boolean:
        - boolalpha, noboolalpha

    - Integer:
        - dec, hex, oct, uppercase, nouppercase, and others

    - Floating Point:
        - fixed, scientific, setpercision, and others

    - Field Width, Justification, and Fill:
        - setw, left, right, internal, setfill

    - Others:
        - endl, flush, skipws, noskipws, ws
*/


#include <iostream>
#include <iomanip>


int main() {

    return 0;
}
