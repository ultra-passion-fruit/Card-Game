#include "Table.h"

/*
* is a constructor which accepts an istream and reconstruct the Table from file.
*/
// Table::Table(std::istream& is, const CardFactory* factory) {

// }

Table::Table(const Player p1, const Player p2, CardFactory* fact) {
    player1 = p1;
    player2 = p2;
    deck = fact->getDeck();
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}