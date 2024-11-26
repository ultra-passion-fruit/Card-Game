#include "Deck.h"
#include <random>
#include <algorithm>

// CardFactory will generate all cards, and so, we will explore the factory pattern. A factory
// ensures that there is only a single unit in the program that is responsible to create and delete
// cards. Other parts of the program will only use pointers to access the cards. Note that means, we
// will delete the copy constructor and assignment operator in Card.

class CardFactory {
private:

    // Total amount of each card type in deck
    static const int
    blueSz = 20,
    chiliSz = 18,
    stinkSz = 16,
    greenSz = 14,
    soySz = 12,
    blackSz = 10,
    redSz = 8,
    gardenSz = 6;

    Deck d; // A deck of 104 cards

    // The constructor, copy constructor, and destructor are declared private to ensure
    // that once created, no other classes can temper with the CardFactory instance and
    // that there is at most on CardFactory object in the program.
    CardFactory();
    CardFactory(const CardFactory&);
    ~CardFactory();

public:

    // Returns a pointer to the only instance of the CardFactory.
    static CardFactory* getFactory();

    // Returns a shuffled Deck of all 104 cards.
    Deck getDeck();
};
