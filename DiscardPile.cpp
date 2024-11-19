//Implementation for discardpile
#include "DiscardPile.h"

DiscardPile::DiscardPile(std::istream &, const CardFactory *) {}

DiscardPile& DiscardPile::operator+=(Card * c) {
    discardPile.push_back(c);
    return *this;
}

Card* DiscardPile::pickUp() {
    // Check if empty
    Card* c = discardPile.back();
    discardPile.pop_back();
    return c;
}

Card* DiscardPile::top() const {
    return discardPile.back();
}

void DiscardPile::print(std::ostream & os) const {}

std::ostream& operator<<(std::ostream& os, const DiscardPile& discardPile){}
