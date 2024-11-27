#include <istream>
#include "CardFactory.h"

/*
* Chain_Base is an interface to the Chain class.
*/
class Chain_Base {
    public:
        Chain_Base() = default;
        ~Chain_Base() = default;

        // Returns the coin value of chain based on length.
        virtual int sell() = 0;

        // Print the chain according to specified format.
        virtual void print(std::ostream&) = 0;
};
