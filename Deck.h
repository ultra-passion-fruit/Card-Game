#include <vector>
#include <istream>
#include "Card.h"
#include "CardFactory.h"

class Deck : std::vector<Card> {
    public:
        Deck(std::istream&, CardFactory*);
        ~Deck();
        Card* draw();
        friend std:ostream& operator<<(std::ostream&, const Deck&);
};
