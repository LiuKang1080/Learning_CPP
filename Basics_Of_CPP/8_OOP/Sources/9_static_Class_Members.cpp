// static Class Members

/*
Static  Class Members:
    - Class data members can be declared as static.
    - A single data member that belongs to the class, not to the objects.
    - Useful to store class wide information.
    - Class members can declared as static independent of any objects.
    - Can be called using the class name.

    - ex) Player class that counts the number of players. Counts the number current active players.

        The class prototyping would generally be in a Player.h header file.

        class Player {
        private:
            static int num_players;

        public:
            static int get_num_players();
        };

    The implementation of the methods and the functions will generally be in the .cpp file 

        #include "Player.h"

        int Player::num_players = 0;        
        // Initialization of the data members. This must happen exaclty once, typically happening in the .cpp file.

        // Implementation of the member function
        int Player::get_num_players() {
            return num_players;
        } 

    - Since the get_num_players function has been designated as static, it only has access to static data members.
    - It does NOT have access to non-static data members in the class.

    - We also need to increment / decrement the Player count whenever we create / destroy objects.
    - Increment the player count in the constructor.

        Player::Player(std::string name_val, int health_val, int xp_val)
            : name{name_val}, health {health_val}, xp{xp_val} {
            
            ++num_players;
        }

    - Decrement the play count in the destructor.

        Player::~Player() {
            --num_players;
        }

    - We can also create a display player helper function that we can call at any time. 
    - Displays the current number of players:

        void display_active_players() {
            std::cout << "Number of active players: " << Player::get_num_players() << "\n";
        }
*/


#include <iostream>


int main() {

    return 0;
}
