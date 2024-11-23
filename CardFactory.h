#include "Deck.h"
#include <random>
#include <algorithm>

// CardFactory will generate all cards, and so, we will explore the factory pattern. A factory
// ensures that there is only a single unit in the program that is responsible to create and delete
// cards. Other parts of the program will only use pointers to access the cards. Note that means, we
// will delete the copy constructor and assignment operator in Card.

class CardFactory {
private:
    static const int blueSz = 20, chiliSz = 18, stinkSz = 16, greenSz = 14, soySz = 12, blackSz = 10, redSz = 8, gardenSz = 6;
    CardFactory();
    CardFactory(const CardFactory&);
    ~CardFactory();
    Deck d;
public:
    // CardFactory& operator=(const CardFactory&) = delete;
    static CardFactory* getFactory();
    Deck getDeck();
};
