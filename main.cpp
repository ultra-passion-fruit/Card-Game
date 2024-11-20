#include <iostream>
#include "Player.h"
#include "Table.h"

void main() {
    Player p1;
    Player p2;
    // creating factory
    CardFactory* factory = CardFactory::getFactory();;

    std::cout << "Welcome to Card Game!" << std::endl;
    // Player 1 input name
    std::cin >> p1;
    // Player 2 input name    
    std::cin >> p1;
    
    std::cout << "Great! Let's begin." << std::endl;

    // making table (deals cards in ctor)
    Table table(p1, p2, factory);
    
    // winner variable for later
    std::string winner;

    // OR

    // Load game from file

    while (!table.win(winner))
    {
        // if PAUSE then save game (to file) and exit
        // else
        
        // for each player

            // display Table
    }

        

}