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
Table::Table(const Player p1, const Player p2, CardFactory* fact) {
    player1 = p1;
    player2 = p2;
    deck = fact->getDeck();
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}

void Table::printHand(bool all=false) {
    // printing p1 hand
    std::cout << "Player 1:" << std::endl;
    player1.printHand(std::cout, all) << std::endl;
    // printing p2 hand
    std::cout << "Player 2:" << std::endl;
    player2.printHand(std::cout, all) << std::endl;
}