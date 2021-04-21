// Align and Fill Stream Manipulators in C++

/*
Align and Fill Stream Manipulators:
    - Alight and Fill Manipulators requires the <iomanip> header file

        #include <iomanip>

    - Stream formatting options that work with any type of data.
    - Determine the field width, then display the next data item either left or right justified within that field.
    - Fill character is used to fill in any empty space.
    - By defualt there is no field width defined.
    - If we set a field width, then the defualt is right justified within that field width.
    - If we set the field and the justification, they are ONLY applied to the next output on the stream!
        - It is not permanent!
        - The fill character WILL persist until we change it!

    - Defualt stream output:

        double num {1234.5678};
        std::string hello {"Hello"};

        std::cout << num << hello << "\n";

        // will display
        1234.57Hello

    - Now we will use the setw() method:

        std::cout << std::setw(10) << num << hello << "\n";

        // will display
            1234.57Hello

    - The setw() only works for the NEXT data item! In this case it is num. The defualt is right justified

        std::cout   << setw(10) << num
                    << setw(10) << hello
                    << setw(10) << hello << "\n";

        // will display
            1234.57     Hello       Hello

    - ALL of the data items are right justified.

        std::cout   << stdw(10) << std::left << num
                    << hello << "\n";

        // will display
        1234.57     Hello

setfill() Method:
    - Only works when a field width is set.
    - We supply the character to it, and it fills in any empty space with that character that we provided.
    - Remember that the fill character method is persistant, but the setw() IS NOT!
        - Once the setw() is "consumed" by the next data point, the fill method will not work until it reaches a new setw() width!

        std::cout   << std::setfill('+') << std::setw(10) << num
                    << std::setfill('-') << std::setw(10) << hello
                    << std::setfill('-') << std::setw(15) << hello << "\n";

        // will display
        ***1234.57-----Hello----------Hello
*/


#include <iostream>
#include <iomanip>


void ruler() {
    std::cout << "\n1234567890123456789012345678901234567890\n";
}


int main() {
    double num = 1234.5678;
    std::string hello = "Hello";

    ruler();
    std::cout   << std::setfill('*') << std::setw(10) << num
                << std::setfill('-') << std::setw(10) << hello
                << std::setfill('-') << std::setw(15) << hello << "\n";

    return 0;
}
