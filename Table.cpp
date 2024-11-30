#include "Table.h"

/*
* is a constructor which accepts an istream and reconstruct the Table from file.
*/
// Table::Table(std::istream& is, const CardFactory* factory) {

// }

/*
* Table Constructor for normal game (no save file)
* @param Player p1
* @param Player p2
* @param CardFactory* factory
*/
Table::Table(Player p1, Player p2, CardFactory* fact) {
    player1 = p1;
    player2 = p2;
    current = &p1;
    deck = fact->getDeck();
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}

/*
* Returns true if a player has won.
* Checks if the deck is empty. If so, checks which player
* has more coins.
*@param winnerName
*@return bool
*/
bool Table::win(std::string& winnerName) {
    if (!empty(deck))
    {
        return false;
    } else {
        if (bool winning = player1.getNumCoins() > player2.getNumCoins())
        {
            winnerName = player1.getName();
            return winning;
        } else {
            winnerName = player2.getName();
            return !winning;
        }
    }
}

/*
* Will only print top card when all=false (default).
@param all
*/
void Table::printHand(bool all=false) {
    // printing p1 hand
    std::cout << "Player 1:" << std::endl;
    player1.printHand(std::cout, all) << std::endl;
    // printing p2 hand
    std::cout << "Player 2:" << std::endl;
    player2.printHand(std::cout, all) << std::endl;
}

/*
* Changes the player for the next turn.
* @return True if successful, false otherwise.
*/
bool Table::changeCurrent() {
    if (current == &player1)
    {
        current = &player2;
        return true;
    } else if (current == &player2) {
        current = &player1;
        return true;
    }
    return false;
}

/*
* Returns the player whose turn it currently is.
*@return Player pointer
*/
Player* Table::getCurrent() {
    return current;
}

/*
* Will let player add cards to chains.
* When allowDiscard=true, player can choose to discard all cards in Trade Area.
* When fromHand=true, card to add is topmost card from hand, otherwise is from Trade Area.
* @param allowDiscard
* @param fromHand
*/
void Table::addToChains(bool allowDiscard, bool fromHand) {
    if (allowDiscard)
    {
        std::cout << "Discarding all cards in the trade area..." << std::endl;
        tradeArea.clear();
    } else {
        if (fromHand)
        {   
            ////// Getting current player top card from hand //////
            Card* card = current->play();

            ////// Getting chain to place card into //////
            int chainChoice;
            bool correct = true;
            do {
                std::cout << "\nInto which chain to add card?" << std::endl;
                std::cout << "Enter the chain number: " << std::endl;
                std::cin >> chainChoice;
                
                // checking user input
                if (chainChoice < 1 || chainChoice > current->getNumChains())
                {
                    correct = false;
                    std::cout << "No such chain. Try a number between 1 and " << current->getNumChains() << std::endl;
                } else {
                    // try adding card to chain

                    // subtract to make up for index
                    chainChoice--;
                    try {
                        // linter refuses to accet current[chainChoice]
                            // so just wrote it explicitly
                        current->operator[](chainChoice)+=card;
                        correct = true;
                    } catch (IllegalType e) {
                        correct = false;
                        std::cout << e.what() << std::endl;
                        std::cout << "Try again." << std::endl;
                    }
                }
            } while (!correct);

        } else {
            // from trade area
            
            char pick = 'y';
            do {
                ////// Getting card from trade area //////
                std::cout << "Pick a card from the trade area." << std::endl;
                
                Card* card;
                bool found = true;
                std::string beanChoice;
                do {
                    std::cout << "\nEnter the bean name: " << std::endl;
                    std::cin >> beanChoice;
                    try {
                        // getting card from trade area
                        card = tradeArea.trade(beanChoice);
                        found = true;
                    } catch (std::invalid_argument e) {
                        found = false;
                        std::cout << e.what() << std::endl;
                    }
                } while (!found);
                
                ////// Getting chain to place card into //////
                int chainChoice;
                bool correct = true;
                do {
                    std::cout << "\nInto which chain to add card?" << std::endl;
                    std::cout << "Enter the chain number: " << std::endl;
                    std::cin >> chainChoice;

                    if (chainChoice < 1 || chainChoice > current->getNumChains())
                    {
                        correct = false;
                        std::cout << "No such chain. Try a number between 1 and " << current->getNumChains() << std::endl;
                    } else {
                        // try adding card to chain

                        // subtract to make up for index
                        chainChoice--;
                        try {
                            // adding card to chain
                            // linter refuses to accet current[chainChoice] so just wrote it explicitly
                            current->operator[](chainChoice)+=card;
                            correct = true;
                        } catch (IllegalType e) {
                            correct = false;
                            std::cout << e.what() << std::endl;
                            std::cout << "Try again." << std::endl;
                        }
                    }
                } while (!correct);
                
                std::cout << "Would you like to pick another card? (y/n)" << std::endl;
            } while (pick == 'y');
        }
    }
}

/*
* Allows player to sell a desired chain.
*/
void Table::playerSellChain() {

}

/*
* Will let player choose a card to discard from their hand.
*/
void Table::playerDiscards() {
    ////// Getting card from hand //////
    std::cout << "Pick a card from your hand." << std::endl;
    current->printHand(std::cout, true);
    
    std::cout << "\nFirst card is 1, second is 2, etc." << std::endl;

    Card* card;
    bool correct = true;
    int position;
    do {
        std::cout << "Enter the position: ";
        std::cin >> position;
        if (position < 1 || position > current->handSize())
        {
            correct = false;
            std::cout << "No such position. Try a number between 1 and " << current->handSize() << std::endl;
        } else {
            // getting card from hand and moving to discard pile
            position--;
            correct = true;
            try {
                discardPile += current->disCard(position);
            } catch (std::out_of_range e) {
                std::cout << e.what();
                std::cout << "Try again.";
            }
        }
    } while (!correct);
}

/*
* Draws a bunch of card everywhere.
*/
void Table::lastDraw() {
    
}

/*
* Draws 2 cards from deck into current player's hand.
*/
void Table::finishTurn() {
    // does it twice
    current->pickUp(deck.draw());
    current->pickUp(deck.draw());
}

std::ostream& operator<<(std::ostream& os, Table& table) {
    // Display Trade Area
    os << table.tradeArea << std::endl;

    // On new line, display discard pile (first card)
    os << table.discardPile.top() << std::endl;
    
    // add player 1 hand to output stream
    os << "Player 1 Hand: ";
    table.player1.printHand(os, false);

    // show player 1 chains
    os << "Player 1 Chains:" << std::endl;
    for (int i = 0; i < table.player1.getNumChains(); i++)
    {   
        os << "(" << i+1 << ")";
        table.player1[i].print(os); os << "\n";
    }
    
    // add player 2 hand to output stream 
    os << "Player 2 Hand: ";
    table.player2.printHand(os, false); 

    // show player 2 chains
    os << "Player 1 Chains:" << std::endl;
    for (int i = 0; i < table.player2.getNumChains(); i++)
    {   
        os << "(" << i+1 << ")";
        table.player2[i].print(os); os << "\n";
    }

    return os;
}