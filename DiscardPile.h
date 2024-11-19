#include <vector>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

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
