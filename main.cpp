#include <iostream>
#include "Player.h"
#include "Table.h"

int main() {
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

    // Making Table Object
        // (deals cards in ctor)
        // (defines p1 as starting player)
    Table table(p1, p2, factory);
    
    // winner variable for later
    std::string winner;

    // deal 5 cards to each player
    table.startGame();

    // OR

    // Load game from file

    // REPEAT as long as deck is not empty
    while (!table.win(winner))
    {
        // if PAUSE then save game (to file) and exit
            // TODO (maybe)
        
        // else
        
        // P1 starting player
        std::cout << table.getCurrent()->getName() << ", it is your turn." << std::endl;

        // display table
            // shows deck, trade area and player hands
        std:: cout << table << std::endl;
        
        //////////   (1)   Pick from trade area to add to chain   //////////
        
        // if trade area not empty
        if(!table.discardIsEmpty())
        {
            // OPTION: Add cards to chain
            // will show Trade Area
            // allow player to choose card to add to chain
            // can choose to discard all cards too
            int pick = true;
            std::cout << "OPTION:" << std::endl;
            std::cout << "(1) Pick a card from trade area to add to chain." << std::endl;
            std::cout << "(2) Discard all cards in the trade area." << std::endl;
            do {
                std::cout << "Choice: " << std::endl;
                std::cin >> pick;
            } while (pick > 2 || pick < 1);
            pick--;
            // if pick=true, don't discard, pick. Otherwise, discard
            // 2nd arg = false, add from trade area, not hand
            table.addToChains(pick, false);
        }
        
        //////////   (2)   Place top card from hand in a chain   //////////
        
        char repeat = 'n';
        std::cout << "Choose a chain to place your topmost card." << std::endl;
        // REPEAT as long as player wants
        do
        {
            // PLAYER play topmost card from hand
            table.addToChains(false, true);

            // TODO: Something that will check if the player 
                // absolutely must sell chains, not sure how to do yet.
            // receive coins (if any)
            // will list to player the chain options to sell
            table.playerSellChain();
            
            std::cout << "Would you like to play another card? (y/n) ";
            std::cin >> repeat;
        } while (repeat == 'y');

        //////////   (3)   Discard a card from hand (OPT)   //////////
        
        char discard = 'n';        
        std::cout << "Would you like to discard a card from your hand? (y/n) ";
        std::cin >> discard;
        // OPTION: Discard a card
        if (discard == 'y')
        {
            // shows cards to discard and player chooses
            table.playerDiscards();
        }
        
        //////////   (4)   New cards added to table   //////////

        // DRAW 3 cards from deck and place in trade area
        // DRAW from discard pile as long as same bean trade area
        std::cout << "Drawing 3 cards from deck..." << std::endl;
        table.lastDraw();

        //////////   (5)   Pick from trade area to add to chain  //////////    

        // ADD from trade area to chain (OPT)
        char add = 'n';
        std::cout << "Would you like to add cards from the Trade Area to a chain? (y/n) " << std::endl;
        std::cin >> add;
        if (add == 'y')
        {
            // SELECT card to add
            table.addToChains(false, false);
        }

        //////////   (6)   Get cards from deck into hand   //////////

        // DRAW 2 cards from deck to current player
        table.finishTurn();

        // CHANGE player
        table.changeCurrent();
    }
    return 0;
}