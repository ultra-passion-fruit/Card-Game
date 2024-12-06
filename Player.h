// #pragma once
#ifndef CARD_GAME_PLAYER_H
#define CARD_GAME_PLAYER_H
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"
#include "Chain_Base.h"
#include "Chain.h"
#include "Hand.h"

class NotEnoughCoins: public std::exception{
public:
    NotEnoughCoins() = default;
    virtual const char* what() const noexcept override {return "Illegal move - Not enough coins for chain purchase.";}
};

class Player {
    private:
        Hand hand;
        std::string name;
        int numOfCoins;
        int maxNumChains;
        bool occupied[3];
        std::vector<Chain_Base*> chains;
    public:
        Player() = default;
        Player(std::string&);
        Player(std::istream&, const CardFactory*);
        ~Player();
        std::string getName();
        int getNumCoins();
        int getMaxNumChains();
        int getNumChains();
        int handSize();
        bool positionOccupied(int);
        bool matchSomeChain(Card*);
        Card* play();
        void pickUp(Card*);
        Card* disCard(int);
        void addChain(std::string, int);
        void buyThirdChain();
        void sellChain(int);
        Player& operator+=(int);
        Chain_Base& operator[](int);
        std::ostream& printHand(std::ostream&, bool);
        friend std::ostream& operator<<(std::ostream&, const Player&);
};

#endif
