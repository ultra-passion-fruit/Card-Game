#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"
#include "Chain_Base.h"
#include "Hand.h"

class Player {
    private:
        Hand hand;
    public:
        Player();
        Player(std::string&);
        Player(std::istream&, const CardFactory*);
        ~Player();
        std::string getName();
        int getNumCoins();
        Player& operator+=(int);
        int getMaxNumChains();
        int getNumChains();
        Chain_Base& operator[](int);
        void buyThirdChain();
        void sellChain();
        std::ostream& printHand(std::ostream&, bool);
        friend std::ostream& operator<<(std::ostream&, const Player&);
};
