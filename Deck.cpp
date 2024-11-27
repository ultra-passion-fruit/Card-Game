// This is implementation of the Deck class
#include "Deck.h"

Deck::Deck(std::istream &, class CardFactory *) {}

void Deck::shuffle_cards() {
    std::random_device rdm;
    std::mt19937 g(rdm());

    shuffle(begin(), end(), g);
}

Card* Deck::draw(){
    if(empty()) return nullptr;

    Card* card = back();
    pop_back();
    return card;
}

std::ostream& operator<<(std::ostream& os, const Deck& deck){
    for(Card* c: deck){
        os << *c;
    }

    return os;
}
