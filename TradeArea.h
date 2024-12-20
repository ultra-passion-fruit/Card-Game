// #pragma once
#ifndef CARD_GAME_TRADEAREA_H
#define CARD_GAME_TRADEAREA_H
#include <list>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

// TradeArea class will have to hold cards openly and support random access insertion and
// removal.

class TradeArea : public std::list<Card*> {
    public:
        TradeArea(std::istream&, const CardFactory*);
        TradeArea();
        int numCards();
        bool legal(Card*);
        Card* trade(std::string);
        TradeArea& operator+=(Card*);
        friend std::ostream& operator<<(std::ostream&, TradeArea&);
};

#endif
