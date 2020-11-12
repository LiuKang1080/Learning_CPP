// Using const with Classes 

/*
const With Classes:
    - Passing arguments to class member methods as const.
    - We can also create const objects.
    - What happens if we call member functions on const objects?
    - const-correctness (using const properly, allowing methods to access const members properly)

    - ex) villain is a const object so its attributes cannot change

        const Player villain {"villain", 100, 55};

    - What happens when we call member methods on a const object?

        void display_player_name(const Player &p) {
            std::cout << p.get_name() << "\n";
        }

        display_player_name(villain);       // Error. Why? The compiler assumes that the get_name() function might potentially
                                                change the const data in the specific Player class

    - What is the solution? We need to tell the compiler that specific methods will NOT modify the object.
    - All we need to do is put the const modifier before the ; in the method prototype.

        class Player {
        private:
            ...
        public:
            std::string get_name() const;   
            ...
        };

    - Now the compiler will allow the get_name method to be called on const objects.
    - The const qualifier will also provide a compiler error if we try to modify any of the object attributes in the method.

        std::out << villain.get_name() << "\n";     // ok now
        villain.set_name("Someone else");           // Error 
*/


#include <iostream>


int main() {

    return 0;
}
