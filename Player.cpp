#include "Player.h"

#include <stdexcept>
#include <iostream>



/*
* Constructor with name.
*/
Player::Player(std::string& inputName) : 
    name(inputName),
    numOfCoins(5),
    maxNumChains(2),
    chains(0) {
        occupied[0] = false;
        occupied[1] = false;
        occupied[2] = false;
    }

/*
* Constructor for create from file save.
*/
Player::Player(std::istream& inputStream, const CardFactory*) {

}

/**
 * Destructor for Player class. Deleted Chain_Base references
 * inside the chains vector.
 */
Player::~Player() {
    for (Chain_Base* chain : chains) {
        delete chain;
    }
}

/*
* Getter for player name.
@return name
*/
std::string Player::getName() {
    return name;
}

/*
* Getter for number of coins.
@return numOfCoins
*/
int Player::getNumCoins() {
    return numOfCoins;
}

/**
* Getter for number of coins.
* @return numOfCoins
*/
int Player::getMaxNumChains() {
    return maxNumChains;
}

/**
 * Returns the number of chains the player has.
 * @return int
 */
int Player::getNumChains() {
    return chains.size();
}

/*
* Returns size of the player's hand 😏.
* Nah bro, you wildin'
*@return int
*/
int Player::handSize() {
    return hand.size();
}

/**
 * Returns true if top card in hand matches any chain player has.
 * False, otherwise.
 * @param card
 * @return bool
 */
bool Player::matchSomeChain(Card* card) {
    bool matched;
    for (int i = 0; i < getNumChains(); i++)
    {
        if (occupied[i])
        {
            std::ostringstream ss;
            chains[i]->print(ss);
            matched = matched || (ss.str().at(0) == card->getName().at(0));
        }
    }
    return matched;
}

/**
 * Returns true if there is a chain created at specified position.
 */
bool Player::positionOccupied(int i) {
    return occupied[i];
}

/*
* Gets the top card from the hand. Just a silly wrapper function
* because someone decided to make the class structure like this.
*/
Card* Player::play() {
    return hand.play();
}

/*
* Adds card to player's hand.
*/
void Player::pickUp(Card* card) {
    hand+=card;
}

/*
* Discards a card from the player's hand. Another silly wrapper function.
*/
Card* Player::disCard(int i) {
    return hand[i];
}

/**
 * Adds the chain passed as argument.
 */
void Player::addChain(std::string cardName, int chainPosition) {
    Chain_Base* chain;
    if (cardName == "Blue")
    {
        chain = new Chain<Blue>();
    } else if (cardName == "Chili") {
        chain = new Chain<Chili>();
    } else if (cardName == "Stink") {
        chain = new Chain<Stink>();
    } else if (cardName == "Green") {
        chain = new Chain<Green>();
    } else if (cardName == "soy") {
        chain = new Chain<Soy>();
    } else if (cardName == "black") {
        chain = new Chain<Black>();
    } else if (cardName == "Red") {
        chain = new Chain<Red>();
    } else if (cardName == "garden") {
        chain = new Chain<Garden>();
    }
    if (chains.size() < chainPosition+1)
    {
        chains.resize(chainPosition+1);
    }
    chains[chainPosition] = chain;
    occupied[chainPosition] = true;
}

/** 
* Adds a new chain to the player.
*/
void Player::buyThirdChain() {
    if(numOfCoins < 3) throw NotEnoughCoins();
    numOfCoins = numOfCoins - 3;
    chains.resize(3);
    maxNumChains = 3;
}

/**
 * Sells a player's chain.
 */
void Player::sellChain(int idx) {
    // idk
    delete chains[idx];
    occupied[idx] = false;
    // int i = 4;
}

/*
* += operator to add coins to player object
@return Player& (a Player reference)
*/
Player& Player::operator+= (int newCoins) {
    numOfCoins += newCoins;
    return *this;
}

/*
* Returns chain at specified index.
* Indexed from 0.
* @param i
* @return Chain_Base reference
* @throws out_of_range
*/
Chain_Base& Player::operator[](int i) {
    if (i < chains.size() && i > -1)
    {
        return *(chains[i]);
    } else {
        throw std::out_of_range("Index out of range.");
    }
}

/*
* Prints player's hand to console.
* When all=true, prints all cards. therwise, only prints top card.
*@param os
*@param all
*@return ostream reference
*/
std::ostream& Player::printHand(std::ostream& os, bool all) {
    if (all)
    {
        os << hand;
    } else {
        os << hand.front();
    }
    return os;
}

/**
 * Insertion operator for Player object.
 */
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.name;
    os << player.numOfCoins;
    return os;
}

