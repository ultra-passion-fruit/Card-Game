#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

class Hand : std::list<Card*> {
    public:
        Hand(std::istream&, const CardFactory*);
        ~Hand();
        Hand& operator+=(Card*);
        Card* play();
        Card* top();
        Card* operator[](int);
        friend std::ostream& operator<<(std::ostream&, const Hand&);
};
