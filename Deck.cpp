// This is implementation of the Deck class
#include "Deck.h"
#include "CardFactory.h"

/**
 * Reconstructs a deck from file using cards from the CardFactory
 */
Deck::Deck(std::istream & is, const CardFactory * cardFactory) {
    std::string ln;
    std::vector<bool> got(104, false);
    std::getline(is, ln);
    Deck fullDeck = cardFactory->getDeck();
    for(char& c: ln){
        if(c != ' '){
            for(int i = 0; i < 104; i++){
                if(!got[i] && fullDeck[i]->getName().at(0) == c){
                    push_back(fullDeck[i]);
                    got[i] = true;
                }
            }
        }
    }
}

/**
 * Shuffles the deck.
 */
void Deck::shuffle_cards() {
    std::random_device rdm;
    std::mt19937 g(rdm());

    shuffle(begin(), end(), g);
}

/**
 * Returns and removes the card on top of the deck.
 * @return The top card.
 */
Card* Deck::draw(){
    if(empty()) return nullptr;

    Card* card = back();
    pop_back();
    return card;
}

/**
 * Insert all cards in Deck on a provided ostream.
 * @param os The ostream.
 * @param deck A Deck.
 * @return The ostream.
 */
std::ostream &operator<<(std::ostream & os, Deck & deck) {
    for(Card* c: deck){
        os << *c;
    }
    return os;
}


