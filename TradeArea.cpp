#include "TradeArea.h"
#include <stdexcept>

/*
* Default constructor for TradeArea.
* 
*/
TradeArea::TradeArea() {

}

/**
 * Constructor for create from file save.
 */
TradeArea::TradeArea(istream& is, const CardFactory* cardFactory) {
    std::string ln;
    std::vector<bool> got(104, false);
    std::getline(is, ln);
    Deck fullDeck = cardFactory->getDeck();
    for(char& c: ln){
        if(c != ' '){
            for(int i = 0; i < 104; i++){
                if(!got[i] && fullDeck[i]->getName().at(0) == c){
                    push_back(fullDeck[i]);
                }
            }
        }
    }
}

/*
* Returns the number of cards in the trade area.
* @return int
*/
int TradeArea::numCards() {
    return this->size();
}

/*
* Returns true if a card can be added to the trade area.
* False, otherwise.
* Will check if there is at least one card with the same
* bean as the card to be added.
*@param card
*@return bool
*/
bool TradeArea::legal(Card* card) {
    std::list<Card*>::iterator it;
    bool matched = false;
    for(it = this->begin(); it != this->end(); it++) {
        bool check = ((*it)->getName() == card->getName());
        matched = matched || check;
    }
    return matched;
}

/*
* Removes a card with the specified bean name from the trade area.
* @param beanName
* @return Card pointer
* @throws invalid_argument
*/
Card* TradeArea::trade(std::string beanName) {
    std::list<Card*>::iterator it;
    for(it = this->begin(); it != this->end(); it++) {
        if ((*it)->getName() == beanName)
        {
            Card* card = *it;
            this->erase(it);
            return card;
        }
    }
    throw std::invalid_argument("No card with such bean in trade area.");
}

/*
* Adds a new card to the trade area.
@param newCard
@return list reference
*/
TradeArea& TradeArea::operator+=(Card* newCard) {
    this->push_back(newCard);
    return *this;
}

/*
* Insertion operator for TradeArea class. Displays all cards in 
* trade area with card properly formatted.
* @param os
* @param tradeArea
* @return ostream reference
*/
std::ostream& operator<<(std::ostream& os, TradeArea& tradeArea) {
    if (!tradeArea.empty())
    {
        for(Card* card : tradeArea) {
            os << *card;
        }
    }
    return os;
}