//Implementation for discardpile
#include "DiscardPile.h"

DiscardPile::DiscardPile(std::istream &, const CardFactory *) {}

DiscardPile& DiscardPile::operator+=(Card * c) {
    discardPile.push_back(c);
    return *this;
}

Card* DiscardPile::pickUp() {
    if(discardPile.empty()) return nullptr;
    Card* c = discardPile.back();
    discardPile.pop_back();
    return c;
}

Card* DiscardPile::top() const {
    if(discardPile.empty()) return nullptr;
    return discardPile.back();
}

void DiscardPile::print(std::ostream & os) const {
    for(Card* c: discardPile){
        os << *c;
    }
}

std::ostream &operator<<(std::ostream & os, const DiscardPile & pile) {
    if(!pile.discardPile.empty()){
        os << pile.top()->getName();
    }
    return os;
}
