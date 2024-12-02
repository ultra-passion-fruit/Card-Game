#include "Table.h"
#include <stdexcept>

/*
* Table constructor which accepts an istream and reconstruct the Table from file.
* @param istream& is
* @param CardFactory* factory
*/
Table::Table(std::istream& is, const CardFactory* factory) {

}

/*
* Table Constructor for normal game (no save file)
* @param Player p1
* @param Player p2
* @param CardFactory* factory
*/
Table::Table(Player p1, Player p2, CardFactory* fact) {
    player1 = p1;
    player2 = p2;
    current = &player1;
    deck = fact->getDeck();
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}

Table::~Table() {
    delete current;
}

/*
* Returns true if a player has won.
* Checks if the deck is empty. If so, checks which player
* has more coins.
*@param winnerName
*@return bool
*/
bool Table::win(std::string& winnerName) {
    if (!deck.empty())
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

/**
 * Returns the player whose turn it currently is.
 * @return Player pointer
*/
Player* Table::getCurrent() {
    return current;
}

/**
 * Returns true if discard pile is empty.
 */
bool Table::discardIsEmpty() {
    return discardPile.empty();
}

/**
 * Returns true if trade area is empty.
 */
bool Table::tradeAreaIsEmpty() {
    return tradeArea.empty();
}

/**
 * This deals the initial cards to the players.
 */
void Table::startGame() {
    // draw 5 cards for each player
    for (int i = 0; i < 5; i++)
    {
        player1.pickUp(deck.draw());
        player2.pickUp(deck.draw());
    }
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
        std::cout << "\n\tDiscarding all cards in the trade area..." << std::endl;
        tradeArea.clear();
    } else {
        // card to add
        Card* card;
        if (fromHand)
        {
            //////    Getting card from current player top of hand      //////
            card = current->play();
        } else {
            //////            Getting card from trade area             //////
            std::cout << "\tPick a card from the trade area." << std::endl;
            
            bool found = true;
            std::string beanChoice;
            do {
                std::cout << "\n\tEnter the bean name: ";
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
        }
        
        ////// Getting chain to place card into //////
        int chainChoice = 0; // 0 default if no chain
        bool correct = true;
        do {
            std::cout << "\n\tInto which chain to add card?" << std::endl;
            std::cout << "\tEnter the chain number: ";
            std::cin >> chainChoice;
            // checking user input
            if (chainChoice < 1 || chainChoice > current->getMaxNumChains())
            {
                correct = false;
                std::cout << "\tNo such chain. Try a number between 1 and " << current->getMaxNumChains() << std::endl;
            } else {
                // subtract to make up for index
                chainChoice--;
                
                // try getting chain
                Chain_Base* chain;
                try {
                    // in case player selects a chain that is empty
                    // must create it
                    if (!current->positionOccupied(chainChoice))
                    {   
                        // creates chain with card type (still empty tho)
                        current->addChain(card->getName(), chainChoice);
                    }

                    // getting chain
                    chain = &(current->operator[](chainChoice));

                    // add card to chain 
                    chain->operator+=(card);
                    correct = true;
                    std::cout << "\n\tCard added to chain." << std::endl;
                } catch (std::exception const&e) {
                    correct = false;
                    std::cout << "\n\tError: There was an error." << std::endl;
                    std::cout << "\n\tTry again." << std::endl;
                }
            }
        } while (!correct);
    }
}

/**
 * Returns true if player must sell chain.
 */
bool Table::mustSell() {
    // returns false if no chains, dont need to sell, cant lmao
    if (current->getNumChains() == 0) return false;
    
    // checks if all available chains occupied
    bool allOccupied = true;
    for (int i = 0; i < current->getMaxNumChains(); i++)
    {
        allOccupied = allOccupied && current->positionOccupied(i);
    }
    
    return allOccupied && !current->matchSomeChain();
}

/*
* Allows player to sell a desired chain.
*/
void Table::playerSellChain() {
    ////// Getting chain to sell //////
    int chainChoice = 0; // 0 default if no chain
    bool correct = true;
    do {
        std::cout << "\n\tWhich chain would you like to sell?" << std::endl;
        std::cout << "\tEnter the chain number: ";
        std::cin >> chainChoice;
        // checking user input
        if (chainChoice < 1 || chainChoice > current->getMaxNumChains())
        {
            correct = false;
            std::cout << "\tNo such chain. Try a number between 1 and " << current->getMaxNumChains() << std::endl;
        } else {
            // subtract to make up for index
            chainChoice--;
            
            try {
                // LEO HERE WRITE SELL IMPLEMENTATION //






                ////////////////////////////////////////
                correct = true;
                std::cout << "\n\tChain sold." << std::endl;
            } catch (std::exception const&e) {
                correct = false;
                std::cout << "\n\tError: There was an error." << std::endl;
                std::cout << "\n\tTry again." << std::endl;
            }
        }
    } while (!correct);
}

/*
* Will let player choose a card to discard from their hand.
*/
void Table::playerDiscards() {
    ////// Getting card from hand //////
    std::cout << "\n\tPick a card from your hand. Take a look at the table above to see your hand." << std::endl;
    // current->printHand(std::cout, true);
    
    std::cout << "\tFirst card is 1, second is 2, etc." << std::endl;

    Card* card;
    bool correct = true;
    int position;
    do {
        std::cout << "\tEnter the position: ";
        std::cin >> position;
        if (position < 1 || position > current->handSize())
        {
            correct = false;
            std::cout << "\n\tNo such position. Try a number between 1 and " << current->handSize() << "." << std::endl;
        } else {
            // getting card from hand and moving to discard pile
            position--;
            correct = true;
            try {
                card = current->disCard(position);
                discardPile += card;
            } catch (std::out_of_range e) {
                std::cout << e.what();
                std::cout << "\tTry again.";
            }
        }
    } while (!correct);

    std::cout<< "\n\tCard discarded." << std::endl;
}

/*
* Draws a bunch of card everywhere.
*/
void Table::lastDraw() {
    // drawing 3 cards into trade area
    for (int i = 0; i < 3; i++)
    {
        tradeArea += deck.draw();
    }
    
    // adding cards from discard pile into trade area until illegal or no more cards
    Card* card;
    do {        
        // requires if for first card picked, to check if not empty
        if (!discardIsEmpty())
        {
            card = discardPile.pickUp();
            
            if (tradeArea.legal(card))
            {
                tradeArea+= card;
            } else {
                discardPile+= card;
            }
        }
    } while (tradeArea.legal(card) && !discardIsEmpty());
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
    os << "\n============================== Table ===============================\n\n";
    
    // Display Trade Area
    os << "Trade Area: ";
    if (!table.tradeArea.empty())
    {   
        os << table.tradeArea << std::endl;
    } else {
        os << "Empty" << std::endl; 
    }

    // On new line, display discard pile (first card)
    os << "Discard Pile: ";
    if (!table.discardPile.empty())
    {
        os << *(table.discardPile.top()) << std::endl;
    } else {
        os << "Empty" << std::endl;
    }

    // show player 1 chains
    os << "\nPlayer 1 Chains: \n";
    for (int i = 0; i < table.player1.getMaxNumChains(); i++)
    {   
        os << "(" << i+1 << ") ";
        if (table.player1.positionOccupied(i))
        {
            table.player1[i].print(os); os << "\n";
        } else {
            os << "Empty\n";
        }
    }

    // show player 1 chains
    os << "\nPlayer 2 Chains: \n";
    for (int i = 0; i < table.player2.getMaxNumChains(); i++)
    {   
        os << "(" << i+1 << ") ";
        if (table.player2.positionOccupied(i))
        {
            table.player2[i].print(os); os << "\n";
        } else {
            os << "Empty\n";
        }
    }

    if (table.current->getName() == table.player1.getName())
    {
        // add player 1 hand to output stream
        os << "\n\nPlayer 1 Hand: ";
        table.player1.printHand(os, true);
    } else if (table.current->getName() == table.player2.getName()) {
        // add player 2 hand to output stream
        os << "\n\nPlayer 2 Hand: ";
        table.player2.printHand(os, true);
    }
    std::cout << "\n" << std::endl;

    os << "====================================================================";
    return os;
}
