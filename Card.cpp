#include "Card.h"

std::ostream& operator<<(std::ostream& os, Card& c){
    c.print(os);
    return os;
}

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
    os << "B";
}

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
    os << "C";
}

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
    os << "S";
}

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
    os << "G";
}

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
    os << "s";
}

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
    os << "b";
}

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
    os << "R";
}

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
    os << "g";
}


