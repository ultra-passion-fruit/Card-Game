#include <string>
#include <ostream>

/*
* Card is an abtract class used as an interface for Cards of types
* Blue, Chili, Stink, Green, soy, black, Red and garden.
*/
class Card {
    public:
        virtual int getCardsPerCoin(int) = 0;
        virtual std::string getName() = 0;
        virtual void print(std::ostream&) = 0;
};
