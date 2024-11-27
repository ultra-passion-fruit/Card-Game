#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>

#include "Card.h"

// Deck will initially hold all the cards which will have to be shuffled to produce a randomized
// order, then players' hands are dealt and during game play players draw cards from the Deck.
// There is no insertion into the Deck. Deck can therefore usefully extend a std::vector.

class Deck : public std::vector<Card*> {

    // Shuffles the deck.
    void shuffle_cards();
public:

    // Default constructor of the Deck.
    Deck() = default;

    // Reconstructs a deck from file using cards from the CardFactory
    Deck(std::istream&, class CardFactory*);

    // Returns and removes the card on top of the deck.
    Card* draw();

    // Insert all cards in Deck on a provided ostream.
    friend std::ostream& operator<<(std::ostream&, Deck&);
};