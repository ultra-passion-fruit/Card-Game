//Implementation for discardpile
#include "DiscardPile.h"

DiscardPile::DiscardPile(std::istream &, const CardFactory *) {}

DiscardPile& DiscardPile::operator+=(Card * c) {
    if(c){
        this->push_back(c);
    }
    return *this;
}

Card* DiscardPile::pickUp() {
    // Check if empty
    Card* c = this->back();
    this->pop_back();
    return c;
}

Card* DiscardPile::top() const {
    return this->back();
}

void DiscardPile::print(std::ostream & os) const {}

ostream& operator<<(ostream& os, const DiscardPile& discardPile){}
