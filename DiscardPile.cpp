//Implementation for discardpile
#include "DiscardPile.h"

DiscardPile::DiscardPile(std::istream & is, const CardFactory * cardFactory) {
    std::string ln;
    std::vector<bool> got(104, false);
    std::getline(is, ln);
    Deck fullDeck = cardFactory->getDeck();
    for(char& c: ln){
        if(c != ' '){
            for(int i = 0; i < 104; i++){
                if(!got[i] && fullDeck[i]->getName().at(0) == c){
                    discardPile.push_back(fullDeck[i]);
                }
            }
        }
    }
}

/**
 * Adds a provided card to the discard pile.
 * @param c A card to add.
 * @return Reference to the discard pile.
 */
DiscardPile& DiscardPile::operator+=(Card * c) {
    discardPile.push_back(c);
    return *this;
}

/**
 * Returns and removes a card from the top of the discard pile.
 * @return The top card.
 */
Card* DiscardPile::pickUp() {
    if(discardPile.empty()) return nullptr;
    Card* c = discardPile.back();
    discardPile.pop_back();
    return c;
}

/**
 * Returns true if vector is empty.
 */
bool DiscardPile::empty() {
    return discardPile.empty();
}

/**
 * Returns but does not remove a card from the top of the discard pile.
 * @return The top card.
 */
Card* DiscardPile::top() const {
    if(discardPile.empty()) return nullptr;
    return discardPile.back();
}

/**
 * Insert all cards to a provided ostream.
 * @param os The ostream.
 */
void DiscardPile::print(std::ostream & os) const {
    for(Card* c: discardPile){
        os << *c;
    }
}

/**
 * Insert only the top card to a provided ostream.
 * @param os The ostream.
 * @param pile A discard pile.
 * @return The ostream.
 */
std::ostream &operator<<(std::ostream & os, const DiscardPile & pile) {
    if(!pile.discardPile.empty()){
        os << pile.top()->getName();
    } else {
        os << "Discard Pile: Empty";
    }
    return os;
}
