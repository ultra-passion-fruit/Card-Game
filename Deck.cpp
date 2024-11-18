// This is implementation of the Deck class
#include "Deck.h"

Deck::Deck(istream& in, const CardFactory* cardFactory){}

//Deck::~Deck(){
//    for(Card* c: *this){
//        delete c;
//    }
//}

void Deck::shuffle_cards() {
    random_device rdm;
    mt19937 g(rdm());

    shuffle(this->begin(), this->end(), g);
}

Card* Deck::draw(){
    //Check for empty
    Card* card = this->back();
    this-> pop_back();
    return card;
}

ostream& operator<<(ostream& os, const Deck& deck){}




