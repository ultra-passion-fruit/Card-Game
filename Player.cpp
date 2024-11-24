#include "Player.h"

/*
* Constructor with name.
*/
Player::Player(std::string& inputName) : 
    name(inputName),
    numOfCoins(0),
    maxNumChains(2) {
        chains.resize(maxNumChains);
    }

/*
* Constructor for create from file save.
*/
Player::Player(std::istream& inputStream, const CardFactory*) {

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

/*
* Getter for number of coins.
@return numOfCoins
*/
int Player::getMaxNumChains() {
    return chains.size();
}

/*
* Adds a new chain to the player.
*/
void Player::buyThirdChain() {
    
}

/*
* += operator to add coins to player object
@return Player& (a Player reference)
*/
Player& Player::operator+= (int newCoins) {
    numOfCoins += newCoins;
    return *this;
}

