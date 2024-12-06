#include <iostream>
#include "Player.h"
#include "Table.h"
#include <stdlib.h>
#include <unistd.h>

// main formatting helper function
void enter();

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
    std::string nameP2 = "Test 2";
    std::cout << "P2 Name: ";
    std::cin >> nameP2;
    Player p2(nameP2);
    
    std::cout << "\nGreat! Let's begin." << std::endl;

    // Making Table Object
        // (deals cards in ctor)
        // (defines p1 as starting player)
    Table table(p1, p2, factory);
    
    // winner variable for later
    std::string winner;

    // deal 5 cards to each player
    table.startGame();

    std::cout << "\nFirst, each player is dealt 5 cards." << std::endl;

    // displays ENTER message
    enter();

    // OR

    // Load game from file

    // REPEAT as long as deck is not empty
    while (!table.win(winner))
    {

        // display table
            // shows deck, trade area and player hands
        std:: cout << table << std::endl;
        
        // P1 starting player
        std::cout << std::endl;
        std::cout << table.getCurrent()->getName() << ", it is your turn." << std::endl;

        // displays ENTER message
        enter();

        //////////   (1)   Pick from trade area to add to chain   //////////
        
        std::cout << "[1] Pick from trade area to add to chain, or choose to clear trade area." << std::endl;

        // if trade area not empty
        if(!table.tradeAreaIsEmpty())
        {
            // OPTION: Add cards to chain
            // will show Trade Area
            // allow player to choose card to add to chain
            // can choose to discard all cards too
            int pick = true;
            std::cout << "\n\tOPTION:" << std::endl;
            std::cout << "\t(1) Pick a card from trade area to add to chain." << std::endl;
            std::cout << "\t(2) Discard all cards in the trade area." << std::endl;
            do {
                std::cout << "\n\tChoice: ";
                std::cin >> pick;
            } while (pick > 2 || pick < 1);
            // assigning bool value to pick based on player choice
            pick = pick == 1;
            char another = 'n';
            do {
                // SELECT card to add
                // if pick=true, don't discard, pick. Otherwise, discard
                // 2nd arg = false, add from trade area, not hand
                table.addToChains(!pick, false);

                // displays ENTER message
                enter();

                std::cout << table << std::endl;

                if (pick)
                {
                    std::cout << "\n\tWould you like to add another card? (y/n) ";
                    std::cin >> another;
                } else {
                    another = 'n';
                }
            } while (another == 'y');
        } else {
            std::cout << "\n\tTrade area is empty. Skipping..." << std::endl;
            // displays ENTER message
            enter();
        }
        
        //////////   (2)   Place top card from hand in a chain   //////////
        
        char repeat = 'n';
        std::cout << "\n[2] Choose a chain to place your topmost card in." << std::endl;
        // REPEAT as long as player wants
        do
        {   
            // PLAYER play topmost card from hand
            table.addToChains(false, true);
            
            // displays ENTER message
            enter();

            // displaying table to player after adding card
            std::cout << table << std::endl;
            
            std::cout << "\n\tWould you like to play another card? (y/n) ";
            std::cin >> repeat;
        } while (repeat == 'y');

        //////////   (3)   Discard a card from hand (OPT)   //////////
        
        std::cout << "\n[3] Discard a card from your hand. (Optional)" << std::endl;
        char discard = 'n';        
        std::cout << "\n\tWould you like to discard a card from your hand? (y/n) ";
        std::cin >> discard;
        // OPTION: Discard a card
        if (discard == 'y')
        {
            // shows cards to discard and player chooses
            table.playerDiscards();
        }

        // enter message
        enter();

        std::cout << table << std::endl;
        
        //////////   (4)   New cards added to table   //////////

        std::cout << "\n[4] Drawing more cards in trade area." << std::endl;
        std::cout << "\n\tDrawing 3 cards from deck and placing in trade area." << std::endl;
        std::cout << "\tDrawing from discard pile as long as matching bean in trade area." << std::endl;
        // DRAW 3 cards from deck and place in trade area
        // DRAW from discard pile as long as same bean trade area
        table.lastDraw();

        // displays ENTER message
        enter();

        std::cout << table << std::endl;

        //////////   (5)   Pick from trade area to add to chain  //////////    

        std::cout << "\n[5] Pick from trade area to add to chain. (Optional)" << std::endl;

        // ADD from trade area to chain (OPT)
        char add = 'n';
        std::cout << "\n\tWould you like to add cards from the trade area to a chain? (y/n) ";
        std::cin >> add;
        if (add == 'y')
        {
            char another = 'n';
            do {
                // SELECT card to add
                table.addToChains(false, false);

                // displays ENTER message
                enter();

                std::cout << table << std::endl;

                std::cout << "\n\tWould you like to add another card? (y/n) ";
                std::cin >> another;
            } while (another == 'y');
        }

        //////////   (6)   Get cards from deck into hand   //////////

        std::cout << "\n[6] Draw 2 cards from deck into player's hand." << std::endl;

        // displays ENTER message
        enter();

        // DRAW 2 cards from deck to current player
        table.finishTurn();

        std::cout << table << std::endl;

        // displays ENTER message
        enter();

        // CHANGE player
        table.changeCurrent();
    }
    if(winner == "Draw"){
        std::cout << "It is a draw" << std:: endl;
    } else {
        std::cout << winner << " won! Congrats!" << std::endl; 
    }
    return 0;
}

void enter() {
    std::cout << "\n\tPress (ENTER) or any key to continue." << std::endl;
    std::cin.get();
}