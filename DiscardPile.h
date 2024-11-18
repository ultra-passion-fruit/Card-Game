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
    std::vector<Card*> discardPile;
    public:
        DiscardPile(std::istream&, const CardFactory*);
        ~DiscardPile();
        DiscardPile& operator+=(Card*);
        Card* pickUp();
        Card* top() const;
        void print(std::ostream&) const;
        friend std::ostream& operator<<(std::ostream&, const Card&);
};
