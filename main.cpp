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
    std::cin >> p2;
    
    std::cout << "Great! Let's begin." << std::endl;

    // making table (deals cards in ctor)
    Table table(p1, p2, factory);
    
    // winner variable for later
    std::string winner;

    // OR

    // Load game from file

    // sets starting player as p1
    Player* current = &p1;

    // REPEAT as long as deck is not empty
    while (!table.win(winner))
    {
        // if PAUSE then save game (to file) and exit
        // else
        
        // starts off with p1
        // changes to p2 at the end
        
        // display table
        std:: cout << table << std::endl;
        
        // if trade area not empty
        if(!table.discardEmpty())
        {
            // OPTION:
                // 1. to add to chain
                // 2. or discard cards (all of them ig?)
            table.addTOCHonas();
        }
        
        char repeat = 'n';
        std::cout << "place u topmost card in chain." << std::endl;
        // REPEAT as long as USER wants
        do
        {
            // USER play topmost card from hand
            try {
                table.usRplaYs();
            } catch (ChainInsertionException e) {
                std::cout << e.out << std::endl;
            }
            
            char sell;
            std::cout << "wannT sell chains? (y/n) ";
            std::cin >> sell;

            if (sell == 'y')
            {
                // receive coins (if any)
                table.selLCahisn();
            }
            
            std::cout << " wan a place card again? (y/n) ";
            std::cin >> repeat;
        } while (repeat == 'y');

        // DISCARD card from hand (OPT)
        char discard = 'n';        
        std::cout << "wanna dis card? (y/n) ";
        if (discard == 'y')
        {
            // OPTION:
                // 1. want to discard
                    // SHOW full player hand
                    // SELECT card to discard
                // 2. not want discard
            table.desCaRds();
        }
            
        std::cout << "Drawing 3 cards from deck..." << std::endl;
        
        // TODO:
        // DRAW 3 cards from deck and place in trade area
        // DRAW from dicard pile as long as same bean trade area
        // ADD from trade area to chain (OPT)
            // SELECT card to add

        // DRAW 2 cards from deck to current player

        // CHANGE player
        if (current == &p1)
        {
            current = &p2;
        } else {
            current = &p1;
        }
    }

        

}