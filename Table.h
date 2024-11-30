#pragma once
#ifndef TABLE_H
#define TABLE_H
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Chain.h"

class Table {
    private:
        Player player1;
        Player player2;
        Player* current;
        Deck deck;
        DiscardPile discardPile;
        TradeArea tradeArea;
    public:
        Table(std::istream&, const CardFactory*);
        Table(Player, Player, CardFactory*);
        ~Table();
        bool win(std::string&);
        void printHand(bool);
        bool changeCurrent();
        Player* getCurrent();
        bool discardIsEmpty();
        void addToChains(bool, bool);
        void playerPlay();
        void playerSellChain();
        void playerDiscards();
        void lastDraw();
        void finishTurn();
        friend std::ostream& operator<<(std::ostream&, Table&);

};

#endif
