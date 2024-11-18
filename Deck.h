#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>

#include "Card.h"
#include "CardFactory.h"

// Deck will initially hold all the cards which will have to be shuffled to produce a randomized
// order, then players' hands are dealt and during game play players draw cards from the Deck.
// There is no insertion into the Deck. Deck can therefore usefully extend a std::vector.


// Deck will initially hold all the cards which will have to be shuffled to produce a randomized
// order, then players' hands are dealt and during game play players draw cards from the Deck.
// There is no insertion into the Deck. Deck can therefore usefully extend a std::vector.


class Deck : public std::vector<Card*> {
    void shuffle_cards();
public:
    Deck(std::istream&, class CardFactory*);
    ~Deck();
    Card* draw();
    friend std::ostream& operator<<(std::ostream&, Deck&);
};