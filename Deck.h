#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>

#include "Card.h"
#include "CardFactory.h"

class Deck : public std::vector<Card*> {
    void shuffle_cards();
public:
    Deck(std::istream&, class CardFactory*);
    ~Deck();
    Card* draw();
    friend std::ostream& operator<<(std::ostream&, Deck&);
};