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

    //A discard pile.
    std::vector<Card*> discardPile;
public:
    // Default constructor for DiscardPile.
    DiscardPile() = default;

    // Reconstructs a DiscardPile from file based on cards on CardFactory.
    DiscardPile(std::istream&, const CardFactory*);

    // Adds a provided card to the discard pile.
    DiscardPile& operator+=(Card*);

    // Returns and removes a card from the top of the discard pile.
    Card* pickUp();

    // Returns but does not remove a card from the top of the discard pile.
    Card* top() const;

    // Insert all cards to a provided ostream.
    void print(std::ostream&) const;

    // Insert only the top card to a provided ostream.
    friend std::ostream& operator<<(std::ostream&, const DiscardPile&);
};
