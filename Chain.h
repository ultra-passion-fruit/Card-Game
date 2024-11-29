#pragma once
#ifndef CHAIN_H
#define CHAIN_H
#include <istream>
#include "Chain_Base.h"
#include "CardFactory.h"

// Chain is also a container and will have to grow and shrink as the game progresses. Again
// insertion is only to one end of the chain and a std::vector is fine (see below).

// A template class will have to created for Chain being parametric in the type of card. In this
// project, we will instantiate Chain for the corresponding bean card.

class IllegalType: public _exception{
public:
    IllegalType() = default;
    const char* what() const {return "Card type mismatch.";}
};

template <class T> class Chain : public Chain_Base {
private:

    // The chain.
    std::vector<T*> chain;
public:
    Chain(std::istream&, const CardFactory*);
    int sell() override;
    void print(std::ostream&) override;

    Chain<T>& operator+=(Card*);


    /**
     * Insert the chain on a provided ostream.
     * @param os The ostream.
     * @param ch A card chain.
     * @return The ostream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Chain<T>& ch){
        ch.print(os);
        return os;
    }
};

template <class T>
Chain<T>::Chain(std::istream & is, const CardFactory * cardFactory) {
    std::string ln;
    std::vector<bool> got(104, false);
    std::getline(is, ln);
    Deck fullDeck = cardFactory->getDeck();
    for(char& c: ln){
        if(c != ' '){
            for(int i = 0; i < 104; i++){
                if(!got[i] && fullDeck[i]->getName().at(0) == c){
                    chain.push_back(fullDeck[i]);
                }
            }
        }
    }
}

/**
 * Returns the coin value of chain based on length.
 * @tparam T A card type.
 * @return The value of the chain.
 */
template <class T>
int Chain<T>::sell() {
    int coins = 0;
    if(chain.empty()){
        return coins;
    }

    int numChain = chain.size();
    for(int i = 1; i <= 4; i++){
        if(chain.front()->getName() == "garden" && i == 1){
            continue;
        } else if(chain.front()-> getName() == "garden" && i > 3){
            break;
        } else {
            int numReference = chain.front() -> getCardsPerCoin(coins);
            if (numChain >= numReference){
                coins = i;
            } else {
                break;
            }
        }
    }
    return coins;
}

template <class T>
void Chain<T>::print(std::ostream & os) {
    os << chain.front()->getName() <<"\t";
    for(const auto c: chain){
        c->print(os);
    }
}

/**
 * Adds a Card to the chain.
 * @tparam T A card type.
 * @param c A card.
 * @return The Chain object.
 */
template <class T>
Chain<T> &Chain<T>::operator+=(Card * c) {
    T* type = dynamic_cast<T*>(c);
    if(!type){
        throw IllegalType();
    } else {
        chain.push_back(type);
        return *this;
    }

}
#endif

