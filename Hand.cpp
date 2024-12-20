#include <iterator>
#include <stdexcept>

#include "Hand.h"

Hand::Hand() {

}

/**
 * Constructor for create from file save.
 */
Hand::Hand(std::istream& is, const CardFactory* cardFactory){
    std::string ln;
    std::vector<bool> got(104, false);
    std::getline(is, ln);
    Deck fullDeck = cardFactory->getDeck();
    for(char& c: ln){
        if(c != ' '){
            for(int i = 0; i < 104; i++){
                if(!got[i] && fullDeck[i]->getName().at(0) == c){
                    push(fullDeck[i]);
                    got[i] = true;
                }
            }
        }
    }
}

/*
* Adds a new card to the player's hand.
* Hand is automatically sorted after adding.
@return Hand reference
*/
Hand& Hand::operator+=(Card* newCard) {
    this->push(newCard);
    return *this;
}

/*
* Removes top card from player's hand.
* @return Card pointer
* @throws out_of_range
*/
Card* Hand::play() {
    if (!this->empty())
    {
        Card* card = this->front();
        this->pop();
        return card;
    } else {
        throw std::out_of_range("The hand is empty.");
    }
}

/*
* Shows top card from player's hand. (does not remove it)
* @return Card pointer
* @throws out_of_range
*/
Card* Hand::top() {
    if (!this->empty())
    {
        return this->front();
    } else {
        throw std::out_of_range("The hand is empty.");
    }
}

/*
* Returns and removes the Card at the specified position.
* Indexed from 0.
* @return Card pointer
* @throws out_of_range
*/
Card* Hand::operator[](int i) {
    std::list<Card*>::iterator it = this->c.begin();
    if (i < this->size() && i > -1)
    {
        std::advance(it, i);
        Card* card = *it;
        this->c.erase(it);
        return card;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

/*
* Returns inner list container from queue adapter.
*@return list reference
*/
std::list<Card*> Hand::getContainer() {
    return this->c;
}

/*
* Insertion operator for Hand class. Displays all cards in 
* hand with card properly formatted.
* @param os
* @param hand
* @return ostream reference
*/
std::ostream& operator<<(std::ostream& os, Hand& hand) {
    std::list<Card*> innerList = hand.getContainer();
    std::list<Card*>::iterator it;
    if (!innerList.empty())
    {
        for (it = innerList.begin(); it != innerList.end(); it++)
        {
            os << *(*it);
        }
    }
    return os;
}
