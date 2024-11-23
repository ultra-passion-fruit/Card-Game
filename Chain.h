#include <istream>
#include "Chain_Base.h"
#include "CardFactory.h"

// Chain is also a container and will have to grow and shrink as the game progresses. Again
// insertion is only to one end of the chain and a std::vector is fine (see below).

// A template class will have to created for Chain being parametric in the type of card. In this
// project, we will instantiate Chain for the corresponding bean card.

template <class T> class Chain : public Chain_Base {
    private:
        std::vector<T*> chain;
    public:
        Chain(std::istream&, const CardFactory*);
        ~Chain();
        Chain<T>& oeperator+=(Card*);
        int sell();
        friend std::ostream& operator<<(std::ostream&, const Chain&);
};
