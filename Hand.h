// #pragma once
#ifndef CARD_GAME_HAND_H
#define CARD_GAME_HAND_H
#include <istream>
#include <list>
#include <queue>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

// Hand is well mapped by a queue since players have to keep their hand in order and the first card
// drawn is the first card played. The only derivation form this pattern is if players discard a card
// from the middle in Step 4 in the above description of a player's turn. Therefore, we can use a
// std::list to remove at an arbitrary location efficiently with a std::queue adapter

class Hand : public std::queue<Card*, std::list<Card*> > {
    public:
        Hand();
        Hand(std::istream&, const CardFactory*);
        // ~Hand();
        std::list<Card*> getContainer();
        Hand& operator+=(Card*);
        Card* play();
        Card* top();
        Card* operator[](int);
        friend std::ostream& operator<<(std::ostream&, Hand&);
};

#endif
