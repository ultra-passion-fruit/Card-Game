// #pragma once
#ifndef CARD_GAME_CARD_H
#define CARD_GAME_CARD_H
#include <string>
#include <ostream>
#include <array>

// Card will be an abstract base class and the eight different bean cards will be derived from it
// (inheritance). All containers will hold cards through the base type. However, standard containers
// do not work well with polymorphic types because they hold copies (slicing will occur).

/*
* Card is an abtract class used as an interface for Cards of types
* Blue, Chili, Stink, Green, soy, black, Red and garden.
*/
class Card {
    protected:
        int valTable[4];
    public:
        Card() = default;
        // Card(const std::array<int, 4>& chainVal){
        //     for(int i = 0; i < 4; i++){
        //         valTable[i] = chainVal[i];
        //     }
        // }
        // explicit Card(const int chainVal[4]){
        //     for(int i = 0; i < 4; i++){
        //         valTable[i] = chainVal[i];
        //     }
        // }
        Card(const Card&) = delete;
        Card& operator=(const Card&) = delete;

        // Takes an amount of coins as integer input and return a chain number with
        // the corresponding value.
        virtual int getCardsPerCoin(int) = 0;

        // Returns a string to represent the full name of the card.
        virtual std::string getName() const = 0;

        // Inserts the first character of the card in the provided output stream.
        virtual void print(std::ostream&) = 0;

        // Global output stream for printing any card types derived from Card.
        friend std::ostream& operator <<(std::ostream& os, Card& c);
};

// Below are the different card types which will provide unique implementations for the
// abstract functions inherited from the Card class.

class Blue: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Blue(){
        valTable[0] = 3;
        valTable[1] = 6;
        valTable[2] = 8;
        valTable[3] = 9;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Chili: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Chili(){
        valTable[0] = 3;
        valTable[1] = 6;
        valTable[2] = 8;
        valTable[3] = 9;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Stink: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Stink(){
        valTable[0] = 3;
        valTable[1] = 6;
        valTable[2] = 8;
        valTable[3] = 9;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Green: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Green(){
        valTable[0] = 3;
        valTable[1] = 6;
        valTable[2] = 8;
        valTable[3] = 9;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Soy: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Soy(){
        valTable[0] = 2;
        valTable[1] = 4;
        valTable[2] = 5;
        valTable[3] = 6;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Black: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Black(){
        valTable[0] = 2;
        valTable[1] = 4;
        valTable[2] = 5;
        valTable[3] = 6;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Red: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Red() {
        valTable[0] = 2;
        valTable[1] = 3;
        valTable[2] = 4;
        valTable[3] = 5;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Garden: public Card {
    friend class CardFactory;
    // std::vector<int> valTable;
    Garden(){
        valTable[0] = -1;
        valTable[1] = 2;
        valTable[2] = 3;
        valTable[3] = -1;
    }
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

#endif