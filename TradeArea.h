#include <list>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

class TradeArea : std::list<Card*> {
    public:
        TradeArea(std::istream&, const CardFactory*);
        ~TradeArea();
        TradeArea& operator+=(Card*);
        bool legal(Card*);
        Card* trade(std::string);
        int numCards();
        friend std::ostream& operator<<(std::ostream&, const TradeArea&);
};
