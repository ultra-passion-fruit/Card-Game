#include <iostream>
#include "Player.h"
#include "Table.h"

void main() {
    // creating factory
    CardFactory* factory = CardFactory::getFactory();;
    std::cout << "Welcome to Card Game!" << std::endl;
    // Player 1 input name
    std::string nameP1;
    std::cout << "P1 Name: ";
    std::cin >> nameP1;
    Player p1(nameP1);
    
    // Player 2 input name
    std::string nameP2;
    std::cout << "P2 Name: ";
    std::cin >> nameP2;
    Player p2(nameP2);
    
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
        if(!table.discardIsEmpty())
        {
            // OPTION:
                // 1. to add to chain
                // 2. or discard cards (all of them ig?)
            // will show Trade Area and allow player to choose card
                // to add to chain
            // can choose to discard all cards too
            table.addToChains(true, false);
        }
        
        char repeat = 'n';
        std::cout << "Choose a chain to place your topmost card." << std::endl;
        // REPEAT as long as USER wants
        do
        {
            // PLAYER play topmost card from hand
            try {
                table.addToChains(false, true);
            } catch (ChainInsertionException e) {
                std::cout << e.out << std::endl;
            }

            // TODO: Something that will check if the player 
                // absolutely must sell chains, not sure how to do yet.
            // receive coins (if any)
            // will list to player the chain options to sell
            table.playerSellChain(current);
            
            std::cout << "Would you like to play another card? (y/n) ";
            std::cin >> repeat;
        } while (repeat == 'y');

        // DISCARD card from hand (OPT)
        char discard = 'n';        
        std::cout << "Would you like to discard a card from your hand? (y/n) ";
        std::cin >> discard;
        // OPTION:
            // 1. want to discard
                // SHOW full player hand
                // SELECT card to discard
            // 2. not want discard
        if (discard == 'y')
        {
            // shows player cards to discard and chooses
            table.playerDiscards();
        }
            
        // DRAW 3 cards from deck and place in trade area
        // DRAW from discard pile as long as same bean trade area
        std::cout << "Drawing 3 cards from deck..." << std::endl;
        // will draw 3 cards and keep drawing from discard pile till no good
        table.lastDraw();

        // ADD from trade area to chain (OPT)
        char add = 'n';
        std::cout << "Would you like to add cards from the Trade Area to a chain? (y/n) " << std::endl;
        std::cin >> add;
        if (add == 'y')
        {
            // SELECT card to add
            table.addToChains(false, false);
        }
        // DRAW 2 cards from deck to current player
        table.finishTurn();

        // CHANGE player
        if (current == &p1)
        {
            current = &p2;
        } else {
            current = &p1;
        }
    }

        

}