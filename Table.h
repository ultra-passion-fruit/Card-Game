#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
    private:
        Player Player1;
        Player Player2;
        Deck deck;
        DiscardPile discardPile;
        TradeArea tradeArea;
    public:
        Table(std::istream&, const CardFactory*);
        ~Table();
        bool win(std::string&);
        void printHand(bool);
        friend std::ostream& operator<<(std::ostream&, const Table&);
};
