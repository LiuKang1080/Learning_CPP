// Unscoped Enumerations in C++

/*
Unscoped Enums in C++:
    - Here we have the general syntax for enums

        enum_key enum_name : enumerator_type { };

    - The enum_key defines if the enum will be scoped or not.
    - By defualt the enum_key is unscoped. In the previous examples we had the enum keyword with followed by the strcuture of the
        enum, this by defualt is unscoped.
    - When an enum is unscoped, it means that the enumerators are unqualified, and they're visibile to the entire scope in which
        the enum is defined in.

    - Some of the best places to use unscoped enums is in if / switch statements:

        State state = get_state();

        if (state == Nominal) {
            initiate(Launch);
        } else if (state == Incelment_Weather) {
            initiate(Hold);
        } else if (state == Engine_Failure) {
            initiate(Abort);
        }

    - Here the enum represents the different states of a rocket launch.
    - There is still a small issue in this if statement. If the state returns Engine_Failure, the logic still checks to see if
        it's Nominal, and then checks to see if it's Inclement_Weather, and then finally checks to see if the state is
        Engine_Failure. We need this check to happen instantly!
    - Rather than using if-else statements we can use switch statements with enums. Switch statements allows equal access time
        to the switch.

        State state = get_state();

        switch (state) {
            case Engine_Failure:
                initiate(Abort);
                break;

            case Inclement_Weather:
                initiate(Hold);
                break;

            case Nominal:
                initiate(Launch);
                break;
        }

Using cin and cout with Unscoped Enumerations:
    - There are 2 ways to to set user definied data into an enum

    1) Using the underlying data type, and then casting it to a specific enum

        enum State {Engine_Failure, Inclement_Weather, Nominal};
                        0                   1             2

        - The underlying data type is int

        std::underlying_type_t<State> user_input;
        std::cin >> user_input;
        State state = State(user_input);

    - std::underlying_type_t is a class template that we use to cast it into the State data type. The compiler will try to
        deduce it.
    - Since the underlying_type_t is of type int, user_input will also be of type int.
    - There is NO guarentee that the value entered will correspond to once of the values in the enum!
    - Ex) If the user enters in 3, it will be casted into the State data type of 3, We will get NO ERRORS! BUT THIS IS WRONG!
        3 does not correspond to anything!
    - We need to manually check to see if the data enteres corresponds properly to the State enum.
    - We can do so with switch statements:

        enum State {Engine_Failure, Inclement_Weather, Nominal};

        std::underlying_type_t<State> user_input;
        std::cin >> user_input;
        State state;

        switch (user_input) {
            case Engine_Failure:
                state = State(user_input);
                break;

            case Inclement_Weather:
                state = State(user_input);
                break;

            case Nominal:
                state = State(user_input);
                break;

            defualt:
                std::cout << "User input is not a valid state! \n";
        }

    2) The second method to enter user input into enums is through the overloaded extraction operator function:

        enum State {Engine_Failure, Inclement_Weather, Nominal};

        std::istream &operator>>(std::istream &is, State &state) {
            std::underlying_type_t<State> user_input;                   // type int
            is >> user_input;

            switch (user_input) {
                case Engine_Failure:
                    state = State(user_input);
                    break;

                case Inclement_Weather:
                    state = State(user_input);
                    break;

                case Nominal:
                    state = State(user_input);
                    break;

                default:
                    std::cout << "User input is not a valid state! \n";
            }

            return is;
        }

    - It is EXTREAMLY IMPORTANT that the overloaded extraction operator is in the SAME SCOPE as the enum!
    - Now we can do:

        State state;
        std::cin >> state;  // This is now valid with the overloaded extraction operator function

std::cout with Enums:
    - When we use the Insertion operator, it will display the underlying data type 

        enum State {Engine_Failure, Inclement_Weather, Nominal};

        State state = Engine_Failure;

        std::cout << state;         // displays 0

    - Whenever we print out enums it will ALWAYS print the underlying data type which is generally ints. It will NEVER print the
        name / string itself
    - If we wanted it to print the name / string we can use a switch to set it up:

        enum State {Engine_Failure, Inclement_Weather, Nominal};

        State state = Engine_Failure;

        switch (state) {
                case Engine_Failure:
                    std::cout << "Engine_Failure. \n";
                    break;

                case Inclement_Weather:
                    std::cout << "Inclement Weather. \n";
                    break;

                case Nominal:
                    std::cout << "Nominal. \n";
                    break;

                default:
                    std::cout << "Unknown. \n";
            }

    - We can also implement this using an overloaded insertion operator function:

        enum State {Engine_Failure, Inclement_Weather, Nominal};

        std::ostream &operator<<(std::ostream &os, const State &state) {
            switch (state) {
                case Engine_Failure:
                    os << "Engine Failure";
                    break;

                case Inclement_Weather:
                    os << "Inclement Weather";
                    break;

                case Nominal:
                    os << "Nominal";
                    break;

                default:
                    os << "Unknown";
            }

            return os;
        }

    - Now we can use the insertion operator to print out the actual name / string

        State state = Engine_Failure;
        std::cout << state;                 // displays "Engine Failure"
*/


#include <iostream>


int main() {

    return 0;
}
