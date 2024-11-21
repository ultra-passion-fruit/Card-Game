#include "CardFactory.h"
#include "Card.h"

CardFactory::CardFactory() {
    for(int i = 0; i < blueSz; i++){
        d.push_back(new Blue());
    }

    for(int i = 0; i < chiliSz; i++){
        d.push_back(new Chili());
    }

    for(int i = 0; i < stinkSz; i++){
        d.push_back(new Stink());
    }

    for(int i = 0; i < greenSz; i++){
        d.push_back(new Green());
    }

    for(int i = 0; i < soySz; i++){
        d.push_back(new Soy());
    }

    for(int i = 0; i < blackSz; i++){
        d.push_back(new Black());
    }

    for(int i = 0; i < redSz; i++){
        d.push_back(new Red());
    }

    for(int i = 0; i < gardenSz; i++){
        d.push_back(new Garden());
    }

}

CardFactory::~CardFactory() {
    for(Card &c: d){
        delete c;
    }
}

Deck CardFactory::getDeck() {
    std::random_device rdm;
    std::mt19937 g(rdm());

    shuffle(d.begin(), d.end(), g);

    return d;
}

CardFactory* CardFactory::getFactory() {
    static CardFactory inst;
    return &inst;
}