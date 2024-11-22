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
* Will let player add cards to chains.
* When allowDiscard=true, player can choose to discard all cards in Trade Area.
* When fromHand=true, card to add is topmost card from hand, otherwise is from Trade Area.
* @param allowDiscard
* @param tradeArea
*/
void Table::addToChains(bool allowDiscard, bool fromHand) {

}