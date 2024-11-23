#include <string>
#include <ostream>

// Card will be an abstract base class and the eight different bean cards will be derived from it
// (inheritance). All containers will hold cards through the base type. However, standard containers
// do not work well with polymorphic types because they hold copies (slicing will occur).

/*
* Card is an abtract class used as an interface for Cards of types
* Blue, Chili, Stink, Green, soy, black, Red and garden.
*/
class Card {
protected:
    int valTable[4]{};
public:
    explicit Card(const int chainVal[4]){
        for(int i = 0; i < 4; i++){
            valTable[i] = chainVal[i];
        }
    }
    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;

    virtual int getCardsPerCoin(int) = 0;
    virtual std::string getName() const = 0;
    virtual void print(std::ostream&) = 0;
    friend std::ostream& operator <<(std::ostream& os, Card& c);
};

class Blue: public Card {
    friend class CardFactory;
    Blue(): Card((const int[4]){3,6,8,9}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Chili: public Card {
    friend class CardFactory;
    Chili(): Card((const int[4]){3,6,8,9}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Stink: public Card {
    friend class CardFactory;
    Stink(): Card((const int[4]){3, 6,8,9}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Green: public Card {
    friend class CardFactory;
    Green(): Card((const int[4]){3,5,6,7}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Soy: public Card {
    friend class CardFactory;
    Soy(): Card((const int[4]){2,4,5,6}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Black: public Card {
    friend class CardFactory;
    Black(): Card((const int[4]){2,4,5,6}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Red: public Card {
    friend class CardFactory;
    Red(): Card((const int[4]){2,3,4,5}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};

class Garden: public Card {
    friend class CardFactory;
    Garden(): Card((const int[4]){-1,2,3,-1}){}
public:
    int getCardsPerCoin(int) override;
    std::string getName() const override;
    void print(std::ostream& os) override;
};