#include <iterator>
#include <stdexcept>

#include "Hand.h"

Hand::Hand() {

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
@return Card pointer
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
@return Card pointer
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
* Return the Card at the specified position.
* Indexed from 0.
* @return Card pointer
*/
Card* Hand::operator[](int i) {
    std::list<Card*>::iterator it = this->c.begin();
    if (i < this->size() && i > -1)
    {
        std::advance(it, i);
        return *it;
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

std::ostream& operator<<(std::ostream& os, Hand& hand) {
    std::list<Card*> innerList = hand.getContainer();
    std::list<Card*>::iterator it = innerList.begin();
    if (!innerList.empty())
    {
        for(Card* card : innerList) {
            os << card;
        }
    }
    return os;
}