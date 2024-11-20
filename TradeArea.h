#include <list>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

// TradeArea class will have to hold cards openly and support random access insertion and
// removal.

class TradeArea : std::list<Card*> {
    public:
        TradeArea(std::istream&, const CardFactory*);
        TradeArea();
        ~TradeArea();
        TradeArea& operator+=(Card*);
        bool legal(Card*);
        Card* trade(std::string);
        int numCards();
        friend std::ostream& operator<<(std::ostream&, const TradeArea&);
};
