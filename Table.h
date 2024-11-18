#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
    private:
        Player1;
        Player2;
        Deck;
        DiscardPile;
        TradeArea;
    public:
        Table(std::istream&, const CardFactory*);
        ~Table();
        bool win(std::string&);
        void printHand(bool);
        friend std:ostream& operator<<(std::ostream&, const Table&);
};
