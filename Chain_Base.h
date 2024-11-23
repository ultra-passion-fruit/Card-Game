#include <istream>
#include "CardFactory.h"

/*
* Chain_Base is an interface to the Chain class.
*/
class Chain_Base {
    public:
        // Chain_Base(std::istream&, const CardFactory*);
        Chain_Base() = default;
        ~Chain_Base() = default;

        virtual int sell() = 0;
};
