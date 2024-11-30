#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"
#include "Chain_Base.h"
#include "Hand.h"

class Player {
    private:
        Hand hand;
        std::string name;
        int numOfCoins;
        int maxNumChains;
        std::vector<Chain_Base> chains;
    public:
        Player();
        Player(std::string&);
        Player(std::istream&, const CardFactory*);
        ~Player();
        std::string getName();
        int getNumCoins();
        int getMaxNumChains();
        int getNumChains();
        Card* play();
        void buyThirdChain();
        void sellChain();
        Player& operator+=(int);
        Chain_Base& operator[](int);
        std::ostream& printHand(std::ostream&, bool);
        friend std::ostream& operator<<(std::ostream&, const Player&);
};

#endif
