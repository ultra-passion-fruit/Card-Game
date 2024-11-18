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
    public:
        virtual int getCardsPerCoin(int) = 0;
        virtual std::string getName() = 0;
        virtual void print(std::ostream&) = 0;
};
