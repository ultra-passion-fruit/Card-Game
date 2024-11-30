// #pragma once
#ifndef CARD_GAME_DISCARDPILE_H
#define CARD_GAME_DISCARDPILE_H
#include <vector>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

// DiscardPile must support insertion and removal but not at random locations but all at the
// end. Again a std::vector will work fine but here we can use simple aggregation.

// DiscardPile must support insertion and removal but not at random locations but all at the
// end. Again a std::vector will work fine but here we can use simple aggregation.

class DiscardPile{

    //A discard pile.
    std::vector<Card*> discardPile;
public:
    // Default constructor for DiscardPile.
    DiscardPile() = default;

    // Reconstructs a DiscardPile from file based on cards on CardFactory.
    DiscardPile(std::istream&, const CardFactory*);

    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top() const;
    void print(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, const DiscardPile&);
};

#endif
