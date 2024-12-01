#include "Player.h"

#include <stdexcept>

/*
* Constructor with name.
*/
Player::Player(std::string& inputName) : 
    name(inputName),
    numOfCoins(0),
    maxNumChains(2),
    chains(0) {}

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
* Returns size of the player's hand 😏
*@return int
*/
int Player::handSize() {
    return hand.size();
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

/*
* Adds a new chain to the player.
*/
void Player::buyThirdChain() {
    if (numOfCoins >= 3)
    {
        chains.resize(3);
    } else {

    }
}

/**
 * Sells a player's chain.
 */
void Player::sellChain() {
    // idk
    int i = 4;
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
    os << hand;
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

