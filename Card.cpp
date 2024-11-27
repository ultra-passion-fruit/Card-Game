#include "Card.h"

std::ostream& operator<<(std::ostream& os, Card& c){
    os << "| ";
    c.print(os);
    os << "|";
    return os;
}

// Card type Blue *************************************************************
int Blue::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Blue::getName() const {
    return "Blue";
}
void Blue::print(std::ostream &os) {
    os << "B ";
}

// Card type Chili *************************************************************
int Chili::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Chili::getName() const {
    return "Chili";
}
void Chili::print(std::ostream &os) {
    os << "C ";
}

// Card type Stink *************************************************************
int Stink::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Stink::getName() const {
    return "Stink";
}
void Stink::print(std::ostream &os) {
    os << "S ";
}

// Card type Green *************************************************************
int Green::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Green::getName() const {
    return "Green";
}
void Green::print(std::ostream &os) {
    os << "G ";
}

// Card type Soy *************************************************************
int Soy::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Soy::getName() const {
    return "soy";
}
void Soy::print(std::ostream &os) {
    os << "s ";
}

// Card type Black *************************************************************
int Black::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Black::getName() const {
    return "black";
}
void Black::print(std::ostream &os) {
    os << "b ";
}

// Card type Red *************************************************************
int Red::getCardsPerCoin(int coins) {
    if(coins >= 1 && coins <= 4){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Red::getName() const {
    return "Red";
}
void Red::print(std::ostream &os) {
    os << "R ";
}

// Card type Garden *************************************************************
int Garden::getCardsPerCoin(int coins) {
    if(coins >= 2 && coins <= 3){
        return valTable[coins - 1];
    } else {
        return 0;
    }
}
std::string Garden::getName() const {
    return "garden";
}
void Garden::print(std::ostream &os) {
    os << "g ";
}


